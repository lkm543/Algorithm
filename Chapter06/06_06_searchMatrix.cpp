/*

LeetCode#240  Search a 2D Matrix II

A. 題目
試寫一個有效率的演算法來搜尋大小為 m×n 的整數二維陣列中的某個目標值，若該值存在在陣列中，回傳 true，否則回傳 false。

該陣列有下列性質：
	a. 每個橫列中，整數由左到大遞增
	b. 每個直行中，整數由上到下遞增

B. 出處：
https://leetcode.com/problems/search-a-2d-matrix-ii/

*/

class Solution{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target){
	    // 例外處理：陣列是空的
	    if (matrix.empty())
	    	return false;
	    if (matrix[0].empty())
		    return false;

	    // 一般情形
	    // 取得陣列大小
	    int rows = matrix.size();
	    int cols = matrix[0].size();
	    // 從右上角的元素出發
	    int row_now = 0;
	    int col_now = cols - 1;

	    // 超出左邊與下方邊界前繼續執行
	    while (row_now < rows && col_now >= 0){
            // 找到目標，回傳 true
		    if (matrix[row_now][col_now] == target){
			    return true;
            }
		    // 往左找
		    else if (matrix[row_now][col_now] > target){
		    	col_now--;
            }
		    // 往下找
		    else {
			    row_now++;
            }
        } // end of while
        return false;
	} // end of searchMatrix
}; // end of Solution
