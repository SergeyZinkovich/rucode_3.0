#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>

using namespace std;

long long solve (long long a, long long b, long long m) {
    long long n = (long long) sqrt (m)+2;

    long long an = 1;
    for (long long i = 0; i < n; i++)
        an = (an * a) % m;

    map<long long,long long> vals;
    for (long long i = 1, cur = an; i <= n; i++) {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = (cur * an) % m;
    }

    long long m_ans = -1;
    for (long long i = 0, cur = b; i <= n; i++) {
        if (vals.count(cur)) {
            long long ans = vals[cur] * n - i;
            if ((m_ans == -1 && ans < m) || ans < m_ans)
                m_ans = ans;
        }
        cur = (cur * a) % m;
    }
    if (m_ans != -1)
        return m_ans;

    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long p, b, n;
    while (cin >> p >> b >> n) {
        if (p < 1 ||  b < 1 || n < 1)
            break;
        long long ans = solve(b, n, p);
        if (n == 1)
            cout << 0 << '\n';
        else if (ans == -1)
            cout << "no solution" << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}