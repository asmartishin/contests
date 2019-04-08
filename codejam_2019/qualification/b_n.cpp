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

    int T, N;
    string P;

    cin >> T;

    for (size_t t = 0; t < T; ++t) {
        cin >> N >> P;
        string result;

        for (size_t i = 0; i < 2 * N - 2; ++i) {
            if (P[i] == 'S') {
                result += 'E';
            } else {
                result += 'S';
            }
        }

        cout << "Case #" << t + 1 << ": " << result << endl;
    }


    return 0;
}
