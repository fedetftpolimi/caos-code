#include <stdio.h>

int compute_gcd(int n, int m)
{
    int p;
    if(n < m) p = n; else p = m;
    int x = 1; int gcd = 1;
    while(x < p)
    {
        x = x + 1;
        if(n % x == 0 && m % x == 0)
            gcd = x;
    }
    return gcd;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int gcd = compute_gcd(n, m);
    printf("%d\n", gcd);
}
