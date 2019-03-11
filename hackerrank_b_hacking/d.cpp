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
#include <sstream>

using namespace std;

#define endl '\n'

vector<int> sort_hotels(string keywords, vector<int> hotel_ids, vector<string> reviews) {
    if (hotel_ids.empty()) {
        return {};
    }

    istringstream keywordsIss(keywords);

    unordered_set<string> keywordsSet;
    string keyword;

    while (keywordsIss >> keyword) {
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
        keywordsSet.insert(keyword);
    }

    unordered_map<int, int> hotelsToMatch;

    for (size_t i = 0; i < hotel_ids.size(); ++i) {
        auto id = hotel_ids[i];
        auto& review = reviews[i];

        review.erase(
            remove_if(review.begin(), review.end(), [](char& c)
                {
                    return c == ','|| c == '.';
                }
            ),
            review.end()
        );
        transform(review.begin(), review.end(), review.begin(), ::tolower);

        istringstream reviewIss(review);
        while (reviewIss >> keyword) {
            if (keywordsSet.find(keyword) != keywordsSet.end()) {
                ++hotelsToMatch[id];
            }
        }
    }

    vector<pair<int, int>> MatchToHotel;

    for (const auto& p : hotelsToMatch) {
        MatchToHotel.emplace_back(p.second, p.first);
    }

    sort(begin(MatchToHotel), end(MatchToHotel), [](auto& lhs, auto& rhs) {
        if (lhs.first == rhs.first) {
            return lhs.second < rhs.second;
        }
        return lhs.first > rhs.first;
    });

    vector<int> result;

    for (const auto& p : MatchToHotel) {
        result.push_back(p.second);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    auto result = sort_hotels(
        "breakfast beach citycenter location metro view staff price",
        {1, 2, 1, 1, 2},
        {
            "This hotel has a nice view of the citycenter. The location is perfect.",
            "The breakfast is ok. Regarding location, it is quite far from citycenter but price is cheap so it is worth.",
            "Location is excellent, 5 minutes from citycenter. There is also a metro station very close to the hotel.",
            "They said I couldn't take my dog and there were other guests with dogs! That is not fair.",
            "Very friendly staff and good cost-benefit ratio. Location is a bit far from citycenter."
        }
    );

    for (auto i : result) {
        cout << i << endl;
    }

    return 0;
}
