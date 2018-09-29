#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>
#include <array>

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    size_t n, s;
    cin >> n;
    array<int, 100> numbersCount = {};
    vector<int> numbers;

    for (size_t i = 0; i < n; ++i) {
        cin >> s;
        ++numbersCount[--s];
        numbers.push_back(s);
    }

    size_t onesCount = 0, multipleCount = 0;

    for (const auto& i: numbersCount) {
        if (i == 1) {
            ++onesCount;
        } else if (i > 2) {
            ++multipleCount;
        }
    }

    int limitFirst;
    limitFirst = onesCount / 2;

    if (onesCount % 2 == 0) {
        cout << "YES" << endl;
        for (auto i: numbers) {
            if (numbersCount[i] == 1) {
                if (limitFirst > 0) {
                    cout << 'A';
                    --limitFirst;
                } else {
                    cout << 'B';
                }
            } else {
                cout << 'A';
            }
        }
    } else {
        if (multipleCount > 0) {
            cout << "YES" << endl;

            ++limitFirst;
            bool addMultiple = true;

            for (auto i: numbers) {
                if (numbersCount[i] == 1) {
                    if (limitFirst > 0) {
                        --limitFirst;
                        cout << 'A';
                    } else {
                        cout << 'B';
                    }
                } else if (numbersCount[i] > 2 && addMultiple) {
                    cout << 'B';
                    addMultiple = false;
                } else {
                    cout << 'A';
                }
            }
        } else {
            cout << "NO";
        }
    }

    cout << endl;

    return 0;
}
