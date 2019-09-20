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
#include "tt.h"
#include <set>
#include <sstream>
#include <map>
#include <stack>


const double PI = 3.14159;




class Shapes   //抽象类
{
protected:
	int x, y;
public:
	void setvalue(int d, int w = 0) { x = d; y = w; }
	virtual void disp() = 0;//纯虚函数
	void dispx()
	{
		cout << x;
	}
};

class Square :public Shapes
{
public:
	Square() = default;
	Square(int a, int b)
	{
		x = a;
		y = b;
	}
	void dispx() 
	{
		cout << x << y << endl;
	}
	void disp() {
		cout << "矩形面积:" << x * y << endl;
	}
};

class Circle :public Shapes {
public:
	void disp() {
		cout << "圆面积:" << PI * x*x << endl;
	}
};


struct Base {
	virtual void print(int x = 1) {
		std::cout << "Base:" << x;
	}

};

struct Derived : Base {
	virtual void print(int x = 2) {
		std::cout << "Derived:" << x;
	}

};

int findMinGates(vector<int> arrivals, vector<int> departures, int flights) {
	sort(arrivals.begin(), arrivals.end());
	sort(departures.begin(), departures.end());
	//initialize current port and result;
	int curr = 0, result = 0;
	//initialize index for both vectors;
	for (int i = 0, j = 0; i < flights;)
	{
		if (arrivals[i] < departures[j])
		{
			curr ++ ;
			result = max(curr, result);
			i++;
		}
		else
		{
			curr--;
			j++;
		}
	}
	return result;

}

int findmaxave(vector<vector<string>> scores)
{
	unordered_map<string, vector<int>> mapping;
	int result = INT_MIN;
	for (int i = 0; i < scores.size(); i++)
	{
		if (mapping.find(scores[i][0]) == mapping.end())
		{
			vector<int> temp;
			temp.push_back(stoi(scores[i][1]));
			temp.push_back(1);
			mapping.insert(make_pair(scores[i][0], temp));
		}
		else
		{
			mapping[scores[i][0]][0] += stoi(scores[i][1]);
			mapping[scores[i][0]][1]++;
		}
	}
	for (auto i : mapping)
	{
		result = max(result, i.second[0] / i.second[1]);
	}
	return result;
}

void swap2(int *p, int *q)
{
     int temp;
     temp = *p;
	 * p = *q;
	 * q = temp;
}

void swap3(int *p, int *q)
{
    int *temp;
    temp = p;
    p = q;
    q = temp;
}

using namespace std;
class tr
{
public:
	void see()
	{
		cout << "see";
	}
};
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

auto func(int i) ->int
{
	return i;
}

int compress(vector<char>& chars) {
	int l = 0, i = 0;
	for (int j = 0; j<chars.size(); j++)
	{
		if (j + 1 == chars.size() || chars[j + 1] != chars[j])
		{
			chars[l++] = chars[j];
			if (i<j)
			{
				for (auto c : to_string(j - i + 1))
					chars[l++] = c;
			}
			i = j + 1;
		}
	}
	return l;

}

string reverseString1(string s) {
	for (int i = 0; i<s.size() / 2; i++)
	{
		char temp = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = temp;
	}
	return s;
}

int testr(int a)
{	
	
	int b = 3;
	return a = b;
}

int sum(int&i, int&j)
{
	return i + j;
}

class TrieNode {
public:
	bool word;
	TrieNode* children[26];
	TrieNode() {
		word = false;
		memset(children, NULL, sizeof(children));
	}
};


class node
{
public:
	node * next[26];
	bool hasword;
	node() {
		hasword = false;
		for (auto &a : next)
			a = NULL;
	};

};
class WordDictionary {

public:
	/** Initialize your data structure here. */
	WordDictionary() {

	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		node* temp = root;
		for (char c : word)
		{
			if (!temp->next[c - 'a'])
			{
				temp->next[c - 'a'] = new node();
			}
			temp = temp->next[c - 'a'];
			cout << c - 'a' << "add" << endl;
		}
		temp->hasword = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		node* temp = root;
		return searchdfs(word, temp,0);
	}
private:
	node * root = new node();
	bool searchdfs(const string& s, node* n, int start)
	{
		for (int i = start; n&&i<s.size(); i++)
		{
			if (s[i] != '.')
			{
				n = n->next[s[i] - 'a'];
				cout << s[i] - 'a' << endl;
			}
			else
			{
				node* tmp = n;
				for (int j = 0; j<26; j++)
				{
					n = tmp->next[j];
					if (n&&searchdfs(s, n, i + 1))
					{
						cout << j << endl;
						return true;
					}

				}
			}
		}
		return n && n->hasword;
	}
	bool search(const char* word, node* tnode) {
		for (int i = 0; word[i] && tnode; i++) {
			if (word[i] != '.') {
				tnode = tnode->next[word[i] - 'a'];
			}
			else {
				node* tmp = tnode;
				for (int j = 0; j < 26; j++) {
					tnode = tmp->next[j];
					if (search(word + i + 1, tnode)) {
						cout << j;
						return true;
					}
				}
			}
		}
		return tnode && tnode->hasword;
	}





};

