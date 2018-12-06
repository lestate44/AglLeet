#ifndef Leet_h
#define Leet_h
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

#pragma region class test
class test
{
public:
	int plus();
};
#pragma endregion

#pragma region ListNode Struct
struct ListNode
{
	int val;
	ListNode* next;
	ListNode* end;
	ListNode(const int& x) :val(x), next(NULL), end(this) {};
	void add(const int& x);
	void display();

};
#pragma endregion

#pragma region TreeNode Struct
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#pragma endregion

#pragma region TreeLinkNode
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {};
};
#pragma endregion

#pragma region Interval Struct
struct Interval
{
	int start;
	int end;
	Interval() :start(0), end(0) {};
	Interval(int s, int e) :start(s), end(e) {};
};

#pragma endregion


#pragma region 1 Two Sum
vector<int> twosum(vector<int>& nums, int target);
vector<int> twosummap(vector<int>& nums, int target);
#pragma endregion

#pragma region 2 Add Two Numbers
//2. Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode* addTwoNumbersShort(ListNode* l1, ListNode* l2);
ListNode* addTwoNumberRe(ListNode* l1, ListNode* l2);
void addTwoNumberRecursion(ListNode* l1, ListNode* l2);
#pragma endregion

#pragma region 461 Haming Distance
int hammingDistance(int x, int y);
#pragma endregion

#pragma region 3 Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s);
int lengthOfLongestSubStringSS(string s);
#pragma endregion

#pragma region 4 Median of Two Sorted Arrays
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
double findK(vector<int>& a, int alen, int as, vector<int>& b, int blen, int bs, int k);
double findMedian(vector<int>& nums1, vector<int>& nums2);
#pragma endregion

#pragma region 5 Longest Palindromic Substring
string longestPalindrome(string s);
string manacher(string s);
#pragma endregion

#pragma region 7 Reverse Integer
int reversestr(int x);
int reverse(int x);
#pragma endregion

#pragma region 8 String to Integer (atoi)
int myAtoi(string str);
#pragma endregion

#pragma region 11 Container With Most Water
int maxArea(vector<int>& height);
#pragma endregion

#pragma region 13 Roman to Integer
int romanToInt(string s);
int getvalue(char i);
#pragma endregion

#pragma region 14 Longest Common Prefix
string longestCommonPrefix(vector<string>& strs);
#pragma endregion

#pragma region 17 Letter Combinations of a Phone Number
vector<string> letterCombinations(string digits);
vector<string> letterCombinationsRe(string digits);
void dfs(string digits, int level, string out, vector<string> map, vector<string> &result);
#pragma endregion

#pragma region 15 3Sum
vector<vector<int>> threesum(vector<int>& nums);
#pragma endregion

#pragma region 19 Remove Nth Node From End of List
ListNode* removeNthFromEnd(ListNode* head, int n);
ListNode* removeNthFromEndOP(ListNode* head, int n);
#pragma endregion

#pragma region 20 Valid Parentheses
bool isValid(string s);
bool match(char left, char right);
#pragma endregion

#pragma region 21 Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
#pragma endregion

#pragma region 22 Generate Parentheses
vector<string> generateParenthesis(int n);
void backtrack(vector<string>& ans, string cur, int open, int close, int max);
#pragma endregion

#pragma region 26 Remove Duplicates from Sorted Array
int removeDuplicates(vector<int>& nums);
void it(vector<int>& nums, int start);
#pragma endregion

#pragma region 28 Implement strStr()
int strStr(string haystack, string needle);
#pragma endregion

#pragma region 29 Divide Two Integers
int divide(int dividend, int divisor);
#pragma endregion

#pragma region 69 Sqrt(x)
int sqrt(int x);
#pragma endregion

#pragma region 50 Pow(x, n)
double myPow(double x, int n);
#pragma endregion

#pragma region 38. Count and Say
string countAndSay(int n);
#pragma endregion

#pragma region 33. Search in Rotated Sorted Array
int search(vector<int>& nums, int target);
#pragma endregion

#pragma region 34. Search for a Range
vector<int> searchRange(vector<int>& nums, int target);
#pragma endregion

#pragma region 36. Valid Sudoku
bool isValidSudoku(vector<vector<char>>& board);
#pragma endregion

#pragma region 10. Regular Expression Matching
bool isMatch(string s, string p);
bool isMatchdp(string s, string p);
#pragma endregion

#pragma region fb contiguous sum
vector<int> consum(vector<int> nums, int target);
#pragma endregion

#pragma region 44. Wildcard Matching
bool isMatchwl(string s, string p);
bool isMatchwldp(string s, string p);
//bool ismatchmain(string s, string p);
#pragma endregion

#pragma region 41. First Missing Positive
int firstMissingPositive(vector<int>& nums);
#pragma endregion

#pragma region 53. Maximum Subarray
int maxSubArray(vector<int>& nums);
#pragma endregion

#pragma region 66. Plus One
vector<int> plusOne(vector<int>& digits);
#pragma endregion

#pragma region 287. Find the Duplicate Number
int findDuplicate(vector<int>& nums);
#pragma endregion

#pragma region 268. Missing Number
int missingNumber(vector<int>& nums);
#pragma endregion

