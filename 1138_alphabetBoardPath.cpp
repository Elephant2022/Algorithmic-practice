#include <iostream>
#include <vector>

using namespace std;

class Solution {
/*
 *我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。
 *
 *在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"].
 *
 *我们可以按下面的指令规则行动：
 *
 *如果方格存在，'U' 意味着将我们的位置上移一行；
 *如果方格存在，'D' 意味着将我们的位置下移一行；
 *如果方格存在，'L' 意味着将我们的位置左移一列；
 *如果方格存在，'R' 意味着将我们的位置右移一列；
 *'!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
 *返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。
 *
 *
 *示例 1：
 *
 *输入：target = "leet"
 *输出："DDR!UURRR!!DDD!"
 *示例 2：
 *
 *输入：target = "code"
 *输出："RR!DDRR!UUL!R!"
 *
 *
 *提示：
 *
 *1 <= target.length <= 100
 *target 仅含有小写英文字母。
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/alphabet-board-path
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	string alphabetBoardPath(string target) {
		int curX = 0;
		int curY = 0;
		if (target.empty()) return string{};
		
		string strResult = "";
		for (size_t i = 0; i < target.length(); ++i)
		{
			int tarY = (target.at(i) - 'a') / 5;
			int tarX = (target.at(i) - 'a') % 5;

			int difX = tarX - curX;
			int difY = tarY - curY;

			if (difX == 0 && difY == 0)
			{
				strResult.push_back('!');
				continue;
			}

			bool tarIsZ = false;		//判断目标是不是 z ,特殊处理，z只能向下，不能左右移动
			if (tarX == 0 && tarY == 5)
			{
				difY--;
				tarIsZ = true;
			}

			for (size_t j = 0; j < abs(difY); j++)
			{
				strResult.push_back(difY > 0 ? 'D' : 'U');
			}

			for (size_t j = 0; j < abs(difX); j++)
			{
				strResult.push_back(difX > 0 ? 'R' : 'L');
			}

			if (tarIsZ)
			{
				strResult.push_back('D');
			}

			strResult.push_back('!');

			curX = tarX;
			curY = tarY;
		}

		return strResult;
	}
};

int main()
{
	Solution s = Solution();
	string re = s.alphabetBoardPath("zdz");

	return 0;
}
