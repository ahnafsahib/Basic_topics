parmutation
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
class Solution {

private:
    void f(vector<int> &nums, vector<int> &a, vector<vector<int>> &ans, int freq[]) {
        if(a.size() == nums.size()) {
            for(auto i : a) {
                cout << i << " ";
            }
            cout << endl;
            ans.push_back(a);
            return;
        }

        for(int i = 0; i<nums.size(); i++) {
            if(freq[i] == 0) {
                freq[i] = 1;
                a.push_back(nums[i]);
                f(nums, a, ans, freq);
                a.pop_back();
                freq[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        int freq[nums.size()];
        for(int i = 0; i<nums.size(); i++) {
            freq[i] = 0;
        }
        f(nums, a, ans , freq);
        return ans;
    }
};

palindrom partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]
class Solution {
public:
bool ispalindrom(string &s, int l , int r) {
    while(l <= r) {
        if(s[l++] != s[r--]) {
            return false;
        }
    }
    return true;
}

void f(int idx , vector<vector<string>> &ans, vector<string> &a, string &s,int n) {
    if(idx == n) {
        ans.push_back(a);
        cout << "ans" << endl;
        for(auto i : a) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for(int i = idx; i<n; i++) {
                                                                    cout << "current idx " << idx << endl;
        if(ispalindrom (s, idx, i)) {
            a.push_back(s.substr(idx, i - idx + 1));
                                                                 cout << "call " << i+1 << endl;
            f(i+1, ans, a, s , n);
                                                                cout << "pop " << a.back() << endl;
            a.pop_back();
        }
        else {
            cout << "invalid i & idx " << i << " " <<idx << endl; 
        }
    }
}
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> a;
        int n = s.size();
        f(0, ans, a, s, n);
        return ans;
    }
};

subset II
// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
class Solution {
public:
    void getsubsets(vector<int> &nums, vector<int> &ans,int i, vector<vector<int>>& allsubsets) {
        if(i == nums.size()) {
            allsubsets.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        getsubsets(nums, ans, i+1, allsubsets);
        ans.pop_back();
        int idx = i+1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]) {
            idx++;
        }
        getsubsets(nums, ans, idx, allsubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allsubsets;
        vector<int> ans;
        getsubsets(nums, ans , 0, allsubsets);
        return allsubsets;
    }

};

39. Combination Sum
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []
class Solution {
public:
void fun(int index , int target, vector<int>& candidates, vector<int>& current,vector< vector<int>>& result) {
    if(target == 0) {
        result.push_back(current);
        return;
    }
    if(target < 0 || index >= candidates.size()) {
        return;
    }
    current.push_back(candidates[index]);
    fun(index, target - candidates[index],candidates, current , result);
    current.pop_back();

    fun(index+1, target, candidates, current , result);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        fun(0, target, candidates, current , result);
        return result;
    }
};

40. Combination Sum II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
class Solution {

public:
void fun(int idx , vector<int>& candidates, vector<int>& current, vector<vector<int>>& ans, int target) {
    if(target == 0) {
        ans.push_back(current);
        return;
    }
    if(idx == candidates.size() || target < 0) {
        return;
    } 
    
    current.push_back(candidates[idx]);
    fun(idx + 1, candidates, current , ans , target - candidates[idx]);
    current.pop_back();
    int i = idx + 1;
    while(i < candidates.size() && candidates[i] == candidates[i-1]) {
        i++;
    }
    fun(i , candidates, current, ans , target);

}
public:


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        fun(0, candidates, current , ans , target);
        return ans ;
    }
};

17. Letter Combinations of a Phone Number
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = "2"
// Output: ["a","b","c"]
class Solution {

public: 
    map<char, string> phonemap = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    void fun(int index, string& current, string& digits, vector<string>& result) {
        if(index == digits.length()) {
            result.push_back(current);
            return;
        }
    string letters = phonemap[digits[index]];
    for(auto c : letters) {
        current.push_back(c);
        fun(index + 1, current, digits, result);
        current.pop_back();
    }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string current;
        fun(0, current, digits, result);
        return result;
    }
};

51. N-Queens
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]
 
class Solution {

public:
    void fun(int row, int n , vector<string>&board, vector<vector<string>>& ans, vector<bool>& cols, vector<bool>& maindiag , vector<bool>& antidiag) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int col = 0; col <n; col++) {
            if(!cols[col] && !maindiag[row - col + n] && !antidiag[row + col] ) {
                board[row][col] = 'Q';
            
            cols[col] = true;
            maindiag[row - col + n] = true;
            antidiag[row + col] = true;
            fun(row + 1,n, board, ans , cols, maindiag, antidiag);
            board[row][col] = '.';
            cols[col] = false;
            maindiag[row - col + n] = false;
            antidiag[row + col] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> board(n, string(n, '.'));
       vector<bool> cols(n, false);
       vector<bool> maindiag(2 * n, false);
       vector<bool> antidiag(2 * n, false);
       fun(0 , n , board, ans, cols, maindiag, antidiag);
       return ans;
    }
};

