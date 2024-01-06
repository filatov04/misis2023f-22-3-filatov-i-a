#include <iostream>
#include <algorithm>

const int maxn = 200005;
int T, n, k, p[maxn], t[maxn], cnt, vis[maxn];

bool check()
{
	for (int i = 1; i <= n; i++)
	{
		if (p[i] != i)
		{
			return 0;
		}
	}
	return 1;
}

bool check2()
{
	int res = 0;
	for (int i = 1; i <= k; i++)
	{
		for (int j = i; j <= n; j += k)
		{
			vis[p[j]] = 1;
		}
		for (int j = i; j <= n; j += k)
		{
			if (!vis[j])
			{
				res++;
			}
		}
		for (int j = i; j <= n; j += k)
		{
			vis[p[j]] = 0;
		}
	}
	return res == 2;
}
int main()
{
	std::cin >> T;
	while (T--)
	{
		std::cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			std::cin >> p[i];
		}
		for (int i = 1; i <= k; i++)
		{
			cnt = 0;
			for (int j = i; j <= n; j += k)
			{
				t[++cnt] = p[j];
			}
			std::sort(t + 1, t + cnt + 1); cnt = 0;
			for (int j = i; j <= n; j += k)
			{
				p[j] = t[++cnt];
			}
		}
		if (check())
		{
			std::cout << 0 << std::endl;
		}
		else if (check2())
		{
			std::cout << 1 << std::endl;
		}
		else
		{
			std::cout << -1 << std::endl;
		}
	}
}