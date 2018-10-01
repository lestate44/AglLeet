#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include "Leet.h"
#include <algorithm>
#include <iomanip>
#include <exception>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

#pragma region class test
int test::plus()
{
	return 0;
}
#pragma endregion

#pragma region ListNode Struct
void ListNode::add(const int& x) {
	this->end->next = new ListNode(x);
	end = end->next;
}

void ListNode::display()
{
	ListNode* temp = this;
	while (temp != NULL)
	{
		cout << "{" << temp->val << "} ";
		temp = temp->next;
	}
	cout << endl;
}
#pragma endregion

#pragma region 1 Two Sum
vector<int> twosum(vector<int>& nums, int target) 
{
	unordered_map<int, int>hash;
	vector<int> result;
	for (int i = 0; i != nums.size(); ++i)
	{	
		if (hash.find(target - nums[i]) != hash.end())
		{
			result.push_back(hash[target - nums[i]]);
			result.push_back(i);
			return result;
		}
		hash[nums[i]] = i;
	}
	return result;

}

vector<int> twosummap(vector<int>& nums, int target)
{
	map<int, int> hash;
	for (int i = 0; i != nums.size(); ++i)
		hash[nums[i]] = i;
	for (int i = 0; i != nums.size(); ++i)
	{
		if (hash.find(target - nums[i]) != hash.end())
			return vector<int>{ i,hash[target - nums[i]] };
	}
}

#pragma endregion

#pragma region 2 Add Two Numbers
//2. Add Two Numbers



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* result = l1;
	while (true)
	{
		int sum = l1->val + l2->val;
		if (sum >= 10)
		{
			if (l1->next == NULL)
				l1->next = new ListNode(0);
			l1->next->val += 1;
			l1->val = sum % 10;
		}
		else
		{
			l1->val = sum;
		}


		if (l1->next == NULL && l2->next == NULL)
		{
			return result;
		}
		else if (l1->next == NULL && l2->next != NULL)
		{
			l1->next = new ListNode(0);

		}
		else if (l1->next != NULL && l2->next == NULL)
		{
			l2->next = new ListNode(0);
		}
		l1 = l1->next;
		l2 = l2->next;


	}


}


ListNode* addTwoNumbersShort(ListNode* l1, ListNode* l2)
{
	ListNode p(0), *pt = &p;
	int extra = 0;
	while (l1 || l2 || extra)
	{
		if (l1)extra += l1->val, l1 = l1->next;
		if (l2)extra += l2->val, l2 = l2->next;
		pt->next = new ListNode(extra % 10);
		extra /= 10;
		pt = pt->next;
	}
	return p.next;
}


void addTwoNumberRecursion(ListNode* l1, ListNode* l2) {
	l1->val += l2->val;
	if (l1->val >= 10)
	{
		if (l1->next == NULL)
			l1->next = new ListNode(0);

		l1->next->val += 1;
		l1->val %= 10;
	}
	if (l1->next == NULL && l2->next == NULL)
		return;
	else if (l1->next == NULL && l2->next != NULL)
		l1->next = new ListNode(0);
	else if (l1->next != NULL && l2->next == NULL)
		l2->next = new ListNode(0);

	addTwoNumberRecursion(l1->next, l2->next);
}


ListNode* addTwoNumberRe(ListNode* l1, ListNode* l2) {
	addTwoNumberRecursion(l1, l2);
	return l1;

}







#pragma endregion

#pragma region 461 Hamming Distance
int hammingDistance(int x, int y)
{
	int z = x ^ y;
	int diff = 0;
	while (z!=0)
	{
		diff += z & 1;
		z >>= 1;
	}
	return diff;
}
#pragma endregion

#pragma region 3 Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s) 
{	
	unordered_map<char, int> hash;
	int max=0,n = 0;
	while (n < s.size()) {

		if (hash.find(s[n]) != hash.end())
		{

			hash.erase(hash.begin(), hash.find(s[n]));
			hash.erase(hash.find(s[n]));

		}
		hash[s[n]] = n;
		if (hash.size() >= max)
			max = hash.size();
		n += 1;

	}


	return max;

}

int lengthOfLongestSubStringSS(string s)
{
	int length, cur = 0;
	string str;
	for (int i = 0; i < s.size(); ++i)
	{
		int pos = str.find(s[i]);
		if (pos != string::npos)
		{
			length = max(length, (int)str.size());
			str.erase(str.begin(), str.begin() + pos + 1);
		}
		str.push_back(s[i]);
	}
	return max(length, (int)str.size());
}
#pragma endregion

#pragma region 4 Median of Two Sorted Arrays
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int lena = nums1.size(), lenb = nums2.size();
	if (!lena && !lenb) return 0;
	if ((lena + lenb) % 2) return findK(nums1, lena, 0, nums2, lenb, 0, (lena + lenb) / 2 + 1);
	else return(findK(nums1, lena, 0, nums2, lenb, 0, (lena + lenb) / 2) + findK(nums1, lena, 0, nums2, lenb, 0, (lena + lenb) / 2 + 1)) / 2.0;
	

}

double findK(vector<int>& a, int alen, int as, vector<int>& b, int blen, int bs, int k)
{
	if (alen > blen)
		return findK(b, blen, bs, a, alen, as, k);
	if (alen == 0)
		return b[bs + k - 1];
	if (k == 1)
		return min(a[as], b[bs]);
	int palen, pblen, mida, midb;
	palen = min(k / 2, alen);
	pblen = k - palen;
	mida = as + palen - 1;
	midb = bs + pblen - 1;
	
	if (a[mida] == b[midb])  return a[mida];
	else if (a[mida] < b[midb]) return findK(a, alen - palen, mida + 1, b, blen, bs, k - palen);
	else return findK(a, alen, as, b, blen - pblen, midb + 1, k - pblen);
}

double findMedian(vector<int>& nums1, vector<int>& nums2)
{
	int len1 = nums1.size(), len2 = nums2.size();
	if (len1 > len2)return findMedian(nums2, nums1);
	int mid = (len1 + len2 + 1) / 2;
	int left = 0, right = len1;
	int i, j;
	while (left <= right)
	{
		i = (left+right)/2, j = mid-i;
		if ( i < len1 && nums1[i] < nums2[j - 1])
		{
			left = i + 1;
		}
		else if (i > 0 && nums2[j] < nums1[i - 1])
		{
			right = i - 1;
		}
		else
		{
			break;
		}
	}
	int result1;
	if (i == 0)
		result1 = nums2[j - 1];
	else if (j == 0)
		result1 = nums1[i - 1];
	else
		result1 = max(nums1[i - 1], nums2[j - 1]);
	if ((len1 + len2) & 1) return result1;
	int result2;
	if (i == len1) result2 = nums2[j];
	else if (j == len2) result2 = nums1[i];
	else
	{
		result2 = min(nums1[i], nums2[j]);
	}
	return (result1 + result2) / 2.0;
}



