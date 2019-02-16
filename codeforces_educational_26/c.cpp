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

#define X first
#define Y second


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, a, b, x, y;
    cin >> n >> a >> b;

    int result = 0;

    vector<pair<int, int>> stamps;

    for (size_t i = 0; i < n; ++i) {
        cin >> x >> y;
        stamps.emplace_back(x, y);
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }

            const auto& firstStamp = stamps[i];
            const auto& secondStamp = stamps[j];

            vector<pair<int, int>> possibleSquares{
                {firstStamp.Y + secondStamp.X, max(firstStamp.X, secondStamp.Y)},
                {firstStamp.Y + secondStamp.Y, max(firstStamp.X, secondStamp.X)},
                {max(firstStamp.Y, secondStamp.Y), firstStamp.X + secondStamp.X},
                {max(firstStamp.Y, secondStamp.X), firstStamp.X + secondStamp.Y},
                {firstStamp.X + secondStamp.X, max(firstStamp.Y, secondStamp.Y)},
                {firstStamp.X + secondStamp.Y, max(firstStamp.Y, secondStamp.X)},
                {max(firstStamp.X, secondStamp.Y), firstStamp.Y + secondStamp.X},
                {max(firstStamp.X, secondStamp.X), firstStamp.Y + secondStamp.Y},
            };

            for (const auto& sq: possibleSquares) {
                if ((sq.first <= a && sq.second <= b) || (sq.first <= b && sq.second <= a)) {
                    result = max(result, firstStamp.X * firstStamp.Y + secondStamp.X * secondStamp.Y);
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}
