#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long
using namespace std;
LL a, b, Z, N, M, res;
// POJ1995 Raising Modulo Numbers
// 快速幂
LL power(LL a, LL b, LL p) {
    LL ans = 1 % p;
    for(;b;b>>=1) {
        if (b & 1) ans = (ans * a) % p;
        a = (a * a) % p;
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    cin >> Z;
    while(Z--) {
        cin >> M >> N;
        res = 0;
        while(N--) {
            cin >> a >> b;
            res = (res + power(a, b, M)) % M;
        }
        cout << res << endl;
    }
    return 0;
}
