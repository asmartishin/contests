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
    int pa = 0, pb = 0, a, b;
    long long result = 1;

    for (size_t i = 0; i < n; ++i) {
        cin >> a >> b;
        auto cur = min(a, b);
        auto pre = max(pa, pb);

        if (cur >= pre) {
            if (cur > pre) {
                result += cur - pre;
            }

            if (pa != pb) {
                result += 1;
            }
        }

        pa = a;
        pb = b;
    }

    cout << result << endl;

    return 0;
}
