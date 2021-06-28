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
    cout.precision(5);

    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    double v1x = xa - xb;
    double v1y = ya - yb;
    double v2x = xc - xb;
    double v2y = yc - yb;

//    double cos = (v1x * v1y + v2x * v2y) / (sqrt(v1x*v1x + v2x*v2x) + sqrt(v1y*v1y + v2y*v2y));
//    double scal = sqrt(v1x*v1x + v1y*v1y) * sqrt(v2x*v2x + v2y*v2y) * cos;
    double scal = v1x * v2x + v1y * v2y;

    if (scal >= 0) {
        double A = yb - yc;
        double B = xc - xb;
        double C = xb*yc - xc*yb;
        cout << abs(A*xa + B*ya + C) / sqrt(pow(A, 2) + pow(B, 2));
    } else {
        cout << sqrt(v1x*v1x + v1y*v1y);
    }

    return 0;
}