#pragma endregion

#pragma region 5 Longest Palindromic Substring
string longestPalindrome(string s)
{
	string max = s.substr(0,1);
	int maxlen = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		int left = i, right = i, midl = i, midr = i + 1;
		int len1 = 0, len2 = 0;
		while (left >= 0 && right < s.length() && s[left] == s[right])
		{
			--left;
			++right;
			++len1;
		}
		while (midl >= 0 && midr < s.length() && s[midl] == s[midr])
		{
			--midl;
			++midr;
			++len2;
		}
		if (maxlen < std::max(2*len1-1, 2*len2))
		{
			maxlen = std::max(2 * len1 - 1, 2 * len2);
			len1 > len2 ? max = s.substr(i-len1+1,2*len1-1) : max = s.substr(i-len2+1,2*len2);
		}

	}

	return max;
}

string manacher(string s)
{
	string rs;
	for (int i = 0; i != s.size(); ++i)
	{
		rs += '#';
		rs += s[i];
	}
	rs += '#';
	cout << rs << endl;
	int center = 0, maxlen = 0, bound = 0, maxcen = 0;
	vector<int> ct(rs.size(), 0);

	for (int i = 0; i != rs.size(); ++i)
	{
		int j = 2 * center - i;
		ct[i] = bound > i ? (min(ct[j], bound - i)) : 1;
		cout << bound<<" "<<i << endl;
		while (i - ct[i] >= 0&& i + ct[i]<rs.size()/*&&j>=0&&(ct[j]==bound-i||bound<=i)*/)
		{
			if (rs[i + ct[i]] == rs[i - ct[i]])
				ct[i]++;
			else
				break;
		}
		if (i + ct[i] > bound)
		{
			bound = i + ct[i];
			center = i;
		}
		if (ct[i] > maxlen)
		{
			maxlen = ct[i];
			maxcen = i;
		}
	}
	for (int i=0;i<ct.size();i++)
		cout << ct[i];
	cout << endl;
	return s.substr((maxcen - maxlen+1) / 2, maxlen - 1);


}

#pragma endregion

#pragma region 7 Reverse Integer
int reversestr(int x)
{	
	int re;
	string s = std::to_string(x);
	if (x<0)
	{
		string result="-";
		for (int i = s.length() - 1; i > 0; --i)
		{
			result += s[i];
		}
		re = std::stoi(result);
	}
	else
	{
		string result = "";
		cout << s.length() << endl;
		for (int i = s.length() - 1; i >= 0; --i)
		{
			result += s[i];
			cout << result << endl;
		}
		re = std::stoi(result);
	}
	return re;
}

int reverse(int x)
{

	long r = 0;
	while (x) r = r * 10 + x % 10, x /= 10;
	return (int(r) == r) * r;



}
#pragma endregion

#pragma region 8 String to Integer (atoi)
int myAtoi(string str)
{
	long result = 0;		
	int i = str.find_first_not_of(' '), sign = 1;
	if (str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ? 1 : -1;
	while (isdigit(str[i]))
	{
		result = result * 10 + (str[i++] - '0');
		if (sign*result >= INT_MAX) return INT_MAX;
		if (sign*result <= INT_MIN) return INT_MIN;
	}
	return result * sign;

}
#pragma endregion

#pragma region 11 Container With Most Water
int maxArea(vector<int>& height)
{
	int left = 0, right = height.size() - 1, area = 0;
	while (left<right)
	{
		if (height[left] < height[right])
		{
			area = max(area, (right - left)*height[left]);
			left++;
		}
		else
		{
			area = max(area, (right - left)*height[right]);
			right--;
		}
	}
	return area;
}
#pragma endregion

#pragma region 13 Roman to Integer
int getvalue(char i)
{
	
	switch (i)
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	}
	throw ("non recognizable character");
	return 0;
}
int romanToInt(string s)
{	
	int result = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int next = i + 1;
		try
		{
			if (i + 1 < s.length() && getvalue(s[i]) < getvalue(s[next]))
			{
				result -= getvalue(s[i]);
			}
			else
				result += getvalue(s[i]);
		}
		catch (const char* msg)
		{
			cerr << msg << endl;
			return 0;
		}

	}
	return result;


}
#pragma endregion

#pragma region 14 Longest Common Prefix

string longestCommonPrefix(vector<string>& strs)
{
	string result("");
	int ind = 0;
	while (!strs.empty())
	{
		for (int i = 0; i<strs.size(); i++)
		{
			if (ind >= strs[i].size() || strs[0][ind]!= strs[i][ind])
			{
				return result;
			}
		}
		result += strs[0][ind];
		ind++;
	}
	return result;
}


#pragma endregion

#pragma region 17 Letter Combinations of a Phone Number
vector<string> letterCombinations(string digits)
{	
	if (digits.empty()) return vector<string>();
	vector<string> result;
	result.push_back("");
	vector<string> map{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	for (int i = 0; i != digits.length(); ++i)
	{
		int num = digits[i] - '0';
		string value = map[num];
		vector<string> temp;
		for (int j = 0; j != value.size(); ++j)
		{
			for (int k = 0; k != result.size(); ++k)
			{
				temp.push_back(result[k] + value[j]);
			}
		}
		result.swap(temp);

	}
	return result;
}

vector<string> letterCombinationsRe(string digits)
{	
	if (digits.empty()) return vector<string>();
	vector<string> result;
	vector<string> map{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };        
	dfs(digits, 0, "", map, result);
	return result;
}
void dfs(string digits, int level, string out, vector<string> map, vector<string> &result)
{
	if (level == digits.size()) {
		//cout << out << endl;
		result.push_back(out);
	}

	else
	{
		string str = map[digits[level] - '0'];
		for (int i = 0; i != str.size(); ++i)
		{	
			string tt = out;
			tt += str[i];
			/*out += str[i];*/

			dfs(digits, level + 1, tt, map, result);
			//out.pop_back();
		}
	}
}
#pragma endregion

#pragma region 15 3Sum
vector<vector<int>> threesum(vector<int>& nums)
{	
	vector<vector<int>> result;
	if (nums.size() == 0)
		return result;
	sort(nums.begin(), nums.end());
	//for (auto i : nums)
	//	cout << i<<",";
	cout << endl;
	for (int i = 0; i+1 < nums.size(); ++i)
	{

		int left = i + 1, right = nums.size() - 1;
		while (left < right)
		{	
			if (nums[left] + nums[right] == -nums[i])
			{
				vector<int> temp = {nums[i],nums[left],nums[right]};
				result.push_back(temp);
				while (left < right&&temp[1] == nums[left])
					left++;
				while (left < right&&temp[2] == nums[right])
					right--;
			}
			else if (nums[left] + nums[right] < -nums[i])
			{
				left++;
			}
			else if (nums[left] + nums[right] > -nums[i])
			{
				right--;
			}
		}
		while (i+1 < nums.size() && nums[i + 1] == nums[i])
			i++;
		
	}
	return result;

}
#pragma endregion

#pragma region 19 Remove Nth Node From End of List
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode* first = new ListNode(0);
	first->next = head;
	int len = 0;
	ListNode *temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
		len++;
	}
	len++;
	temp = first;
	for (int i = 0; i != len - n; i++)
	{
		temp = temp->next;
	}
	ListNode* nex = temp->next->next;
	temp->next->next = NULL;
	temp->next = nex;

	return first->next;
}

