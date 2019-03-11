#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, l, r;
    cin >> n;

    vector<int> pages(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> l >> r;
        pages[i] = r;
    }

    int k;
    cin >> k;
    int c = 0;

    for (size_t i = 0; i < n; ++i) {
        if (pages[i] >= k) {
            break;
        }
        ++c;
    }

    cout << n - c << endl;

    return 0;
}
