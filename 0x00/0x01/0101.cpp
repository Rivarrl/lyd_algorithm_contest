#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a, b, p, res;
// 快速幂问题 (a ^ b) mod p
int power(int a, int b, int p) {
    int ans = 1 % p; // p为1时取模一定为0，所以先用1%p来确认ans的初始值
    for (; b; b >>= 1) {
        if (b & 1) ans = (long long)ans * a % p; // 只有当前位为1时才进行累乘
        a = (long long)a * a % p; // a的1,2,4,...,2^n次幂
    }
    return ans;
}
int main(int argc, char const *argv[]) {
    scanf("%d %d %d", &a, &b, &p);
    res = power(a, b, p);
    printf("%d", res);
    return 0;
}
