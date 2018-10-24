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

long long mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long n, m, k, l;

    cin >> n >> m >> k >> l;

    auto possibleCoins = n - k;

    long long giftCoins = ceil(l / (double)m);

    giftCoins %= mod;
    m %= mod;
    possibleCoins %= mod;

    if (giftCoins * m > possibleCoins) {
        cout << -1 << endl;
        return 0;
    }

    cout << giftCoins << endl;

    return 0;
}
