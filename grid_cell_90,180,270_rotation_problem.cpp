#include<bits/stdc++.h>
#define int long long
using namespace std;
// ei problem e ekta matrix ke 90,180,270 degree rotation korle tar cell gula kothay kothay shift hoy sheita track kore
int32_t main () {
ios::sync_with_stdio(false);
cin.tie(nullptr);
 int t;
 cin >> t;
 while(t--) {
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n;j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            int z = 0, one = 0;
            if(arr[i][j] == '0') {
                z++;
            }
            else {
                one++;
            }
            if(arr[j][n-i-1] == '0') {
                z++;
            }
            else {
                one++;
            }
            if(arr[n-i-1][n-j-1] == '0') {
                z++;
            }
            else {
                one++;
            }
            if(arr[n-j-1][i] == '0') {
                z++;
            }
            else {
                one++;
            }
            if(z == 0 || one == 0) {
                continue;
            }
            else if(z >= one) {
                ans += one;
                arr[i][j] = '0';
                arr[j][n-i-1] = '0';
                arr[n-i-1][n-j-1] = '0';
                arr[n-j-1][i] = '0';
            }
            else {
                ans += z;
                arr[i][j] = '1';
                arr[j][n-i-1] = '1';
                arr[n-i-1][n-j-1] = '1';
                arr[n-j-1][i] = '1';
            }
        }
    }
    cout << ans << endl;
 }
return 0;
}
