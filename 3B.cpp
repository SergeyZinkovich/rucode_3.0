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

    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    double v1x = xa - xb;
    double v1y = ya - yb;
    double v2x = xc - xb;
    double v2y = yc - yb;

    double scal1 = v1x * v2x + v1y * v2y;

    double v3x = xa - xc;
    double v3y = ya - yc;
    double v4x = xb - xc;
    double v4y = yb - yc;

    double scal2 = v3x * v4x + v3y * v4y;

    if (scal1 >= 0 && scal2 >= 0) {
        double A = yb - yc;
        double B = xc - xb;
        double C = xb*yc - xc*yb;
        cout << abs(A*xa + B*ya + C) / sqrt(pow(A, 2) + pow(B, 2));
    } else {
        cout << min(sqrt(v1x*v1x + v1y*v1y), sqrt(v3x*v3x + v3y*v3y));
    }

    return 0;
}