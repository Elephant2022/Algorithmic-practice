#include <iostream>
#include <vector>
using namespace std;

class Solution {
/*
*编写一个函数来查找字符串数组中的最长公共前缀。
*
*如果不存在公共前缀，返回空字符串 ""。
*
*示例 1:
*
*输入: ["flower","flow","flight"]
*输出: "fl"
*示例 2:
*
*输入: ["dog","racecar","car"]
*输出: ""
*解释: 输入不存在公共前缀。
*说明:
*
*所有输入只包含小写字母 a-z 。
*
*来源：力扣（LeetCode）
*链接：https://leetcode-cn.com/problems/longest-common-prefix
*著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*
*/
public:
	/*最长公共前缀——解法一（暴力）*/
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";

		string s = strs.at(0);
		for (size_t i = 1; i < strs.size(); i++)
		{
			int k = s.length() > strs.at(i).length() ? strs.at(i).length() : s.length();
			size_t j = 0;
			for (; j < k; j++)
			{
				if (s.at(j) != strs.at(i).at(j))
				{
					break;
				}
			}
			s = s.substr(0, j);
		}

		return s;
	}

	/*最长公共前缀——解法er（水平扫描法）*/
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";

		for (size_t i = 0; i < strs.at(0).length(); i++)
		{
			for (size_t j = 0; j < strs.size(); j++)
			{
				if (i == strs.at(j).size() || strs.at(j).at(i) != strs.at(0).at(i))
					return strs.at(0).substr(0, i);
			}
		}
		return strs.at(0);
	}

};

int main()
{
	Solution* p = new Solution;
	vector<string> s = { "flower","flow","flowht" };
	string ss = p->longestCommonPrefix(s);

	system("pause");
	return 0;
}
