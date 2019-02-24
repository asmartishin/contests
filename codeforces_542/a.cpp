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

    double n;
    int a;
    cin >> n;

    int positiveCount = 0;
    int negativeCount = 0;

    for (size_t i = 0; i < n; ++i) {
        cin >> a;
        if (a > 0) {
            ++positiveCount;
        } else if (a < 0) {
            ++negativeCount;
        }
    }

    if (positiveCount >= ceil(n / 2)) {
        cout << 1 << endl;
    } else if (negativeCount >= ceil(n / 2)) {
        cout << -1 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