ListNode* removeNthFromEndOP(ListNode* head, int n)
{
	ListNode* first = new ListNode(0);
	ListNode* second = new ListNode(0);
	first->next = head;
	second->next = head;
	ListNode* temp = first;
	int j = 0;
	while (true)
	{
		j++;
		second = second->next;
		if (j>n + 1)
			first = first->next;
		if (second == NULL)
			break;
	}
	ListNode* temp1 = first->next;
	first->next = first->next->next;
	temp1->next = NULL;
	return temp->next;
}

#pragma endregion

#pragma region 20 Valid Parentheses
bool isValid(string s)
{
	vector<char> stack;
	for (int i = 0; i<s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stack.push_back(s[i]);
		else
		{
			if (stack.size() == 0 || !match(stack.back(), s[i]))
				return false;
			stack.pop_back();
		}
	}
	if (stack.size() != 0)
		return false;
	return true;
}

bool match(char left, char right)
{
	if ((left == '('&&right == ')') || (left == ')'&&right == '('))
		return true;
	if ((left == '['&&right == ']') || (left == ']'&&right == '['))
		return true;
	if ((left == '{'&&right == '}') || (left == '}'&&right == '{'))
		return true;
	return false;
}
#pragma endregion

#pragma region 21 Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* head = new ListNode(0);
	ListNode* tail = head;
	while (l1&&l2)
	{
		if (l1->val<l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	tail->next = l1 ? l1 : l2;

	return head->next;
}
#pragma endregion

#pragma region 22 Generate Parentheses
//vector<string> generateParenthesis(int n)
//{
//	vector<string> ans;
//	backtrack(ans, "", 0, 0, n);
//	return ans;
//}
void backtrack(vector<string>& ans, string cur, int open, int close, int max)
{
	if (cur.length() == max * 2)
	{
		ans.push_back(cur);
		return;
	}
	if (open < max)
	{
		backtrack(ans, cur + "(", open + 1, close, max);
	}
	if (close < open)
	{
		backtrack(ans, cur + ")", open, close + 1, max);
	}

}
vector<string> generateParenthesis(int n) {
	string start(n, '('); // initial: "(((...((", then add ')' to it.  
	vector<string> v1(1, start), v2;
	string temp;
	for (int i = 0; i<n; i++) { // add one ')' at a time. 
		//cout << i <<":"<< endl;
		for (auto vec = v1.begin(); vec != v1.end(); vec++) {
			for (int j = n - i; j <= n + i; j++) 
			{ 
				// add from tail. for example, 1st time, (((..( becomes ((((..(), 
				//and 2nd time, it becomes (((..(()) and (((..()()  
				temp = *vec;
				if (temp[j - 1] == ')') break;
				temp.insert(temp.begin() + j, ')');
				//cout << temp << endl;
				v2.push_back(temp);
			}
		}
		swap(v1, v2);
		v2.clear();
	}
	return v1;
}
#pragma endregion

#pragma region 26 Remove Duplicates from Sorted Array
int removeDuplicates(vector<int>& nums)
{	
	//iterator version:
	/*it(nums, 0);
	return nums.size();*/
	if (nums.size() == 0)
		return 0;
	//int len = 1;
	int temp = nums[0];
	vector<int> s;
	s.push_back(nums[0]);
	for (int i = 1; i<nums.size(); ++i)
	{
		if (nums[i] != temp)
		{
		//	len++;
			temp = nums[i];
			s.push_back(nums[i]);
		}
	}
	nums.swap(s);
	//return len;
	return nums.size();
}
void it(vector<int>& nums, int start)
{
	if (nums.size() == 0)
		return;
	if (start == nums.size() - 1)
		return;
	else
	{
		if (nums[start] == nums[start + 1])
		{
			nums.erase(nums.begin() + start);
			it(nums, start);
		}
		else
		{
			it(nums, start + 1);
		}
	}
}
#pragma endregion

#pragma region 28 Implement strStr()
int strStr(string haystack, string needle)
{
	if (needle.empty())
		return 0;
	for (int i = 0, j = 0; i<haystack.length(); ++i)
	{
		if (haystack.length() - i<needle.length())
			return -1;
		if (haystack.substr(i, needle.length()) == needle)
			return i;
	}
	return -1;
}
#pragma endregion

#pragma region 29 Divide Two Integers
int divide(int dividend, int divisor)
{
	if (dividend == INT_MIN && divisor == -1)
		return INT_MAX;

	int result = 0;
	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	long long dvd = labs(dividend);
	long long dvs = labs(divisor);
	while (dvd >= dvs)
	{
		long long cnt = 1, temp = dvs;
		while (dvd >= (temp << 1))
		{
			temp <<= 1;
			cnt <<= 1;
		}
		dvd -= temp;
		result += cnt;
	}
	return sign == 1 ? result : -result;
}
#pragma endregion

#pragma region 69 Sqrt(x)
int sqrt(int x)
{
	if (x == 0) return 0;
	int l = 1, r = (x / 2 + 1);
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (m <= x / m && (m + 1)>x / (m + 1))
			return m;
		if (x / m<m)
			r = m - 1;
		else
			l = m + 1;
	}
	return 0;
}
#pragma endregion

#pragma region 50 Pow(x, n)
//递归，n划分为2个x的n/2次方，递归。。
double myPow(double x, int n)
{
	if (x == 0)
		return 1;
	double temp = myPow(x, n / 2);
	if (n % 2 == 0)
	{
		return temp * temp;
	}
	else if (n > 0)
	{
		return temp * temp * x;
	}
	else
		return temp * temp / x;


}
//n转换为二进制,eg.1100010 右移逢1乘以一个x^(2^(k-1))到result
//double myPow(double x, int n) {
//	double result = 1;
//	int p = n;
//	if (n<0)
//	{
//		if (n == INT_MIN)
//		{
//			p = 0 - (n + 1);
//			result *= (1 / x);
//			x = 1 / x;
//		}
//		else
//		{
//			p = -n;
//			x = 1 / x;
//		}
//
//	}
//	else
//	{
//		p = n;
//	}
//	while (p)
//	{
//		if (p & 1)
//		{
//			result *= x;
//		}
//		x *= x;
//		p >>= 1;
//	}
//	return result;
//}
#pragma endregion

