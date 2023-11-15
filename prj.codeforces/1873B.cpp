#include <iostream>
#include <vector>

int main() {
	int k;
	std::cin >> k;
	for (int i = 0; i < k; i++) {
		int n, min = 999, composition = 1, imin = 0;
		std::cin >> n;
		std::vector<int> a(n);
		for (size_t j = 0; j < a.size(); j++) {
			std::cin >> a[j];
			if (a[j] < min) {
				min = a[j];
				imin = j;
			}
		}
		a[imin] = a[imin] + 1;
		for (size_t j = 0; j < a.size(); j++)
		{
			composition *= a[j];
		}
		std::cout << composition << std::endl;
	}
}