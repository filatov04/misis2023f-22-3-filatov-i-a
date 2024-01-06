#include <iostream>

int main() {
	unsigned long long sum = 0, c; int t;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		sum = 0;
		std::cin >> c;
		while (c != 1) {
			if (c % 2 == 1) {
				sum += c;
				c = (c - 1) / 2;
			}
			else {
				sum += c;
				c /= 2;
			}
		}
		std::cout << sum + 1 << "\n";
	}
}