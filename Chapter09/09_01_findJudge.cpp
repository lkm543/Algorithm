/*

LeetCode #997. 尋找小鎮法官 Find the Town Judge

A. 題目
在一個小鎮裡，有 n 個居民分別被編號為 1 到 n。傳言其中一個居民其實是秘密的小鎮法官。

如果小鎮法官存在，那麼：
	a. 該法官不信任任何人
	b. 所有人（除了法官自己）都信任小鎮法官
	c. 只有剛好一個人滿足前兩項條件

給定一個向量 trust，trust[i] = [a,b] 代表 a 居民信任 b 居民。如果小鎮法官存在，且身份可以被判斷，回傳小鎮法官的編號，否則回傳 -1。

B. 出處
https://leetcode.com/problems/find-the-town-judge/

*/

class Solution{
public:
	int findJudge(int n, vector<vector<int>>& trust){
		// 用兩個向量分別記錄每個點的入度與出度
		// 入度與出度初始化為 0
		vector<int> in_degree(n, 0);
		vector<int> out_degree(n, 0);

		// 依序取出每個邊
		// 根據邊的資訊，統計每個頂點的入度與出度
		for (vector<int>& edge: trust){
			// 邊的方向為 edge[0] -> edge[1]
			// 居民編號為 1 到 n
			// 對應索引值編號 0 到 n - 1
			in_degree[edge[1] - 1]++;
			out_degree[edge[0] - 1]++;
		}

		// 檢查每個邊的入度與出度
		for (int i = 0; i < n; i++){
            // 有符合小鎮法官定義的居民時，回傳編號
			if (in_degree[i] == n - 1 && out_degree[i] == 0){
				return i + 1;
			}
		}
		// 沒有符合條件的頂點時
		return -1;
	} // end of findJudge
}; // end of Solution
