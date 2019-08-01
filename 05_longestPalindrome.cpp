#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
/*
 *给定一个字符串s，找到s中最长的回文子串。你可以假设s的最大长度为 1000。
 *
 *示例 1：
 *
 *输入 : "babad"
 *输出 : "bab"
 *注意 : "aba" 也是一个有效答案。
 *
 *示例 2：
 *输入 : "cbbd"
 *输出 : "bb"
 *
 *来源：力扣（LeetCode）
 *链接：https ://leetcode-cn.com/problems/longest-palindromic-substring
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	/*最长回文子串--解法一（中心扩展法）*/
	string longestPalindrome(string s)
	{
		if (s.size() < 1)
		{
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int len1 = expandAroundCenter(s, i, i);		//一个元素为中心 
			int len2 = expandAroundCenter(s, i, i + 1);	//两个元素为中心
			int len = max(len1, len2);
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.size() && s[L] == s[R])
		{
			--L;
			++R;
		}
		return R - L - 1;
	}

	/*最长回文子串--解法二（动态规划）*/
	string longestPalindrome(string s)
	{
		if (s.size()<2)
		{
			return s;
		}
		int maxLeng = 1;
		int start = 0;
		vector<vector<int>> stateArr(s.size(), vector<int>(s.size()));
		for (int i = 0; i < s.size(); i++)
		{
			stateArr[i][i] = 1;
			if ( i<s.size()-1&&s.at(i) == s.at(i+1))
			{
				stateArr[i][i + 1] = 1;
				maxLeng = 2;
				start = i;
			}
		}

		for (int l = 3; l <= s.size(); l++)
		{
			for (int i = 0; i + l - 1 < s.size(); ++i)
			{
				if (s.at(i) == s.at(i+l-1)&& stateArr[i+1][i+l-2] == 1)
				{
					stateArr[i][i + l - 1] = 1;
					if (l>maxLeng)
					{
						maxLeng = l;
						start = i;
					}
				}
			}
		}
		return s.substr(start, maxLeng);
	}

};

#if 0

int main()
{
	Solution p; 
	string str = "ccc";
	string s = p.longestPalindrome(str);
	system("pause");
	return 0;
}

#endif