ListNode* recurr(ListNode* head)
{
	if (!head)
		return NULL;
	ListNode* pre = head;
	ListNode* cur = head->next;
	if (!cur||!cur->next)
		return head;
	while (cur->next)
	{
		pre = pre->next;
		cur = cur->next;
	}
	ListNode* temp = head->next;
	pre->next = NULL;
	head->next = cur;
	head->next->next = recurr(temp);
	return head;
}
void recorderList(ListNode* head)
{
	recurr(head);
}

vector<string> getsingle(string a, string b)
{
	string z = "abc def hij";
	stringstream  ss(z);
	vector<string> result;
	string temp;
	while (ss>>temp)
	{

		result.push_back(temp);
	}
	return result;
}
int numMatchingSubseq(string S, vector<string>& words) {
	vector<pair<int, int>> sall[128];
	
	vector<vector<pair<int, int>>> all(128,vector<pair<int,int>>());
	auto z = all[0];
	int res = 0, n = words.size();
	for (int i = 0; i < n; i++) {
		all[words[i][0]].emplace_back(i, 1);
	}
	for (char c : S) {
		auto vect = all[c];
		all[c].clear();
		for (auto it : vect) {
			if (it.second == words[it.first].size()) ++res;
			else all[words[it.first][it.second++]].push_back(it);
		}
	}
	return res;
}

