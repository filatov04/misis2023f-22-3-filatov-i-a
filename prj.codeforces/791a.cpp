#include<iostream>
int main(int argc, char* argv)
{
	int a, b;
	std::cin >> a;
	std::cin >> b;
	int i = 0;
	while (a <= b)
	{
		a *= 3;
		b *= 2;
		i++;
	}
	std::cout << i;
}