#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    vector<bool> prime ((long long)ceil(sqrt(b))+1, true);
    prime[0] = false;
    prime[1] = false;
    vector<bool> prime1 (b-a+1, true);
    if (a == 1) {
        prime1[0] = false;
    }
    for (long long i=2; i <= (long long)ceil(sqrt(b)); ++i)
        if (prime[i])
            if (i <= (long long)ceil(sqrt(b))) {
                for (long long j = i * i; j <= (long long) ceil(sqrt(b)); j += i) {
                    if (j < prime.size()) {
                        prime[j] = false;
                    }
                }
                long long p = a % i;
                long long begin = 1ll*i*i >= a ? 1ll*i*i : (p == 0 ? a : a + (i - p));
                for (long long j=begin; j <= b; j+=i)
                    prime1[j - a] = false;

            }


    for (long long i = a; i <= b; i++) {
        if (prime1[i-a])
            cout << i << " ";
    }
}