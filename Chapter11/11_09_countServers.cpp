/*

LeetCode #1267. 溝通伺服器的總數 Count Servers that Communicate

A. 題目
給定一個 m×n 的整數陣列，代表了一個伺服器中心的地圖，陣列中每個 1 代表該處有伺服器，0 代表該處沒有伺服器。兩個伺服器只有位在相同直行或相同橫列時，被認為會互相「溝通」。回傳會和其他伺服器溝通的伺服器總數。

B. 出處
https://leetcode.com/problems/count-servers-that-communicate/

*/

class Solution{
	int Connected(vector<vector<int>>& grid, int i, int j, int row, int col){
		// 不處理的情形
		if (grid[i][j] == -1)
			return 0;
		// 把目前伺服器標成 -1 代表已處理過
		grid[i][j] = -1;		
		int row_sum = 0, col_sum = 0;

		// 檢查同橫列的伺服器
		for (int m = 0; m < col; m++){
			if (grid[i][m] == 1){
				row_sum += Connected(grid, i, m, row, col);
			}
		}
		// 檢查同直行的伺服器
		for (int n = 0; n < row; n++){
			if (grid[n][j] == 1){
				col_sum += Connected(grid, n, j, row, col);
			}
		}
		return row_sum + col_sum + 1;
	}

public:
	int countServers(vector<vector<int>>& grid){
		// 取得 grid 的大小
		int row = grid.size();
		int col = grid[0].size();
		// 記錄會與其他伺服器溝通的伺服器數量
		int counts = 0;
        int tmp;

		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				if (grid[i][j] == 1){
					// tmp 從現在這台伺服器向外深度優先搜尋
					// 得到過程中共有幾台有在溝通的伺服器
					tmp = Connected(grid, i, j, row, col);
					// tmp = 1 時，目前的伺服器沒有向外溝通
					// 有溝通時，counts 加上 DFS 找到的
					if (tmp > 1)
						counts += tmp;
				} 
			} // end of inner for
		} // end of outer for
		return counts;
	} // end of countServers
}; // end of Solution
