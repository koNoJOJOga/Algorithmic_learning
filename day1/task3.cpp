#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 字符串大数乘法
string multiply(string a, int b) {
    int carry = 0;  // 进位
    string result = "";
    for (int i = a.size() - 1; i >= 0; --i) {
        int product = (a[i] - '0') * b + carry;
        carry = product / 10;
        result = char(product % 10 + '0') + result;
    }
    // 处理进位
    while (carry) {
        result = char(carry % 10 + '0') + result;
        carry /= 10;
    }
    return result;
}

// 字符串大数加法
string add(string a, string b) {
    int lenA = a.size(), lenB = b.size();
    int carry = 0;
    string result = "";
    int i = lenA - 1, j = lenB - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i] - '0';
        if (j >= 0) sum += b[j] - '0';
        carry = sum / 10;
        result = char(sum % 10 + '0') + result;
        i--;
        j--;
    }
    return result;
}

// 计算阶乘
string factorial(int x) {
    string result = "1";  // 1! = 1
    for (int i = 2; i <= x; ++i) {
        result = multiply(result, i);  // 累乘每个数
    }
    return result;
}

int main() {
    int n;
    cin >> n;  // 输入n
    
    string sum = "0";  // 初始化和为0
    for (int i = 1; i <= n; ++i) {
        string fact = factorial(i);  // 计算i!
        sum = add(sum, fact);  // 累加到sum
    }
    
    cout << sum << endl;  // 输出最终结果
    return 0;
}
