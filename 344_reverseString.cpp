#include <iostream>
#include <vector>

using namespace std;

class Solution {
/*
 *��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������
 *
 *��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
 *
 *����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���
 *
 *��Դ�����ۣ�LeetCode��
 *���ӣ�https://leetcode-cn.com/problems/reverse-string
 *����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

public:
	//˫ָ��
	void reverseString(vector<char>& s) {
		int start = 0;
		int end = s.size() - 1;
		while (start < end)
		{
			char c;
			c = s[start];
			s[start] = s[end];
			s[end] = c;

			start++;
			end--;
		}
	}
};


int main()
{
	Solution s = Solution();
	s.reverseString(vector<char>{'a','b','c','d'});

	return 0;
}
