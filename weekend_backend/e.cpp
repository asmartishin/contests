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

struct UserView {
    int timestamp;
    int userId;

    UserView(int timestamp, int userId)
    : timestamp(timestamp)
    , userId(userId)
    {}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int userLimit, serviceLimit, durationTime, timestamp, userId;
    deque<UserView> queueOfRequests;
    unordered_map<int, int> userRequestsNumber;

    cin >> userLimit >> serviceLimit >> durationTime;

    while (true) {
        cin >> timestamp;

        if (timestamp == -1) {
            break;
        }

        cin >> userId;

        while (!queueOfRequests.empty() && queueOfRequests.back().timestamp < timestamp - durationTime) {
            --userRequestsNumber[queueOfRequests.back().userId];
            queueOfRequests.pop_back();
        }

        if (userRequestsNumber[userId] >= userLimit) {
            cout << 429 << endl;
        } else if (queueOfRequests.size() >= serviceLimit) {
            cout << 503 << endl;
        } else {
            cout << 200 << endl;
            queueOfRequests.emplace_front(timestamp, userId);
            ++userRequestsNumber[userId];
        }

        cout.flush();
    }

    return 0;
}
