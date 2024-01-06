
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main()
{
    string s;
    int n;
    cin >> n;
    int l;
    string o;
    for (int w = 0; w < n; w++) {
        cin >> l;
        cin >> s;
        o = "";
        for (int i = (s.length() - 1); i >= 0; i--) {
            int q = 0;
            if (s[i] != '0')
                q += s[i] - 48;
            else {
                q += (s[i - 1] - 48);
                q += (s[i - 2] - 48) * 10;
                i -= 2;
            }
            o += (char)(q + 96);
        }
        for (int e = (o.length() - 1); e >= 0; e--) {
            cout << o[e];
        }
        cout << endl;
    }
}