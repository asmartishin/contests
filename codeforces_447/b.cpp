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

long long binpow(long long n, long long p) {
    long long result = 1;
    long long abs_p = abs(p);

    while (abs_p) {
        if (abs_p % 2 == 1) {
            result *= n;
            result %= 1000000007;
        }
        n *= n;
        n %= 1000000007;
        abs_p >>= 1;
    }

    return p > 0 ? result: 1 / result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long n, m;
    int k;

    cin >> n >> m >> k;

    cout << binpow(binpow(2, (n - 1)), m - 1) << endl;

    return 0;
}
