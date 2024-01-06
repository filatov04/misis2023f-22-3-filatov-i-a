#include <iostream>
#include <vector>


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k, H;
        std::cin >> n >> m >> k >> H;
        std::vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> h[i];
        }
        int conversations = 0;
        for (int i = 0; i < n; ++i) {
            for (int step = 1; step < m; ++step) {
                int diff = abs(H - h[i]);

                if (diff == (k * step)) { conversations++; }

            }
        }
        std::cout << conversations << std::endl;
    }
}