#pragma region 38. Count and Say
string countAndSay(int n)
{
	if (n == 1)
		return  "1";
	string result = countAndSay(n - 1);
	string newresult = "";
	int count = 1;
	for (int i = 0; i < result.size(); ++i)
	{
		if (result[i] == result[i + 1]&&i+1<result.size())
		{
			count++;
			continue;
		}
		newresult += count + '0';
		newresult += result[i];
		count = 1;
	}
	return newresult;

}
#pragma endregion

#pragma region 33. Search in Rotated Sorted Array
int search(vector<int>& nums, int target)
{	
	if (nums.size() == 1)
		return nums[0] == target ? 0 : -1;
	int left = 0, right = nums.size() - 1, mid = 0;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (nums[left] == target)
			return left;
		if (nums[mid] == target)
			return mid;
		if (nums[mid + 1] == target)
			return mid + 1;
		if (nums[right] == target)
			return right;
		if (nums[left] < nums[right])
		{
			if (target < nums[mid])
				right = mid;
			else
				left = mid+1;
		}
		else
		{
			if (nums[left] > nums[mid])
			{
				if (target < nums[mid] || target>nums[left])
					right = mid;
				else
					left = mid+1;
			}
			else
			{
				if (target > nums[left] && target < nums[mid])
					right = mid;
				else
					left = mid+1;
			}

		}

	}
	return -1;



}



#pragma endregion

#pragma region 34. Search for a Range
vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> result{-1,-1};
	if (!nums.size()) return result;
	int left = 0, right = nums.size() - 1, mid = 0;
	if (target<nums[left] || target>nums[right])
	{
		return result;
	}

	while (left < right)
	{	
		mid = (left + right) / 2;
		if (target <= nums[mid])
			right = mid;
		else 
			left = mid + 1;

	}
	if (nums[left] != target)
		return result;
	else
		result[0] = left;

	left = 0, right = nums.size() - 1, mid = 0;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (target >= nums[mid+1] )
			left = mid+1;
		else 
			right = mid;

	}
	result[1] = right;
	return result;
}
#pragma endregion

#pragma region 36. Valid Sudoku
void reset(unordered_map<int, int>& check)
{
	for (int i = 1; i < 10; i++)
	{
		check[i] = 0;
	}
}

bool isValidSudoku(vector<vector<char>>& board)
{
	unordered_map<int, int> check;
	reset(check);
//horizontal
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] != '.')
				check[board[i][j] - '0']++;
			if (check[board[i][j] - '0'] > 1)
				return false;
		}
		reset(check);
	}
//vertical
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[j][i] != '.')
				check[board[j][i] - '0']++;
			if (check[board[j][i] - '0']> 1)
				return false;
		} 
		reset(check);
	}
//square
	for (int i = 0; i < 9; i = i + 3)
	{
		for (int j = 0; j < 9; j=j+3)
		{
			for (int k = i; k < i + 3; k++)
			{
				for (int l = j; l < j + 3; l++)
				{
					if (board[k][l] != '.')
						check[board[k][l] - '0']++;
					if (check[board[k][l] - '0']> 1)
						return false;
				}
			}
			reset(check);
		}
	}
	return true;
}

#pragma endregion

#pragma region 10. Regular Expression Matching
bool isMatch(string s, string p)
{
	if (p.empty()) return s.empty();
	bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

	if (p.size() > 1 && p[1] == '*')
	{
		return isMatch(s, p.substr(2)) || (first_match&&isMatch(s.substr(1), p));
	}
	else
	{
		return first_match && isMatch(s.substr(1), p.substr(1));
	}
}
bool isMatchdp(string s, string p)
{
	int m = s.size(), n = p.size();
	vector<vector<bool>> mat(m + 1, vector<bool>(n + 1, false));
	mat[0][0] = true;

	for (int i = 0; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (p[j - 1] == '*')
			{
				mat[i][j] = mat[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && mat[i - 1][j]);
			}
			else
			{
				mat[i][j] = i > 0 && mat[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
		}
	}
	return mat[m][n];



}
#pragma endregion

#pragma region fb contiguous sum
vector<int> consum(vector<int> nums, int target)
{
	int start = 0, end = -1, sum = 0;
	vector<int> result;
	for (int i = 0; i < nums.size(); i++)
	{
		sum += nums[i];
		end = i;
		if (sum == target)
		{
			for (int j = start; j <= end; j++)
				result.push_back(nums[j]);
			return result;
		}
		else if (sum > target)
		{
			if (nums[i] > target)
			{
				start = i + 1, end = i + 1;
				sum = 0;
			}
			else
			{
				while (sum > target) 
				{
					sum -= nums[start];
					start += 1;
					if (sum == target)
					{
						for (int j = start; j <= end; j++)
							result.push_back(nums[j]);
						return result;
					}

				}

			}
		}			
	}
	return { -1 };
}
#pragma endregion

#pragma region 44. Wildcard Matching
//bool ismatchmain(string s, string p)
//{
//	string ps;
//	for (int i = 0; i < p.size(); i++)
//	{
//		if (p[i] != '*')
//			ps += p[i];
//		else
//		{
//			if (i==0||p[i - 1] != '*')
//				ps += p[i];
//			else
//				continue;
//		}
//	}
//	cout << ps;
//	return isMatchwl(s, ps);
//
//}
//bool isMatchwl(string s, string p)
//{
//	if (p.empty()) return s.empty();
//	else if (s.empty())
//	{
//		if (p.empty())
//			return true;
//		else
//		{
//			if (p[0] == '*')
//				return isMatchwl(s, p.substr(1));
//			else
//				return false;
//		}
//	}
//	if (p[0] == '*')
//		return isMatchwl(s.substr(1), p) || isMatchwl(s.substr(1), p.substr(1)) || isMatchwl(s, p.substr(1));
//
//	else if (p[0] == '?' || p[0] == s[0])
//		return isMatchwl(s.substr(1), p.substr(1));
//	else
//		return false;
//
//}
bool isMatchwl(string s, string p)
{
	int m = s.size(), n = p.size(), i, j, sstar = -1, pstar = -1;
	for (i = 0, j = 0; i < m; i++, j++)
	{
		if (p[j] == '*')
		{
			sstar = i;
			pstar = j;
			i--;
		}
		else
		{
			if (s[i] != p[j] && p[j] != '?')
			{
				if (sstar >= 0)
				{
					i = sstar++;
					j = pstar;
				}
				else
					return false;
			}
		}
	}
	while (p[j] == '*')++j;
	return j == n;
}

//bool isMatchwldp(string s, string p)
//{
//		int m = s.length(), n = p.length();
//		bool f[m + 1][n + 1];
//		memset(f, 0, sizeof(f));
//		f[0][0] = 1;
//		for (int i = 1; i <= n; i++) {
//			f[0][i] = p[i - 1] == '*' && f[0][i - 1];
//		}
//		for (int i = 1; i <= m; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (p[j - 1] != '*') {
//					if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
//						f[i][j] = f[i - 1][j - 1];
//					}
//				}
//				else {
//					f[i][j] = (f[i][j - 1] || f[i - 1][j]);
//				}
//			}
//		}
//		return f[m][n];
//
//}

#pragma endregion

#pragma region 41. First Missing Positive
int firstMissingPositive(vector<int>& nums)
{
	for (int i = 0; i<nums.size(); i++)
	{
		while (nums[i] <= nums.size() && nums[i] > 0 && nums[i] != nums[nums[i]-1])
		{
			swap(nums[i], nums[nums[i] - 1]);
		}
	}
	for (int j = 0; j<nums.size(); j++)
	{
		if (nums[j] != j+1)
			return j + 1;
	}
	return nums.size() + 1;
}
#pragma endregion

#pragma region 53. Maximum Subarray
int maxSubArray(vector<int>& nums)
{
	int sum = nums[0], end = 0, max = nums[0];
	for (int i = 1; i<nums.size(); i++)
	{
		if (nums[i]>sum&&sum<0)
		{
			end = i;
			sum = nums[i];
		}
		else if (sum + nums[i]>0)
		{
			if (i == end + 1)
			{
				sum += nums[i];
				end = i;
			}
			else
			{
				sum = nums[i];
				end = i;
			}
		}
		if (sum>max)
			max = sum;
	}
	return max;
}
#pragma endregion

#pragma region 66. Plus One
vector<int> plusOne(vector<int>& digits)
{
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			digits[i]++;
			return digits;
		}
		else if (digits[i]==9&&i==0)
		{
			digits[i] = 0;
			digits.insert(digits.begin(), 1);
			return digits;
		}
		else
		{
			digits[i] = 0;
		}

	}

}
#pragma endregion

