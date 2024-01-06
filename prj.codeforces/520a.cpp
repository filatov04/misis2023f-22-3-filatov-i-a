#include <iostream>
#include <string>
#include<set>
int main()
{
	int n; std::cin >> n;
	char arr[105];
	std::set<char>st;
	for (int i = 0; i < n; i++) {
		char in; std::cin >> in;
		if (in > 90)
			in -= 32;
		st.insert(in);
	}
	if (st.size() == 26)
		std::cout << "YES";
	else
		std::cout << "NO";
}