/*

LeetCode #1791. 找到星形圖的中心 Find Center of Star Graph

A. 題目
有一個無向的星型圖，其 n 個節點分別被編號為 1 到 n。一個星型圖有一個中心節點，且該節點正好透過 n-1 個邊連接到其他所有的節點。

給定一個二維整數向量 edges，其中 edges[i] = [u_i,v_i] 代表節點 u_i 與 v_i  間有一條邊。回傳該星型圖的中心節點。

B. 出處
https://leetcode.com/problems/find-center-of-star-graph/

*/

class Solution{
public:
	int findCenter(vector<vector<int>>& edges){
		// 邊的數目 + 1 = 頂點數目
		int len = edges.size() + 1;
		// 本題為無向圖
		// 用向量記錄每個頂點的度數
		vector<int> edge_connected(len, 0);

		// 依序取出每個邊
		// 邊連接到的兩個節點度數都要 + 1
		for (auto& edge:edges){
			edge_connected[edge[0] - 1]++;
			edge_connected[edge[1] - 1]++;
		}

		// 檢查每個邊的度數
		// 中心節點的度數為 n-1
		for (int i = 0; i < len; i++){
			if (edge_connected[i] == len - 1){
				return i + 1;
			}
		}
		return -1;
	} // end of find Center;
}; // end of Solution
