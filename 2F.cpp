#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, p;
    cin >> n >> p;

    vector<vector<int>> d(n + 1, vector<int>(n + 1));
    d[0][0] = 1;
    for (int i = 0; i < n+1; i++) {
        for (int j = n; j >= 0; j--) {
            if (i < j)
                d[i][j] = 0;
            else if (i == j)
                d[i][j] = 1;
            else
                d[i][j] = d[i - j][j] + d[i][j + 1];
        }
    }

    if (p >= d[n][0]) {
        cout << "N/A";
        return 0;
    }

    int last = 0;
    int sum = 0;
    vector<int> answer;
    int id = n;
    while (true) {
        if (sum == n) {
            break;
        }

        for (int i = 1; i < n + 1; i++) {
            if (i < last)
                continue;

            if (sum + i == n) {
                last = i;
                sum = sum + i;
                answer.push_back(i);
                break;
            }

            if (p < d[id - i][i]) {
                last = i;
                sum = sum + i;
                id -= i;
                answer.push_back(i);
                break;
            }

            if (p >= d[id - i][i]) {
                p = max(p - d[id - i][i], 0);
            }
        }

    }
    cout << answer.size() << "\n";
    for (int i : answer) {
        cout << i << " ";
    }

    return 0;
}