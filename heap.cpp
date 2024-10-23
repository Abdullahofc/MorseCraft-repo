# include <iostream> 
# include <cstring>
# include<cstdlib>
using namespace std;
const int b = 100;
int main()
{
    char name1[500];
    string name2, name4 = "A..-`B-..`C--..`D--.`E---`F..-.-`G..--`H.---`I---`J-...`K.-.-`L---`....`N.--.`M-.-.`O---`P....`Q.....`R-.-..`S--.-`T---`U.--.`V---.`W-.-.`X...-.`Y-.--`Z--`1....`2.--.`3----`4.--`5--./`6-.--`7---`8-.-`9----`0---`?!!`,....`.!!` -../`-()`.{}`";
    int count = 0, kk = 0, a = 0;
    std::cout << "enter a string ";
    cin.getline(name1, b);
    std::cout << "size " << name4.size() << endl;
    for (count = 0; count < strlen(name1); count++)
    {
        if (name1[count] == '.' || name1[count] == '-')
        {
            kk = 225;
            kk = name4.find(name1[count], kk);

            while (name4[kk] != '`')
            {

                std::cout << name4[kk];
                kk++;
            }
            a = 0;
            kk = 0;
            continue;
        }
        kk = name4.find(toupper(name1[count]), kk);

        while (name4[kk] != '`')
        {
            if (a == 0)
            {
                std::cout << " ";
                kk++;
                a++;
            }
            std::cout << name4[kk];
            kk++;
        }
        a = 0;
        kk = 0;
    }

}