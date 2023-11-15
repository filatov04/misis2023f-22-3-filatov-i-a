#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> matrix(n, std::vector<int>(3));
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < 3; j++) {
			std::cin >> matrix[i][j];
		}
	}
	int ans = 0;
	for (size_t i = 0; i < n; i++) {
		int k = 0;
		for (size_t j = 0; j < 3; j++) {
			if (matrix[i][j] == 1) {
				k++;
				if (k >= 2) {
					ans++;
					break;
				}
			}

		}
	}
	std::cout << ans;
}