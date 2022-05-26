/*

LeetCode#1584. Min Cost to Connect All Points

A. 題目
給定一個陣列 points，代表了二維平面上一些頂點的整數座標，points[i] = [x_i,y_i]。

連接兩個頂點  [x_i,y_i] 和 [x_j,y_j] 的成本設定為 |x_i-x_j |+|y_i-y_j |，也就是 x 座標相減的絕對值與 y 座標相減的絕對值之和。

回傳要連接所有頂點的最小成本。

B. 出處
https://leetcode.com/problems/min-cost-to-connect-all-points/

*/

// 邊的結構
struct edge{
	int from;
	int to;
	int cost;
};

// 邊的排序函式
class compare{
public:
	bool operator()(edge &e1, edge &e2){
		return e1.cost > e2.cost;
	}
};

class Solution{
	vector<int> MST_set;
	// Find_Set
	int Find_Set(int current){
		int root = current;
		while (MST_set[root]>=0){
			root = MST_set[root];
		}
		while (current!=root){
			int predecessor = MST_set[current];
			MST_set[current] = root;
			current = predecessor;
		}
		return root;
	}
	// Merge_Set
	void Merge_Set(int u, int v){
		int u_root = Find_Set(u);
		int v_root = Find_Set(v);
		if (u_root == v_root){ return ; }
		if (MST_set[u_root] < MST_set[v_root]){
            MST_set[u_root] += MST_set[v_root];
            MST_set[v_root] = u_root;
        } else {
            MST_set[v_root] += MST_set[u_root];
            MST_set[u_root] = v_root;
        }
	}
public:
	int minCostConnectPoints(vector<vector<int>>& points){
		// 已加入的邊數
		int completed = 0;
		int total_cost = 0;
		int vertex = points.size();
		MST_set.resize(vertex);
		priority_queue<edge, vector<edge>, compare> 
            sorted_edges;

		// 計算所有邊的成本，並生成該條邊
		for (int i = 0; i < vertex; i++){
			MST_set[i] = -1;
			// 在任兩個點間都加上一條邊edge(i, j)
			for (int j = i + 1; j < vertex; j++){ 
				// 計算 cost
				int current_cost = 
                    abs(points[i][0] - points[j][0]) +
                    abs(points[i][1] - points[j][1]);
				edge current = {i, j, current_cost};
				sorted_edges.push(current);
			} // end of inner for
		} // end of outer for
        // 依序取出所有邊作處理
		while (!sorted_edges.empty() &&
               completed < vertex - 1)
        {
			edge current = sorted_edges.top();
			sorted_edges.pop();
            // 若 current 為 crossing edge
			if (Find_Set(current.from) !=
                Find_Set(current.to))
            {
				Merge_Set(current.from, current.to);
				total_cost += current.cost;
				completed++;
			}
		}
		// 回傳最小成本
		return total_cost;
	} // end of minCostConnectPoints
}; // end of Solution
