#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>

int max(int a, int b) { return (a > b) ? a : b; }

std::string testcase(int a, int b, int c) {
    int m = max(a, max(b, c));

    if (2 * m == a + b + c)
        return "YES";

    if (a == b && c % 2 == 0) return "YES";
    if (a == c && b % 2 == 0) return "YES";
    if (b == c && a % 2 == 0) return "YES";

    return "NO";
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        std::string output = testcase(a, b, c);
        std::cout << output << '\n';
    }

    return 0;
}