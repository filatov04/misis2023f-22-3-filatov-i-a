#include<iostream>
int main()
{
    int a;
    std::cin >> a;
    for (int i = 0; i < a; i++)
    {
        int n, x, count = 0;
        std::cin >> n >> x;
        if (n < 2)
        {
            count = 1;
            std::cout << count << "\n";
        }
        else {
            count = 1;
            count = count + (n - 2) / x;
            if ((n - 2) % x != 0)
                count++;
            std::cout << count << "\n";
        }
    }
}