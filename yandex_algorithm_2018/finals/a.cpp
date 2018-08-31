#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    long long millionsCount, coinsCount, colaCost, coinsInMachineCount;
    std::cin >> millionsCount >> coinsCount >> colaCost >> coinsInMachineCount;

    unordered_set<long long> changes;

    long long maxCansCount = (1e6 * millionsCount + coinsCount) / colaCost;
    long long ourDiff = colaCost % static_cast<long long>(1e6);
    long long machineDiff = 1e6 - ourDiff;

    if (coinsCount + coinsInMachineCount >= 1e6 - 1) {
        cout << maxCansCount << endl;
        return 0;
    } else {
        size_t cans = 0;
        while (true) {
            if (coinsInMachineCount >= machineDiff) {
                coinsInMachineCount -= machineDiff;
                coinsCount += machineDiff;

                if (changes.find(coinsCount) != changes.end()) {
                    cout << maxCansCount << endl;
                    return 0;
                }

                changes.insert(coinsCount);
            } else if (coinsCount >= ourDiff) {
                coinsCount -= ourDiff;
                coinsInMachineCount += ourDiff;

                if (changes.find(coinsCount) != changes.end()) {
                    cout << maxCansCount << endl;
                    return 0;
                }

                changes.insert(coinsCount);
            } else {
                cout << cans << endl;
                return 0;
            }
            ++cans;
        }
    }

    return 0;
}
