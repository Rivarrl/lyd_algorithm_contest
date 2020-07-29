#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a, b, Z, N, M, res;
// POJ1995 Raising Modulo Numbers
// 快速幂
int power(int a, int b, int p) {
    int ans = 1 % p;
    for(;b;b>>=1) {
        if (b & 1) ans = (long long) ans * a % p;
        a = (long long) a * a % p;
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    scanf("%d", &Z);
    while(Z--) {
        scanf("%d%d", &M, &N);
        res = 0;
        while(N--) {
            scanf("%d%d", &a, &b);
            res = (res + power(a, b, M)) % M;
        }
        printf("%d", res);
    }
    return 0;
}
