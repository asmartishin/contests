#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>
#include <array>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long n, m;
    cin >> n >> m;

    long long minVertices = max(0ll, n - m * 2);

    long long takenVertices = 0;

    while (takenVertices * (takenVertices - 1) / 2 < m && takenVertices < n) {
        ++takenVertices;
    }

    cout << minVertices << ' ' << n - takenVertices << endl;

    return 0;
}
