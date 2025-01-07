# include<iostream>
# include<string>
# include<stack>

using namespace std;

bool isOP(char c) 
{
    if ((c == '+') || (c == '-') || (c == '*') || (c = '/')) return true;
    else return false;
}

bool isDigit(char c) 
{
    if (c >= '0' && c <= '9') return true;
    else return false;
}

int main ()
{
    string s;
    cin >> s;

    stack<int> n;

    int result = 0;
    int temp = 0;

    int a, b;

    for (char factor : s)
    {
        if (factor == '@') 
        {
            result = n.top();
            cout << result;
            break;
        }
        if (factor != '.')
        {
            if (isDigit(factor)) temp = (temp * 10) + (factor - '0');
            if (isOP(factor))
            {
                if (factor == '+')
                {
                    a = n.top();
                    n.pop();
                    b = n.top();
                    n.pop();
                    n.push(a + b);
                }
                else if (factor == '-')
                {
                    a = n.top();
                    n.pop();
                    b = n.top();
                    n.pop();
                    n.push(b - a);
                }
                else if (factor == '*')
                {
                    a = n.top();
                    n.pop();
                    b = n.top();
                    n.pop();
                    n.push(b * a);
                }
                else if (factor == '/')
                {
                    a = n.top();
                    n.pop();
                    b = n.top();
                    n.pop();
                    n.push(b / a);
                }
            }
        }
        else
        {
            n.push(temp);
            temp = 0;
        }
    }

    return 0;
}