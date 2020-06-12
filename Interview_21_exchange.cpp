#include <iostream>
#include <vector>

class Solution
{
/*
 *输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 *
 *示例：
 *
 *输入：nums = [1,2,3,4]
 *输出：[1,3,2,4] 
 *注：[3,1,2,4] 也是正确的答案之一。
 *
 *提示：
 *
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10000
*/
public:
    std::vector<int> exchange(std::vector<int>& nums)
    {
        int l =0;
        int r = nums.size()-1;

        while(l<r)
        {
           while(l<r&&(nums.at(l)%2 == 1)) l++;
           while(l<r&&(nums.at(r)%2 == 0)) r--;

           int temp = nums.at(l);
           nums.at(l)= nums.at(r);
           nums.at(r) = temp;

           l++;
           r--;
        }

        return nums;
    }
};

int main()
{
    std::vector<int> vecNums {1,2,3,4};
    Solution p;
    p.exchange(vecNums);

    return 0;
}