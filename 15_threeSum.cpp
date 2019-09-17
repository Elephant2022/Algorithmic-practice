#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	/*
	*给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
	*
	*注意：答案中不可以包含重复的三元组。
	*
	*例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
	*
	*满足要求的三元组集合为：
	*[
	*[-1, 0, 1],
	*[-1, -1, 2]
	*]
	*
	*来源：力扣（LeetCode）
	*链接：https://leetcode-cn.com/problems/3sum
	*著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());
		if (nums.empty() || nums.front() > 0 || nums.back() < 0)return{};

		vector<vector<int>> vecRes;

		for (size_t i = 0; i < nums.size(); i++)
		{
			int k = nums.at(i);
			if (k > 0)   break;
			if (i > 0 && k == nums.at(i - 1))	continue;

			int l = i + 1;
			int r = nums.size() - 1;

			while (l < r)
			{
				if (nums.at(l) + nums.at(r) == -k)
				{
					vecRes.push_back(vector<int>{k, nums.at(l), nums.at(r)});

					while (l < r&&nums.at(l) == nums.at(l + 1)) l++;
					while (l < r&&nums.at(r) == nums.at(r - 1)) r--;
					l++;
					r--;
				}
				else if (nums.at(l) + nums.at(r) > -k)
				{
					r--;
				}
				else {
					l++;
				}
			}
		}
		return vecRes;
	}
};

int main()
{
	Solution* p = new Solution;

	vector<int> vec = vector<int>{ -1,0,1 };

	p->threeSum(vec);

	system("pause");
	return 0;
}
