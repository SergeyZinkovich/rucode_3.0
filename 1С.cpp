#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <map>
#include <climits>

using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n;
    map<string, long long> person_money;
    map<string, long long> city_money;
    map<string, string> person_city;
    set<pair<long long, string>> cities;

    for (int i = 0; i < n; i++) {
        string name, city;
        long long money;
        cin >> name >> city >> money;

        person_money[name] = money;
        person_city[name] = city;
        if (city_money.find(city) != city_money.end()) {
            cities.erase({city_money[city], city});
            city_money[city] += money;
            cities.insert({city_money[city], city});
        } else {
            city_money[city] = money;
            cities.insert({city_money[city], city});
        }
    }

    cin >> m >> k;

    int day = 0;
    map<string, int> city_days;

    for (int i = 0; i < k; i++) {
        int new_day;
        string person, city;
        cin >> new_day >> person >> city;
        if (cities.size() == 1 || prev(cities.end())->first > prev(cities.end(), 2)->first) {
            if (city_days.find(prev(cities.end())->second) != city_days.end())
                city_days[prev(cities.end())->second] += new_day - day;
            else
                city_days[prev(cities.end())->second] = new_day - day;
        }
        day = new_day;

        string old_city = person_city[person];
        person_city[person] = city;
        cities.erase({city_money[city], city});
        cities.erase({city_money[old_city], old_city});
        city_money[city] += person_money[person];
        city_money[old_city] -= person_money[person];
        cities.insert({city_money[city], city});
        cities.insert({city_money[old_city], old_city});
    }
    if (cities.size() == 1 || prev(cities.end())->first > prev(cities.end(), 2)->first) {
        city_days[prev(cities.end())->second] += m - day;
    }

    for (const auto &c : city_days) {
        if (c.second > 0)
            cout << c.first << " " << c.second << '\n';
    }

    return 0;
}