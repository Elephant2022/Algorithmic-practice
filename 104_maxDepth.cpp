#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
/*
 *给定一个二叉树，找出其最大深度。
 *
 *二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 *
 *说明: 叶子节点是指没有子节点的节点。
 *
 *示例：
 *给定二叉树 [3,9,20,null,null,15,7]，
 *
 *	  3
 *	 / \
 *	 9  20
 * /  \
 *15   7
 *返回它的最大深度 3 。
 *
 *来源：力扣（LeetCode）
 *链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
 *著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
public:
	//递归
	int maxDepth(TreeNode* root) {
		int depth = 0;
		if (root)
		{
			depth = 1 + max(maxDepth(root->left), maxDepth(root->right));
		}
		return depth;
	}

	//尾递归
	int maxDepth(TreeNode* root) {
		int maxDepth = 0;
		dfs(root, 0, maxDepth);
		return maxDepth;
	}

	void dfs(TreeNode* root, int depth, int& maxDepth) {
		if (root) {
			depth = depth + 1;
			maxDepth = maxDepth < depth ? depth : maxDepth;
			if (root->left) {
				dfs(root->left, depth, maxDepth);
			}
			if (root->right) {
				dfs(root->right, depth, maxDepth);
			}
		}
	}

	//迭代
	int maxDepth(TreeNode* root)
	{
		if (!root) {
			return 0;
		}

		stack<pair<TreeNode*, int>>s;

		TreeNode*p = root;
		int maxdeep = 0;
		int deep = 0;
		while (p || !s.empty()) {
			//一直遍历所有的左节点；
			while (p) {
				s.push(pair<TreeNode*, int>(p, deep + 1));
				p = p->left;
				deep++;
			}
			p = s.top().first;
			deep = s.top().second;
			maxdeep = max(maxdeep, deep);
			s.pop();
			p = p->right;
		}
		return maxdeep;
	}
};