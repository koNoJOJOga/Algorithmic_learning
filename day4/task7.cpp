#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // 读取单词数量 N
    int N;
    cin >> N;

    // 读取 N 个单词
    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    // 读取前缀字符串 T
    string T;
    cin >> T;

    // 筛选以 T 为前缀的单词
    vector<string> result;
    for (const string& word : words) {
        if (word.find(T) == 0) { // 判断是否以 T 开头
            result.push_back(word);
        }
    }

    // 按字典序排序
    sort(result.begin(), result.end());

    // 输出结果
    for (const string& word : result) {
        cout << word << endl;
    }

    return 0;
}
