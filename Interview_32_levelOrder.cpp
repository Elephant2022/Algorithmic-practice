#include <iostream>
#include <vector>
#include <queue>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
/**
 * 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
 * 
 * 例如:
 * 
 * 给定二叉树: [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * 
 * 返回：
 * [3,9,20,15,7]
 * 
 * 提示：
 * 节点总数 <= 1000
 * 
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
public:
    std::vector<int> levelOrder(TreeNode* root) {
        if (!root) return {};

        std::vector<int> retVec{};
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty())
        {
            auto ptr = queue.front();
            queue.pop();
            if (ptr->left)
            {
                queue.push(ptr->left);
            }
            if (ptr->right)
            {
                queue.push(ptr->right);
            }
            
            retVec.emplace_back(ptr->val);
        }
        return retVec;
    }
};