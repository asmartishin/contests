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
#include <deque>

using namespace std;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;

    deque<int> a(n);

    string result;

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (size_t i = 1; i <= n; ++i) {
        if (!a.empty()) {
            if (a.front() == i) {
                result += 'L';
                a.pop_front();
            } else if (a.back() == i) {
                result += 'R';
                a.pop_back();
            }
        }
    }

    cout << result.size() << endl << result << endl;

    return 0;
}
