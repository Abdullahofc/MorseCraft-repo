using System;
using System.Collections;
namespace Triesdsa
{
    public class Tries
    {
        private class Node
        {
            public char value;
            public Dictionary<char,Node> node = new Dictionary<char,Node>();
            public bool isendofword;
            public Node()
            {
                
            }
            public Node(char va)
            {
                this.value= va;
            }
            public Node[] getchildren()
            {
                return node.Values.ToArray();
            }
            public bool check_child(Node node)
            {
                return node?.value==null;
            }
            public bool has_child()
            {
                return node.Count==0;
            }
            public void remove_child(char ch)
            {
                node.Remove(ch);
            }
            public Node getchild(char va)
            {
                return node[va];
            }
        }
        private Node root=new Node(' ');
        public void insert(string val)
        {
            var current=root;
            foreach (var item in val)
            {
                if (!current.node.ContainsKey(item))
                {
                    current.node[item]   = new Node(item);
                }
                    current = current.node[item];
            }
                current.isendofword = true;
            }
        public void Preorder()
        {
            Preorder(root);
        }
        private void Preorder(Node root)
        {
            Console.WriteLine(root.value);
           foreach(var child in root.getchildren())
            {
                Preorder(child);
            }
        }
            public bool contain(string ch)
            {
            if(ch == null) return false;
            string word="";
            var current = root;
             foreach (var item in ch)
            {
                    if (!current.node.ContainsKey(item))
                    {
                    Console.WriteLine("match word " + word);
                    return false;
                    }
                     word += item;
                    current = current.node[item];
            }
            Console.WriteLine("match word "+word);
            return current.isendofword;
            }
        public void revmove(string word)
        {
            if(word==null) return;
            remove(root,word,0,new Node());
        }
        private void remove(Node root,string word,int count,Node previos)
        {
            int i = word.Length-1;
                foreach (var item in root.getchildren())
                {
                if (count != i+1)
                {
                    if (item.value == word[count])
                    {
                        if (item.isendofword && count == i)
                        {
                            item.isendofword = false;
                            delete(previos);
                            Console.WriteLine("done");
                            return ;
                        }
                        if (item.isendofword)
                        {
                              previos = item;
                        }
                        count++;
                    }
                }
                remove(item, word, count,previos);
            }
        }
        private void delete(Node previos)
        {
               foreach(var item in previos.getchildren())
               {
                delete(item);
                if (item.node.Count==0 && !item.isendofword)
                  {
                    previos.node.Remove(item.value);
                  }
               }
        }
        public void revove_mosh(string word)
        {
            revove_mosh(root, word,0);
        }
        private void revove_mosh(Node node,string word,int index)
        {
            if(index==word.Length)
            {
                node.isendofword=false;
                return;
            }
            var ch = word[index];
            var child= node.getchild(ch);
            if(child==null)
            {
                return;
            }
            revove_mosh(child, word, index + 1);
            if(node.has_child()&&!node.isendofword)
            {
                node.remove_child(ch);
            }
        }
        public void auto_complition(string word)
        {
            auto_complition(root, word, new List<string>());
        }
        private void auto_complition(Node node,string word,List<string>  words)
        {
             foreach(Node node1 in node.getchildren())
            {
                if(node1.isendofword)
                {
                    words.Add(word);
                }
                auto_complition(node1, word, words);
            }
        }
        public void find_word(string ch)
        {
            find_word(root,ch,0);
        }
        private void find_word(Node root,string ch,int index)
        {
            foreach(var item in root.getchildren())
            {
                if (item.value == ch[index]&&item.isendofword)
                {
                    find_word(item, ch, index);
                }
            }
        }
    }
    public class Program
    {
        static void Main(string[] args)
        {

            Tries tries = new Tries();
            tries.insert("pic");
            tries.insert("picture");
            tries.insert("pickle");
            //tries.insert("pictures");

            Console.WriteLine(tries.contain("picture"));

            tries.revove_mosh("picture");
            Console.WriteLine(tries.contain("picture"));
            Console.WriteLine(tries.contain("pickle"));
            //Console.WriteLine(tries.contain("pictures"));
        }

    }
}



      