#include <iostream>
#include <string>
using namespace std;
void convert(string &p);
int main(void)
{
    string key;
    string data;
    int flag = 0;
    int demo = -1;
    getline(cin,key);
    getline(cin,data);
    convert(data);
    convert(key);
    int i = 0; int j = 0;
    while(data[i] != '\0')
    {
        if(flag == 0)
        {
            demo = i;
        }
        while(data[i] == key[j])
        {
            if(key[j+1] == '\0' && (data[i+1] == ' ' || data[i+1] == '\0'))
            {
                flag++;
                break;
            }
            else
            {
                j++;
                i++;
            }
        }
        j = 0;
        while(data[i++] != ' ' && data[i] != '\0')
        {
        }
    }
    if(flag != 0)
        cout << flag << " " << demo;
    else
        cout << -1;
    return 0;
}
void convert(string &p)
{
    int i = 0;
    while(p[i] != '\0')
    {
        if(p[i] >= 'A' && p[i] <= 'Z' )
            p[i] += 32;
        i++;
    }
}