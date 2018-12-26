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

static int mod = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    string s;
    cin >> s;

    int a = 1, ab = 1;

    for (const auto& c : s) {
        switch (c) {
            case 'a':
                a += ab;
                if (a > mod) {
                    a -= mod;
                }
                break;
            case 'b':
                ab = a;
                break;
        }
    }

    a -= 1;

    cout << a << endl;

    return 0;
}
