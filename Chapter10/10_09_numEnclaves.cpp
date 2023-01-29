/*
LeetCode #1020. 飛地數目 Number of Enclaves
A. 題目
給定一個二維、大小為 m×n 的二元陣列 grid，每個值為 0 的方格代表海，值為 1 的方格代表陸地。
一次「移動」是從一個陸地方格走到相鄰（上下左右四個方向）的陸地方格，或者走到邊界之外。回傳所有「從這裡出發時，不論走多少步，都無法走到邊界外」的陸地方格數量。
B. 出處
https://leetcode.com/problems/number-of-enclaves/
*/

class Solution{
public:
	int numEnclaves(vector<vector<int>>& grid){
		// 取得 grid 的大小
		int rows = grid.size();
		int cols = grid[0].size();
		// 記錄飛地數目
		int sum = 0;

    	queue<int> Position;
        
		for (int i = 0; i < rows; i++){
			// Position = x*cols+y
			// 檢查最左邊的直行
			if (grid[i][0]){
				// 對應的 Position 是 i*cols
                Position.push(i * cols);
			}
			// 檢查最右邊的直行
			if (grid[i][cols - 1]){
				// 對應的 Position 是 i * cols + (cols - 1)
                Position.push(i * cols + (cols - 1));
			}
		}
        
		for (int j = 0; j < cols; j++){
			// 檢查最上面的橫列
			if (grid[0][j]){
				// 對應的 Position 是 j
                Position.push(j);
			}
			// 檢查最下面的橫列
			if (grid[rows - 1][j]){
				// 對應的 Position 是 (rows-1)*cols+j
                Position.push((rows - 1) * cols + j);
			}
		}

	// 透過兩個陣列設定上下左右四個方向的 x、y 偏移量
	int direction_x[4] = {-1,1,0,0};
	int direction_y[4] = {0,0,-1,1};

	while(!Position.empty()){
		// 取出 Queue 中最前面的元素，並轉換為 (x,y) 形式
		int P = Position.front();
		Position.pop();
		int x = P / cols;
		int y = P % cols;

        if(grid[x][y] == 0)
            continue;

		// 把取出的點改為 0				
        grid[x][y] = 0;

		// 透過 x、y 偏移量，往上下左右四個方向移動
		for (int i = 0; i < 4 ; i++){
			int new_x = x + direction_x[i];
			int new_y = y + direction_y[i];
			// 邊界處理
			if (new_x < 0 || new_y < 0)
                continue;
			if (new_x >= rows||new_y >= cols)
                    continue;

                // 如果移動後是 0，不需加到 Queue 中
                if (grid[new_x][new_y] == 0){
                    continue;
                }
                // 移動後方格是 1 時需要加到 Queue 中處理
                Position.push(new_x * cols + new_y);
            }
        } // end of while

		// 用雙重迴圈檢查剩下幾個 1
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				if (grid[i][j])
					sum++;
			}
		}
        return sum;
	} // end of numEnclaves
}; // end of Solution