#include <iostream>
#include <vector>
#define ll long long
int main() {
    ll t;
    std::cin >> t;
    for (ll g = 0; g < t; g++) {
        ll n;
        std::cin >> n;
        std::vector<long long> s(n);
        s[0] = 1; s[1] = 3;
        for (ll i = 0; i < n - 2; i++) {
            s[i + 2] = s[i + 1] + 1;
            while (((3 * s[i + 2]) % (s[i] + s[i + 1])) == 0) {
                s[i + 2]++;
            }
        }
        for (ll i = 0; i < n; i++) {
            std::cout << s[i] << " ";
        }
        std::cout << "\n";
    }
}