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

    vector<int> values(4);

    for (size_t i = 0; i < 4; ++i) {
        cin >> values[i];
    }

    sort(begin(values), end(values));

    int c = values[3] - values[0];
    int a = values[2] - c;
    int b = values[1] - c;

    cout << a << ' ' << b << ' ' << c << endl;

    return 0;
}
