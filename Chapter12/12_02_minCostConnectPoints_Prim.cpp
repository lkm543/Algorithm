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

class Solution{
	vector<int> predecessor;
	vector<int> distance;
	vector<bool> finished;
	vector<list<edge>> edges;
	int vertex;

    int Find_Minimal_Distance(){
		int minimal = INT_MAX;
		int index = -1;
		for (int i=0 ; i<vertex ; i++){
			if (distance[i]<minimal && !finished[i]){
				index = i;
				minimal = distance[i];
			}
		}
		return index;
	}
public:
	int minCostConnectPoints(vector<vector<int>>& points){
        // 初始化
        int total_cost = 0;
        vertex = points.size();
        predecessor.resize(vertex);
        distance.resize(vertex);
        finished.resize(vertex);
        edges.resize(vertex);

        // 加入邊與權重
        for (int i = 0; i < vertex; i++){
            for (int j=i + 1; j < vertex; j++){
                int current_cost = 
                    abs(points[i][0]-points[j][0]) + 
                    abs(points[i][1]-points[j][1]);
                edge current1{i, j, current_cost};
                edge current2{j, i, current_cost};
                edges[i].push_back(current1);
                edges[j].push_back(current2);
            }	
        }

        for (int i = 0; i < vertex; i++){
            predecessor[i] = -1;
            distance[i] = INT_MAX;
            finished[i] = false;
        }

        // 開始把頂點加入 MST 中
        distance[0] = 0;
        int index = 0;
        for (int i = 0; i < vertex; i++){
            index = Find_Minimal_Distance();
            finished[index] = true;
            total_cost += distance[index];
            auto iter = edges[index].begin();
            for (; iter != edges[index].end(); iter++){
                int target = iter->to;
                int current_weight = distance[target];
                int cross_weight = iter->cost;
                if (finished[target]) continue;
                if (cross_weight < current_weight){
                    distance[target] = cross_weight;
                    predecessor[target] = index;
                }
            }
        }
        return total_cost;
	} // end of minCostConnectPoints
}; // end of Solution
