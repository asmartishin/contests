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
    size_t n, swaps = 0;
    string a, b;

    cin >> n >> a >> b;

    for (size_t i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            if (i < n - 1 && a[i] == b[i + 1] && a[i + 1] == b[i]) {
                ++i;
            }

            ++swaps;
        }
    }

    cout << swaps << endl;

    return 0;
}
