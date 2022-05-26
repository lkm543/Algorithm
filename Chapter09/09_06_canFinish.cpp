/*

LeetCode #207. 課程排序 Course Schedule

A. 題目
你必須修習總共 numCourses 門課，編號分別為 0 到 numCourses-1。給定一個陣列 prerequisites，其中 prerequisites[i] = [a_i,b_i] 代表必須要先修過「b_i」這門課，才能往下修「a_i」這門課（注意 b_i 才是先修要求）。

舉例來說，如果有陣列中有 [0,1]，就代表必須先修過課程 1，才可以修課程 0。

如果有任一種方法能夠把所有課程修完，回傳 true，否則回傳 false。

B. 出處
https://leetcode.com/problems/course-schedule/

*/

class Solution{
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
		// 鄰接列表外層是長度為 numCourses 的向量
		// 向量內每個元素都是另一個向量，記錄該課程的先修要求
		vector<vector<int>> edges(numCourses);

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
		// 已經加入過佇列的頂點數目
		int visited = 0;

		// 找到入度為 0 的點，先放入 Queue 中
		for (int i = 0; i < numCourses; i++){
			if (in_degree[i] == 0){
				// 放到佇列中						       
                topological_sort.push(i);
				visited++;
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
				if (in_degree[neighbor]==0){
					topological_sort.push(neighbor);
					// 加入拓樸排序的頂點數目加一
					visited++;
				}
			} // end of for
		} // end of while
		// 所有課程都被加入到拓樸排序中
		if (visited == numCourses){
			return true;
		}
        // 否則代表無法產生拓樸排序，也就是無法修完所有課程
		return false;
	} // end of canFinish
}; // end of Solution
