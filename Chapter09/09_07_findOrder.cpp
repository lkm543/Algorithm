/*

LeetCode #210. 課程排序II  Course Schedule II

A. 題目
你必須修習總共 numCourses 門課，編號分別為 0 到 numCourses-1。給定一個陣列 prerequisites，其中 prerequisites[i] = [a_i,b_i] 代表必須要先修過「b_i」這門課，才能往下修「a_i」這門課（注意順序不是反過來）。舉例來說，如果有陣列中有 [0,1]，就代表必須先修過課程 1，才可以修課程 0。

回傳任一種能夠把所有課程修完的修課順序，如果沒有任何可行的順序，回傳一個空陣列。

B. 出處
https://leetcode.com/problems/course-schedule-ii/

*/

class Solution{
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
		// 鄰接列表外層是長度為 numCourses 的向量
		// 向量內每個元素都是另一個向量，記錄該課程的先修要求
		vector<vector<int>> edges(numCourses);
		// 儲存回傳結果的陣列
		vector<int> result;

		// 計算每個頂點的入度，初始化為 0
		vector<int> in_degree(numCourses, 0);

		// 依序處理每個先修數字對
		// prerequisite[1] -> prerequisite[0]
		for (auto& pre : prerequisites){
            edges[pre[1]].push_back(pre[0]);
			// 調整頂點的入度 
			in_degree[pre[0]]++;
		}

		// 進行拓樸排序
		// 儲存入度為 0 頂點的佇列
		queue<int> topological_sort;

		// 找到入度為 0 的點，先放入 Queue 中
		for (int i = 0; i < numCourses; i++){
			if (in_degree[i] == 0){
				// 放到佇列中						       
                topological_sort.push(i);
				// 把新增的頂點放到回傳結果中
				result.push_back(i);
			}
		}

		// 當入度為 0 的頂點還未處理完時
		while (!topological_sort.empty()){
			// 從 Queue 中拿出一個入度為 0 的頂點
			int current = topological_sort.front();
			topological_sort.pop();

			// 取出該頂點的所有出邊，調整相鄰頂點的入度
			for (int neighbor : edges[current]){
				// 邊的方向：current -> neighbor
				in_degree[neighbor]--;

                // 如果 neighbor 調整後入度為 0
                // 把該頂點加到佇列中
				if (in_degree[neighbor] == 0){
					topological_sort.push(neighbor);
					// 把新增的頂點放到回傳結果中
					result.push_back(neighbor);
					// 加入拓樸排序的頂點數目加一
				}
			} // end of for
		} // end of while
		// 能形成排序時，回傳結果向量
		if(result.size() == numCourses){
			return result;
		}
		// 不能形成排序時，回傳空向量
        else {
			return vector<int>(0);
		};
	} // end of canFinish
}; // end of Solution
