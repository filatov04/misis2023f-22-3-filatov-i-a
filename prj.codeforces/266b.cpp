#include<iostream>
#include<cstring>
using namespace std;
int main() {
	int n, ci;
	char a[60];
	cin >> n >> ci;
	cin >> a;
	int l = strlen(a);
	for (int i = 0; i < ci; i++) {
		for (int j = 0; j < l - 1; j++) {
			if (a[j] == 'B' && a[j + 1] == 'G') {
				a[j] = 'G';
				a[j + 1] = 'B';
				j++;
			}
		}

	}
	cout << a << endl;
	return 0;
}