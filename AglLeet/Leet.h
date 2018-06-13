#ifndef Leet_h
#define Leet_h
#include <vector>

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

#pragma region TreeNode
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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




#pragma region 46. Permutations
vector<vector<int>> permute(vector<int>& nums);
#pragma endregion














#endif