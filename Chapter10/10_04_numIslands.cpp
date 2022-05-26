/*

LeetCode #200. 島嶼數目 Number of islands

A. 題目
給定一個 n×n 的二維陣列 grid，代表一張地圖，其中 1 代表「陸地」，0 代表「水」，回傳「島嶼的數目」。

一個島嶼被水包圍，陸地間上下左右連接起來就成為一個島嶼，假設陣列的外面四周都是水（島嶼不會延伸超出邊界）。

B. 出處
http://leetcode.com/problems/number-of-islands/

*/

class Solution{
public:
	int numIslands(vector<vector<char>>& grid){
		// 取得 grid 的大小
		int rows = grid.size();
		int cols = grid[0].size();
		// BFS 使用的 Queue
		queue<int> Pixel;
		// 計算島嶼數目
		int islands = 0;

		// 對每筆資料進行處理S
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
		        // 一旦發現一筆資料是未造訪過的陸地，就進行 BF
                // 把 '1' 定義為「未造訪過」
                // 把 '2' 定義為「已造訪過」
				if (grid[i][j] == '1'){
					// 把 grid[i][j] 當作起點進行 BFS
					// 每做一輪 BFS，島嶼數量加 1
					islands++;
					// 先把該頂點標記為已造訪過
					grid[i][j] = '2';
					// 把起點加入 Queue 中
					Pixel.push(i * cols + j);

					// BFS
					while(!Pixel.empty()){
                        // 每次從 Queue 中取出一筆資料
						int current = Pixel.front();
						Pixel.pop();
						int x = current / cols;
						int y = current % cols;

                        // 處理下方
                        if (x + 1 < rows && grid[x + 1][y] == '1'){
	                        grid[x + 1][y] = '2';
	                        Pixel.push((x + 1) * cols + y);
                        }
                        // 處理上方
                        if (x - 1 >= 0 && grid[x - 1][y] == '1'){
	                        grid[x - 1][y] = '2';
	                        Pixel.push((x - 1) * cols + y);
                        }
                        // 處理右方
                        if (y + 1 < cols && grid[x][y + 1] == '1'){
	                        grid[x][y + 1] = '2';
	                        Pixel.push(x * cols + (y + 1));
                        }
                        // 處理左方
                        if (y - 1 >= 0 && grid[x][y - 1] == '1'){
	                        grid[x][y - 1] = '2';
	                        Pixel.push(x * cols + (y - 1));
                        }
					} // end of while
				} // end of if
			} // end of inner for
		} // end of outer for
		return islands;
	} // end of numIslands
}; // end of Solution
