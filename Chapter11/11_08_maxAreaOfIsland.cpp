/*

LeetCode #695. 最大島嶼的面積 Max Area of Island

A. 題目
給定一個 m×n 的二元陣列 grid，一個「島嶼」是一些上下左右連接在一起的「1」，假設 grid 的邊界外全部都是代表水的「0」。

一個島嶼的面積是組成整個島嶼的「1」的個數，回傳整個 grid 中最大島嶼的面積，如果沒有任何島嶼，回傳 0。

B. 出處
https://leetcode.com/problems/max-area-of-island/

*/

class Solution{
	// 從 (i, j) 開始深度優先搜尋，並同時計算面積
	int Area(vector<vector<int>>& grid, int i, int j, int row, int col){
		// 超出邊界時，回傳面積 0
		if (i < 0 || j < 0)
			return 0;
		if (i >= row || j >= col)
			return 0;
		// 遇到海洋或已經走過的陸地時，回傳 0
		if (grid[i][j] == 0 || grid[i][j] == -1)
			return 0;

		// 把現在造訪的陸地值改為 -1
		grid[i][j] = -1;

		// 往四個方向移動
		int up = Area(grid, i - 1, j, row, col);
		int down = Area(grid, i + 1, j, row, col);
		int left = Area(grid, i, j - 1, row, col);
		int right = Area(grid, i, j + 1, row, col);

		// 回傳的面積是目前方格面積 1
		// 加上往四個方向移動後繼續處理所得面積
		return up + down + left + right + 1;
	}	

public:
	int maxAreaOfIsland(vector<vector<int>>& grid){
		// 取出 grid 的大小
		int row = grid.size();
		int col = grid[0].size();
		// 最大島嶼面積
		int max_area = 0;

		for (int i = 0; i < row; i++){
			for (int j = 0; j < col ; j++){
				// 遇到陸地 1 時就進行深度優先搜尋
				if (grid[i][j] == 1){
					int tmp = Area(grid,i,j,row,col);
					max_area = max_area > tmp ?
                                max_area : tmp;
				}
				
			}
		}
		return max_area;
	} // end of maxAreaOfIsland
}; // end of Solution
