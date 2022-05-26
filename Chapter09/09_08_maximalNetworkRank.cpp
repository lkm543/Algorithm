/*

LeetCode #1615. 最大網路排序 Maximal Network Rank

A. 題目
共有 n 個城市，且有一些道路連接其間。每個 roads[i] = [a_i,b_i] 代表了 a_i 城市和 b_i 城市之間的一條雙向道路。

兩個不同城市間的「網路排序」被定義為連接到這兩個城市的道路數量總和，如果一條路連接的正好就是這兩個城市，只能計算一次。「最大網路排序」指的是這些城市當中，每一對（兩個城市）的網路排序中，其值最大者。

給定整數 n 和陣列 roads，回傳所有城市中能找到的最大網路排序。

B. 出處
https://leetcode.com/problems/maximal-network-rank/

*/

class Solution{
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads){
		// 記錄每個城市連接到幾條道路
		vector<int> numbers(n, 0);
		// 記錄每對城市間是否有道路直接相連
        // 大小為 n x n
		vector<vector<bool>> connected(n, vector<bool>(n, false));

		// 依序針對每條道路處理
		for(auto& road : roads){
			// road[0] <-> road[1]
			// 調整起點與終點城市的連接道路數量
			numbers[road[0]]++;
			numbers[road[1]]++;

			// 記錄城市間的相連情形
			connected[road[0]][road[1]] = true;
			connected[road[1]][road[0]] = true;
		}
		// 負無限大
		int max = -2147483648;
		int current;

		// 用雙重迴圈計算每對城市的網路排序
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				// 不與自己城市計算
				if(i == j)
					continue;
				// 兩個城市間有道路直接連接
                else if (connected[i][j])
					current = numbers[i] + numbers[j] - 1;
				// 兩個城市間沒有道路直接連接
                else 
					current = numbers[i] + numbers[j];
                // 取出最大值
				max = max > current ? max : current;
			}
		}
		// 回傳得到的網路排序中的最大值
		return max;
	} // end of maximalNetworkRank
}; // end of Solution
