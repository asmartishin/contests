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

    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;

    int ta, fa, tb, fb;

    for (size_t i = 0; i < k; ++i) {
        cin >> ta >> fa >> tb >> fb;

        if (ta == tb) {
            cout << abs(fa - fb) << endl;
            continue;
        }

        int usedFloor;
        int result = 0;

        if (fa > b) {
            result += fa - b;
            usedFloor = b;
        } else if (fa < a) {
            result += a - fa;
            usedFloor = a;
        } else {
            usedFloor = fa;
        }

        result += abs(ta - tb);

        result += abs(usedFloor - fb);

        cout << result << endl;
    }

    return 0;
}
