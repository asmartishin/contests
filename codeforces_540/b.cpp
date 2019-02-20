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

struct Sums {
    long long prefixEven = 0;
    long long prefixOdd = 0;
    long long suffixEven = 0;
    long long suffixOdd = 0;
};

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;

    vector<Sums> sums(n);
    vector<int> a(n);
    long long currentEvenSum = 0;
    long long currentOddSum = 0;

    for (size_t i = 0; i < n; ++i) {
        sums[i].prefixEven = currentEvenSum;
        sums[i].prefixOdd = currentOddSum;

        cin >> a[i];
        if (i % 2 == 0) {
            currentOddSum += a[i];
        } else {
            currentEvenSum += a[i];
        }
    }

    currentEvenSum = 0;
    currentOddSum = 0;

    for (int i = n - 1; i >= 0; --i) {
        sums[i].suffixEven = currentEvenSum;
        sums[i].suffixOdd = currentOddSum;

        if (i % 2 == 0) {
            currentOddSum += a[i];
        } else {
            currentEvenSum += a[i];
        }
    }

    long long result = 0;

    for (size_t i = 0; i < n; ++i) {
        if (sums[i].prefixEven + sums[i].suffixOdd == sums[i].prefixOdd + sums[i].suffixEven) {
            ++result;
        }
    }

    cout << result << endl;

//    for (const auto& v : sums) {
//        cout << v.prefixEven << ' ' << v.prefixOdd << ' ' << v.suffixEven << ' ' << v.suffixOdd << endl;
//    }

    return 0;
}
