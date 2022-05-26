/*

LeetCode #51. N 皇后問題 N-Queens

A. 題目
「N 皇后問題」指的是要在 n×n 的西洋棋盤上放置 N 個皇后，使得皇后間不會互相攻擊。給定一個整數 n，以任意順序回傳「N 皇后問題」所有可行的解。

回傳時，需以 'Q' 和 '.'（分別代表擺放皇后的位置和空位）來表示整個棋盤上的分佈。

B. 出處
https://leetcode.com/problems/n-queens/

*/

class Solution{
	// 儲存目前皇后位置的堆疊
	stack<int> Positions;
	// 回傳的結果
	vector<vector<string>> result;
	// 檢查新皇后位置 (row, col) 是否合法
	bool Available(stack<int> s, int row, int col){
		if (s.empty()){return true;}
		int col_prev_queen = s.top();
		s.pop();
		bool result = true;

		int diff_c = col - col_prev_queen;
		int diff_r = row - s.size();

		if (col==col_prev_queen)
			result = false;
		if (diff_c==diff_r)
			result = false;
		if (diff_c==-1*diff_r)
			result = false;
		if (result)
			result = Available(s,row,col);
		return result;
	}

	// 生成一個可行解用 'Q' 和 '.' 表示
	vector<string> Add_Solution(stack<int>& s, int n){
		if (s.empty()){return {};}
		// 從可行解 s 中取出一個橫列的皇后位置
		int col = s.top();
		s.pop();
		// 遞迴得到前面所有橫列產生的向量 this_solution
		// 比如得到 ["..Q.","Q...","...Q"]
		vector<string> this_solution = Add_Solution(s, n);
		// 產生目前橫列的表達方式
		string result_str;

		// 除了要放的位置 col 外，用 '.' 補滿
		// 比如得到 ".Q.."
		for (int i = 0; i < col; i++){
			result_str += '.';
		}
		result_str += 'Q';
		for (int i = col + 1; i < n; i++){
			result_str += '.';
		}
		s.push(col);
		// 在 this_solution 中加上目前橫列的內容
        this_solution.push_back(result_str);
		return this_solution;
	}

	int KQueens(stack<int>& s, int N){
        // 找到一個可行解
		if (s.size() == N){
            // Add_Solution 產生對應的向量後加到 result 中
			result.push_back(Add_Solution(s,N));
		}
		int counts = 0;
		for (int i = 0; i < N; i++){
			if (Available(s, s.size(), i)){
				s.push(i);
				counts += KQueens(s,N);
				s.pop();
			}
		}
		return counts;
	}
public:
	vector<vector<string>> solveNQueens(int n){
		KQueens(Positions, n);
		return result;
	} // end of solveNQueens
}; // end of Solution
