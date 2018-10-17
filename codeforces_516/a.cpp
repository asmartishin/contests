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

    int a, b, c;
    cin >> a >> b >> c;
    int result = 0;

    if (a >= b + c) {
        result = a - (b + c) + 1;
    } else if (b >= a + c) {
        result = b - (a + c) + 1;
    } else if (c >= a + b) {
        result = c - (a + b) + 1;
    }

    cout << result << endl;

    return 0;
}
