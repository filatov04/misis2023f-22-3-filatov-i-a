#include <iostream>
#include <string>

int Min(std::string s) {
    int ones = 0;
    int zeros = 0;
    int min = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            ones++;
        if (s[i] == '0')
            zeros++;
    }
    if (zeros > ones)
        min = ones;
    else
        min = zeros;
    return min;
}
int Count(std::string s, std::string t) {
    int count = 0;
    int k = 0;
    std::string n = "";
    do {
        count = 0;
        n = "";
        for (int i = 0; i < t.length(); i++)
        {
            if (s[i] == t[i])
                count++;
            else
                n += t[i];
        }
        k += count;

        t = n;
    } while (count != 0);
    return k;

}

std::string swap(std::string s) {
    std::string t = "";
    int min = Min(s);
    int o = 0;
    int z = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0' && z < min) {
            t += '1';
            z++;
        }

        else if (s[i] == '1' && o < min) {
            t += '0';
            o++;
        }
        else
            t += s[i];
    }
    return t;

}
int main() {
    int n;
    std::cin >> n;
    int a[10000];
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        std::string t = swap(s);
        a[i] = Count(s, t);
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << std::endl;
    }

    return 0;
}