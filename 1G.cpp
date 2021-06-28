#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool cmp_less(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

bool cmp_1_greater_2_less(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
}

int main() {
    long long int n, m;
    cin >> n >> m;

    set<pair<int, int>, decltype(&cmp_1_greater_2_less)> len_pos(cmp_1_greater_2_less);
    set<pair<int, int>, decltype(&cmp_less)> pos_len(cmp_less);
    len_pos.insert({n, 1});
    pos_len.insert({1, n});
    vector<pair<int, int>> hist;
    for (long long i = 0; i < m; i++) {
        int k;
        cin >> k;

        if (k > 0) {
            if (len_pos.empty() || len_pos.begin()->first < k) {
                cout << -1 << '\n';
                hist.emplace_back(-1, -1);
            } else {
                auto segment = *len_pos.begin();
                len_pos.erase(len_pos.begin());
                auto iter = pos_len.lower_bound({segment.second, segment.first});
                pos_len.erase(iter);
                if (segment.first != k) {
                    len_pos.insert({segment.first - k, segment.second + k});
                    pos_len.insert({segment.second + k, segment.first - k});
                }
                cout << segment.second << '\n';
                hist.emplace_back(k, segment.second);
            }
        } else {
            k = -k - 1;

            if (hist[k].first > 0) {
                auto segment = hist[k];
                pos_len.insert({segment.second, segment.first});
                len_pos.insert(segment);
                auto it = pos_len.lower_bound({hist[k].second, 0});
                auto r = next(it);
                auto l = prev(it);
                if (l != pos_len.end() && l->first + l->second == it->first) {
                    len_pos.erase({it->second, it->first});
                    len_pos.erase({l->second, l->first});

                    segment.first = l->second + it->second;
                    segment.second = l->first;

                    pos_len.erase(l);
                    pos_len.erase(it);

                    pos_len.insert({segment.second, segment.first});
                    len_pos.insert(segment);
                }

                it = pos_len.lower_bound({segment.second, segment.first});

                if (r != pos_len.end() && it->first + it->second == r->first) {
                    len_pos.erase({it->second, it->first});
                    len_pos.erase({r->second, r->first});

                    segment.first = r->second + it->second;

                    pos_len.erase(r);
                    pos_len.erase(it);

                    pos_len.insert({segment.second, segment.first});
                    len_pos.insert(segment);
                }
            }
            hist.emplace_back(-2, -2);
        }
    }

    return 0;
}