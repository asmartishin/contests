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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int a, b;
    cin >> a >> b;

    int l = 0;
    int r = 1e9;
    long long abSize;

    while (l < r) {
        abSize = (l + r) / 2;
        long long sum = abSize * (abSize + 1) / 2;

        if (sum == a + b) {
            break;
        } else if (sum < a + b) {
            l = abSize + 1;
        } else {
            r = abSize;
        }
    }

    if (abSize * (abSize + 1) / 2 >  a + b) {
        --abSize;
    }

    int aTakenFromB = -1;
    int aPutToB = -1;

    size_t aSize = 0;
    int atmp = a;

    if (a > 0) {
        for (int i = abSize; i >= 1; --i) {
            ++aSize;
            if (i < atmp) {
                atmp -= i;
            } else if (i == atmp) {
                break;
            } else {
                aTakenFromB = atmp;
                aPutToB = i;
                break;
            }
        }
    }

    size_t bSize = abSize - aSize;

    cout << aSize << endl;

    for (int i = abSize; i >= 1; --i) {
        if (i < a) {
            cout << i << ' ';
            a -= i;
        } else if (i == a) {
            cout << i << ' ';
            break;
        } else {
            if (aTakenFromB != -1) {
                cout << aTakenFromB << ' ';
            }
            break;
        }
    }

    cout << endl;

    cout << bSize << endl;

    for (int i = 1; i <= bSize; ++i) {
        if (i != aTakenFromB) {
            cout << i << ' ';
        }
    }

    if (aPutToB != -1) {
        cout << aPutToB << ' ';
    }

    cout << endl;

    return 0;
}
