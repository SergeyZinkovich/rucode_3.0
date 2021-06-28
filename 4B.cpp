#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lp(n + 1);
    vector<unsigned char> cnt(n + 1);
    vector<int> pr;

    for (int i=2; i <= n; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            cnt[i] = 1;
            pr.push_back(i);
        }
        for (int j=0; j<pr.size() && pr[j]<=lp[i] && i*pr[j] <= n; j++) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] < lp[i])
                if (cnt[i] > 3)
                    cnt[i*pr[j]] = cnt[i];
                else
                    cnt[i*pr[j]] = cnt[i] + 1;
            else if (pr[j] == lp[i])
                cnt[i*pr[j]] = cnt[i];
        }
    }

    for (int i = 2; i <= n; i++) {
        if (cnt[i] >= 3)
            cout << i << " ";
    }
}