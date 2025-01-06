#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 检查是否是大写字母
bool isUpper(char c) {
    return c >= 'A' && c <= 'Z';
}

// 检查是否是小写字母
bool isLower(char c) {
    return c >= 'a' && c <= 'z';
}

// 检查是否是数字
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// 检查是否是特殊字符
bool isSpecial(char c) {
    return c == '!' || c == '@' || c == '#' || c == '$';
}

// 检查密码是否合规
bool isValidPassword(const string &password) {
    if (password.length() < 6 || password.length() > 12) {
        return false; // 长度不符合要求
    }

    int upperCount = 0, lowerCount = 0, digitCount = 0, specialCount = 0;

    for (char c : password) {
        if (isUpper(c)) upperCount++;
        else if (isLower(c)) lowerCount++;
        else if (isDigit(c)) digitCount++;
        else if (isSpecial(c)) specialCount++;
        else return false; // 包含非法字符
    }

    // 判断是否包含至少两种类型
    int typeCount = 0;
    if (upperCount > 0) typeCount++;
    if (lowerCount > 0) typeCount++;
    if (digitCount > 0) typeCount++;
    if (specialCount > 0) typeCount++;

    return typeCount >= 2 && specialCount >= 1; // 至少两种类型，且至少一个特殊字符
}

int main() {
    string input;
    cin >> input;

    vector<string> passwords;
    string currentPassword = "";

    // 分割输入字符串
    for (char c : input) {
        if (c == ',') {
            if (!currentPassword.empty()) { // 忽略空密码
                passwords.push_back(currentPassword);
            }
            currentPassword = "";
        } else {
            currentPassword += c;
        }
    }
    if (!currentPassword.empty()) { // 添加最后一个密码
        passwords.push_back(currentPassword);
    }

    // 检查并输出合规密码
    for (const string &password : passwords) {
        if (isValidPassword(password)) {
            cout << password << endl;
        }
    }

    return 0;
}
