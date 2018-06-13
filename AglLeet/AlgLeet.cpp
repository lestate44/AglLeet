#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Leet.h"
#include <iomanip>
#include <limits>
#include <conio.h>
#include <unordered_map>
#include <algorithm>
using namespace std;
vector<int> kmpProcess(string& needle) {
	int n = needle.length();
	vector<int> lps(n, 0);
	for (int i = 1, len = 0; i < n; ) {
		if (needle[i] == needle[len])
			lps[i++] = ++len;
		else if (len) len = lps[len - 1];
		else lps[i++] = 0;
	}
	return lps;
}
void ad(int& x)
{
	x = x + 1;
	return;
}


int main()
{
	cout.precision(4);
	cout << fixed;

	//class test
	//cout << test().plus();

	//1. Two Sums
	//vector<int> nums{ 5,3,4,5,1 };
	//vector<int> result = twosummap(nums, 5);
	//for (auto i : result)
	//	cout << "("<<i<<")";

	//2. Add Two Numbers
	//ListNode* l1 = new ListNode(2);
	//ListNode* l2 = new ListNode(5);
	//l1->add(4);
	//l1->add(3);
	//l2->add(6);
	//l2->add(4);
	//l2->add(2);
	//l1->display();
	//l2->display();
	//ListNode* result2 = addTwoNumbersShort(l1, l2);
	//result2->display();
	//ListNode* result = addTwoNumbers(l1, l2);
	//result->display();
	//ListNode* result3 = addTwoNumberRe(l1, l2);
	//result3->display();

	//671 Hamming Distance
	//cout << hammingDistance(2, 3) << endl;

	//3 Longest Substring Without Repeating Characters
	//string s= "abbc";
	//int result1 = lengthOfLongestSubstring(s);
	//int result2 = lengthOfLongestSubStringSS(s);
	//cout << result1 << " " << result2;
	
	//4 Median of Two Sorted Arrays
	//vector<int> nums1 = {1,2 };
	//vector<int> nums2 = {};
	//cout  <<std::setprecision(2)<< findMedian(nums1, nums2);

	// 5 Longest Palindromic Substring
	//string a = "babad";
	//cout << longestPalindrome(a);
	//string a = "abae";
	//cout << manacher(a);

	//7. Reverse Integer
	//int s = 12345678901;
	//cout << reverse(s) << endl;

	//8. String to Integer
	//string str = "   44 best";
	//cout << myAtoi(str);

	//11. Container With Most Water
	//vector<int> test = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	//cout << maxArea(test);
	
	//13. Roman to Integer
	//cout << romanToInt("IaX");

	//14. Longest Common Prefix
	//vector<string> strs{};
	//cout << longestCommonPrefix(strs);

	//17. Letter Combinations of a Phone Number
	//string s = "34";
	//vector<string> v = letterCombinationsRe(s);
	//for (auto i : v)
	//	cout << i << endl;
	
	//15. 3Sum
	//vector<int> nums = {0,0};
	//vector<vector<int>> result = threesum(nums);
	//for (int i = 0; i < result.size(); i++)
	//{
	//	for (int j = 0; j < result[i].size(); j++)
	//		cout << result[i][j]<<" ";
	//	cout << endl;
	//}

	//19.Remove Nth Node From End of List
	//ListNode* a = new ListNode(1);
	//ListNode* b = new ListNode(2);
	//ListNode* c = new ListNode(3);
	//a->next = b;
	//b->next = c;
	//ListNode* result = removeNthFromEndOP(a, 2);
	//result->display();
	
	//20. Valid Parentheses
	//string s = "{}]";
	//cout << isValid(s);

	//21. Merge Two Sorted Lists
	//ListNode *l1 = new ListNode(0);
	//ListNode* l2 = new ListNode(4);
	//l1->add(1);
	//l1->add(3);
	//l1->add(7);
	//l2->add(5);
	//l2->add(9);
	//l2->add(11);
	//ListNode* re = mergeTwoLists(l1, l2);
	//re->display();

	//22. Generate Parentheses
	//vector<string> result = generateParenthesis(3);
		//for (auto i : result)
		//	cout << i << " ";

	//26. Remove Duplicates from Sorted Array
	//vector<int> test{ 0,1,1,2,3,3,4,4,5 };
	//cout<<removeDuplicates(test)<<endl;
	//for (auto i : test)
	//	cout << i << endl;

	//29. Divide Two Integers
	//int a = 2147483647, b = 1;
	//cout << divide(a, b);

	//69. Sqrt(x)
	//cout << sqrt(1);

	//50 Pow(x, n)
	//cout << -4 % 2;

	//38. Count and Say
	//cout << countAndSay(4);

	//33. Search in Rotated Sorted Array
	//vector<int> s = { 4,5,6,7,0,1,2 };
	//int target = 1;
	//cout << search(s, target);

	//34. Search for a Range
	//vector<int> nums{ 5,7,7,8,8,10 };
	//int target = 8;
	//vector<int> result = searchRange(nums, target);
	//cout << result[0] << "," << result[1];

	//36. Valid Sudoku
	//vector<vector<char>> s = {
	//{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
	//{'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
	//{'5', '.', '.', '.', '.', '.', '.', '9', '.'}, 
	//{'.', '.', '.', '5', '6', '.', '.', '.', '.'}, 
	//{'4', '.', '3', '.', '.', '.', '.', '.', '1'}, 
	//{'.', '.', '.', '7', '.', '.', '.', '.', '.'}, 
	//{'.', '.', '.', '5', '.', '.', '.', '.', '.'}, 
	//{'.', '.', '.', '.', '.', '.', '.', '.', '.'}, 
	//{'.', '.', '.', '.', '.', '.', '.', '.', '.'}};

	//10. Regular Expression Matching
	//cout << isMatchdp("aaa", "a*");

	//fb contiguous sum
	//vector<int> nums = {18,1,6,7,2 };
	//int target = 9;
	//vector<int> result = consum(nums, target);
	//for (auto i : result)
	//	cout << i << " ";

	//44. Wildcard Matching
	//string s = "abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb";
	//string p = "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**";
	//cout << isMatchwl(s, p);

	//41. First Missing Positive
	//vector<int> nums{-5,-6,-8,2 };
	//int s = firstMissingPositive(nums);
	//cout << s;

	//53. Maximum Subarray
	//vector<int>  nums{ -2,1,-3,4,-1,2,1,-5,4 };
	//cout << maxSubArray(nums);

	//66. Plus One
	//vector<int> s{ 1,9,9,9 };
	//vector<int> result = plusOne(s);
	//for (auto i : result)
	//cout << i;

	//287. Find the Duplicate Number
	//vector<int> nums{ 2,2,1,3 };
	//cout << findDuplicate(nums);

	//268. Missing Number
	//vector<int> nums{ 3,0,1 };
	//cout << missingNumber(nums);

	//136. Single Number
	//vector<int> nums{ 2,2,3,4,4 };
	//cout << singleNumber(nums);

	// 48. Rotate Image
	//vector<vector<int>> matrix = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
	//int n = matrix.size();
	//rotate(matrix);
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << matrix[i][j]<<" ";
	//	}
	//	cout << endl;
	//}

	// 49. Group Anagrams
	//string s = "cba";
	//sort(s.begin(), s.end());
	//cout << s;

	//438. Find All Anagrams in a String
	//string s = "cbaebabacd", p = "abc";
	//vector<int> result = findAnagrams(s, p);
	//for (auto i : result)
	//cout << i << endl;


	// 46. Permutations






}