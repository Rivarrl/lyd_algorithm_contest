#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
// 0104. 起床困难综合症
pair<string, int> a[100005];
int n, m;
// 对第bit位进行操作
int calc(int bit, int now) {
    for (int i = 0; i < n; i++) {
        int x = a[i].second >> bit & 1;
        if (a[i].first == "AND") now &= x;
        else if (a[i].first == "OR") now |= x;
        else now ^= x;
    }
    return now;
}
// 由于位运算是二进制无进位的运算，所以可以对每一位分别计算取最大值
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        char str[5];
        int x;
        scanf("%s%d", str, &x);
        a[i] = make_pair(str, x);
    }
    int val = 0, ans = 0;
    for (int bit = 29; bit >= 0; bit--) {
        int res0 = calc(bit, 0);
        int res1 = calc(bit, 1);
        if (val + (1 << bit) <= m && res0 < res1)
            val += 1 << bit, ans += res1 << bit;
        else
            ans += res0 << bit;
    }
    cout << ans << endl;
    return 0;
}