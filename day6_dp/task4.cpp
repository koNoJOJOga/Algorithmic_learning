#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>
using namespace std;

int main() {
    vector<unordered_set<string>> elements(11); // 存储不同长度的元素集合，索引为长度（最大10）
    int max_element_length = 0;

    // 读取元素集合，直到遇到单独的"."行
    string element;
    while (cin >> element) {
        if (element == ".") break;
        int len = element.size();
        if (len >= 1 && len <= 10) { // 题目保证元素长度不超过10
            elements[len].insert(element);
            if (len > max_element_length) {
                max_element_length = len;
            }
        }
    }

    // 读取主字符串并拼接所有行
    ostringstream oss;
    string line;
    while (cin >> line) {
        oss << line;
    }
    string full_str = " " + oss.str(); // 前面添加一个空格，使索引从1开始

    vector<bool> dp(full_str.size(), false);
    dp[0] = true; // 空字符串是合法的
    int max_prefix_length = 0;

    for (int i = 1; i < full_str.size(); ++i) {
        int max_j = min(max_element_length, i); // 当前可能的最大元素长度
        for (int j = max_j; j >= 1; --j) { // 从大到小尝试
            int start = i - j;
            if (start < 0) continue;
            if (dp[start]) {
                string substr = full_str.substr(start + 1, j);
                if (elements[j].count(substr)) {
                    dp[i] = true;
                    max_prefix_length = i; // 更新最大合法前缀长度
                    break; // 找到最长可能的j，无需继续检查更小的j
                }
            }
        }
    }

    cout << max_prefix_length << endl;

    return 0;
}