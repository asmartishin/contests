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

    int n;
    cin >> n;

    vector<int> c(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> c[i];
    }

    int result;
    int l = 0;
    int r = n - 1;

    while (c[r] == c[l]) {
        --r;
    }

    result = r;

    r = n - 1;

    while (c[r] == c[l]) {
        ++l;
    }

    result = max(result, r - l);

    cout << result << endl;

    return 0;
}
