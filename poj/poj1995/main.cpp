#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a, b, M, res;
// 快速幂问题 (a ^ b) mod p
int power(int a, int b, int p) 
{
    int ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = (long long)ans * a % p;
        a = (long long)a * a % p;
    }
    return ans;
}
int main(int argc, char const *argv[]) 
{
    int z, h;
    scanf("%d", &z);
    while (z--)
    {
        res = 0;
        scanf("%d", &M);
        scanf("%d", &h);
        while (h--)
        {
            scanf("%d%d", &a, &b);
            int ans = power(a, b, M);
            res = (res + ans) % M;
        }
        printf("%d\n", res);
    }
    return 0;
}
