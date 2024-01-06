#include<iostream>
#include<algorithm>
int main()
{
    long long a, n, k, t;
    std::cin >> n;
    for (k = 0; k < n; k++)
    {
        std::cin >> t;
        if (t % 4 == 0) { std::cout << "YES" << std::endl; }
        else { std::cout << "NO" << std::endl; }
    }

}