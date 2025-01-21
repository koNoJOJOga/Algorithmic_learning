#include <iostream>
#include <vector>
using namespace std;

const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    int bx, by, mx, my;
    cin >> bx >> by >> mx >> my;

    // Adjust coordinates for easier indexing
    bx += 2;
    by += 2;
    mx += 2;
    my += 2;

    // Dynamic programming table and obstacle grid
    vector<vector<long long>> f(2, vector<long long>(by + 1, 0));
    vector<vector<bool>> s(bx + 1, vector<bool>(by + 1, false));

    // Mark the knight's position and its control points
    s[mx][my] = true;
    for (int i = 1; i <= 8; ++i) {
        int nx = mx + fx[i];
        int ny = my + fy[i];
        if (nx >= 2 && nx <= bx && ny >= 2 && ny <= by) {
            s[nx][ny] = true;
        }
    }

    // Initialize starting position
    f[1][2] = 1;

    // Dynamic programming
    for (int i = 2; i <= bx; ++i) {
        for (int j = 2; j <= by; ++j) {
            if (s[i][j]) {
                f[i & 1][j] = 0; // Reset if blocked by the knight
            } else {
                f[i & 1][j] = f[(i - 1) & 1][j] + f[i & 1][j - 1];
            }
        }
    }

    // Output the result
    cout << f[bx & 1][by] << endl;
    return 0;
}
