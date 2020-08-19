#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
// 0103. 最短Hamilton路径
int n, ans;
int arr[20][20];
int f[1 << 20][20];

// f[i][j]表示当前状态i和当前位置
int hamilton(int[20][20] arr, int n) {
    memset(arr, 0x3f, sizeof(arr));
    for (int i = 0; i < n; i++) f[1<<i][i] = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) continue;
            for (int k = 0; k < n; k++) {
                f[i ^ (1 << j)][j] = f[i][k] + arr[j][k];
            }
        }
    }
    return f[(1 << n) - 1][n - 1];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    ans = hamilton(arr, n);
    cout << ans << endl;
    return 0;
}