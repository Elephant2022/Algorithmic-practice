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
 *反转一个单链表。
 *
 *示例:
 *
 *输入: 1->2->3->4->5->NULL
 *输出: 5->4->3->2->1->NULL
 *进阶:
 *你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/reverse-linked-list
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	/*递归*/
	ListNode* reverseList(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode *p = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;

		return p;
	}

	/*迭代*/
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
