#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>
#include <array>

using namespace std;

#define endl '\n'

class DSU {
public:
    size_t setsCount = 0;

    DSU(const size_t size)
        : parent(size, -1)
        , rank(size, -1)
    {}

    bool make_set(int element) {
        if (parent[element] > -1) {
            return false;
        }
        ++setsCount;
        parent[element] = element;
        rank[element] = 0;
        return true;
    }

    int find_set(int x) {
        if (x != parent[x]) {
            parent[x] = find_set(parent[x]);
        }
        return parent[x];
    }

    bool union_sets(int x, int y) {
        int xp = find_set(x);
        int yp = find_set(y);

        if (xp == yp) {
            return false;
        }
        --setsCount;

        if (rank[xp] < rank[yp]) {
            parent[xp] = yp;
        } else if (rank[xp] > rank[yp]) {
            parent[yp] = xp;
        } else {
            parent[yp] = xp;
            ++rank[xp];
        }

        return true;
    }

    void print() {
        for (size_t i = 0; i < parent.size(); ++i) {
            cout << i << ' ' << parent[i] << endl;
        }
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class TUnionSet {
public:

    TUnionSet(const size_t size)
        : Parent(size, -1)
        , Rank(size, -1)
    {}

    bool MakeSet(const int element) {
        if (Parent[element] > -1) {
            return false;
        }
        ++SetsCount;
        Parent[element] = element;
        Rank[element] = 0;
        return true;
    }

    int Find(int element) {
        while (element != Parent[element])
            element = Parent[element];
        return element;
    }

    void Union(const int firstElement, const int secondElement) {
        auto firstElementParent = Find(firstElement);
        auto secondElementParent = Find(secondElement);

        if (firstElementParent == secondElementParent) {
            return;
        } else {
            if (Rank[firstElementParent] > Rank[secondElementParent])
                Parent[secondElementParent] = firstElementParent;
            else {
                Parent[firstElementParent] = secondElementParent;
                if (Rank[firstElementParent] == Rank[secondElementParent])
                    ++Rank[secondElementParent];
            }
            --SetsCount;
        }
    }

    void Print() {
        for (size_t i = 0; i < Parent.size(); ++i) {
            cout << i << ' ' << Parent[i] << endl;
        }
    }

    size_t SetsCount = 0;
private:
    vector<int> Parent;
    vector<int> Rank;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, m, p, t;
    long long l, d;

    cin >> n >> m >> l;

    vector<long long> hairs(n);
    DSU unionSet(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> hairs[i];
    }

    for (size_t i = 0; i < n; ++i) {
        if (hairs[i] > l) {
            unionSet.make_set(i);

            if (i > 0 && hairs[i - 1] > l) {
                unionSet.union_sets(i - 1, i);
            }
        }
    }

    for (size_t i = 0; i < m; ++i) {
        cin >> t;

        if (t == 0) {
            cout << unionSet.setsCount << endl;
        } else {
            cin >> p >> d;
            --p;
            hairs[p] += d;

            if (hairs[p] > l) {
                unionSet.make_set(p);
                if (p > 0 && hairs[p - 1] > l) {
                    unionSet.union_sets(p - 1, p);
                }

                if (p < n - 1 && hairs[p + 1] > l) {
                    unionSet.union_sets(p, p + 1);
                }
            }
        }
    }

    return 0;
}
