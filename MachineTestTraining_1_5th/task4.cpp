# include<iostream>
# include<vector>
# include<string>

using namespace std;

bool isupper(char c)
{
    if (c >= 'A' && c <= 'Z') return true;
    else return false;
}

bool islower(char c)
{
    if (c >= 'a' && c <= 'z') return true;
    else return false;
}

bool ifabc(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
    else return false;
}

string Reverse(string &a)
{
    string result = "";
    for (int i = a.size() - 1; i >= 0; -- i)
    {
        if (isupper(a[i])) a[i] = char(a[i] - 'A' + 'a');
        else if (islower(a[i])) a[i] = char(a[i] - 'a' + 'A');
    }
    string temp = "";
    for (int i = 0; i < a.size(); ++ i)
    {
        if (ifabc(a[i])) temp = temp + a[i];
        else
        {
            result = temp + result;
            temp = "";
            result = a[i] + result;
        }
    }
    if (temp != "") result = temp + result; // 若temp非空，加在result上
    return result;
}

int main()
{
    string a;
    
    // 使用 getline 函数读取包含空格的整行输入
    getline(cin, a);

    string result = Reverse(a);
    cout << result << endl;

    return 0;
}