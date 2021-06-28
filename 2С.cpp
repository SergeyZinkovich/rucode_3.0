#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    cout.setf(ios::fixed);
//    cout.precision(10);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long mod = 1e9+7;

    vector<long long> fact(n+1);
    vector<bool> used(n+1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++)
        fact[i] = (fact[i-1] * i) % mod;

    long long numOfPermutation = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < a[i]; j++) {
            if (!used[j])
                numOfPermutation += fact[n - i - 1];
            numOfPermutation %= mod;
        }
        used[a[i]] = true;
    }

    cout << (numOfPermutation+1) % mod;

    return 0;
}