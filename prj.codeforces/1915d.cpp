#include <iostream>
#include <vector>
#include <string>

bool vowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

int main()
{
    int t;
    std::cin >> t;

    for (int k = 0; k < t; k++)
    {
        int n;
        std::cin >> n;

        std::string st;
        std::cin >> st;

        int i;
        for (i = 0; i < n - 3; )
        {
            if (!vowel(st[i]) && vowel(st[i + 1]))
            {
                if (!vowel(st[i + 2]) && !vowel(st[i + 3]))
                {
                    std::cout << st[i] << st[i + 1] << st[i + 2] << '.';
                    i += 3;
                }
                else if (vowel(st[i + 3]))
                {
                    std::cout << st[i] << st[i + 1] << '.';
                    i += 2;
                }
            }
        }
        for (i; i < n; i++)
        {
            std::cout << st[i];
        }
        std::cout << std::endl;
    }
}