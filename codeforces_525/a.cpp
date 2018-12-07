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

    int x;
    cin >> x;

    for (size_t i = 1; i <= x; ++i) {
        for (size_t j = 1; j <= i; ++j) {
            if (i % j == 0 && i * j > x && i / j < x) {
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
