#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <list>
using namespace std;

// 邊的結構
typedef struct{
    int from;
    int to;
    // 目前流量
    int flow;
    // 容量
    int capacity;
}edge;

class Graph{
    private:
        int vertex;
        // 每個邊對應的 list 形成的向量
        vector<list<edge*>> edges;
    public:
        Graph(int);
        void Print_Edges();
        bool Add_Edge(int, int, int=1);
        int Network_Flow(int, int);
};

Graph::Graph(int v){
	// 設定頂點數
	vertex = v;
	// 把向量的長度設為 vertex
	edges.resize(vertex);
}

bool Graph::Add_Edge(int from, int to, int capacity){
    edges[from - 1].push_back(new edge{from - 1, to - 1, 0, capacity});
    edges[to - 1].push_back(new edge{to - 1, from - 1, 0, capacity}); // Undirected graph
}

int Graph::Network_Flow(int s, int t){
    s--;
    t--;
    // 記錄最大流流量
    int max_flow = 0;
    while(true){
        // Step 1: 用廣度優先搜尋找到新的增廣路徑
        queue<vector<int>> data;
        // 記錄是否找到增廣路徑
        bool found = false;
        vector<int> initial_path;
        vector<int> current;
        vector<int> visited(vertex);
        initial_path.push_back(s);
        // 沒走過：0、有走過：1
        visited[s] = 1;
        data.push(initial_path);
        while(!data.empty()){
            // 取出 queue 中的第一個路徑
            current = data.front();
            data.pop();
            int now = current.back();
            // 檢查目前頂點是否已經到達匯點 t
            // 若已經到達匯點 t
            if(now == t){
                found = true;
                break;
            }
            // 還未到達匯點 t
            else{
                for(auto iter=edges[now].begin(); iter!=edges[now].end(); iter++) {
                    auto target = *iter;
                    // 往有剩餘流量、還未造訪過的頂點方向移動
                    if(target->capacity > target->flow && visited[target->to] == 0) {
                        // 在原本的路徑後加上新造訪的頂點
                        vector<int> new_path = current;
                        new_path.push_back((*iter)->to);
                        // 記錄該頂點已經造訪過
                        visited[(*iter)->to] = 1;
                        data.push(new_path);
                    } // end of inner if
                } // end of for
            } // end of outer if
        } // end of while

        // 沒有找到增廣路徑
        if(!found)
            break;
        // Step2: 找到增廣路徑中剩餘容量最小的邊
        int minimal = 2147483647;
        for(int i = 0; i < current.size() - 1; i++){
            int u = current[i];
            int v = current[i + 1];
            // 要得到邊(u,v)的剩餘容量，只能從 edges 中尋找
            // 若改用矩陣方式儲存圖，會較方便
            for(auto iter=edges[u].begin(); iter!=edges[u].end(); iter++){
                // 在 u 的出邊中找到指向 v 的那條
                // 比較 minimal 與邊的剩餘容量
                int residual = (*iter)->capacity - (*iter)->flow;
                if((*iter)->to == v && residual < minimal){
                    minimal = residual;
                }
            } // end of inner for
        } // end of outer for
        // Step3: 更新殘餘網路
        for(int i = 0; i < current.size() - 1; i++){
            int u = current[i];
            int v = current[i + 1];
            for(auto iter=edges[u].begin(); iter!=edges[u].end(); iter++){
                // 在 u 的出邊中找到指向 v 的那條
                if((*iter)->to == v){
                    (*iter)->flow += minimal;
                }
            }
        }
        max_flow += minimal;
    }
    return max_flow;
}

int main(){
	Graph g(6);
	g.Add_Edge(1,2,5);
	g.Add_Edge(1,3,3);
	g.Add_Edge(2,3,2);
	g.Add_Edge(2,4,3);
	g.Add_Edge(3,5,6);
	g.Add_Edge(4,5,2);
	g.Add_Edge(4,6,5);
	g.Add_Edge(5,6,2);
	cout << "Max Flow: " << g.Network_Flow(1, 6);
	return 0;
}
