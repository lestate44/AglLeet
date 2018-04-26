#ifndef Leet_h
#define Leet_h
#include <vector>

using namespace std;

#pragma region problem1 Two Sum
vector<int> twosum(vector<int>& nums, int target);
vector<int> twosummap(vector<int>& nums, int target);
#pragma endregion

#pragma region problem2 Add Two Numbers
//2. Add Two Numbers
struct ListNode
{
	int val;
	ListNode* next;
	ListNode* end;
	ListNode(const int& x) :val(x), next(NULL),end(this) {};
	void add(const int& x);
	void display();

};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode* addTwoNumbersShort(ListNode* l1, ListNode* l2);
ListNode* addTwoNumberRe(ListNode* l1, ListNode* l2);
void addTwoNumberRecursion(ListNode* l1, ListNode* l2);
#pragma endregion

#pragma region Problem 461 Haming Distance
int hammingDistance(int x, int y);
#pragma endregion

#pragma region Problem 3 Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s);
int lengthOfLongestSubStringSS(string s);
#pragma endregion

#pragma region Problem 4 Median of Two Sorted Arrays
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
double findK(vector<int>& a, int alen, int as, vector<int>& b, int blen, int bs, int k);
double findMedian(vector<int>& nums1, vector<int>& nums2);
#pragma endregion

#pragma region 5 Longest Palindromic Substring
string longestPalindrome(string s);
#pragma endregion

#pragma region 7 Reverse Integer
int reversestr(int x);
int reverse(int x);
#pragma endregion

#pragma region 8 String to Integer (atoi)
int myAtoi(string str);
#pragma endregion






#endif