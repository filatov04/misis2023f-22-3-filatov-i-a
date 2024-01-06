#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<string.h>
#include <sstream>
int main() {
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::string s;
        std::cin >> n >> s;
        std::vector<long long>an;
        reverse(s.begin(), s.end());
        int j = 1;
        long long w = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                an.push_back(w);
            }
            else {
                while (j < n && s[j] == '1' || j < i) {
                    j++;
                }
                if (j < n) {
                    w += j - i;
                    an.push_back(w);
                    s[j] = '1';
                }
                else {
                    an.push_back(-1);
                }
            }
        }
        for (int i = 0; i < an.size(); i++) {
            std::cout << an[i] << " ";
        }
        std::cout << std::endl;
    }
}