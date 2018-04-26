#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <map>
#include "Leet.h"
#include <algorithm>
#include <iomanip>

using namespace std;

#pragma region problem1 Two Sum
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

#pragma region problem2 Add Two Numbers
//2. Add Two Numbers
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

#pragma region Problem 461 Hamming Distance
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

#pragma region Problem 3 Longest Substring Without Repeating Characters
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

#pragma region Problem 4 Median of Two Sorted Arrays
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
