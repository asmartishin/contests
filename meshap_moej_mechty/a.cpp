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

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, x, y;
    string num;
    cin >> n >> x >> y >> num;

    int result = 0;

    for (size_t i = n - x; i < n; ++i) {
        if (i != n - y - 1 && num[i] == '1') {
            ++result;
        } else if (i == n - y - 1 && num[i] == '0') {
            ++result;
        }
    }

    cout << result << endl;

    return 0;
}
