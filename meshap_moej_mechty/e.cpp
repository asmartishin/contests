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

static const long long MOD = 998244353;

long long mulmod(long long a, long long b, long long mod) {
    long long result = 0;
    a %= mod;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result + a) % mod;
	}

        a = (a * 2) % mod;

        b /= 2;
    }

    return result % mod;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long n;

    cin >> n;

    vector<long long> a(n);
    vector<long long> b(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = a[i] * (n - i) * (i + 1);
    }

    for (size_t i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(begin(a), end(a));
    sort(begin(b), end(b));

    long long result = 0;

    for (size_t i = 0; i < n; ++i) {
        result += mulmod(a[i], b[n - i - 1], MOD);
        result %= MOD;
    }

    cout << result << endl;

    return 0;
}
