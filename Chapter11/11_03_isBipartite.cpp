/*

LeetCode #785. 判別二分圖 Is Graph Bipartite?

A. 題目
有一個共有 n 個節點的無向圖，每個節點分別被編號為 0 到 n-1。給定一個二維陣列 graph，其中 graph[u] 是含有節點 u 所有相鄰節點的陣列。也就是說，如果 graph[u] 中有節點 v，則節點 u 和節點 v 之間有一條無向邊。

如果一個圖是二分圖，該圖的所有節點可以被分到兩個獨立的集合 A 和 B 之一當中，使得該圖上的每一條邊都是連接一個「集合 A 中的點」與一個「集合 B 中的點」。

只有在該圖為二分圖時，回傳 true。

B. 出處
https://leetcode.com/problems/is-graph-bipartite/

*/

class Solution{
	// 記錄頂點是否造訪過（DFS 中的白、灰、黑）
	vector<int> visited;
	// 頂點的顏色，只有 0 或 1，而-1 代表還沒染過
	vector<int> color;
	bool DFS(int vertex, int color_now, vector<vector<int>>& graph){
		// 頂點塗成灰色
		visited[vertex] = 1;
		// 依序檢查相鄰節點
		for (int i = 0; i < graph[vertex].size(); i++){         
			int vertex_now = graph[vertex][i];
            // 如果相鄰節點的染色與 vertex 的染色衝突
            // 比如 vertex 的染色是「0」，相鄰節點也被染為「0」
            if (color[vertex_now] == color_now)
                return false;
            // 如果相鄰頂點是白色頂點（未造訪過）
            if (visited[vertex_now] == 0){
                // 如果相鄰頂點的染色是「-1」（未染色過）
                if (color[vertex_now] == -1){
                    // 把相鄰頂點染上「相反」顏色
                    // vertex 染色為 1 時，相鄰頂點染上 0
                    // vertex 染色為 0 時，相鄰頂點染上 1
                    color[vertex_now] = !color_now;
                }
                // 往相鄰頂點繼續進行
                bool flag = DFS(vertex_now,
                                !color_now, graph);
                if(!flag){return false;}
            }
		} // end of for
		// 頂點 vertex 處理完成
		visited[vertex] = 2;
		// 若從頂點 vertex 往下染色都不會發生衝突，回傳 true
		return true;
	}

public:
	bool isBipartite(vector<vector<int>>& graph){
		// 取出頂點個數
		int vertex = graph.size();
		visited.resize(vertex);
		// -1 代表還未著色過（黑白染色）
		color.resize(vertex,-1);

		// 對所有白色頂點進行 DFS
		// 過程中用 color 另外染色（與原本的白、灰、黑獨立）
		// 染色順序為 0 1 0 1...
		for (int i = 0; i < vertex; i++){
			if (visited[i] == 0){
				color[i] = 0;
				// 從起點開始，檢查能不能順利進行黑白染色
				// 起點的染色為「0」
				bool flag = DFS(i, 0, graph);
				// 如果染色過程中產生衝突，回傳 false
				// 代表非二分圖
				if(!flag){return false;}
			}
		} // end of for
		// 沒有衝突時，代表為二分圖
		return true;
	} // end of isBipartite
}; // end of Solution
