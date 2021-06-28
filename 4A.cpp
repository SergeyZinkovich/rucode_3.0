#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

using namespace std;

long long mul_inv(long long a, long long b) {
    long long b0 = b;
    long long x0 = 0;
    long long x1 = 1;
    if (b == 1)
        return 1;
    while (a > 1) {
        long long q = a / b;
        long long temp = b;
        b = a % b;
        a = temp;
        temp = x0;
        x0 = x1 - q * x0;
        x1 = temp;
    }
    if (x1 < 0)
        x1 += b0;
    return x1;
}

int main() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    long long M = 1ll*n*m;
    long long c1 = m * mul_inv(m, n);
    long long c2 = n * mul_inv(n, m);

    long long x = (c1 * a + c2 * b) % M;

    cout << x;
}