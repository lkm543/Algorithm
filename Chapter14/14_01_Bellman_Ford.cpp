#include <iostream>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <list>
#include <limits>

using namespace std;

// 代表邊的結構
// 只需要紀錄指到的頂點即可
typedef struct{
	int to;
	int weight;
}edge;

class Graph{
    private:
    	vector<int> distance;
    	vector<int> predecessor;
        int vertex;
        // 每個邊對應的 list 形成的向量
        vector<list<edge*>> edges;
        bool Relax(int, int, float);
        void Initialize(int);
    public:
        Graph(int);
        bool Add_Edge(int, int, int=1);
        bool Bellman_Ford(int);
        void Print_Path(int);
};

Graph::Graph(int v){
	// 設定頂點數
	vertex = v;
	// 把向量的長度設為 vertex
	edges.resize(vertex);
	distance.resize(vertex);
	predecessor.resize(vertex);
}

bool Graph::Add_Edge(int from, int to, int weight){
	edges[from - 1].push_back(new edge{to - 1, weight});
}

bool Graph::Relax(int from, int to, float weight){
    if(distance[to] > distance[from] + weight){
        distance[to] = distance[from] + weight;
        predecessor[to] = from;
        return true;
    }
    return false;
}

void Graph::Initialize(int s){
    distance.clear();
    predecessor.clear();
    for(int i = 0; i < vertex; i++){
        distance[i] = numeric_limits<int>::max();
        predecessor[i] = -1;
    }
    // 起點距離為 0
    distance[s] = 0;
}

bool Graph::Bellman_Ford(int s){
	s--;
    // 初始化
    Initialize(s);
    list<edge*>::iterator it;
    // 重複 v - 1 輪
    for(int i = 0; i < vertex - 1; i++){
        // 每一輪對所有邊進行 Relax
        for(int j = 0; j < vertex; j++){
            for(it = edges[j].begin(); it != edges[j].end();it++){
                Relax(j, (*it)->to, (*it)->weight);
            }
        }
    }
    // 判斷負環是否存在
    for(int j = 0; j < vertex; j++){
        for(it = edges[j].begin(); it != edges[j].end(); it++){
            // 負環存在
            if(distance[(*it)->to] > distance[j] + (*it)->weight)
                return false;
        }
    }

    // 印出距離
    for(int j = 0; j < vertex; j++){
    	cout << s + 1 << "<->" << j + 1 << ":" << distance[j] << endl;
    }
    return true;
}

void Graph::Print_Path(int dest){
    dest--;
    if(distance[dest] != numeric_limits<int>::max()){
        cout << "Distance:" << distance[dest] << endl;
        stack<int> path;
        path.push(dest);
        while(predecessor[dest] != -1){
            path.push(predecessor[dest]);
            dest = predecessor[dest];
        }
        cout << "Path:";
        while(!path.empty()){
            int vertex_now = path.top();
            path.pop();
            cout << vertex_now + 1 << " ";
        }
        cout << endl;
    }
}

int main(){
	Graph g(7);
    g.Add_Edge(1,2,20);
    g.Add_Edge(1,3,10);
    g.Add_Edge(1,4,15);
    g.Add_Edge(2,5,10);
    g.Add_Edge(3,5,10);
    g.Add_Edge(3,4,10);
    g.Add_Edge(3,6,5);
    g.Add_Edge(4,7,25);
    g.Add_Edge(6,7,10);
    g.Add_Edge(5,7,20);
    // 從 1 開始
	g.Bellman_Ford(1);
    // 找 1 到 7 的最短路徑
	g.Print_Path(7);
	return 0;
}
