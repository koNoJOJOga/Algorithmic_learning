    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        int K;
        cin >> K;

        // 保存满足条件的五位数
        vector<int> results;

        // 枚举范围内所有五位数
        for (int num = 10000; num <= 30000; ++num) {
            int sub1 = num / 100;         // 提取前三位
            int sub2 = (num / 10) % 1000; // 提取中间三位
            int sub3 = num % 1000;        // 提取后三位

            // 检查是否满足条件
            if (sub1 % K == 0 && sub2 % K == 0 && sub3 % K == 0) {
                results.push_back(num);
            }
        }

        for (int num : results) cout << num << endl;

        return 0;
    }
