struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
/*
 *给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 *
 *你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 *
 *示例:
 *
 *给定 1->2->3->4, 你应该返回 2->1->4->3.
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode* p = head->next;
		head->next = p->next;
		p->next = head;
		head->next = swapPairs(head->next);

		return p;
	}
};

int main()
{
	ListNode *head = &ListNode(1);
	
	ListNode n2 = ListNode(2);
	head->next = &n2;
	ListNode n3 = ListNode(3);
	n2.next = &n3;
	ListNode n4 = ListNode(4);
	n3.next = &n4;

	Solution ss = Solution();
	ss.swapPairs(head);

	system("pause");

	return 0;
}