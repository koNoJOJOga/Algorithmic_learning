#include <iostream>
#include <string>
using namespace std;

// 将整数 x 转换为符合格式的 2 的幂次方表示
string toPowerOfTwo(int x) {
    if (x == 0) return "0";  // 2^0
    if (x == 1) return "2(0)";   // 2^1 不需要括号

    string result = "";
    int power = 0;

    // 遍历 x 的二进制表示，从低位到高位
    while (x > 0) {
        if (x % 2 == 1) {  // 如果当前位是 1
            if (!result.empty()) result = "+" + result;  // 加上分隔符
            if (power == 1) result = "2" + result;       // 2^1 简化为 2
            else result = "2(" + toPowerOfTwo(power) + ")" + result;  // 递归分解 power
        }
        power++;
        x /= 2;  // 右移一位
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    // 输出 n 的幂次方表示
    cout << toPowerOfTwo(n) << endl;

    return 0;
}
