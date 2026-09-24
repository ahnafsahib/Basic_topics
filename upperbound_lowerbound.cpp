#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;


// ============================================================
// PBDS TEMPLATE
// ============================================================

// PBDS = Policy Based Data Structure
// সাধারণ set-এর মতো, কিন্তু এখানে order/index সম্পর্কিত query করা যায়।
//
// less<T>  → ascending order
// greater<T> → descending order করা যায়
//
// PBDS-এর গুরুত্বপূর্ণ:
// order_of_key(x)   → x-এর চেয়ে ছোট কয়টা element আছে
// find_by_order(k)  → 0-indexed k-th smallest element
//
// Time Complexity:
// insert         → O(log n)
// erase          → O(log n)
// find           → O(log n)
// order_of_key   → O(log n)
// find_by_order  → O(log n)

template <typename T>
using pbds = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;


int main() {

    // ========================================================
    // VECTOR
    // ========================================================

    vector<int> v = {1, 2, 2, 4, 6, 8};

    // size() → কয়টি element আছে
    int n = v.size();

    // v[i] → i-th element
    cout << v[2] << '\n';

    // front() → প্রথম element
    cout << v.front() << '\n';

    // back() → শেষ element
    cout << v.back() << '\n';

    // push_back(x) → শেষে x যোগ করে
    v.push_back(10);

    // pop_back() → শেষ element remove করে
    v.pop_back();

    // empty() → vector খালি হলে true
    if(v.empty())
        cout << "Empty\n";


    // ========================================================
    // SORT
    // ========================================================

    // Ascending sort
    sort(v.begin(), v.end());

    // Descending sort
    sort(v.rbegin(), v.rend());

    // আবার ascending
    sort(v.begin(), v.end());


    // ========================================================
    // REVERSE
    // ========================================================

    // পুরো vector reverse করে
    reverse(v.begin(), v.end());


    // ========================================================
    // LOWER BOUND
    // ========================================================

    // IMPORTANT:
    // vector/array অবশ্যই sorted হতে হবে।
    //
    // lower_bound(x)
    // → x-এর সমান বা x-এর চেয়ে বড় প্রথম element
    //
    // Example:
    // v = {1, 2, 2, 4, 6, 8}
    //
    // lower_bound(2) → প্রথম 2
    // lower_bound(3) → 4
    // lower_bound(7) → 8

    sort(v.begin(), v.end());

    auto it1 = lower_bound(v.begin(), v.end(), 2);

    // Iterator থেকে value
    cout << *it1 << '\n';

    // Iterator থেকে index
    int idx1 = it1 - v.begin();

    cout << idx1 << '\n';


    // সরাসরি index
    int idx2 = lower_bound(v.begin(), v.end(), 2) - v.begin();


    // ========================================================
    // UPPER BOUND
    // ========================================================

    // upper_bound(x)
    // → x-এর চেয়ে বড় প্রথম element
    //
    // v = {1, 2, 2, 4, 6, 8}
    //
    // upper_bound(2) → 4
    // upper_bound(3) → 4
    // upper_bound(8) → end()

    auto it2 = upper_bound(v.begin(), v.end(), 2);

    if(it2 != v.end())
        cout << *it2 << '\n';

    // upper_bound এর index
    int idx3 = upper_bound(v.begin(), v.end(), 2) - v.begin();


    // ========================================================
    // COUNT OCCURRENCE
    // ========================================================

    // x কতবার আছে
    //
    // sorted vector হলে lower_bound + upper_bound
    // দিয়ে efficient ভাবে count করা যায়।

    int x = 2;

    int cnt = upper_bound(v.begin(), v.end(), x)
            - lower_bound(v.begin(), v.end(), x);

    cout << cnt << '\n';


    // ========================================================
    // BINARY SEARCH
    // ========================================================

    // x আছে কিনা check করে
    // sorted vector/array দরকার

    if(binary_search(v.begin(), v.end(), 4))
        cout << "Found\n";
    else
        cout << "Not Found\n";


    // ========================================================
    // FIND
    // ========================================================

    // x খুঁজে iterator return করে
    // না পেলে end() return করে

    auto it3 = find(v.begin(), v.end(), 4);

    if(it3 != v.end()) {

        // Value
        cout << *it3 << '\n';

        // Index
        cout << it3 - v.begin() << '\n';
    }


    // ========================================================
    // COUNT
    // ========================================================

    // vector-এর মধ্যে x কতবার আছে
    // O(n)

    cout << count(v.begin(), v.end(), 2) << '\n';


    // ========================================================
    // MINIMUM / MAXIMUM
    // ========================================================

    // Minimum element-এর iterator
    auto mn = min_element(v.begin(), v.end());

    // Maximum element-এর iterator
    auto mx = max_element(v.begin(), v.end());

    // Value
    cout << *mn << '\n';
    cout << *mx << '\n';

    // Minimum-এর index
    int mn_idx = mn - v.begin();

    // Maximum-এর index
    int mx_idx = mx - v.begin();

    cout << mn_idx << '\n';
    cout << mx_idx << '\n';


    // ========================================================
    // SET
    // ========================================================

    // Set:
    // 1. Unique element রাখে
    // 2. Automatically sorted থাকে

    set<int> s;

    // Insert
    s.insert(10);
    s.insert(20);
    s.insert(30);

    // Duplicate insert করলে দ্বিতীয়বার রাখবে না
    s.insert(20);


    // Find
    auto sit = s.find(20);

    if(sit != s.end())
        cout << "20 exists\n";


    // Erase
    s.erase(20);


    // Size
    cout << s.size() << '\n';


    // Smallest element
    cout << *s.begin() << '\n';

    // Largest element
    cout << *s.rbegin() << '\n';


    // ========================================================
    // SET LOWER_BOUND
    // ========================================================

    // Set-এর lower_bound:
    // x-এর সমান অথবা x-এর চেয়ে বড় প্রথম element

    auto slb = s.lower_bound(15);

    if(slb != s.end())
        cout << *slb << '\n';


    // ========================================================
    // SET UPPER_BOUND
    // ========================================================

    // x-এর চেয়ে বড় প্রথম element

    auto sub = s.upper_bound(10);

    if(sub != s.end())
        cout << *sub << '\n';


    // ========================================================
    // SET-এ INDEX
    // ========================================================

    // সাধারণ set-এ direct index নেই।
    //
    // যেমন s[2] → কাজ করবে না।
    //
    // Iterator-এর position বের করতে distance():
    
    auto temp = s.begin();

    int pos = distance(s.begin(), temp);

    // কিন্তু distance সাধারণ set-এর জন্য O(n) হতে পারে।
    // তাই frequent index query দরকার হলে PBDS ব্যবহার করো।


    // ========================================================
    // MULTISET
    // ========================================================

    // Multiset duplicate রাখে

    multiset<int> ms;

    ms.insert(10);
    ms.insert(10);
    ms.insert(20);

    // 10 কয়বার আছে
    cout << ms.count(10) << '\n';

    // erase(10) করলে সব 10 remove হবে
    // ms.erase(10);

    // শুধু একটি 10 remove করতে:
    auto mit = ms.find(10);

    if(mit != ms.end())
        ms.erase(mit);


    // ========================================================
    // MAP
    // ========================================================

    // map:
    // key -> value
    //
    // key sorted থাকে
    // key unique

    map<int, int> mp;

    // Insert / update
    mp[10] = 100;
    mp[20] = 200;


    // Value access
    cout << mp[10] << '\n';


    // Find key
    auto mapit = mp.find(20);

    if(mapit != mp.end()) {

        // key
        cout << mapit->first << '\n';

        // value
        cout << mapit->second << '\n';
    }


    // Map lower_bound
    // key >= x-এর প্রথম key

    auto mlb = mp.lower_bound(15);

    if(mlb != mp.end())
        cout << mlb->first << " " << mlb->second << '\n';


    // Map upper_bound
    // key > x-এর প্রথম key

    auto mub = mp.upper_bound(10);

    if(mub != mp.end())
        cout << mub->first << " " << mub->second << '\n';


    // ========================================================
    // PAIR
    // ========================================================

    pair<int, int> p = {10, 20};

    // First value
    cout << p.first << '\n';

    // Second value
    cout << p.second << '\n';


    // Pair-এর vector sort করলে:
    // প্রথমে first অনুযায়ী sort
    // first same হলে second অনুযায়ী sort

    vector<pair<int, int>> vp = {
        {2, 5},
        {1, 10},
        {2, 3}
    };

    sort(vp.begin(), vp.end());


    // ========================================================
    // PBDS
    // ========================================================

    pbds<int> ps;

    ps.insert(10);
    ps.insert(20);
    ps.insert(30);
    ps.insert(40);
    ps.insert(50);


    // --------------------------------------------------------
    // order_of_key(x)
    // --------------------------------------------------------

    // x-এর চেয়ে STRICTLY ছোট কয়টি element আছে?
    //
    // ps = {10,20,30,40,50}
    //
    // order_of_key(30) = 2
    //
    // কারণ 30-এর চেয়ে ছোট:
    // 10, 20

    cout << ps.order_of_key(30) << '\n';


    // --------------------------------------------------------
    // find_by_order(k)
    // --------------------------------------------------------

    // 0-indexed k-th smallest element-এর iterator দেয়
    //
    // ps = {10,20,30,40,50}
    //
    // find_by_order(0) → 10
    // find_by_order(1) → 20
    // find_by_order(2) → 30
    // find_by_order(3) → 40

    cout << *ps.find_by_order(2) << '\n';


    // k valid কিনা check করতে
    if(ps.find_by_order(10) != ps.end()) {
        cout << *ps.find_by_order(10) << '\n';
    }


    // ========================================================
    // PBDS DESCENDING ORDER
    // ========================================================

    // চাইলে greater ব্যবহার করে descending PBDS বানানো যায়

    using rev_pbds = tree<
        int,
        null_type,
        greater<int>,
        rb_tree_tag,
        tree_order_statistics_node_update
    >;

    rev_pbds rs;

    rs.insert(10);
    rs.insert(20);
    rs.insert(30);


    // ========================================================
    // IMPORTANT SHORTCUTS
    // ========================================================

    /*
    
    VECTOR
    ------------------------------------------------------------
    v[i]                         → i-th element
    v.size()                     → size
    v.front()                    → first
    v.back()                     → last
    v.push_back(x)               → add
    v.pop_back()                 → remove last
    v.empty()                    → empty কিনা


    SORT
    ------------------------------------------------------------
    sort(v.begin(), v.end())     → ascending
    sort(v.rbegin(), v.rend())   → descending
    reverse(v.begin(), v.end())  → reverse


    BINARY SEARCH
    ------------------------------------------------------------
    binary_search(...)           → x আছে কিনা

    lower_bound(...)             → >= x
    upper_bound(...)             → > x

    lower_bound(...) - begin()  → index
    upper_bound(...) - begin()  → index


    FIND / COUNT
    ------------------------------------------------------------
    find(...)                    → iterator
    count(...)                   → কয়বার আছে


    MIN / MAX
    ------------------------------------------------------------
    min_element(...)             → minimum iterator
    max_element(...)             → maximum iterator


    SET
    ------------------------------------------------------------
    s.insert(x)
    s.erase(x)
    s.find(x)
    s.lower_bound(x)
    s.upper_bound(x)
    *s.begin()                   → smallest
    *s.rbegin()                  → largest


    MAP
    ------------------------------------------------------------
    mp[key]                      → value
    mp.find(key)
    mp.lower_bound(key)
    mp.upper_bound(key)
    it->first                    → key
    it->second                   → value


    PBDS
    ------------------------------------------------------------
    ps.order_of_key(x)
        → x-এর চেয়ে ছোট কয়টা element

    *ps.find_by_order(k)
        → 0-indexed k-th smallest


    ============================================================
    সবচেয়ে গুরুত্বপূর্ণ ৪টা:
    ============================================================

    lower_bound(x)       → প্রথম >= x

    upper_bound(x)       → প্রথম > x

    order_of_key(x)      → < x কয়টা

    find_by_order(k)     → k-th smallest

    */
    
    return 0;
}
