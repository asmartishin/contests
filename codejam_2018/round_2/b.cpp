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

    int tests;
    cin >> tests;

    for (size_t t = 0; t < tests; ++t) {
        int seatsCount, customersCount, ticketsCount, seat, customer;

        cin >> seatsCount >> customersCount >> ticketsCount;

        vector<int> seatsToTickets(seatsCount);
        vector<int> customersToTickets(customersCount);

        for (size_t i = 0; i < ticketsCount; ++i) {
            cin >> seat >> customer;
            --seat;
            --customer;

            ++seatsToTickets[seat];
            ++customersToTickets[customer];
        }

        int minRollerCoasterRides = *max_element(begin(customersToTickets), end(customersToTickets));
        int maxRollerCoasterRides = 1001;

        int currentRollerCoasterRides, resultRollerCoasterRides;

        int possiblePromotions;
        int numberOfPromotions, resultPromotions;

        while (minRollerCoasterRides < maxRollerCoasterRides) {
            bool notEnough = false;

            numberOfPromotions = 0;
            possiblePromotions = 0;

            currentRollerCoasterRides = (minRollerCoasterRides + maxRollerCoasterRides) / 2;

            for (auto tickets: seatsToTickets) {
                if (tickets <= currentRollerCoasterRides) {
                    possiblePromotions += currentRollerCoasterRides - tickets;
                } else {
                    if (tickets - possiblePromotions > currentRollerCoasterRides) {
                        notEnough = true;
                        break;
                    } else {
                        numberOfPromotions += tickets - currentRollerCoasterRides;
                        possiblePromotions -= tickets - currentRollerCoasterRides;
                    }
                }
            }

            if (notEnough) {
                minRollerCoasterRides = currentRollerCoasterRides + 1;
            } else {
                maxRollerCoasterRides = currentRollerCoasterRides;
                resultRollerCoasterRides = currentRollerCoasterRides;
                resultPromotions = numberOfPromotions;
            }
        }

        cout << "Case #" << t + 1 << ": " << resultRollerCoasterRides << ' ' << resultPromotions << endl;
    }

    return 0;
}
