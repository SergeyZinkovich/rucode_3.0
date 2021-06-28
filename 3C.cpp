#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

using namespace std;

struct pt {
    int x, y;
};

double area(double ax, double ay, double bx, double by, double cx, double cy) {
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

bool intersect1(double a, double b, double c, double d) {
    if (a > b)  swap (a, b);
    if (c > d)  swap (c, d);
    return max(a,c) <= min(b,d);
}

bool intersect(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy) {
    return intersect1 (ax, bx, cx, dx) && intersect1 (ay, by, cy, dy)
           && area(ax, ay, bx, by, cx, cy) * area(ax, ay, bx, by, dx, dy) <= 0
           && area(cx, cy, dx, dy, ax, ay) * area(cx, cy, dx, dy, bx, by) <= 0;
}

double dist(double xa, double ya, double xb, double yb, double xc, double yc) {
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
        return abs(A*xa + B*ya + C) / sqrt(pow(A, 2) + pow(B, 2));
    } else {
        return min(sqrt(v1x*v1x + v1y*v1y), sqrt(v3x*v3x + v3y*v3y));
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    double xa, ya, xb, yb, xc, yc, xd, yd;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;

    if (intersect(xa, ya, xb, yb, xc, yc, xd, yd)) {
        cout << 0;
    } else {
        cout << min(min(dist(xa, ya, xc, yc, xd, yd), dist(xb, yb, xc, yc, xd, yd)), min(dist(xc, yc, xa, ya, xb, yb),
                                                                                         dist(xd, yd, xa, ya, xb, yb)));
    }

    return 0;
}