#pragma region 136. Single Number
int singleNumber(vector<int>& nums);
#pragma endregion

#pragma region 141. Linked List Cycle
bool hasCycle(ListNode *head);
bool hasCycleOn(ListNode *head);
#pragma endregion

#pragma region 142. Linked List Cycle II
ListNode *detectCycle(ListNode *head);
#pragma endregion

#pragma region 48. Rotate Image
void rotate(vector<vector<int>>& matrix);
#pragma endregion

#pragma region 55. Jump Game
bool canJump(vector<int>& nums);
bool canJumpdp(vector<int>& nums);
#pragma endregion

#pragma region 70. Climbing Stairs
int climbStairs(int n);
#pragma endregion

#pragma region 49. Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs);
#pragma endregion

#pragma region 242. Valid Anagram
bool isAnagram(string s, string t);
bool isAnagramHash(string s, string t);
#pragma endregion

#pragma region 438. Find All Anagrams in a String
vector<int> findAnagrams(string s, string p);
#pragma endregion

#pragma region 104. Maximum Depth of Binary Tree
int maxDepth(TreeNode* root);
#pragma endregion

#pragma region DP Gold
int getMostGoldIt(int n, int w, vector<int> g, vector<int> p);
int getMostGoldDP(int n, int w, vector<int> g, vector<int> p);
#pragma endregion

#pragma region Serling Cut DP
int cutrecu(vector<int> len, vector<int> price, int l);
int cutrecusive(vector<int> price, int n);
int cutdp(vector<int> price, int n);
#pragma endregion

#pragma region 56. Merge Intervals
void intervalsort(vector<Interval>& intervals, int start, int end);
vector<Interval> merge(vector<Interval>& intervals);
#pragma endregion

#pragma region 88. Merge Sorted Array
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
#pragma endregion

#pragma region 75. Sort Colors
void sortcolors(vector<int>& nums);
#pragma endregion

#pragma region 79. Word Search
bool verify(vector<vector<char>>&board, string word, int i, int j, int index);
bool exist(vector<vector<char>>& board, string word);
#pragma endregion

#pragma region 78. Subsets
vector<vector<int>> subsets(vector<int>& nums);
vector<vector<int>> subsetsbck(vector<int>& nums);
#pragma endregion

#pragma region 90. Subsets II
vector<vector<int>> subsetsWithDup(vector<int>& nums);
#pragma endregion

#pragma region 46. Permutations
vector<vector<int>> permute(vector<int>& nums);
vector<vector<int>> permuteswap(vector<int>& nums);
#pragma endregion

#pragma region 47. Permutations II
vector<vector<int>> permuteUnique(vector<int>& nums);
#pragma endregion

#pragma region 62. Unique Paths
int uniquePaths(int m, int n);
#pragma endregion

#pragma region 31. Next Permutation
void nextPermutation(vector<int>& nums);
#pragma endregion

#pragma region 94. Binary Tree Inorder Traversal
vector<int> inorderTraversal(TreeNode* root);
void recur(TreeNode* root, vector<int>& result);
void inter(TreeNode* root, vector<int>& result);
#pragma endregion

#pragma region 39. Combination Sum
vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void combin(vector<int>& candidates, vector<vector<int>>& result, vector<int>& temp, int target,int begin);
#pragma endregion

#pragma region 91. Decode Ways
int numDecodings(string s);
string its(int i);
int sti(string s);
void numd(string s, int& result);
#pragma endregion

#pragma region 121. Best Time to Buy and Sell Stock
int maxProfit(vector<int>& prices);
#pragma endregion

#pragma region 122. Best Time to Buy and Sell Stock II
int maxProfitII(vector<int>& prices);
#pragma endregion

#pragma region 102. Binary Tree Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root);
#pragma endregion

#pragma region 103. Binary Tree Zigzag Level Order Traversal
vector<vector<int>> zigzagLevelOrder(TreeNode* root);
#pragma endregion

#pragma region 127. Word Ladder
int ladderLength(string beginWord, string endWord, vector<string>& wordList);
bool compare(string a, string b);
void addnext(string word, queue<string>& tovisit, unordered_set<string>& wordDict);
#pragma endregion

#pragma region 105. Construct Binary Tree from Preorder and Inorder Traversal
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& mid, int start, int end);
#pragma endregion

#pragma region 116. Populating Next Right Pointers in Each Node
void connect(TreeLinkNode *root);
#pragma endregion

#pragma region 42. Trapping Rain Water
int trap(vector<int>& height);
#pragma endregion

#pragma region 101. Symmetric Tree
bool isSymmetric(TreeNode* root);
bool ismirror(TreeNode* root1, TreeNode* root2);
#pragma endregion

#pragma region 111. Minimum Depth of Binary Tree
int minDepth(TreeNode* root);
#pragma endregion

#pragma region 110. Balanced Binary Tree
int depth(TreeNode* root);
bool isBalanced(TreeNode* root);
#pragma endregion

#pragma region 125. Valid Palindrome
bool isPalindrome(string s);
#pragma endregion

#pragma region 219. Contains Duplicate II
bool containsNearbyDuplicate(vector<int>& nums, int k);
#pragma endregion



#endif