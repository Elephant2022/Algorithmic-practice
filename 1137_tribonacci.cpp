#include <iostream>
#include <vector>

using namespace std;

class Solution {
/*
 *泰波那契序列 Tn 定义如下： 
 *
 *T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
 *
 *给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
 *
 *
 *示例 1：
 *
 *输入：n = 4
 *输出：4
 *解释：
 *T_3 = 0 + 1 + 1 = 2
 *T_4 = 1 + 1 + 2 = 4
 *示例 2：
 *
 *输入：n = 25
 *输出：1389537
 *
 *提示：
 *
 *0 <= n <= 37
 *答案保证是一个 32 位整数，即 answer <= 2^31 - 1。
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/n-th-tribonacci-number
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	/*递归：简单易懂，但是耗时，计算后面几个数值是超出时间限制*/
	int tribonacci(int n) {
		if (n == 0) return 0;
		else if (n == 1 || n == 2) return 1;
		else
			return tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
	}

	/*记忆化，缩小计算量*/
	vector<int> vecArray{ 0,1,1 };
	int tribonacci(int n) {
		if (n < vecArray.size())
		{
			return vecArray.at(n);
		}
		for (size_t i = vecArray.size(); i <= n; ++i)
			vecArray.push_back(vecArray.at(i - 3) + vecArray.at(i - 2) + vecArray.at(i - 1));
		return vecArray.at(n);
	}
};

int main()
{
	vector<vector<int>> vec1 = { {0,1},{1,0},{4,0},{0,4},{3,3},{2,4} };
	vector<int> vec2 = {0,0};

	Solution s = Solution();
	s.tribonacci(6);

	return 0;
}
