# include<iostream>
# include<vector>

using namespace std;

string result;

string baseConversion (int num, int M)
{
    if (!num) return 0;
    int temp = num % M;
    if (M > 10)
    {
        if (temp >= 10) 
    }
}

int main()
{
    int num, M;
    cin >> num >> M;
    result = baseConversion(num, M);
    cout << result << endl;
    return 0;
}