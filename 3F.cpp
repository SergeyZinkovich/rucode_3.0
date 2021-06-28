#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>

using namespace std;

struct pt{
    double x;
    double y;
};

vector<pt> points;
int n;
double xh, yh;

bool Cross(int j)
{
    int first = j;
    int second = j == n - 1 ? 0 : j + 1;
    double y = (xh - points[first].x) * (points[second].y - points[first].y) / (points[second].x - points[first].x) + points[first].y;
    double minimal = min(points[first].x, points[second].x);
    double maximal = max(points[first].x, points[second].x);
    return (points[first].x != points[second].x) && (yh >= y) && (xh > minimal) && (xh <= maximal);
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

double dist1(int i) {
    int j = i == n - 1 ? 0 : i + 1;

    return dist(xh, yh, points[i].x, points[i].y, points[j].x, points[j].y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    cin >> n >> xh >> yh;


    for (int i = 0; i < n; i++) {
        pt p;
        cin >> p.x >> p.y;

        points.push_back(p);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += Cross(i);

        if (dist1(i) == 0) {
            cout << "YES";

            return 0;
        }
    }

    if (count % 2 == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}