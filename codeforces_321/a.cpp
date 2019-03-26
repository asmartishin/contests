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

    int maxLength = numeric_limits<int>::min();
    int currentLength = 0;
    int previousElement = numeric_limits<int>::min();

    for (size_t i = 0; i < n; ++i) {
        cin >> a;
        if (a >= previousElement) {
            ++currentLength;
        } else {
            currentLength = 1;
        }
        maxLength = max(maxLength, currentLength);
        previousElement = a;
    }

    cout << maxLength << endl;

    return 0;
}
