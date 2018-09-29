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

    long long r, l;
    cin >> r >> l;

    cout << "YES" << endl;

    for (long long i = r; i <= l; i += 2) {
        cout << i << ' ' << i + 1 << endl;
    }

    return 0;
}