int main()
{
	cout << "hello";
	//vector<vector<bool>> matrix(1000, vector<bool>(1001, false));
	//cout << matrix[0][0];
	//char a = 'a';
	//int b = a;
	//cout << b;

	//string a = "cadddaaccz";
	//cout << xiaoxiaole(a);





	//char a = 'f';
	//int b = a - 'a';
	//cout << b;



	//string S = "abcde";
	//vector<string>words = { "a", "bb", "acd", "ace" };
	//cout<<numMatchingSubseq(S,words);

	//string a = "ab ";
	//string b = "d";
	//stringstream ss(a);
	//string temp;
	//while (ss>>temp)
	//{
	//	
	//	cout << temp << endl;
	//}


	//vector<string> result = getsingle(a, b);
	//for (auto &i : result)
	//	cout << i;
	//cout << result.size();


	//printf("1/2= %f", (float)(1 / 2));
	//char c = 255;
	//if (c > 10)
	//	cout << c;
	//ListNode* a = new ListNode(1);
	//a->add(2);
	//a->add(3);
	//a->add(4);
	//a->add(5);
	//a->add(6);

	//a->display();
	//recorderList(a);
	//a->display();
	//int a = 3;
	//int b = 4;
	//int c = 5;

	//int* pa = &a;
	//int* pb = &b;
	//int* pc = &c;
	//pa = pb;
	//*pa = 9;
	//cout << *pb;



	//TreeNode* t1 = new TreeNode(1);
	//TreeNode* t2 = new TreeNode(2);
	//TreeNode* t3 = t1;
	//t3->left = t2;
	//cout << t1->left->val;

	//string a = "abcc";
	//string b = "abc";
	//cout << (a > b);
	//reversestr(88);
	//WordDictionary ss;
	//ss.addWord("aaa");
	//ss.search("a.");

	//int a = 65;
	//char b = char(a);
	//cout << b;

	//char a = 'a';
	//int s = int(a);
	//cout << s;

	//unionfind uf(5);
	//uf.us(1, 2);
	//uf.us(2, 3);
	//uf.us(3, 4);
	//uf.us(4, 5);
	////uf.unionset(1, 2);
	////uf.unionset(2, 3);
	////uf.unionset(3, 4);
	////uf.unionset(4, 5);
	//
	//uf.print();
	//cout << endl;
	//cout << uf.rootf(5) << endl;
	//uf.print();
	//cout << endl;
	//uf.rootf(5);
	//uf.print();










	//cout << numSquaresbfs(12);


	//Shapes *ptr[2]; //定义对象指针数组
	//Square s1(4,5);
	//Shapes* sp1 = &s1;
	//sp1->dispx();
	//Circle c1;
	//ptr[0] = &s1;
	////ptr[0]->setvalue(10, 5);
	//ptr[0]->disp();
	//ptr[1] = &c1;
	//ptr[1]->setvalue(10);
	//ptr[1]->disp();
	//return 0;


	//cout << sum(1, 2);
	
	//string test = "/.//c";
	//cout << simplifyPath(test);
	

	//ListNode a(1);
	//ListNode b(2);
	//ListNode c(3);
	//ListNode d(4);
	//ListNode e(5);
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;
	//ListNode* node = &a;
	//ListNode* test = rotateRight(node,2);


	//vector<vector<string>> test{ {"abc","19"},{"bcd","14"},{"abc","59"} };
	//cout << findmaxave(test);

	//cout.precision(4);
	//cout << fixed;

	//test tt;
	//cout << tt.plus();
	//tr see;
	//see.see();
	


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

	//DP Gold
	//vector<int> g = { 400,500,200,300,250 };
	//vector<int> p = { 5,5,3,4,3 };
	//int n = 5;
	//int w = 10;
	//int z = getMostGoldIt(n, w, g, p);
	//int k = getMostGoldDP(n, w, g, p);
	//cout << z<<"sss"<<k;
	
	//Serling Cut DP
	//vector<int> length{ 1,2,3,4,5,6,7,8,9,10 };
	//vector<int> price{ 1,5,8,9,10,17,17,20,24,30 };
	//int re = cutdp(price, 5);
	//cout << re;

	//56. Merge Intervals
	//Interval a(1, 4), b(1, 5), c(8, 10), d(15, 18);
	//vector<Interval> intervals{ a,b };
	//intervalsort(intervals,0,3);
	//for (auto i : intervals)
	//	cout << i.start << endl;
	//vector<Interval> result = merge(intervals);
	//cout << result[0].end;
	
	// 88. Merge Sorted Array
	//vector<int> nums1{1};
	//int m = 1, n = 0;
	//vector<int> nums2{};
	//merge(nums1, m, nums2, n);

	//79. Word Search
	//vector<vector<char>> board{ {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	//string word{ "ABCCED" };
	//cout << exist(board, word);

	//78. Subsets
	//vector<int> nums{ 1,2,3 };
	//vector<vector<int>> result = subsetsbck(nums);
	//for (int i = 0; i < result.size(); i++)
	//{
	//	for (auto j : result[i])
	//		cout << j<<" ";
	//	cout << endl;
	//}

	//90. Subsets II
	//vector<int> nums{ 1,2,2,3,4 };
	//vector<vector<int>> result = subsetsWithDup(nums);
	//for (int i = 0; i < result.size(); i++)
	//{
	//	for (auto j : result[i])
	//		cout << j<<" ";
	//	cout << endl;
	//}

	// 46. Permutations
	//vector<int> nums{ 4,3,2,1 };
	//vector<vector<int>> result = permute(nums);
	//for (int i = 0; i < result.size(); i++)
	//{
	//	for (auto j : result[i])
	//		cout << j << " ";
	//	cout << endl;
	//}

	//47. Permutations II
	//vector<int> nums{ 1,2,2,3 };
	//vector<vector<int>> result = permuteUnique(nums);
	//for (int i = 0; i < result.size(); i++)
	//{
	//	for (auto j : result[i])
	//		cout << j << " ";
	//	cout << endl;
	//}

	//62. Unique Paths
	//cout << uniquePaths(10, 10);

	//31. Next Permutation
	//vector<int> ts{ 1,2,6,5,4,3};
	//nextPermutation(ts);
	//for (auto i : ts)
	//	cout << i << endl;

	//39. Combination Sum
	//vector<int> candidate{ 2,3,5 };
	//int target = 8;
	//vector<vector<int>> result = combinationSum(candidate, target);
	//cout << result.size()<<endl;
	//for (auto i : result)
	//{
	//	for (auto j : i)
	//		cout << j << ",";
	//	cout << endl;
	//}

	//91. Decode Ways
	//string a = "101";
	//cout << numDecodings(a);

	//121. Best Time to Buy and Sell Stock
	//vector<int> stock{ 5,3,5,67,7 };
	//cout << maxProfit(stock);

	//122. Best Time to Buy and Sell Stock II
	//vector<int> stock{ 7,1,5,3,6,4 };
	//cout << maxProfitII(stock);

	//127. Word Ladder
	//string be = "hit", ed = "cog";
	//vector<string> wl{ "hot","dot","dog","lot","log","cog" };
	//cout << ladderLength(be, ed, wl) << endl;
	//cout << wl.size();

	//42. Trapping Rain Water
	//vector<int> test = { 0,1,0,2,10,0,1,3,2,11,2,1 };
	//cout << trap(test);

	//125. Valid Palindrome
	//string s = "A man, a plan, a canal: Panama";
	//cout << isPalindrome(s);
	//
	//
	//
	//reverse(s.begin(), s.end());
	//cout << s;

	//ListNode* head = new ListNode(1);
	//head->add(2);
	//head->add(3);
	//head->add(4);
	//head->add(5);
	//head->display();
	//
	//ListNode* k = reverseList(head);
	//k->display();

	//char a = 'A';
	//int x = (int)a;
	//cout << x;

	//169. Majority Element
	//vector<int> num{ 1, 2, 1 };
	//cout << maj(num,0,2);

	//387. First Unique Character in a String
	//string a = "abc";

	//cout << isHappy(99);
	//int i = 1;
	//i = (i << 1);
	//cout << i;

	//vector<int> s{ 9,1,1,7 };
	//cout << rob(s);
	
	//int t = 1808548329;
	//cout << trailingZeroes(t);
	
	//cout << countPrimes(40);

	//vector<int> a{ 1,2,3 };
	//vector<vector<int>> res = permuteiterate(a);

	//unordered_map<string, int> map;
	//map.insert({ "abc", 31 });
	//cout << map["abc"];
	
	//string a = "1 2 3";
	//istringstream is(a);
	//string aaa,bbb,ccc;
	//is >> aaa;
	//cout << aaa<<endl;
	//is >> bbb;
	//cout << bbb;

	//string a = "0.3", b = "0.1";
	//cout << compareVersion(a, b);
	

	//int a = 1, b = 3;
	//int* ap = &a, *bp = &b;
	//cout << ap << bp << endl;
	//swap3(ap, bp);
	//cout << ap << bp;
	
	//vector<int> arr{  };
	//vector<int> dep{  };
	//cout << findMinGates(arr, dep, 0);



	//Base * B = new Derived;
	//B->print();

	//vector <vector<int>> ma = { {8,4,3,5},{6,5,9,8},{7,2,3,6} };
	//cout << mmpath(ma);

	//string s = "bbvaee";
	//vector<string> re = amword(s, 4);
	//for (auto &i : re)
	//	cout << i << endl;

	//vector<vector<int>> maze = { {1,0,0},{1,1,0},{0,9,1} };
	//cout << ammaze(maze);
	

	//string a = "abcd", b = "acd";
	//cout << minDistance(a, b);

	//int a[8][8];
	//int count = 0, row = 0;
	//queensr(a,count,0);
	//cout << count;

	//cout << lpdp("abbc");

	//TreeNode* root = new TreeNode(5);
	//root->left = new TreeNode(1);
	//root->right = new TreeNode(4);
	//root->right->left = new TreeNode(3);
	//root->right->right = new TreeNode(6);

	//cout << isValidBSTW(root);

	//vector<vector<char>> board{
	//	{'X', 'O', 'X', 'O', 'X', 'O'},
	//	{'O', 'X', 'O', 'X', 'O', 'X'},
	//	{'X', 'O', 'X', 'O', 'X', 'O'},
	//	{'O', 'X', 'O', 'X', 'O', 'X'}};

	//solve(board);

	//string s = "aaabac";
	//vector<vector<string>> result = partition(s);
	//for (auto&i : result)
	//{
	//	for (auto&j : i)
	//		cout << j << " ";
	//	cout << endl;
	//}

	//ListNode a(3);
	//ListNode b(5);
	//ListNode c(1);
	//ListNode d(7);
	//ListNode e(4);
	//a.next = &b;
	//b.next = &c;
	//c.next = &d;
	//d.next = &e;
	//
	//ListNode* x = sortList(&a);
	//
	//x->display();
	

	//vector<int> s{ 4,2,6,33,5,2 };
	//cout << largestNumber(s);

	//int a = 9;
	//cout << testr(a);


	//vector<pair<int, int>> course{ {0,1},{2,1} };
	//int n = 3;
	//vector<int> r=findOrder(n, course);

	//string a = "14-3/2";
	//cout << calculate(a);

	//vector<char> s{ 'a','a','a','a','b' };
	//cout << compress(s);

	//string a = "abc";
	//cout << reverseString1(a);

	//vector<int> t{ 2,3,1,9,7,4,0 };
	//nextPermutation1(t);



	//string num1 = "123", num2 = "43";
	//cout << multiply(num1, num2);

	//string s = "PAYPALISHIRING";
	//cout << convert(s,4);


	//vector<string> test{ "a","b","ac", "banana", "app", "appl", "ap", "apply", "apple" };
	//sort(test.begin(), test.end());
	//for (auto i : test)
	//cout << i<<endl;

//stack<string> st;
//string s;
//st.push(s);
//cout << st.size();
//st.push(s);
//cout << st.size();

//vector<vector<int>> s{ {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//vector<int> r = spiralOrder(s);

//vector<int> s = getRow(2);




}