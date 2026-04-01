#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

// ============================================================
//            LOWER BOUND & UPPER BOUND - COMPLETE GUIDE
// ============================================================

// LOWER BOUND: প্রথম position যেখানে value >= target
// UPPER BOUND: প্রথম position যেখানে value > target
// ⚠️  Array/Vector অবশ্যই SORTED হতে হবে!

// ------------------------------------------------------------
// SYNTAX:
// lower_bound(শুরু, শেষ, value) -> iterator return করে
// upper_bound(শুরু, শেষ, value) -> iterator return করে
// ------------------------------------------------------------

int main() {

    // ============================================================
    // 1. BASIC EXAMPLE - Array দিয়ে
    // ============================================================
    // index:  0  1  2  3  4  5
    // array:  1  3  3  3  5  7
    //            ↑           ↑
    //         lb(3)=1     ub(3)=4

    int arr[] = {1, 3, 3, 3, 5, 7};
    int n = 6;

    int* lb_arr = lower_bound(arr, arr + n, 3);
    int* ub_arr = upper_bound(arr, arr + n, 3);

    cout << "=== Array ===" << endl;
    cout << "Lower Bound index: " << lb_arr - arr << endl; // 1
    cout << "Upper Bound index: " << ub_arr - arr << endl; // 4


    // ============================================================
    // 2. VECTOR দিয়ে
    // ============================================================

    vector<int> v = {1, 3, 3, 3, 5, 7};

    auto lb = lower_bound(v.begin(), v.end(), 3);
    auto ub = upper_bound(v.begin(), v.end(), 3);

    cout << "\n=== Vector ===" << endl;
    cout << "Lower Bound index: " << lb - v.begin() << endl; // 1
    cout << "Upper Bound index: " << ub - v.begin() << endl; // 4
    cout << "Lower Bound value: " << *lb << endl;            // 3
    cout << "Upper Bound value: " << *ub << endl;            // 5


    // ============================================================
    // 3. VALUE না থাকলে কী হয়?
    // ============================================================
    // array: 1  3  5  7  9
    // 4 নেই, তাই 4 এর >= প্রথম value = 5

    vector<int> v2 = {1, 3, 5, 7, 9};

    auto lb2 = lower_bound(v2.begin(), v2.end(), 4);
    auto ub2 = upper_bound(v2.begin(), v2.end(), 4);

    cout << "\n=== Value না থাকলে ===" << endl;
    cout << "Lower Bound of 4: " << *lb2 << endl; // 5
    cout << "Upper Bound of 4: " << *ub2 << endl; // 5
    // lb == ub মানে value নেই array তে!


    // ============================================================
    // 4. COUNT করা - কতবার আছে
    // ============================================================
    // ub - lb = কতগুলো 3 আছে

    vector<int> v3 = {1, 3, 3, 3, 5, 7};

    auto lb3 = lower_bound(v3.begin(), v3.end(), 3);
    auto ub3 = upper_bound(v3.begin(), v3.end(), 3);

    cout << "\n=== Count ===" << endl;
    cout << "3 আছে: " << ub3 - lb3 << " বার" << endl; // 3


    // ============================================================
    // 5. RANGE COUNT - L থেকে R এর মধ্যে কতগুলো
    // ============================================================

    vector<int> v4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int L = 3, R = 7;

    auto lb4 = lower_bound(v4.begin(), v4.end(), L);
    auto ub4 = upper_bound(v4.begin(), v4.end(), R);

    cout << "\n=== Range Count (L=3, R=7) ===" << endl;
    cout << "Count: " << ub4 - lb4 << endl; // 5 (3,4,5,6,7)


    // ============================================================
    // 6. SET এ LOWER/UPPER BOUND
    // ============================================================
    // ⚠️ Set এ s.lower_bound() use করুন (বেশি fast)
    //    lower_bound(s.begin()...) use করবেন না!

    set<int> s = {1, 3, 5, 7, 9};

    auto lb5 = s.lower_bound(4); // 4 এর >= প্রথম value
    auto ub5 = s.upper_bound(5); // 5 এর > প্রথম value

    cout << "\n=== Set ===" << endl;
    cout << "Lower Bound of 4: " << *lb5 << endl; // 5
    cout << "Upper Bound of 5: " << *ub5 << endl; // 7


    // ============================================================
    // 7. COMMON TRICKS
    // ============================================================

    vector<int> v5 = {1, 3, 5, 7, 9};

    // Trick 1: Index বের করা
    int idx = lower_bound(v5.begin(), v5.end(), 5) - v5.begin();
    cout << "\n=== Tricks ===" << endl;
    cout << "Index of 5: " << idx << endl; // 2

    // Trick 2: Value exist করে কিনা check
    auto it = lower_bound(v5.begin(), v5.end(), 5);
    if (it != v5.end() && *it == 5) {
        cout << "5 আছে!" << endl;
    }

    // Trick 3: x এর <= সবচেয়ে বড় value বের করা
    auto it2 = upper_bound(v5.begin(), v5.end(), 6);
    --it2; // এক পিছনে যান
    cout << "6 এর <= সবচেয়ে বড়: " << *it2 << endl; // 5


    // ============================================================
    // QUICK SUMMARY TABLE
    // ============================================================
    //
    //  | Condition     | Lower Bound       | Upper Bound        |
    //  |---------------|-------------------|--------------------|
    //  | Value আছে     | Value এর শুরু     | Value এর শেষের পরে|
    //  | Value নেই     | পরের বড় number   | পরের বড় number    |
    //  | lb == ub      | Value নেই array তে                    |
    //
    // ============================================================

    return 0;
}
