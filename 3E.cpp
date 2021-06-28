#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    int n;
    cin >> n;

    bool neg = false, pos = false;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int first1_x = x1, first1_y = y1;
    int first2_x = x2, first2_y = y2;

    for (int i = 2; i < n; i++) {
        int x, y;
        cin >> x >> y;

        int vec = (x2-x1)*(y-y2) - (y2-y1)*(x-x2);
        if (vec < 0) {
            neg = true;
        } else if (vec > 0) {
            pos = true;
        }

        x1 = x2;
        y1 = y2;
        x2 = x;
        y2 = y;
    }

    int x = first1_x, y = first1_y;

    int vec = (x2-x1)*(y-y2) - (y2-y1)*(x-x2);
    if (vec < 0) {
        neg = true;
    } else if (vec > 0) {
        pos = true;
    }

    x1 = x2;
    y1 = y2;
    x2 = x;
    y2 = y;

    x = first2_x; y = first2_y;

    vec = (x2-x1)*(y-y2) - (y2-y1)*(x-x2);
    if (vec < 0) {
        neg = true;
    } else if (vec > 0) {
        pos = true;
    }

    if (neg && pos) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}