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

    int n, m, x, t;

    cin >> n >> m;
    vector<pair<int, int>> persons(n + m);
    map<int, int> personToTaxi;
    map<int, int> taxiToRides;

    for (size_t i = 0; i < n + m; ++i) {
        cin >> x;
        persons[i].first = x;
    }

    for (size_t i = 0; i < n + m; ++i) {
        cin >> t;
        persons[i].second = t;
        if (t == 1) {
            taxiToRides[persons[i].first] = 0;
        }
    }

    sort(begin(persons), end(persons));
    int currentTaxi = -1;

    for (size_t i = 0; i < n + m; ++i) {
        if (persons[i].second == 1) {
            currentTaxi = persons[i].first;
        } else if (currentTaxi > -1) {
            personToTaxi[persons[i].first] = currentTaxi;
        }
    }

    currentTaxi = -1;

    for (int i = n + m - 1; i >= 0; --i) {
        if (persons[i].second == 1) {
            currentTaxi = persons[i].first;
        } else if (currentTaxi > -1) {
            if (personToTaxi.find(persons[i].first) == personToTaxi.end()) {
                personToTaxi[persons[i].first] = currentTaxi;
            } else if (currentTaxi - persons[i].first < persons[i].first - personToTaxi[persons[i].first]) {
                personToTaxi[persons[i].first] = currentTaxi;
            }
        }
    }

    for (auto const& ptt: personToTaxi) {
        ++taxiToRides[ptt.second];
    }

    for (auto const& ttr: taxiToRides) {
        cout << ttr.second << ' ';
    }

    cout << endl;

    return 0;
}
