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
#include <deque>

using namespace std;

#define endl '\n'


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, a;
    cin >> n;

    map<int, int> c;

    cin >> a;
    int prevNumber = a;
    int prevNumberCount = 1;

    for (size_t i = 0; i < n - 1; ++i) {
        cin >> a;
        if (prevNumber == a) {
            ++prevNumberCount;
        } else {
            c[prevNumber] = max(c[prevNumber], prevNumberCount);
            prevNumber = a;
            prevNumberCount = 1;
        }
    }

    c[prevNumber] = max(c[prevNumber], prevNumberCount);

    auto bk = *c.rbegin();
    cout << bk.second << endl;

    return 0;
}
