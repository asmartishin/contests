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

long long gcd(long long n, long long k) {
    while (k) {
        n %= k;
        swap(n, k);
    }
    return n;
}

size_t countDivisors(long long n) {
    size_t numberOfDivisors = 0;

    for (size_t i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) {
                numberOfDivisors++;
            } else {
                numberOfDivisors = numberOfDivisors + 2;
            }
        }
    }
    return numberOfDivisors;
}

size_t divisorsCount(long long n) {
    size_t numberOfDivisors = 1;

    for (size_t i = 2; i <= n; i++) {
        long long exponent = 0;
        while (n % i == 0) {
            exponent++;
            n /= i;
        }
        numberOfDivisors *= (exponent + 1);
    }

    return numberOfDivisors;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long b;
    cin >> b;

    cout << countDivisors(b) << endl;

    return 0;
}
