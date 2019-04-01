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

    int n, a;
    cin >> n;
    vector<int> oddNumbers;
    vector<int> evenNumbers;

    for (size_t i = 0; i < n; ++i) {
        cin >> a;

        if (a % 2 == 0) {
            evenNumbers.push_back(a);
        } else {
            oddNumbers.push_back(a);
        }
    }

    int result = 0;

    sort(begin(evenNumbers), end(evenNumbers));
    sort(begin(oddNumbers), end(oddNumbers));

    if (evenNumbers.size() > oddNumbers.size() + 1) {
        for (size_t i = 0; i < evenNumbers.size() - oddNumbers.size() - 1; ++i) {
            result += evenNumbers[i];
        }
    } else if (oddNumbers.size() > evenNumbers.size() + 1) {
        for (size_t i = 0; i < oddNumbers.size() - evenNumbers.size() - 1; ++i) {
            result += oddNumbers[i];
        }
    }

    cout << result << endl;

    return 0;
}
