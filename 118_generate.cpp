#include <iostream>
#include <vector>

using namespace std;

class Solution {
/*给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 *
 *在杨辉三角中，每个数是它左上方和右上方的数的和。
 *
 *示例 :
 *
 *输入: 5
 *输出 :
 *[
 *	[1],
 *	[1, 1],
 *	[1, 2, 1],
 *	[1, 3, 3, 1],
 *	[1, 4, 6, 4, 1]
 *]
 *
 *来源：力扣（LeetCode）
 *链接：https ://leetcode-cn.com/problems/pascals-triangle
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows < 1) return vector<vector<int>>{};

		vector<vector<int>> vecResult;
		vecResult.resize(numRows);
		for (int i = 0; i < numRows; ++i)
		{
			vecResult.at(i).resize(i + 1);
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0 || j == i)
					vecResult.at(i).at(j) = 1;
				else
					vecResult.at(i).at(j) = vecResult.at(i - 1).at(j - 1) + vecResult.at(i - 1).at(j);
			}
		}

		return vecResult;
	}
};

int main()
{
	Solution s = Solution();
	s.generate(5);

	return 0;
}