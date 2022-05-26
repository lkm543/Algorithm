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
    // 儲存頂點顏色的向量
    vector<int> color;
    // 儲存邊的向量
    vector<vector<int>> edges;
	bool check(int vertex){      
		// 把目前頂點 vertex 塗成灰色
		color[vertex] = 1;
		// 檢查頂點 vertex 的每個相鄰頂點
		for (int i = 0; i < edges[vertex].size(); i++){
			// 如果該相鄰頂點是白色
            if (color[edges[vertex][i]] == 0){
				// 從該相鄰頂點出發，再往下檢查是否有環
                bool cycled = check(edges[vertex][i]);
                // 往下找有環時，回傳 true，代表圖中有環
                if (cycled) return true;
			}
			// 如果該相鄰頂點是灰色
			else if (color[edges[vertex][i]] == 1){
                // 相鄰頂點是灰色，回傳 true，代表圖中有環
				return true;
			}
		}
		// 頂點 vertex 處理，塗黑
		color[vertex] = 2;
        // 從這個頂點向下都沒有遇到環時，回傳 false
        return false;
	}

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        // 初始化 color 與 edges 向量
        color.resize(numCourses);
        edges.resize(numCourses);

        // 取出先修資訊建立每條邊
        for (auto edge:prerequisites){
            // edge[1] -> edge[0]
            edges[edge[1]].push_back(edge[0]);
        }

        // 不一定是連通圖
        // 如果跑完一次 DFS 還有白色頂點，要再做另一次 DFS
        for (int i = 0; i < numCourses; i++){
            // 確定從頂點 i 出發會不會有環
            if (color[i] == 0){
                bool cycled = check(i);
                // 有環時回傳 false，代表無法把所有課修完
                if (cycled)
                    return false;
            }
        }
        return true;
    } // end of canFinish
}; // end of Solution
