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

    int n;
    cin >> n;
    int secret, furthestSecret = 1;
    int result = 0;

    for (size_t i = 1; i <= n; ++i) {
        cin >> secret;
        furthestSecret = max(secret, furthestSecret);
        if (i >= furthestSecret) {
            ++result;
        }
    }

    cout << result << endl;

    return 0;
}
