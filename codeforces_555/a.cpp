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

void func(int& n) {
    n += 1;

    while (n % 10 == 0) {
        n /= 10;
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;

    unordered_set<int> nums{n};

    for (size_t i = 0; i < 1e6; ++i) {
        func(n);
        nums.insert(n);
    }

    cout << nums.size() << endl;

    return 0;
}
