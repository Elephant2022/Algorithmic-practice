#include <iostream>
#include <vector>
using namespace std;

#define max(a,b)(((a)>(b))?(a):(b))
#define min(a,b)(((a)<(b))?(a):(b))

class Solution {
/*
 *给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 *
 *你可以假设 nums1 和 nums2 不会同时为空。
 *
 *示例 1:
 *nums1 = [1, 3]
 *nums2 = [2]
 *
 *则中位数是 2.0
 *
 *示例 2:
 *nums1 = [1, 2]
 *nums2 = [3, 4]
 *
 *则中位数是 (2 + 3)/2 = 2.5
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
*/
public:
	/*寻找两个有序数组的中位数--解法一*/
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int median = (nums1.size() + nums2.size()) / 2;

		int p = 0, q = 0;
		vector<int>s;
		for (int i = 0; i < median + 1; i++)
		{
			if (q < nums1.size() && p < nums2.size())
			{
				if (nums1.at(q) < nums2.at(p))
				{
					s.push_back(nums1.at(q));
					q++;
				}
				else
				{
					s.push_back(nums2.at(p));
					p++;
				}
			}
			else if (q < nums1.size())
			{
				s.push_back(nums1.at(q));
				q++;
			}
			else if (p < nums2.size())
			{
				s.push_back(nums2.at(p));
				p++;
			}
		}

		if ((nums1.size() + nums2.size()) % 2 == 1)
		{
			return s.at(median);
		}
		else
		{
			return (s.at(median) + s.at(median - 1)) / 2.0f;
		}
	}

	/*寻找两个有序数组的中位数--解法二（二分法）*/
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		int Lmax1, Lmax2, Rmin1, Rmin2, c1, c2, lo = 0, hi = 2 * n;
		while (lo <= hi)
		{
			c1 = (lo + hi) / 2;
			c2 = m + n - c1;

			Lmax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			Rmin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			Lmax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			Rmin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (Lmax1 > Rmin2)
			{
				hi = c1 - 1;
			}
			else if (Lmax2 > Rmin1)
			{
				lo = c1 + 1;
			}
			else
			{
				break;
			}
		}

		return (max(Lmax1, Lmax2) + min(Rmin1, Rmin2)) / 2.0f;
	}
};
/*
int main()
{
	vector<int> l1 = { 2,7,11,15 };
	vector<int> l2 = { 2,3,4 };
	Solution p;
	int k = p.findMedianSortedArrays(l1, l2);
	system("pause");
	return 0;
}
*/