#pragma region 287. Find the Duplicate Number
int findDuplicate(vector<int>& nums)
{
	int low = 0, high = nums.size(), mid;
	while (low<high)
	{
		int count = 0;
		mid = (low + high) / 2;
		for (auto i : nums)
		{
			if (i <= mid)
				count++;
		}
		if (count>mid)
			high = mid;
		else
			low = mid + 1;
	}
	return low;
}
#pragma endregion

#pragma region 268. Missing Number
int missingNumber(vector<int>& nums)
{
	for (int i = 0; i<nums.size(); i++)
	{
		while (nums[i] < nums.size() && nums[i] != nums[nums[i]])
		{
			swap(nums[i], nums[nums[i]]);
		}

	}
	for (int j = 0; j<nums.size(); j++)
	{
		if (nums[j] != j)
			return j;
	}
	return nums.size();
}
#pragma endregion

#pragma region 136. Single Number
int singleNumber(vector<int>& nums)
{
	int result = 0;
	for (int i = 0; i<nums.size(); i++)
		result ^= nums[i];
	return result;
}
#pragma endregion

#pragma region 141. Linked List Cycle
bool hasCycle(ListNode *head)
{
	set<ListNode*> nodes;
	while (head)
	{
		if (nodes.find(head) != nodes.end())
			return true;
		else
			nodes.insert(head);
		head = head->next;
	}
	return false;
}
bool hasCycleOn(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return false;
	}
	ListNode* fast = head->next;
	ListNode* slow = head;
	while (fast != slow)
	{
		if (fast == NULL || fast->next == NULL)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;

}
#pragma endregion

#pragma region 142. Linked List Cycle II
ListNode *detectCycle(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return NULL;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	while (true)
	{
		if (fast == NULL || fast->next == NULL)
			return NULL;
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	fast = head;
	while (slow != head)
	{
		slow = slow->next;
		head = head->next;
	}
	return head;


}
#pragma endregion

#pragma region 48. Rotate Image
void rotate(vector<vector<int>>& matrix)
{
	int n = matrix.size();
	if (n == 0 || n == 1)
		return;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{	

				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[i][n - j - 1];
			matrix[i][n - j - 1] = temp;
		}
	}
	return;
}
#pragma endregion

#pragma region 55. Jump Game
bool canJump(vector<int>& nums)
{	
	int n = nums.size();
	if (n == 0)return true;
	vector<bool> reach(n, 0);
	reach[0] = 1;
	for (int i = 0; i < n; i++)
	{
		if (reach[n - 1] == 1)
			return true;
		if (reach[i] ==1)
		{
			for (int j = 1; j <= nums[i] && j + i < n; j++)
			{
				reach[j + i] = 1;
			}
		}

	}
	return reach[n-1];
}
//greedy
bool canJumpdp(vector<int>& nums)
{
	int last = nums.size() - 1;
	for (int i = last; i >= 0; i--)
	{
		if (i + nums[i] >= last)
			last = i;
	}
	return last == 0;
}
#pragma endregion

#pragma region 70. Climbing Stairs
int climbStairs(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	int i1 = 1, i2 = 2, result = 0;
	for (int i = 3; i <= n; i++)
	{
		int temp = i1;
		result = i1 + i2;
		i1 = i2;
		i2 = result;

	}
	return result;
}
#pragma endregion

#pragma region 49. Group Anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
	vector<vector<string>> result;
	unordered_map<string, multiset<string>> hash;
	for (auto s : strs)
	{
		string t = s;
		sort(t.begin(), t.end());
		hash[t].insert(s);
	}
	for (auto h : hash)
	{
		vector<string> element(h.second.begin(), h.second.end());
		result.push_back(element);
	}
	return result;
}
#pragma endregion

#pragma region 242. Valid Anagram
bool isAnagram(string s, string t)
{
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}
bool isAnagramHash(string s, string t)
{
	unordered_map<char, int> hash;
	if (s.size() != t.size()) return false;
	for (int i = 0; i<s.size(); i++)
	{
		hash[s[i]]++;
		hash[t[i]]--;
	}
	for (auto i : hash)
	{
		if (i.second) return false;
	}
	return true;
}
#pragma endregion

