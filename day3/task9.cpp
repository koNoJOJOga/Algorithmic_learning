# include<iostream>
# include<string>

using namespace std;

int main ()
{
    string n;
    cin >> n;

    int count = 0;
    int i = 0;

    while (n[i] != '@')
    {
        if (i == 0 && n[i] == ')') 
        {
            printf ("NO");
            return 0;
        }
        if (n[i] == '(') ++ count ;
        if (n[i] == ')') -- count ;
        if (count < 0) 
        {
            printf ("NO");
            return 0;
        }
        ++ i;
    }

    if (count == 0) cout << "YES" << endl;
    if (count != 0) cout << "NO" << endl;

    return 0;
}