// ============================================================
// SNIPPET 1: cpp - Basic Competitive Programming Template
// ============================================================
// prefix: cpp

#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main () {
ios::sync_with_stdio(false);
cin.tie(nullptr);
 
return 0;
}


// ============================================================
// SNIPPET 2: sieve - Sieve of Eratosthenes
// ============================================================
// prefix: sieve

vector<bool> prime(n + 1, true);
   for (int i = 2;i * i <= n;i++) {
      if (prime[i]) {
         for (int j = i + i;j <= n;j += i) {
            prime[j] = false;
         }
      }
   }

   for (int i = 2;i <= n;i++) {
      if (prime[i]) {
         cout << i << " ";
      }
   }


// ============================================================
// SNIPPET 3: isprime - Check if a Number is Prime
// ============================================================
// prefix: isprime

bool isprime(int n) {
    if(n==1) {
        return false;
    }
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}


// ============================================================
// SNIPPET 4: divisor - Count Divisors of a Number
// ============================================================
// prefix: divisor

for(int i = 1; i*i <= r; i++) {
            if(r % i == 0){
                count++;
                if(r / i != i){
                    count++;
                }
            }
        }


// ============================================================
// SNIPPET 5: pbdscpp - Policy Based Data Structure Template
// ============================================================
// prefix: pbdscpp

#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {

   return 0;
}
