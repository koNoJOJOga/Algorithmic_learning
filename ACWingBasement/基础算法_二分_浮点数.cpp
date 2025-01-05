#include <iostream>

using namespace std;

int main()
{
    double x;
    cin >> x;

    double l = 0, r = x;
    while (r - l > 1e-8)    // 若要求我们保留6位小数，这里为1e-8，保留4位小数，这里为1e-6，一般这样就不会出现精度问题。
                            // 或者直接把while循环改成for(int i = 0; i < 100; i ++)也可以完成任务
    {
        double mid = (l + r) / 2;
        if (mid * mid >= x) r = mid;
        else l = mid;
    }

    printf("%lf\n", l);

    return 0;
}