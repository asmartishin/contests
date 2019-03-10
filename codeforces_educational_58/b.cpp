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

    string s;
    cin >> s;
    size_t deleted = 0;

    vector<size_t> openIdx;
    vector<size_t> closeIdx;
    vector<size_t> colonIdx;

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '[') {
            openIdx.push_back(i);
        } else if (s[i] == ']') {
            closeIdx.push_back(i);
        } else if (s[i] == ':') {
            colonIdx.push_back(i);
        }
    }

    if (openIdx.empty() || closeIdx.empty()) {
        cout << -1 << endl;
        return 0;
    }

    auto firstOpenIdx = openIdx.front();
    auto lastCloseIdx = closeIdx.back();
    auto closestToOpenColon = lower_bound(colonIdx.begin(), colonIdx.end(), firstOpenIdx);
    auto closestToCloseColon = upper_bound(colonIdx.begin(), colonIdx.end(), lastCloseIdx);

    if (closestToCloseColon == colonIdx.begin() || closestToOpenColon == colonIdx.end()) {
        cout << -1 << endl;
        return 0;
    }

    auto closestToOpenColonIdx = *closestToOpenColon;
    auto closestToCloseColonIdx = *(closestToCloseColon - 1);

    if (
        firstOpenIdx < lastCloseIdx
        && closestToOpenColonIdx < closestToCloseColonIdx
    ) {
        deleted = s.size() - 4;

        for (size_t i = 0; i < s.size(); ++i) {
            if (i > closestToOpenColonIdx && i < closestToCloseColonIdx && s[i] == '|') {
                --deleted;
            }
        }
    } else {
        cout << -1 << endl;
        return 0;
    }

    cout << s.size() - deleted << endl;

//    cout << firstOpenIdx << ' ' << lastCloseIdx << ' ' << closestToOpenColonIdx << ' ' << closestToCloseColonIdx << endl;

    return 0;
}
