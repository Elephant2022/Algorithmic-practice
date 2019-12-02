#include <iostream>
#include <vector>

using namespace std;

class Solution {
/*
 *在一个 8x8 的棋盘上，放置着若干「黑皇后」和一个「白国王」。
 *
 *「黑皇后」在棋盘上的位置分布用整数坐标数组 queens 表示，「白国王」的坐标用数组 king 表示。
 *
 *「黑皇后」的行棋规定是：横、直、斜都可以走，步数不受限制，但是，不能越子行棋。
 *
 *请你返回可以直接攻击到「白国王」的所有「黑皇后」的坐标（任意顺序）。
 *
 *示例 1：
 *
 *
 *输入：queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
 *输出：[[0,1],[1,0],[3,3]]
 *解释：
 *[0,1] 的皇后可以攻击到国王，因为他们在同一行上。
 *[1,0] 的皇后可以攻击到国王，因为他们在同一列上。
 *[3,3] 的皇后可以攻击到国王，因为他们在同一条对角线上。
 *[0,4] 的皇后无法攻击到国王，因为她被位于 [0,1] 的皇后挡住了。
 *[4,0] 的皇后无法攻击到国王，因为她被位于 [1,0] 的皇后挡住了。
 *[2,4] 的皇后无法攻击到国王，因为她和国王不在同一行/列/对角线上。
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/queens-that-can-attack-the-king
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		vector<vector<int>> map(8, vector<int>(8, 0));
		//初始化皇后位置
		for (auto t : queens)
		{
			map[t.at(0)][t.at(1)] = 1;
		}
		//初始化国王位置
		map[king.at(0)][king.at(1)] = 2;

		int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
		int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
		vector<vector<int>> ansArr = vector<vector<int>>{};
		for (size_t i = 0; i < 8; i++)
		{
			int x = king.at(0);
			int y = king.at(1);

			do 
			{
				x += dx[i];
				y += dy[i];
				//判断越界
				if (x < 0 || x >= 8 || y < 0 || y >= 8) break;;

				//判断是否遇到皇后
				if (map[x][y] == 1)
				{
					ansArr.push_back(vector<int>{x, y});
					break;
				}
			} while (true);
		}

		return ansArr;
	}
};

int main()
{
	vector<vector<int>> vec1 = { {0,1},{1,0},{4,0},{0,4},{3,3},{2,4} };
	vector<int> vec2 = {0,0};

	Solution s = Solution();
	s.queensAttacktheKing(vec1, vec2);

	return 0;
}
