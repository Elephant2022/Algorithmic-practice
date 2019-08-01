#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
/*
 *����һ���ַ���s���ҵ�s����Ļ����Ӵ�������Լ���s����󳤶�Ϊ 1000��
 *
 *ʾ�� 1��
 *
 *���� : "babad"
 *��� : "bab"
 *ע�� : "aba" Ҳ��һ����Ч�𰸡�
 *
 *ʾ�� 2��
 *���� : "cbbd"
 *��� : "bb"
 *
 *��Դ�����ۣ�LeetCode��
 *���ӣ�https ://leetcode-cn.com/problems/longest-palindromic-substring
 *����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
public:
	/*������Ӵ�--�ⷨһ��������չ����*/
	string longestPalindrome(string s)
	{
		if (s.size() < 1)
		{
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int len1 = expandAroundCenter(s, i, i);		//һ��Ԫ��Ϊ���� 
			int len2 = expandAroundCenter(s, i, i + 1);	//����Ԫ��Ϊ����
			int len = max(len1, len2);
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.size() && s[L] == s[R])
		{
			--L;
			++R;
		}
		return R - L - 1;
	}

	/*������Ӵ�--�ⷨ������̬�滮��*/
	string longestPalindrome(string s)
	{
		if (s.size()<2)
		{
			return s;
		}
		int maxLeng = 1;
		int start = 0;
		vector<vector<int>> stateArr(s.size(), vector<int>(s.size()));
		for (int i = 0; i < s.size(); i++)
		{
			stateArr[i][i] = 1;
			if ( i<s.size()-1&&s.at(i) == s.at(i+1))
			{
				stateArr[i][i + 1] = 1;
				maxLeng = 2;
				start = i;
			}
		}

		for (int l = 3; l <= s.size(); l++)
		{
			for (int i = 0; i + l - 1 < s.size(); ++i)
			{
				if (s.at(i) == s.at(i+l-1)&& stateArr[i+1][i+l-2] == 1)
				{
					stateArr[i][i + l - 1] = 1;
					if (l>maxLeng)
					{
						maxLeng = l;
						start = i;
					}
				}
			}
		}
		return s.substr(start, maxLeng);
	}

};

#if 0

int main()
{
	Solution p; 
	string str = "ccc";
	string s = p.longestPalindrome(str);
	system("pause");
	return 0;
}

#endif