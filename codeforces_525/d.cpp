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

//#define endl '\n'

int ask(int c, int d) {
    int result;
    cout << "? " << c << ' ' << d << endl;
    cin >> result;
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int a = 0, b = 0, bigger = ask(0, 0);

    for (int i = 29; i >= 0; --i) {
        int shift = 1 << i;

        int incA = ask(a ^ shift, b);
        int incB = ask(a, b ^ shift);

        if (incA == incB) {
            if (bigger == 1) {
                a ^= shift;
            } else {
                b ^= shift;
            }

            bigger = incA;
        } else if (incA == -1) {
            a ^= shift;
            b ^= shift;
        }
    }

    cout << "! " << a << ' ' << b << endl;

    return 0;
}
