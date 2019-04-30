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

    int n, f;
    string numString;
    cin >> n;

    vector<int> nums(n);
    cin.ignore(1);
    unordered_map<int, int> numToNum;

    getline(cin, numString);

    for (size_t i = 0; i < n; ++i) {
        nums[i] = numString[i] - '0';
    }

    for (size_t i = 1; i <= 9; ++i) {
        cin >> f;
        numToNum[i] = f;
    }

    bool startSubarray = false;

    for (size_t i = 0; i < n; ++i) {
        int& num = nums[i];

        if (!startSubarray) {
             if (numToNum[num] > num) {
                startSubarray = true;
                num = numToNum[num];
             }
        } else {
            if (numToNum[num] >= num) {
                num = numToNum[num];
            } else {
                break;
            }
        }
    }

    for (const auto v : nums) {
        cout << v;
    }
    cout << endl;

    return 0;
}
