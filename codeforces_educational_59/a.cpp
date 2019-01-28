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

    size_t q;
    string s;
    int n, firstN, secondN;

    cin >> q;

    for (size_t i = 0; i < q; ++i) {
        cin >> n;
        cin >> s;

        if (n > 2) {
            cout << "YES" << endl << 2 << endl;
            cout << s[0] << ' ';
            for (size_t j = 1; j < n; ++j) {
                cout << s[j];
            }
            cout << endl;
        } else {
            firstN = s[0] - '0';
            secondN = s[1] - '0';

            if (firstN >= secondN) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl << 2 << endl;
                cout << firstN << ' ' << secondN << endl;
            }
        }
    }

    return 0;
}
