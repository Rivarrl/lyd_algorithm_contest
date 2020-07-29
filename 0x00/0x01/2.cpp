#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LL long long

using namespace std;
LL a, b, p, res;
// 64位整数乘问题 (a * b) mod p
LL mul(LL a, LL b, LL p) {
    LL ans = 0;
    for(;b;b>>=1) {
        if (b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
    }
    return ans;
}

int main() {
    scanf("%lld%lld%lld", &a, &b, &p);
    res = mul(a, b, p);
    printf("%lld", res);
    return 0;
}