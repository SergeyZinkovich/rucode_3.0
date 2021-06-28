#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (!cin.eof()) {
        int n;
        string s;
        cin >> s;
        if (!s.empty() && s != "\n")
            n = stoi(s);
        else
            break;

        int result = n;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        if (n > 1)
            result -= result / n;
        cout << result << '\n';
    }

    return 0;
}