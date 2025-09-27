#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;

    int write = 0; 
    for (int read = 0; read < (int)s.size(); ++read) {
        if (write == 0 || s[write - 1] != s[read]) {
            s[write++] = s[read];
        }
    }
    s.resize(write); 
    cout << s << '\n';
    return 0;
}
