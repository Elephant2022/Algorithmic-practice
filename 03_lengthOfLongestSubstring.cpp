#include <iostream>
using namespace std;

class Solution {
/*
 *给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
 *示例 1:
 *
 *输入: "abcabcbb"
 *输出: 3
 *解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 *
 *示例 2:
 *
 *输入: "bbbbb"
 *输出: 1
 *解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 *
 *示例 3:
 *
 *输入: "pwwkew"
 *输出: 3
 *解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	/*无重复字符的最长子串*/
	int lengthOfLongestSubstring(string s) {
		string str;
		int count = 0;
		for (auto c : s)
		{
			int k = str.find_first_of(c);
			if (std::string::npos == k)
			{
				str.push_back(c);
			}
			else
			{
				count = count < str.size() ? str.size() : count;
				str.erase(0, k + 1);
				str.push_back(c);
			}
		}

		count = count < str.size() ? str.size() : count;
		return count;
	}
};

int main()
{
	string str = "pwwhew";
	Solution p;
	int count = p.lengthOfLongestSubstring(str);
	system("pause");
	return 0;
}