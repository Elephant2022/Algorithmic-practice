#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
/*
 *将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 *
 *比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 *
 *L   C   I   R
 *E T O E S I I G
 *E   D   H   N	
 *之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 *
 *示例 1:
 *
 *输入: s = "LEETCODEISHIRING", numRows = 3
 *输出: "LCIRETOESIIGEDHN"
 *
 *示例 2:
 *
 *输入: s = "LEETCODEISHIRING", numRows = 4
 *输出: "LDREOEIIECIHNTSG"
 *解释:
 *
 *L     D     R
 *E   O E   I I
 *E C   I H   N
 *T     S     G
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/zigzag-conversion
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	/*Z字形变换——解法一*/
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		string str = "";
		int step = 2 * numRows - 2;

		for (int i = 0; i < numRows; ++i)
		{
			int j = i;
			int add = 2 * i;
			for (; j < s.size();)
			{
				str += s.at(j);
				add = step - add;

				j += (i == 0 || i == numRows - 1) ? step : add;
			}
		}
		return str;
	}

	/*Z字形变换——解法二*/
	string convert(string s, int numRows)
	{
		if (numRows == 1) return s;

		vector<string> strArr(numRows);
		bool isDown = false;
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			strArr[k].push_back(s.at(i));
			isDown = (0 == k || k == numRows - 1) ? !isDown : isDown;
			k += isDown ? 1 : -1;
		}
		string str = "";
		for (int i = 0; i < numRows; ++i)
		{
			str += strArr[i];
		}

		return str;
	}
};

#if 1

int main()
{
	Solution p;
	string str = "LEETCODEISHIRING";
	string s = p.convert(str, 1);
	system("pause");
	return 0;
}

#endif