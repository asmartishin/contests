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

    if (n <= 2) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;

        int k = (n % 2 == 0) ? n / 2 : (n + 1) / 2;
        cout << 1 << ' ' << k << endl;

        cout << n - 1 << ' ';
        for (size_t i = 1; i <= n; ++i) {
            if (i != k) {
                cout << i << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
