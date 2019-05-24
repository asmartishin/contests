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

using namespace std;

#define endl '\n'


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    string s;

    cin >> n >> s;

    int result = 0;
    string resultString;
    resultString += s.front();

    for (size_t i = 1; i < n; ++i) {
        if (resultString.size() % 2 == 0) {
            resultString += s[i];
        } else {
            if (resultString.back() == s[i]) {
                ++result;
            } else {
                resultString += s[i];
            }
        }
    }

    if (resultString.size() % 2 == 1) {
        ++result;
        resultString.pop_back();
    }

    cout << result << endl << resultString << endl;

    return 0;
}
