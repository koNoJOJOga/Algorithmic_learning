# include<iostream>
# include<string>
# include<vector>

using namespace std;

void swap (char &n, char &m)
{
    char temp = n;
    n = m;
    m = temp;
}

int main () 
{
    string N;
    cin >> N;

    if ((N[0] == '-') && (N.size() == 2) && (N[1] == '0')) cout << "-0";
    if (N == "0") cout << "0" << endl;
    if (N.size() == 1) cout << N;
    if ((N[0] == '-') && (N.size() == 2)) cout << N;

    if (N[0] == '-')
    {
        for (int i = N.size() - 1; i > (N.size() - 1) / 2; -- i )
        {
            swap(N[i], N[N.size() - i]);
        }
    }
    else
    {
        for (int i = N.size() - 1; i >= N.size() / 2; -- i )
        {
            swap(N[i], N[N.size() - i]);
        }
    }

    bool flag = 0;
    if (N[0] == '-')
    {
        cout << '-';
        for (int i = 1; i < N.size(); ++ i )
        {
            if (flag) cout << N[i];
            else
            {
                if (N[i] != '0') 
                {
                    flag = 1;
                    cout << N[i];
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < N.size(); ++ i )
        {
            if (flag) cout << N[i];
            else
            {
                if (N[i] != '0') 
                {
                    flag = 1;
                    cout << N[i];
                }
            }
        }
    }
}