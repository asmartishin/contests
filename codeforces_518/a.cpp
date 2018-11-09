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

    long long allCoinsCount, friendsCount, currentCoinsCount, newCoinsCount;

    cin >> allCoinsCount >> friendsCount >> currentCoinsCount >> newCoinsCount;

    long long giftCoins = ceil((newCoinsCount + currentCoinsCount) / (double)friendsCount);

    if (giftCoins * friendsCount > allCoinsCount) {
        cout << -1 << endl;
        return 0;
    }

    cout << giftCoins << endl;

    return 0;
}
