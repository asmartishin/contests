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

size_t getPowIdx(int number, const vector<int>& powersOfTwo) {
    size_t i = 1;
    while (number % powersOfTwo[i] == 0) {
        ++i;
    }
    return i - 1;
}

void solve(vector<int>& result, int n, int k) {
    if (n == 1) {
        result.insert(result.end(), {k});
        return;
    } else if (n == 2) {
        result.insert(result.end(), {k, 2 * k});
        return;
    } else if (n == 3) {
        result.insert(result.end(), {k, k, 3 * k});
        return;
    }

    for (size_t i = 0; i < n / 2 + n % 2; ++i) {
        result.push_back(k);
    }

    solve(result, n / 2, k * 2);
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;

    vector<int> result;
    solve(result, n, 1);

//    vector<int> powersOfTwo{1};
//    vector<int> powersOfTwoCount(20, 0);
//
//    for (size_t i = 1; i < 20; ++i) {
//        powersOfTwo.push_back(powersOfTwo[i - 1] * 2);
//    }
//
//    for (size_t i = 1; i <= n; ++i) {
//        ++powersOfTwoCount[getPowIdx(i, powersOfTwo);
//    }

    for (auto v: result) {
        cout << v << ' ';
    }

    cout << endl;

    return 0;
}
