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

    int k;
    for (size_t i = 0; i < 30; ++i) {
        if (2 * pow(2, i) - 1 <= n) {
            k = i;
        }
    }

    if (n > 2 * pow(2, k) - 1) {
        ++k;
    }

    cout << k + 1  << endl;

    return 0;
}
