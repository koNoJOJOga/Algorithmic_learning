#include <iostream>
using namespace std;

void convertToBase(int x, int m, string& result) {
    if (x == 0) return; // 递归终止条件

    int remainder = x % m; // 当前位
    x /= m;               // 更新为下一层递归的值

    // 递归处理更高位
    convertToBase(x, m, result);

    // 将余数转换为字符并添加到结果中
    if (remainder < 10) {
        result += (char)(remainder + '0'); // 0-9
    } else {
        result += (char)(remainder - 10 + 'A'); // A-F
    }
}

int main() {
    int x, m;
    cin >> x >> m;

    string result = "";
    convertToBase(x, m, result);

    cout << result << endl;
    return 0;
}
