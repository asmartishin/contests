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

int Sum(int n) {
    if (n <= 9) {
        return n;
    }

    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }

    return Sum(sum);
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    size_t n;
    long long k;
    int x;

    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        cin >> k >> x;
        cout << 9 * (k - 1) + x << endl;
    }

//    for (size_t i = 1; i < 1000; ++i) {
//        cout << i << ' ' << Sum(i) << endl;
//    }

    return 0;
}
