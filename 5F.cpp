#include <iostream>
#include <vector>

using namespace std;

long long zerg = 0;
int pointer;
const long long p = 1e6 + 3;

vector<int> parent(p);
vector<long long> c(p);
vector<long long> readed(p);

void make_set(long long v) {
    parent[v] = v;
}

pair<long long, long long> find_set(long long x) {
    if (x == parent[x]) {
        return {x, 0};
    }

    auto z = find_set(parent[x]);
    parent[x] = z.first;
    c[x] += z.second;

    return {z.first, c[x]};
}

bool unite(long long a, long long b) {
    a = find_set(a).first;
    b = find_set(b).first;

    if (a == b)
        return false;

    make_set(pointer);
    parent[a] = pointer;
    parent[b] = pointer;
    pointer++;

    return true;
}

void add(long long x) {
    x = find_set(x).first;
    c[x]++;
}

long long count(long long x) {
    long long st = x;
    x = find_set(x).first;
    long long res = c[x] + (st != x ? c[st] : 0);

    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    pointer = n + 1;

    for (int h = 0; h < m; h++) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            cin >> i;

            add((i + zerg) % n);
            zerg = (30 * zerg + 239) % p;
        } else if (t == 2) {
            int i, j;
            cin >> i >> j;

            if (unite((i + zerg) % n, (j + zerg) % n))
                zerg = (13 * zerg + 11) % p;
        } else if (t == 3){
            int i;
            cin >> i;

            long long value = count((i + zerg) % n);
            long long r = readed[(i + zerg) % n];
            readed[(i + zerg) % n] = value;
            value -= r;
            cout << value << "\n";
            zerg = (100500 * zerg + value) % p;
        }
    }

    return 0;
}