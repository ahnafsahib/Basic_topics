#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// ============================================================
//                 SET - COMPLETE GUIDE IN C++
// ============================================================

// SET কী?
// - Automatically SORTED থাকে (ascending order)
// - Duplicate value রাখে না
// - Insert, Delete, Search সব O(log n) এ হয়
// - Internally Binary Search Tree (BST) দিয়ে কাজ করে

// ------------------------------------------------------------
// SYNTAX:
// set<datatype> s;
// ------------------------------------------------------------

int main() {

    // ============================================================
    // 1. BASIC - Insert & Print
    // ============================================================

    set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(8);
    s.insert(1);
    s.insert(3); // Duplicate - রাখবে না!
    s.insert(7);

    cout << "=== Basic Set ===" << endl;
    for (int x : s) {
        cout << x << " "; // Output: 1 3 5 7 8 (sorted!)
    }
    cout << endl;


    // ============================================================
    // 2. SIZE, EMPTY, CLEAR
    // ============================================================

    cout << "\n=== Size, Empty, Clear ===" << endl;
    cout << "Size: " << s.size() << endl;       // 5
    cout << "Empty? " << s.empty() << endl;     // 0 (false)
    // s.clear(); // সব মুছে দেয়


    // ============================================================
    // 3. FIND - value আছে কিনা
    // ============================================================

    cout << "\n=== Find ===" << endl;
    if (s.find(3) != s.end()) {
        cout << "3 আছে!" << endl;
    }
    if (s.find(10) == s.end()) {
        cout << "10 নেই!" << endl;
    }


    // ============================================================
    // 4. COUNT - set এ 0 বা 1 return করে (duplicate নেই বলে)
    // ============================================================

    cout << "\n=== Count ===" << endl;
    cout << "3 আছে? " << s.count(3) << endl;  // 1
    cout << "10 আছে? " << s.count(10) << endl; // 0


    // ============================================================
    // 5. ERASE - মুছে ফেলা
    // ============================================================

    set<int> s2 = {1, 3, 5, 7, 9};

    s2.erase(5);        // value দিয়ে মুছো

    cout << "\n=== Erase ===" << endl;
    for (int x : s2) {
        cout << x << " "; // 1 3 7 9
    }
    cout << endl;

    // Iterator দিয়েও মুছা যায়
    auto it = s2.find(7);
    if (it != s2.end()) {
        s2.erase(it); // iterator দিয়ে মুছো
    }
    for (int x : s2) {
        cout << x << " "; // 1 3 9
    }
    cout << endl;


    // ============================================================
    // 6. LOWER BOUND & UPPER BOUND (set এর নিজের method)
    // ============================================================
    // ⚠️ set এ সবসময় s.lower_bound() use করুন
    //    lower_bound(s.begin(), s.end(), x) slow হয়!

    set<int> s3 = {1, 3, 5, 7, 9};
    // index:       0  1  2  3  4

    cout << "\n=== Lower & Upper Bound ===" << endl;

    // Lower Bound: >= value এর প্রথম position
    auto lb = s3.lower_bound(5);
    cout << "Lower Bound of 5: " << *lb << endl; // 5

    auto lb2 = s3.lower_bound(4);
    cout << "Lower Bound of 4: " << *lb2 << endl; // 5 (4 নেই, পরেরটা)

    // Upper Bound: > value এর প্রথম position
    auto ub = s3.upper_bound(5);
    cout << "Upper Bound of 5: " << *ub << endl; // 7

    auto ub2 = s3.upper_bound(4);
    cout << "Upper Bound of 4: " << *ub2 << endl; // 5 (4 নেই, পরেরটা)


    // ============================================================
    // 7. LOWER/UPPER BOUND TRICKS
    // ============================================================

    set<int> s4 = {1, 3, 5, 7, 9};

    cout << "\n=== Bound Tricks ===" << endl;

    // Trick 1: x এর <= সবচেয়ে বড় value (floor)
    auto it1 = s4.upper_bound(6);
    --it1;
    cout << "6 এর <= সবচেয়ে বড়: " << *it1 << endl; // 5

    // Trick 2: x এর >= সবচেয়ে ছোট value (ceil)
    auto it2 = s4.lower_bound(4);
    cout << "4 এর >= সবচেয়ে ছোট: " << *it2 << endl; // 5

    // Trick 3: Range [L, R] এ কতগুলো value আছে
    set<int> s5 = {1, 3, 5, 7, 9, 11, 13};
    int L = 3, R = 9;
    auto lb3 = s5.lower_bound(L);
    auto ub3 = s5.upper_bound(R);
    cout << "Range [3,9] count: " << distance(lb3, ub3) << endl; // 4


    // ============================================================
    // 8. BEGIN & END - Iterator দিয়ে ঘোরা
    // ============================================================

    set<int> s6 = {1, 3, 5, 7, 9};

    cout << "\n=== Begin & End ===" << endl;
    cout << "সবচেয়ে ছোট: " << *s6.begin() << endl;   // 1
    cout << "সবচেয়ে বড়: "  << *s6.rbegin() << endl;  // 9


    // ============================================================
    // 9. MULTISET - Duplicate রাখা যায়
    // ============================================================

    multiset<int> ms;
    ms.insert(3);
    ms.insert(3);
    ms.insert(3);
    ms.insert(5);

    cout << "\n=== Multiset ===" << endl;
    for (int x : ms) {
        cout << x << " "; // 3 3 3 5
    }
    cout << endl;
    cout << "3 কতবার আছে: " << ms.count(3) << endl; // 3

    // Multiset এ শুধু একটা 3 মুছতে
    ms.erase(ms.find(3)); // একটাই মুছবে
    cout << "একটা মোছার পর 3: " << ms.count(3) << endl; // 2

    // Multiset এ সব 3 মুছতে
    ms.erase(3); // সব মুছবে
    cout << "সব মোছার পর 3: " << ms.count(3) << endl; // 0


    // ============================================================
    // 10. SET OF PAIRS
    // ============================================================

    set<pair<int,int>> sp;
    sp.insert({3, 5});
    sp.insert({1, 2});
    sp.insert({3, 4});
    sp.insert({1, 2}); // Duplicate - রাখবে না

    cout << "\n=== Set of Pairs ===" << endl;
    for (auto p : sp) {
        cout << "{" << p.first << "," << p.second << "} ";
    }
    // Output: {1,2} {3,4} {3,5}
    cout << endl;


    // ============================================================
    // QUICK SUMMARY TABLE
    // ============================================================
    //
    //  | Function           | কাজ                    | Time    |
    //  |--------------------|------------------------|---------|
    //  | insert(x)          | x যোগ করা              | O(logn) |
    //  | erase(x)           | x মুছে ফেলা            | O(logn) |
    //  | find(x)            | x খোঁজা                | O(logn) |
    //  | count(x)           | x আছে কিনা (0 বা 1)   | O(logn) |
    //  | lower_bound(x)     | >= x প্রথম position    | O(logn) |
    //  | upper_bound(x)     | >  x প্রথম position    | O(logn) |
    //  | size()             | কতগুলো element আছে    | O(1)    |
    //  | empty()            | খালি কিনা              | O(1)    |
    //  | clear()            | সব মুছে দেওয়া          | O(n)    |
    //  | *begin()           | সবচেয়ে ছোট value      | O(1)    |
    //  | *rbegin()          | সবচেয়ে বড় value       | O(1)    |
    //
    // ============================================================

    return 0;
}
