/*

LeetCode #210. 課程排序II  Course Schedule II

A. 題目
你必須修習總共 numCourses 門課，編號分別為 0 到 numCourses-1。給定一個陣列 prerequisites，其中 prerequisites[i] = [a_i,b_i] 代表必須要先修過「b_i」這門課，才能往下修「a_i」這門課（注意順序不是反過來）。舉例來說，如果有陣列中有 [0,1]，就代表必須先修過課程 1，才可以修課程 0。

回傳任一種能夠把所有課程修完的修課順序，如果沒有任何可行的順序，回傳一個空陣列。

B. 出處
https://leetcode.com/problems/course-schedule-ii/

*/

class Solution{
    vector<int> color;
    vector<vector<int>> edges;
	// 儲存拓樸排序的向量
	vector<int> topological_sort;
	bool check(int vertex){
		color[vertex] = 1;
		for (int i = 0; i < edges[vertex].size(); i++){
            if (color[edges[vertex][i]] == 0){                
				// 從該相鄰頂點出發，再往下檢查是否有環
                bool cycled = check(edges[vertex][i]);
                // 回傳 true，代表圖中有環
                if (cycled){return true;}
                
			}
			// 如果該相鄰頂點是灰色
			else if (color[edges[vertex][i]]==1){
                // 該頂點的相鄰頂點是灰色，回傳 true，圖中有環
				return true;
			}
		}
		// 頂點 vertex 處理完成
		color[vertex] = 2;
		// 這裡用的是向量，每次把資料插到向量「前端」
		topological_sort.insert(topological_sort.begin(),vertex);
        return false;
	}

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        // 初始化 color 與 edges 向量
        color.resize(numCourses);
        edges.resize(numCourses);
        // 取出先修資訊建立每條邊
        for (auto edge : prerequisites){
            // edge[1] -> edge[0]
            edges[edge[1]].push_back(edge[0]);
        }
        // 從每個白色頂點出發作 DFS
        for (int i = 0; i < numCourses; i++){
            // 確定從頂點 i 出發會不會有環
            if (color[i] == 0){
                bool cycled = check(i);
                // 有環時回傳 false，代表無法把所有課修完
                if (cycled) return vector <int>(0);
            }
        }
        return topological_sort;
    } // end of findOrder
}; // end of Solution
