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

string generateString(int n) {
    char c[3] = {'a', 'b', 'c'};

    string result;
    int cIdx = 0;

    for (size_t j = 0; j < n; ++j) {
        result += c[cIdx++];
        if (cIdx > 2) {
            cIdx = 0;
        }
    }

    return result;
}

int checkString(const string& generatedString, int k) {
    int isPalindromeCount = 0;
    for (size_t i = 0; i < generatedString.size() - 1; ++i) {
        for (size_t j = i; j < generatedString.size(); ++j) {
            size_t l = i;
            size_t r = j;
            bool isPalindrome = true;

            while (l < r) {
                if (generatedString[l] != generatedString[r]) {
                    isPalindrome = false;
                    break;
                }
            }

            if (isPalindrome) {
                ++isPalindromeCount;
            }
        }
    }

    return isPalindromeCount;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout.precision(10);

    int t, n, k;

    cin >> t;

    for (size_t i = 0; i < t; ++i) {
        cin >> n >> k;
        cout << generateString(n) << endl;
    }
//    for (int i = 0; i < 1000; ++i) {
//        for (int j = 0; j < i; ++j) {
//            string generatedString = generateString(n);
//            int palindromesCount = checkString(generatedString, j);
//            if (palindromesCount <= k) {
//                cout << "[SUCCESS] n = " << generatedString.size() << ", k = " << k << ", palindromesCount = " << palindromesCount;
//            } else {
//                cout << "[FAILURE] n = " << generatedString.size() << ", k = " << k << ", palindromesCount = " << palindromesCount;
//            }
//        }
//    }

    return 0;
}
