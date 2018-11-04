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

    long long n, x, y;
    cin >> n >> x >> y;

    auto cellsBlack = abs(n - x) + abs(n - y);
    auto cellsWhite = abs(x - 1) + abs(y - 1);

    if (cellsBlack < cellsWhite) {
        cout << "Black" << endl;
    } else {
        cout << "White" << endl;
    }

    return 0;
}
