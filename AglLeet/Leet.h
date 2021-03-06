#ifndef Leet_h
#define Leet_h
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


#pragma region unionfind
class unionfind
{
	vector<int> root;
	vector<int> rank;

public:
	unionfind(int s) :root(s+1),rank(s+1)
	{
		for (int i=0;i<root.size();i++)
		{
			root[i] = i;
			rank[i] = 0;
		}

	}
	int rootf(int i)
	{
		while (i != root[i])
		{
			root[i] = root[root[i]];
			i = root[i];
		}
		return i;
	}
	int fr(int j)
	{
		int i = j;
		while (i != root[i])
			i = root[i];
		compression(i, j);
		return i;
	}
	void compression(int r, int i)
	{
		while (i != root[i])
		{
			root[root[i]] = r;
			i = root[i];

		}
	}
	int find(int f)
	{
		if (f != root[f])
			root[f] = find(root[f]);
		return root[f];
	}
	void us(int a, int b)
	{
		root[b] = a;

	}
	bool unionset(int a, int b)
	{
		int ra = find(a), rb = find(b);
		if (ra == rb)
			return false;

		if (rank[ra] > rank[rb])
			root[rb] = ra;
		else if (rank[ra] < rank[rb])
			root[ra] = rb;
		else
		{
			root[ra] = rb;
			rank[rb]++;
		}
		return true;
	}
	void print()
	{
		for (int i=0;i< root.size();i++)
			cout << i << ",";
		cout << endl;
		for (auto i : root)
			cout << i << ",";
		
	}



};
#pragma endregion



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

#pragma region struct point
struct point
{
	int x;
	int y;
	point(int x, int y) :x(x), y(y) {};
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
vector<vector<int>> permuteiterate(vector<int>& nums);
#pragma endregion

#pragma region 47. Permutations II
vector<vector<int>> permuteUnique(vector<int>& nums);
#pragma endregion

#pragma region 62. Unique Paths
int uniquePaths(int m, int n);
#pragma endregion

#pragma region 31. Next Permutation
void nextPermutation(vector<int>& nums);
void nextPermutation1(vector<int>& nums);
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

#pragma region 108. Convert Sorted Array to Binary Search Tree
TreeNode* sortedArrayToBST(vector<int>& nums);
TreeNode* sortedArrayToBSThelper(vector<int>& nums, int start, int end);
#pragma endregion

#pragma region 344. Reverse String
string reverseString(string s);
#pragma endregion

#pragma region 412. Fizz Buzz
vector<string> fizzBuzz(int n);
#pragma endregion

#pragma region 283. Move Zeroes
void moveZeroes(vector<int>& nums);
#pragma endregion

#pragma region 371. Sum of Two Integers
int getSum(int a, int b);
#pragma endregion

#pragma region 206. Reverse Linked List
ListNode* reverseList(ListNode* head);
#pragma endregion

#pragma region 237. Delete Node in a Linked List
void deleteNode(ListNode* node);
#pragma endregion

#pragma region 171. Excel Sheet Column Number
int titleToNumber(string s);
#pragma endregion

#pragma region 169. Majority Element
int majorityElement(vector<int>& nums);
int maj(vector<int> &nums, int left, int right);
#pragma endregion

#pragma region 387. First Unique Character in a String
int firstUniqChar(string s);
#pragma endregion

#pragma region 217. Contains Duplicate
bool containsDuplicate(vector<int>& nums);
#pragma endregion

#pragma region 350. Intersection of Two Arrays II
vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
#pragma endregion

#pragma region 202. Happy Number
bool isHappy(int n);
#pragma endregion

#pragma region 118. Pascal Triangle
vector<vector<int>> generate(int numRows);
#pragma endregion

#pragma region 326. Power of Three
bool isPowerOfThree(int n);
#pragma endregion

#pragma region 191. Number of 1 Bits
int hammingWeight(uint32_t n);
#pragma endregion

#pragma region 198. House Robber
int rob(vector<int>& nums);
#pragma endregion

#pragma region 172. Factorial Trailing Zeroes
int trailingZeroes(int n);
#pragma endregion

#pragma region 234. Palindrome Linked List
bool isPalindrome(ListNode* head);
#pragma endregion

#pragma region 190. Reverse Bits
uint32_t reverseBits(uint32_t n);
#pragma endregion

#pragma region 189. Rotate Array
void rotate(vector<int>& nums, int k);
#pragma endregion

#pragma region 204. Count Primes
int countPrimes(int n);
#pragma endregion

#pragma region 347. Top K Frequent Elements
vector<int> topKFrequent(vector<int>& nums, int k);
#pragma endregion

#pragma region 454. 4Sum II
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);
#pragma endregion

#pragma region 230. Kth Smallest Element in a BST
int kthSmallest(TreeNode* root, int k);
#pragma endregion

#pragma region 378. Kth Smallest Element in a Sorted Matrix
int kthSmallest(vector<vector<int>>& matrix, int k);
#pragma endregion

#pragma region Merge two sorted linked lists
ListNode* mergeListsRE(ListNode* head1, ListNode* head2);
ListNode* mergeListsIT(ListNode* head1, ListNode* head2);
#pragma endregion

#pragma region 165. Compare Version Numbers
int compareVersion(string version1, string version2);
#pragma endregion

#pragma region 328. Odd Even Linked List
ListNode* oddEvenList(ListNode* head);
#pragma endregion

#pragma region Maximum Minimum Path
int mmpath(vector<vector<int>> matrix);
#pragma endregion

#pragma region amword
vector<string> amword(string s,int k);
#pragma endregion

