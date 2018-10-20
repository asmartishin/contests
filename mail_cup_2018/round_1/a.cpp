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

    long long x, y, z, t1, t2, t3;

    cin >> x >> y >> z >> t1 >> t2 >> t3;

    auto elevatorTime = abs(x - z) * t2 + abs(x - y) * t2 + t3 * 3;
    auto walkTime = abs(x - y) * t1;

    if (elevatorTime <= walkTime) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
