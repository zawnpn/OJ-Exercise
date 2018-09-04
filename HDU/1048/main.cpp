#include<string>
#include<iostream>
using namespace std;
int main()
{
    int cnt = 0;
    string buf;
    while(getline(cin, buf) && buf!="ENDOFINPUT")
    {
        cnt++;
        if (2 != (cnt % 3))
        {
            continue;
        }
        for (int i = 0; i < buf.size(); i++)
        {
            if (buf[i] >= 'F' && buf[i] <= 'Z')
            {
                buf[i] -= 5;
            }
            else if (buf[i] >= 'A' && buf[i] <= 'E')
            {
                buf[i] += 21;
            }
        }
        cout << buf << endl;
    }
    return 0;
}