#pragma region 438. Find All Anagrams in a String
vector<int> findAnagrams(string s, string p)
{
	vector<int> result;
	int m = s.size(), n = p.size();
	vector<int> ph(26, 0), sh(26, 0);
	for (int pi = 0; pi<n; pi++)
	{
		ph[p[pi] - 'a']++;
		sh[s[pi] - 'a']++;
	}
	if (ph == sh)result.push_back(0);
	for (int i = n; i <= m; i++)
	{
		++sh[s[i] - 'a'];
		--sh[s[i - n] - 'a'];
		if (sh == ph)
			result.push_back(i - n + 1);
	}
	return result;
}
#pragma endregion

#pragma region 104. Maximum Depth of Binary Tree
int maxDepth(TreeNode* root)
{
	if (!root)return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
#pragma endregion

#pragma region DP Gold
int getMostGoldIt(int n, int w, vector<int> g, vector<int> p)
{	
	int s = g.size();
	if (n > s)
	{
		cout << "larger";
		return 0;
	}

	if (n <= 1 && w < p[0])
		return 0;
	if (n == 1 && w >= p[0])
		return g[0];
	if (n > 1 && w < p[n - 1])
		return getMostGoldDP(n - 1, w, g, p);
	int a = getMostGoldDP(n - 1, w, g, p);
	int b = getMostGoldDP(n - 1, w - p[n - 1], g, p) + g[n - 1];
	return max(a, b);
}
int getMostGoldDP(int n, int w, vector<int> g, vector<int> p)
{
	vector<int> result(w+1);
	vector<int> pre(w+1);
	for (int i = 0; i <w+1; i++)
	{
		if (i < p[0])
			pre[i] = 0;
		else
			pre[i] = g[0];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < w+1; j++)
		{
			if (j < p[i])
				result[j] = pre[j];
			else
				result[j] = max(pre[j], pre[j - p[i]] + g[i]);
		}
		pre = result;
	}

	return result[w];

}
#pragma endregion

#pragma region Serling Cut DP
int cutrecu(vector<int> len, vector<int> price, int l)
{
	if (l == 0)
		return 0;
	int q = 0;
	for (int i = 1; i <=l; i++)
	{
		q = max(q, price[i-1]+cutrecu(len,price,l-len[i-1]));
	}
	return q;

}
int cutrecusive(vector<int> price, int n)
{
	if (n == 0)
		return 0;
	int q = -1;
	for (int i = 1; i <= n; i++)
	{
		q = max(q, price[i - 1] + cutrecusive(price, n - i));
	}
	return q;
}
int cutdp(vector<int> price, int n)
{
	vector<int> r(n + 1, 0);
	r[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		int q = -1;
		for (int j = 1; j <= i; ++j)
		{
			q = max(q, price[j - 1] + r[i - j]);
		}
		r[i] = q;
	}
	return r[n];

}
#pragma endregion

#pragma region 56. Merge Intervals
void intervalsort(vector<Interval>& intervals, int start, int end)
{
	if (start >= end)
		return;
	int key = intervals[end].start;
	int left = start, right = end - 1;
	while (left < right)
	{
		while (intervals[left].start < key&&left < right)
			left++;
		while (intervals[right].start >= key && left < right)
			right--;
		swap(intervals[left], intervals[right]);
	}
	if (intervals[left].start >= intervals[end].start)
		swap(intervals[left], intervals[end]);
	else
		left++;
	intervalsort(intervals, start, left - 1);
	intervalsort(intervals, left + 1, end);


}
vector<Interval> merge(vector<Interval>& intervals)
{
	vector<Interval> result;
	if (intervals.size() == 0)
		return result;
	intervalsort(intervals, 0, intervals.size() - 1);
	for (int i = 0; i <= intervals.size()-1;)
	{
		Interval temp = intervals[i];
		for (int j = i + 1; j < intervals.size() && intervals[j].start <= temp.end; j++)
		{
			temp.end = max(temp.end,intervals[j].end);
			i = j;
		}
		result.push_back(temp);
		i++;
	}
	return result;
}

#pragma endregion

#pragma region 88. Merge Sorted Array
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	for (int i = m+n-1; i >= n; i--)
		nums1[i] = nums1[i - n];
	int i = n, j = 0, k = 0;
	while (i < m + n && j < n)
	{
		if (nums1[i] < nums2[j])
			nums1[k++] = nums1[i++];
		else
			nums1[k++] = nums2[j++];
	}
	while (i < m + n)
	{
		nums1[k++] = nums1[i++];
	}
	while (j < n)
	{
		nums1[k++] = nums2[j++];
	}


	//for (int i = n, j = 0,k=0; k<m+n;k++)
	//{	
	//	if (i == m + n)
	//	{
	//		nums1[k] = nums2[j];
	//		j++;
	//		continue;
	//	}
	//	if (j == n)
	//	{
	//		break;
	//	}
	//	if (nums1[i] < nums2[j])
	//	{
	//		nums1[k] = nums1[i];
	//		i++;
	//	}
	//	else
	//	{
	//		nums1[k] = nums2[j];
	//		j++;
	//	}
	//}
}
#pragma endregion

#pragma region 75. Sort Colors
void sortcolors(vector<int>& nums)
{
	int i = 0, j = 0, k = nums.size() - 1;
	for (;i <= k; i++)
	{
		if (nums[i] == 0)
			swap(nums[i], nums[j++]);
		else if (nums[i] == 2)
			swap(nums[i--], nums[k--]);
	}
}
#pragma endregion

#pragma region 79. Word Search
bool verify(vector<vector<char>>&board, string word, int i, int j, int index)
{
	if (index == word.size()) return true;
	if (i >= board.size() || i < 0 || j >= board[i].size() || j < 0) return false;
	if (board[i][j] != word[index]) return false;
	board[i][j] = '$';
	bool next = (
		verify(board, word, i, j + 1, index + 1) || 
		verify(board, word, i, j - 1, index + 1) || 
		verify(board, word, i + 1, j, index + 1) ||
		verify(board, word, i - 1, j, index + 1)
		);
	board[i][j] = word[index];
	return next;

}
bool exist(vector<vector<char>>& board, string word)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
			if (verify(board, word, i, j, 0))
				return true;
	}
	return false;
}
#pragma endregion

#pragma region 78. Subsets
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> result{ {} };
	for (int i = 0; i < nums.size(); i++)
	{
		int n = result.size();
		for (int j = 0; j < n; j++)
		{
			result.push_back(result[j]);
			result.back().push_back(nums[i]);
		}
	}
	return result;
}

void backtrackss(vector<int>& nums, vector<vector<int>>& result, vector<int>& elem, int index)
{
	result.push_back(elem);
	for (int i = index; i < nums.size(); i++)
	{
		elem.push_back(nums[i]);
		backtrackss(nums, result, elem, i + 1);
		elem.pop_back();
	}

}

vector<vector<int>> subsetsbck(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.empty())
		return result;
	vector<int> elem;
	backtrackss(nums, result, elem, 0);
	return result;
}

