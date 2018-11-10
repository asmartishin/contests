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
    TUnionSet unionSet(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> hairs[i];
    }

    for (size_t i = 0; i < n; ++i) {
        if (hairs[i] > l) {
            unionSet.MakeSet(i);

            if (i > 0 && hairs[i - 1] > l) {
                unionSet.Union(i - 1, i);
            }
        }
    }

    for (size_t i = 0; i < m; ++i) {
        cin >> t;

        if (t == 0) {
            cout << unionSet.SetsCount << endl;
        } else {
            cin >> p >> d;
            --p;
            hairs[p] += d;

            if (hairs[p] > l) {
                unionSet.MakeSet(p);
                if (p > 0 && hairs[p - 1] > l) {
                    unionSet.Union(p - 1, p);
                }

                if (p < n - 1 && hairs[p + 1] > l) {
                    unionSet.Union(p, p + 1);
                }
            }
        }
    }

    return 0;
}