#pragma region ammaze
int ammaze(vector<vector<int>> maze);
#pragma endregion

#pragma region amkp
vector<point> amkp(vector<point> points, point origin, int k);
#pragma endregion

#pragma region 72. Edit Distance
int minDistance(string word1, string word2);
#pragma endregion

#pragma region queensr
void queensr(int (&a)[8][8], int &count,int row);
bool check(const int(&a)[8][8], int x, int y);
void queendisplay(const int(&a)[8][8]);
#pragma endregion

#pragma region longestpalindromedp
string lpdp(string s);
#pragma endregion

#pragma region 98. Validate Binary Search Tree
bool isValidBST(TreeNode* root);
void bsthelper(TreeNode* root, vector<int>& v);
bool isValidBSTW(TreeNode* root);
#pragma endregion

#pragma region 130.Surrounded Region
void solve(vector<vector<char>>& board);
void display(vector<vector<char>>& board);
void update(vector<vector<char>>& board, int i, int j);
#pragma endregion

#pragma region 131. Palindrome Partitioning
vector<vector<string>> partition(string s);
vector<vector<string>> partition2(string& s);
void partition2(vector<vector<string>>& result, vector<string> par, string& s, int start);
bool ispal(string& s, int l, int r);
void partition(vector<vector<string>>& result, vector<string>part, string& s, int start);
#pragma endregion

#pragma region 134. Gas Station
int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
#pragma endregion

#pragma region 139. Word Break
bool wordbreak(string s, vector<string>& wordDict);
bool wordbreakbf(string s, vector<string>& wordDict);
bool wordbreakbfhelper(string s, unordered_set<string>& wordDict);
bool wordbreakbfs(string s, vector<string>& wordDict);
#pragma endregion

#pragma region 148. Sort List
ListNode* sortList(ListNode* head);
ListNode* merge(ListNode* left, ListNode* right);
#pragma endregion

#pragma region 150. Evaluate Reverse Polish Notation
int evalRPN(vector<string>& tokens);
bool checknum(string s);
int stoint(string s);
#pragma endregion

#pragma region 152. Maximum Product Subarray
int maxProduct(vector<int>& nums);
#pragma endregion

#pragma region 162. Find Peak Element
int findPeakElement(vector<int>& nums);
#pragma endregion

#pragma region 200. Number of Islands
int numIslands(vector<vector<char>>& grid);
void DFS(vector<vector<char>>& grid, int x, int y);
#pragma endregion

#pragma region 179. Largest Number
string largestNumber(vector<int>& nums);
#pragma endregion

#pragma region 207. Course Schedule
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
bool canFinishdfs(int numCourses, vector<pair<int, int>>& prerequisites);
bool cycledfs(vector<unordered_set<int>>& matrix, int& node, vector<bool>& visited,vector<bool>& onpath);
#pragma endregion

#pragma region 210. Course Schedule II
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites);
#pragma endregion

#pragma region 227. Basic Calculator II
int calculate(string s);
#pragma endregion

#pragma region 236. Lowest Common Ancestor of a Binary Tree
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
#pragma endregion

#pragma region 279. Perfect Squares
int numSquares(int n);
int numSquaresbfs(int n);
#pragma endregion

#pragma region 300. Longest Increasing Subsequence
int lengthOfLIS(vector<int>& nums);
#pragma endregion

#pragma region 322. Coin Change
int coinChange(vector<int>& coins, int amount);
#pragma endregion

#pragma region 324. Wiggle Sort II
void wiggleSort(vector<int>& nums);
#pragma endregion

#pragma region 334. Increasing Triplet Subsequence
bool increasingTriplet(vector<int>& nums);
#pragma endregion

#pragma region shortest distance
int shortestdistance(vector<string>& words, string word1, string word2);
#pragma endregion

#pragma region 43. Multiply Strings
string multiply(string num1, string num2);
#pragma endregion

#pragma region 6. ZigZag Conversion
string convert(string s, int numRows);
#pragma endregion

#pragma region 67. Add Binary
string addBinary(string a, string b);
#pragma endregion

#pragma region 60. Permutation Sequence
string getPermutation(int n, int k);
#pragma endregion

#pragma region 40. Combination Sum II
vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
void combinationSum2helper(vector<vector<int>>& result, vector<int>& candidates, int target, int index, vector<int>& temp);
#pragma endregion

#pragma region 24. Swap Nodes in Pairs
ListNode* swapPairs(ListNode* head);
#pragma endregion

#pragma region 16. 3Sum Closest
int threeSumClosest(vector<int>& nums, int target);
#pragma endregion

#pragma region 12. Integer to Roman
string intToRoman(int num);
#pragma endregion

#pragma region 61. Rotate List
ListNode* rotateRight(ListNode* head, int k);
#pragma endregion

#pragma region 74. Search a 2D Matrix
bool searchMatrix2(vector<vector<int>>& matrix, int target);
#pragma endregion

#pragma region 77. Combinations
vector<vector<int>> combine(int n, int k);
void combinhelp(vector<vector<int>>& result, vector<int>& temp, int index, vector<int>& cand, int& k);
#pragma endregion

#pragma region 71. Simplify Path
string simplifyPath(string path);
#pragma endregion


#pragma region 59. Spiral Matrix II
vector<vector<int>> generateMatrix2(int n);
#pragma endregion

#pragma region 54. Spiral Matrix
vector<int> spiralOrder(vector<vector<int>>& matrix);
#pragma endregion

#pragma region 119. Pascal   
vector<int> getRow(int rowIndex);
#pragma endregion

#pragma region xiaoxiaole
string xiaoxiaole(string s);
#pragma endregion






#endif