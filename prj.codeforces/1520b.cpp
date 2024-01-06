#include <iostream>
int main()
{
	int n;
	std::cin >> n;
	while (n--)
	{
		int ans = 0;
		int num;
		std::cin >> num;
		for (int i = 1; i <= num; i = i * 10 + 1)
		{
			for (int j = 1; j < 10; j++)
			{
				if (i * j <= num)
				{
					ans++;
				}
			}
		}
		std::cout << ans << std::endl;
	}
}