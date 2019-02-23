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

    int w1, h1, w2, h2;

    cin >> w1 >> h1 >> w2 >> h2;

    long long firstArea = (h1 + 2) * (w1 + 2) - h1 * w1 - w2;
    --h2;
    long long secondArea = (h2 + 2) * (w2 + 2) - h2 * w2 - (w2 + 2);

    cout << firstArea + secondArea << endl;

    return 0;
}
