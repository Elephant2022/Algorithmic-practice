#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	/*
	*给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
	*
	*例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
	*
	*与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
	*
	*来源：力扣（LeetCode）
	*链接：https://leetcode-cn.com/problems/3sum-closest
	*著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ans = INT_MAX;

		sort(nums.begin(), nums.end());

		for (size_t i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums.at(i) == nums.at(i - 1)) continue;

			int l = i + 1;
			int r = nums.size() - 1;
			while (l<r)
			{
				int sum = nums.at(i) + nums.at(l) + nums.at(r);
				ans = abs(sum - target) < abs(ans - target) ? sum : ans;

				if ((sum - target) == 0)
				{
					return ans;
				}
				else
				{
					if (sum > target)
					{
						r--;
					}
					else
					{
						l++;
					}
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution* p = new Solution;

	vector<int> vec = vector<int>{ -1,2,1,-4 };

	int k = p->threeSumClosest(vec, 1);

	system("pause");
	return 0;
}
