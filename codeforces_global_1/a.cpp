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

    int b, k, a;
    cin >> b >> k;

    bool prevEven = true;
    bool curEven;

    for (size_t i = 0; i < k - 1; ++i) {
        cin >> a;
        if (a % 2 == 0) {
            curEven = true;
        } else {
            if (b % 2 == 0) {
                curEven = true;
            } else {
                curEven = false;
            }
        }
        if (prevEven) {
            prevEven = curEven ? true : false;
        } else {
            prevEven = curEven ? false : true;
        }
    }

    cin >> a;
    if (a % 2 == 0) {
        curEven = true;
    } else {
        curEven = false;
    }

    if (prevEven) {
        prevEven = curEven ? true : false;
    } else {
        prevEven = curEven ? false : true;
    }

    if (prevEven) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }

    return 0;
}
