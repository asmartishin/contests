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

    int n;
    cin >> n;

    vector<int> contests(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> contests[i];
    }

    sort(begin(contests), end(contests));

    int day = 0;

    for (size_t i = 0; i < n; ++i) {
        while (i < n - 1 && contests[i] < day + 1) {
            ++i;
        }

        if (contests[i] >= day + 1) {
            ++day;
        }
    }

    cout << day << endl;

    return 0;
}
