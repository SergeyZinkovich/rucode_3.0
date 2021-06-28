//Дейкстра для разреженных графов

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
const int INF = 1000000000;

struct X_{
    int x;
    int y1;
    int y2;
    int id;
    bool l;
};

bool comp(X_ u, X_ v) {
    if (u.x != v.x)
        return u.x < v.x;
    else
        return u.y1 > v.y1;
}

bool comp1(pair<int, int> u, pair<int, int> v) {
    return v.second > u.second;
}

int main() {
    int n;
    cin >> n;

    vector<X_> XS;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y2 < y1) swap(y1, y2);
        if (x2 < x1) swap(x1, x2);

        XS.push_back({x1, y1, y2, i,true});
        XS.push_back({x2, y1, y2, i,false});
    }
    sort(XS.begin(), XS.end(), comp);

    vector<bool> used(1e5);
    set<pair<int, int>, decltype(&comp1)> s(comp1);
    int ans = 1;
    s.insert({XS[0].y1, XS[0].y2});
    used[XS[0].id] = true;

    for (int i = 1; i < 2*n; i++) {
        if (XS[i].l) {
            auto u = s.lower_bound({std::numeric_limits<int>::min(), XS[i].y2});
            if (u == s.end() || u->first > XS[i].y1) {
                ans++;
                used[XS[i].id] = true;
                s.insert({XS[i].y1, XS[i].y2});
            }
        } else {
            if (used[XS[i].id]) {
                s.erase({XS[i].y1, XS[i].y2});
            }
        }
    }

    cout << ans;
}