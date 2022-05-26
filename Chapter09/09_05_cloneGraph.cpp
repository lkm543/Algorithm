/*

LeetCode #133. 複製圖 Clone Graph

A. 題目
給定連通無向圖中某個節點的參考，回傳對該圖深複製的結果。

圖中的每個節點都含有一個值（整數）和一個含有所有其相鄰頂點的列表List[Node]：

B. 出處
https://leetcode.com/problems/clone-graph/

*/

class Solution{
private:
	// 記錄哪些頂點已經被複製過
	// 從原本圖上的 node 映射到複製出的頂點 clone
	// 只針對還沒複製過的頂點進行複製
	unordered_map<Node*, Node*> Copied;
public:
	Node* cloneGraph(Node* node){
		// 例外處理：傳入的是空指標
		if (node == 0)
            return 0;

		// 一般情形
        // 在 Copied 內尋找 node
        // 如果 find 的結果在容器外時，代表找不到/還沒複製過		   
        if (Copied.find(node) == Copied.end()){
	        // Node 建構式要傳入 val
	        Copied[node] = new Node(node->val);
	        // 把 Node 的所有相鄰節點丟給複製出來的頂點
	        // 且會先對該相鄰節點進行同樣過程
            //（相鄰節點先完成複製後才能被接上來）
	        // 這裡用到深度優先搜尋的概念，可以之後再回頭來看
	        for (Node* neighbor : node->neighbors){
		        (Copied[node] -> neighbors).push_back(cloneGraph(neighbor));
	        }
        }
		return Copied[node];
	} // end of cloneGraph
}; // end of Solution
