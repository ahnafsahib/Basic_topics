#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;

    vector<int> a(64);

    // Number -> 64-bit vector
    for(int i = 0; i < 64; i++)
        a[i] = (n >> i) & 1;

    // Print 64-bit representation
    for(int i = 63; i >= 0; i--)
        cout << a[i];

    cout << '\n';

    // 64-bit vector -> Number
    int x = 0;

    for(int i = 0; i < 64; i++) {
        if(a[i] == 1)
            x += (1LL << i);
    }

    cout << x << '\n';

    return 0;
}
