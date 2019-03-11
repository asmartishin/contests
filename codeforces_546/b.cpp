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

    int n, k;
    cin >> n >> k;
    --k;

    int sum = 0;

    for (size_t i = 0; i < n; ++i) {
        if (i == 0) {
            sum += 2;
        } else if (i == 1) {
            sum += 4;
        } else {
            sum += 3;
        }
    }

    int lpart = k;
    int rpart = n - k - 1;

    cout << sum + min(lpart, rpart) << endl;

    return 0;
}
