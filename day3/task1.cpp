#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    int num;

    // 读取输入直到遇到0
    while (cin >> num && num != 0) {
        numbers.push_back(num);
    }

    // 倒序输出
    for (int i = numbers.size() - 1; i >= 0; --i) {
        cout << numbers[i];
        if (i != 0) {
            cout << " "; // 在数字之间添加空格
        }
    }
    cout << endl;

    return 0;
}
