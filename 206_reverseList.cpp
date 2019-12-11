#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
/*
 *��תһ��������
 *
 *ʾ��:
 *
 *����: 1->2->3->4->5->NULL
 *���: 5->4->3->2->1->NULL
 *����:
 *����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿
 *
 *��Դ�����ۣ�LeetCode��
 *���ӣ�https://leetcode-cn.com/problems/reverse-linked-list
 *����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
public:
	/*�ݹ�*/
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode *p = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;

		return p;
	}

	/*����*/
	ListNode* reverseList(ListNode* head) {
		ListNode *res = NULL, *cur = head;
		while (cur)
		{
			head = head->next;
			cur->next = res;
			res = cur;
			cur = head;
		}

		return res;
	}
};
