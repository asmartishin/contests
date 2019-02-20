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

    size_t q;

    cin >> q;

    for (size_t i = 0; i < q; ++i) {
        long long n, a, b;
        cin >> n >> a >> b;

        if (b <= 2 * a) {
            cout << (n / 2) * b + (n % 2) * a << endl;
        } else {
            cout << n * a << endl;
        }
    }

    return 0;
}
