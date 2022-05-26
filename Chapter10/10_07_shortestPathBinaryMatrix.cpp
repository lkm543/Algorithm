/*

LeetCode #1091. 二元陣列中的最短路徑 Shortest Path in Binary Matrix

A. 題目
給定一個二維、大小為 n×n 的二元陣列 grid，回傳最短「通關路徑」的長度，如果該陣列沒有通關路徑，回傳 -1。

「通關路徑」定義為從左上角（座標 (0,0) 的方格）走到右下角（座標 (n-1,n-1) 的方格）的路徑，且：

	該路徑經過的所有方格值都是 0
	該路徑經過的一個方格與下一個方格有邊相鄰，或者有角相鄰（往上下左右、左上、右上、左下或右下走）

通關路徑的長度指的是該路徑經過的方格數。

B. 出處
https://leetcode.com/problems/shortest-path-in-binary-matrix/

*/

class Solution{
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid){
		// 取出 grid 的大小
		int rows = grid.size();
		int cols = grid[0].size();
		queue<int> Position;

		// 例外處理：如果起點就是 1，沒有路徑，直接回傳 -1
		if (grid[0][0]){
			return -1;
		}

		// 一般情況，從左上角開始
		Position.push(0);

		// 把原本陣列中 1 都改成 -1，避免與距離 1 混淆
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				if (grid[i][j]){
					grid[i][j] = -1;
				}else {  
                    // 把陣列中的 0 都改成 int_max
					grid[i][j] = 2147483647;
				}
			}
		}

		// 起點的距離是 1，因為此時路徑經過了一個方格
		grid[0][0] = 1;

        // 八個方向: 下、上、左、右、右下、左上、左下、右上
		// 如索引值 7 的 (x,y)=(-1,1) 代表往右上移動 
		int direction_x[8] = {1,-1,0,0,1,-1,1,-1};
		int direction_y[8] = {0,0,-1,1,1,-1,-1,1};
        // 開始 BFS
		while(!Position.empty()){
			// 取出 Queue 中最前面的資料
			int current = Position.front();
			Position.pop();

			// 把位置 P 轉換為 (x,y) 形式
			// P = x * cols + y;
			// (x, y) = (P / cols, P % cols)
			int x = current / cols;
			int y = current % cols;

			// 要造訪的方向有 8 個
			// 用設定好的八個方向的 x、y 偏移量來移動
			for (int i = 0; i < 8; i++){
				// 計算出要造訪的下個方格的位置
				int new_x = x + direction_x[i];
				int new_y = y + direction_y[i];
				// 移動前的距離
				int distance = grid[x][y];

				// 如果移動之後超出邊界或者為牆（-1），不處理
                // 直接嘗試其他方向
				if (new_x < 0 || new_y < 0)
					continue;
				if (new_x >= rows || new_y >=cols)
					continue;
				if (grid[new_x][new_y] == -1)
					continue;
				
				// 移動後方格要填上的距離為舊距離 + 1
				int distance_now = distance + 1; 
                // 如果目前的距離比較短
                if (distance_now < grid[new_x][new_y]){
					// 修改移動後方格的距離
					grid[new_x][new_y] = distance_now;
					// 把移動後的方格放入 Queue 中
					int P = new_x * cols + new_y;
					Position.push(P);
				}
			}
		} // end of while
        // 如果右下角方格不是無限大，代表可以走到
        if (grid[rows - 1][cols - 1] != 2147483647)
            return grid[rows - 1][cols - 1];
        else
            return -1;
	} // end of shortestPathBinaryMatrix
}; // end of Solution
