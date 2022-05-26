/*

LeetCode #733. 洪水填充 Flood Fill

A. 題目
一個 m×n 的整數陣列 image 代表了一張圖片，其中 image[i][j] 是圖片中一個像素的像素值。

給定三個整數 sr, sc 和 newColor，請用「洪水填充」的方式從 image[sr][sc] 開始把整張圖片塗成新的顏色。

所謂「洪水填充」，是從起點開始，把該像素的上下左右四個像素中與起點顏色相同者都一起塗成新的顏色 newColor，接下來，把剛才的四個像素的上下左右四個像素中顏色相同者也都塗成 newColor，依此類推，直到用 newColor 填充完所有應被填充的像素。

完成洪水填充後，回傳修改過的 image。

B. 出處
https://leetcode.com/problems/flood-fill/

*/

class Solution{
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
		// 取得二維陣列 image 的大小
		int rows = image.size();
		int cols = image[0].size();

		// BFS 會用到的 Queue
		// 可以使用一維陣列來表示二維的資料
		queue<int> Pixels;

		// image[x][y] = x*cols + y = P
		// (x,y) = (P/cols, P%cols)
		// 在 Queue 中加入起點 (sr, sc)
		Pixels.push(sr * cols + sc);
		// 起點原本的顏色
		int color_replaced = image[sr][sc];

		// 例外處理：newColor 和起點原本的顏色相同
		// 不需做任何動作
		// 若不做此例外處理，可能產生無窮迴圈
        if (color_replaced == newColor){
			return image;
		}		

		// 先把起點換成 new_color
		image[sr][sc] = newColor;

		// Queue 中還有資料時繼續進行
		while(!Pixels.empty()){
			// 取出 Queue 中最前面的資料
			int current = Pixels.front();
			Pixels.pop();

			// 把 Queue 中資料從位置 P 的形式回復為 (x, y) 形式
			int x = current / cols;
			int y = current % cols;

            // 需在邊界內，且與原點原本的顏色相同時才進行處理
			// 檢查下方像素
			if (x + 1 < rows && image[x + 1][y] == color_replaced){
				// 顏色塗成 newColor
				image[x + 1][y] = newColor;
				// 從這個像素的座標 (x,y) 換算出這個點的位置 P
				int P = (x + 1) * cols + y;
				// 把位置 P 加到 Queue 中
				Pixels.push(P);
			}
			// 檢查上方像素
			if (x - 1 >= 0 && image[x - 1][y] == color_replaced){
				image[x - 1][y]=newColor;
				int P = (x - 1) * cols + y;
				Pixels.push(P);
			}
			// 檢查左方像素
			if (y - 1 >= 0 && image[x][y - 1] == color_replaced){
				image[x][y - 1]=newColor;
				int P = x * cols + (y - 1);
				Pixels.push(P);
			}
			// 檢查右方像素
			if (y + 1 >= 0 && image[x][y + 1] == color_replaced){
				image[x][y + 1] = newColor;
				int P = x * cols + (y + 1);
				Pixels.push(P);
			}
		} // end of while
		return image;
	} // end of floodFill
}; // end of Solution
