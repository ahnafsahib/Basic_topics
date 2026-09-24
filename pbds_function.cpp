#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {

    pbds<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);

    // order_of_key(x)
    // x এর চেয়ে ছোট কয়টি element আছে তা বলে
    // s = {10, 20, 30, 40, 50}
    // order_of_key(30) = 2
    // কারণ 30 এর চেয়ে ছোট: 10, 20
    cout << s.order_of_key(30) << '\n';


    // find_by_order(k)
    // 0-index অনুযায়ী k-th smallest element-এর iterator দেয়
    // s = {10, 20, 30, 40, 50}
    // find_by_order(0) = 10
    // find_by_order(1) = 20
    // find_by_order(2) = 30
    cout << *s.find_by_order(2) << '\n';

    return 0;
}
