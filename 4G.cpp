#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>

using namespace std;

long long powmod (long long a, long long b, long long p) {
    long long res = 1;
    while (b)
        if (b & 1)
            res = res * 1ll * a % p,  --b;
        else
            a = a * 1ll * a % p,  b >>= 1;
    return res;
}

long long generator (long long p) {
    vector<long long> fact;
    long long phi = p-1,  n = phi;
    for (long long i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (long long res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long p;
    while (cin >> p) {
        if (p == 2)
            cout << 1 << '\n';
        else {
            long long ans = generator(p);
            cout << ans << '\n';
        }
    }

    return 0;
}