#pragma endregion

#pragma region 90. Subsets II
void subsetbckdup(vector<vector<int>>& result, vector<int>& nums, vector<int>& temp, int index)
{
	result.push_back(temp);
	for (int i = index; i < nums.size(); i++)
	{
		if (i != index && nums[i] == nums[i - 1])
			continue;
		temp.push_back(nums[i]);
		subsetbckdup(result, nums, temp, i + 1);
		temp.pop_back();
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.empty())
		return result;
	sort(nums.begin(), nums.end());
	vector<int> temp;
	subsetbckdup(result, nums, temp, 0);
	return result;

}
#pragma endregion

#pragma region 46. Permutations
void permutebk(vector<vector<int>>& result, vector<int>& nums, vector<int>& temp)
{
	if (temp.size() == nums.size())
	{
		result.push_back(temp);
		return;
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		auto pos = find(temp.begin(), temp.end(), nums[i]);
		if (pos == temp.end())
		{
			temp.push_back(nums[i]);
			permutebk(result, nums, temp);
			temp.pop_back();
		}
	}
}

vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());
	vector<int> temp;
	permutebk(result, nums, temp);
	return result;
}

void permuteswapbk(vector<int>& nums, int index, vector<vector<int>>& result)
{
	if (index >= nums.size())
		result.push_back(nums);
	else
	{
		for (int i = index; i < nums.size(); i++)
		{
			swap(nums[index], nums[i]);
			permuteswapbk(nums, index + 1, result);
			swap(nums[index], nums[i]);
		}
	}

}
vector<vector<int>> permuteswap(vector<int>& nums)
{
	vector<vector<int>> result;
	permuteswapbk(nums, 0, result);
	return result;
}
#pragma endregion

#pragma region 47. Permutations II
void permutunbck(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, vector<bool>& used)
{
	if (temp.size() == nums.size())
		result.push_back(temp);
	else
	{
		for (int i = 0; i < nums.size(); ++i)
		{
			if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
				continue;
			used[i] = 1;
			temp.push_back(nums[i]);
			permutunbck(nums, result, temp, used);
			used[i] = 0;
			temp.pop_back();
		}
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.empty())
		return result;
	vector<int> temp;
	vector<bool> used(nums.size(), 0);
	sort(nums.begin(), nums.end());
	permutunbck(nums, result, temp, used);
	return result;

}
#pragma endregion

#pragma region 62. Unique Paths
int uniquePaths(int m, int n)
{	
	if (m == 0 || n == 0 )
		return 0;
	if (m == 1 || n == 1 || m == 1 && n == 1)
		return 1;
	int d, z;
	long a = max(m-1, n-1);
	long b = min(m-1, n-1);
	int ac = a, bc = b;
	long long t = a + b, tc = a + b;
	while (tc > a+1)
	{
		cout << t << "," << tc << endl;
		t = t * (tc - 1);
		tc -= 1;
	}
	while (bc > 1)
	{
		cout << b << endl;
		b = b * (bc - 1);
		bc -= 1;
	}
	cout << t << "," << b << endl;
	return t / b;
}
#pragma endregion

#pragma region 31. Next Permutation
void nextPermutation1(vector<int>& nums)
{
	for (int i = nums.size() - 1; i > 0; i--)
	{
		if (nums[i] > nums[i - 1])
		{
			for (int j = i; j < nums.size(); j++)
			{
				if (j == nums.size() - 1|| nums[j] > nums[i - 1] && nums[j + 1] <= nums[i - 1])
				{
					int a = nums[i - 1];
					nums[i - 1] = nums[j];
					nums[j] = a;
					sort(nums.begin() + i, nums.end());
					return;
				}
					
			}
		}
	}
	sort(nums.begin(), nums.end());
}
void nextPermutation(vector<int>& nums) {
	int i = nums.size() - 1, k = i;
	while (i > 0 && nums[i - 1] >= nums[i])
		i--;
	for (int j = i; j<k; j++, k--)
		swap(nums[j], nums[k]);
	if (i > 0) {
		k = i--;
		while (nums[k] <= nums[i])
			k++;
		swap(nums[i], nums[k]);
	}
}
#pragma endregion

#pragma region 94. Binary Tree Inorder Traversal
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> result;
	recur(root, result);
	return result;
}
void recur(TreeNode* root, vector<int>& result)
{
	if (root != NULL)
	{
		recur(root->left, result);
		result.push_back(root->val);
		recur(root->right, result);
	}
}

void inter(TreeNode* root, vector<int>& result)
{
	stack<TreeNode*> st;
	while (root != NULL || !st.empty())
	{
		while (root != NULL)
		{
			st.push(root);
			root = root->left;
		}

		if (!st.empty())
		{
			TreeNode* temp = st.top();
			result.push_back(temp->val);
			root = temp->right;
			st.pop();
		}
	}
}

#pragma endregion

#pragma region 39. Combination Sum
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> result;
	vector<int> temp;
	combin(candidates, result, temp, target,0);
	return result;

}
void combin(vector<int>& candidates, vector<vector<int>>& result, vector<int>& temp, int target,int begin)
{
	if (target == 0)
	{
		result.push_back(temp);
		return;
	}
	for (int i = begin/*avoid duplicate*/; i < candidates.size(); ++i)
	{
		if (target >= candidates[i])
		{
			temp.push_back(candidates[i]);
			combin(candidates, result, temp, target - candidates[i],i);
			temp.pop_back();
		}
		else
			return;
	}
}
#pragma endregion

#pragma region 91. Decode Ways
int numDecodings(string s)
{	
	int len = s.size();
	if (len == 0 || s[0] == '0') return 0;
	if (len == 1) return 1;
	int temp = 0, f1 = 1, f2 = 1;
	for (int i = 1; i < len; ++i)
	{

		//if (s[i] != '0'&&sti(s.substr(i - 1, 2)) < 27 && s[i - 1] != '0')
		//	temp += f1 + f2;
		//if (s[i] == '0' && sti(s.substr(i - 1, 2)) < 27 && s[i - 1] != '0')
		//	temp += f2;
		//if (s[i] != '0'&&(sti(s.substr(i - 1, 2)) > 26|| s[i - 1] == '0'))
		//	temp += f1;
		//if (s[i] == '0'&&(sti(s.substr(i - 1, 2)) > 26 || sti(s.substr(i - 1, 2)) == 0))
		//	return 0;
		if (s[i] != '0')
			temp += f1;
		if (sti(s.substr(i - 1, 2)) < 27 && sti(s.substr(i - 1, 2)) > 9)
			temp += f2;
		int t = f1;
		f1 = temp;
		f2 = t;
		temp = 0;
	}
	return f1;
}
void numd(string s, int& result)
{	
	int len = s.size();
	if (len<=2)
	{
		if (len == 1 && sti(s) != 0)
		{
			result++;
		}
		if (len == 2)
		{
			if (sti(s) >= 10)
			{
				if (sti(s) < 27)
					sti(s.substr(1, 1)) > 0 ? result += 2 : result++;
				else
				{
					if(sti(s.substr(1, 1)) > 0 )
						result++;
				}
			}			
		}
		return;
	}
	if (sti(s.substr(0, 2)) < 27 && sti(s.substr(0,1))>0)
	{
		numd(s.substr(2, s.size() - 2), result);
	}
	if (sti(s.substr(0, 1)) > 0)
	{
		numd(s.substr(1, s.size() - 1), result);
	}
}
string its(int i)
{
	return string(1,char(i + 64));
}
int sti(string s) 
{
	int i=0,r = 0;
	while (i<s.size())
	{
		r = r * 10 + (s[i] - '0');
		i++;
	}
	return r;
}
#pragma endregion

