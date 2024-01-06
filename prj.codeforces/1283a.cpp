#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<numeric>
int main() {
    int t, hours, mins, res, hres, mres;
    std::cin >> t;
    while (t--) {
        hres = 0, mres = 0, res = 0;
        std::cin >> hours >> mins;
        if (mins != 0) {
            mres = 60 - mins;
            hours++;
        }
        else {
            mres = 0;
        }
        if (hours == 24) {
            hres = 0;
        }
        else {
            hres = 24 - hours;
        }
        res += mres; res += (hres * 60);
        std::cout << res << std::endl;
    }
}