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

double sq (const vector<pt> & fig)
{
    double res = 0;
    for (unsigned i=0; i<fig.size(); i++)
    {
        pt p1 = i ? fig[i-1] : fig.back();
        pt p2 = fig[i];
        res += (p1.x - p2.x) * (p1.y + p2.y);
    }
    return fabs (res) / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(20);

    int n;
    cin >> n;
    vector<pt> points;

    for (int i = 0; i < n; i++) {
        pt p;
        cin >> p.x >> p.y;

        points.push_back(p);
    }

    cout << sq(points);

    return 0;
}