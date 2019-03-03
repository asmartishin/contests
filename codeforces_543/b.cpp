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

int countPairs(const unordered_set<int>& nums, int sum) {
    int result = 0;

    for (auto n: nums) {
        if (nums.find(sum - n) != nums.end()) {
            ++result;
        }
    }

    return result / 2;
}

unordered_map<int, int> allSums(const vector<int>& nums) {
    unordered_map<int, int> result;

    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            ++result[nums[i] + nums[j]];
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;

    vector<int> candy(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> candy[i];
    }

    auto sums = allSums(candy);

    int result = numeric_limits<int>::min();

    for (const auto& [sum, c]: sums) {
        result = max(result, c);
    }

    cout << result << endl;

    return 0;
}
