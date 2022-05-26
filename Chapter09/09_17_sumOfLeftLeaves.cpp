/*

LeetCode #404. 左葉節點的和 Sum of Left Leaves

A. 題目
給定一個二元樹的根節點，回傳該樹中所有的左葉節點。

B. 出處
https://leetcode.com/problems/sum-of-left-leaves/

*/

class Solution{
public:
	int sumOfLeftLeaves(TreeNode* root){
		// 例外處理：樹是空的
		if (root == 0)
			return 0;
		// 一般情形
		int sum = 0;
		queue<TreeNode*> BFS;

		// 從根節點開始做 BFS
		BFS.push(root);
		while(!BFS.empty()){
			// 從 Queue 中取出最前面的元素
			TreeNode* current = BFS.front();
			BFS.pop();
			// 檢查目前的節點 current（比如範例中的 3）的左節點
            // 是否為葉節點（如範例中 9 的左右節點都是空的）
            // current->left!=0：current 有左節點
            // current->left->left == 0：左節點的左節點是空的
            // current->left->right == 0：左節點的右節點是空的
			if (current->left != 0){
				if (current->left->left == 0 && current->left->right == 0){
					// 把該左節點的值加入 sum 中
					sum += current->left->val;
				}
			}
			// 把 current 的子節點加入 Queue 中
			// 使樹中每一階層的節點都被依序加入 Queue
			if (current->left != 0){
				BFS.push(current->left);
			}
			if (current->right != 0){
				BFS.push(current->right);
			}
		} // end of while
		return sum;
	} // end of sumOfLeftLeaves
}; // end of Solution
