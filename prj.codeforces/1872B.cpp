#include <iostream>

int main() {
	int t; //���������� ������� ������� ������
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n, d, s, k = 0, kmin = 300, plus = 0; //plus �� ������� ������ ������ ������� ������, ����� �������� ����� �� �������� ���� //���������� �������, ��������� �������(����� �������, ����� �� ���������), ����� ������� , �� ������� ����� ������ �������� 
		std::cin >> n;
		for (int j = 0; j < n; j++) {
			std::cin >> d >> s;
			if (s % 2 == 0) {
				plus = s / 2 - 1;
				k = d + plus;
			}
			else {
				plus = (s - 1) / 2;
				k = d + plus;
			}
			if (k < kmin) {
				kmin = k;
			}
		}
		std::cout << kmin << std::endl;
	}
}
