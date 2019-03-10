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

    vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << n + 1 << endl;

    for (int i = n - 1; i >= 0; --i) {
        int diff = 100000 + i - a[i];
        cout << "1 " << i + 1 << " " << diff << endl;
        for (size_t j = 0; j < i; ++j) {
            a[j] += diff;
            a[j] %= 100000;
        }
    }

    cout << "2 " << n << " 100000" << endl;

    return 0;
}
