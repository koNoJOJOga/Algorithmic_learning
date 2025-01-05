#include <iostream>
using namespace std;

int main() 
{
    int appleHeights[10]; // 存储10个苹果的高度
    int maxReach;         // 陶陶能够达到的最大高度
    int count = 0;        

    for (int i = 0; i < 10; ++i) 
    {
        cin >> appleHeights[i];
    } 

    cin >> maxReach;

    int totalReach = maxReach + 30;

    for (int i = 0; i < 10; ++i) 
    {
        if (appleHeights[i] <= totalReach) 
        {
            ++count;
        }
    }

    cout << count << endl;

    return 0;
}
