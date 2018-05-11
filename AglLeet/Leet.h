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











#endif