#pragma region 121. Best Time to Buy and Sell Stock
int maxProfit(vector<int>& prices)
{
	int result = 0;
	if (prices.size()<2)
		return result;
	int min = prices[0];
	for (int i = 1; i<prices.size(); ++i)
	{
		if (prices[i]>min&&prices[i] - min>result)
			result = prices[i] - min;
		if (prices[i]<min)
			min = prices[i];

	}
	return result;
}
#pragma endregion

#pragma region 122. Best Time to Buy and Sell Stock II
int maxProfitII(vector<int>& prices)
{
	if (prices.size() == 0)
		return 0;
	int result = 0;// , min = prices[0], pre = prices[0];
	for (int i = 1; i < prices.size(); i++)
	{
		//if (prices[i] < pre)
		//{
		//	result += pre - min;
		//	min = prices[i];
		//}
		//else if (i == prices.size() - 1 && prices[i] >= pre)
		//	result += prices[i] - min;
		//
		//pre = prices[i];
		result += prices[i] - prices[i - 1] > 0 ? prices[i] - prices[i - 1] : 0;
	}

	return result;

}
#pragma endregion

#pragma region 102. Binary Tree Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == NULL)
		return result;
	vector<int> single;
	int psize = 1, csize = 0;
	TreeNode* temp = NULL;
	queue<TreeNode* > q;
	q.push(root);
	while (!q.empty())
	{
		temp = q.front();
		single.push_back(temp->val);
		q.pop();
		if (temp->left != NULL)
		{
			q.push(temp->left);
			csize++;
		}
		if (temp->right != NULL)
		{
			q.push(temp->right);
			csize++;
		}
		psize--;
		if (psize == 0)
		{
			result.push_back(single);
			single.clear();
			psize = csize;
			csize = 0;
		}
	}
	return result;
}
#pragma endregion

#pragma region 103. Binary Tree Zigzag Level Order Traversal
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>> result;
	if (root == NULL)
		return result;
	queue<TreeNode*> q;
	q.push(root);
	bool ltr = true;

	while (!q.empty())
	{
		int size = q.size();
		vector<int> r(size);
		for (int i = 0; i < size; i++)
		{
			TreeNode* node = q.front();
			q.pop();
			int index = ltr ? i : (size - 1 - i);
			r[index] = node->val;
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		ltr = !ltr;
		result.push_back(r);
	}
	return result;

}
#pragma endregion

#pragma region 127. Word Ladder
bool compare(string a, string b)
{
	if (a.size() != b.size())
		return false;
	int diff = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			diff++;
		if (diff > 1)
			return false;
	}
	if (diff == 1)
		return true;
	else
		return false;
}
void helper(string tempword, string endword, int cur, int& result, vector<string> templist)
{
	if (compare(tempword, endword))
	{
		result = cur + 1 < result ||result == 0 ? cur + 1 : result;
	}
	else if (cur > result&&result > 0)
		return;
	for (int i = 0; i < templist.size(); i++)
	{
		if (compare(tempword, templist[i]))
		{
			vector<string> next = templist;
			next[i] = "";
			helper(templist[i], endword, cur + 1, result, next);
		}
	}
}


//int ladderLength(string beginWord, string endWord, vector<string>& wordList)
//{
//	int cur = 1, result = 0, check=0;
//	for (int i = 0; i < wordList.size(); i++)
//	{
//		if (wordList[i] == endWord)
//		{
//			check = 1;
//			break;
//		}
//	}
//	if (check == 0)
//		return result;
//	helper(beginWord, endWord, cur, result, wordList);
//	return result;
//}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> wordDict{ wordList.begin(),wordList.end() };
	
	if (wordDict.find(endWord) == wordDict.end())
		return 0;
	queue<string> tovist;
	addnext(beginWord, tovist, wordDict);
	int result = 2;
	while (!tovist.empty())
	{
		int len = tovist.size();
		for (int i = 0; i < len; i++)
		{
			string temp = tovist.front();
			tovist.pop();
			if (temp == endWord)
				return result;
			addnext(temp, tovist, wordDict);
		}
		result++;
	}
	return 0;
}

void addnext(string word, queue<string>& tovisit, unordered_set<string>& wordDict)
{
	wordDict.erase(word);
	for (int i = 0; i < word.size(); i++)
	{
		char c = word[i];
		for (int j = 0; j < 26; j++)
		{
			word[i] = 'a' + j;
			if (wordDict.find(word) != wordDict.end())
			{
				tovisit.push(word);
				wordDict.erase(word);
			}
		}
		word[i] = c;
	}
}

#pragma endregion

#pragma region 105. Construct Binary Tree from Preorder and Inorder Traversal
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int mid = 0;
	return helper(preorder, inorder, mid, 0, inorder.size() - 1);
}

TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& mid, int start, int end)
{
	if (start>end || mid>preorder.size())
		return NULL;
	TreeNode* root = new TreeNode(preorder[mid]);
	auto dis = distance(inorder.begin(), find(inorder.begin() + start, inorder.begin() + end, preorder[mid]));
	mid++;
	root->left = helper(preorder, inorder, mid, start, dis - 1);
	root->right = helper(preorder, inorder, mid, dis + 1, end);

	return root;
}
#pragma endregion

#pragma region 116. Populating Next Right Pointers in Each Node
void connect(TreeLinkNode *root)
{
	if (root == NULL)
		return;
	TreeLinkNode* pre = root;
	TreeLinkNode* cur = NULL;
	while (pre->left)
	{
		cur = pre;
		while (cur)
		{
			cur->left->next = cur->right;
			if (cur->next)
			{
				cur->right->next = cur->next->left;
			}
			cur = cur->next;
		}
		pre = pre->left;
	}
}
#pragma endregion











