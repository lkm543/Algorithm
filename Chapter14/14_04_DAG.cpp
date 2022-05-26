#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
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
        vector<int> color;
        stack<int> topological_sort;
        void DFS_Visit_Topological(int);
        void Get_Topological_Sort(int);
        void Initialize(int);
    public:
        Graph(int);
        void Print_Edges();
        bool Add_Edge(int, int, int=1);
        void DAG(int);
        void Print_Path(int);
};

bool Graph::Relax(int from, int to, float weight){
    if(distance[from] == numeric_limits<int>::max())
        return false;
    if(distance[to] > distance[from] + weight){
        distance[to] = distance[from] + weight;
        predecessor[to] = from;
        return true;
    }
    return false;
}

Graph::Graph(int v){
    // 設定頂點數
    vertex = v;
    // 把向量的長度設為 vertex
    color.resize(vertex);
	edges.resize(vertex);
	distance.resize(vertex);
	predecessor.resize(vertex);
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

bool Graph::Add_Edge(int from, int to, int weight){
    edges[from - 1].push_back(new edge{to - 1, weight});
}

void Graph::DFS_Visit_Topological(int current){
    color[current] = 1;
    // 從 current 的鄰邊中找白點繼續往下做深度優先搜尋
    for(auto iter = edges[current].begin();
        iter!=edges[current].end();
        iter++)
    {
        int neighbor = (*iter)->to;
        if(color[neighbor] == 0){
            DFS_Visit_Topological(neighbor);
        }
    }
    color[current] = 2;
    // 從離開 current 後就插入拓樸排序內
    topological_sort.push(current);
}

void Graph::Get_Topological_Sort(int start){
    // 把所有點塗成白色
    fill(color.begin(), color.end(), 0);
    // 從起點開始做拓墣排序
    DFS_Visit_Topological(start);
    for(int i = 0; i < vertex; i++){
        if(color[i] == 0){
            DFS_Visit_Topological(i);
        }
    }
}

void Graph::DAG(int s){
    s--;
    // 初始化
    Initialize(s);
    // 利用深度優先搜尋生成拓樸排序
    Get_Topological_Sort(s);
    cout << "Topological sort:";
    // 依照拓樸排序的順序進行 Relax
    while(!topological_sort.empty()){
        int index = topological_sort.top();
        cout << index + 1 << " ";
        topological_sort.pop();
        // Relax 頂點 index 的 所有出邊
        auto it=edges[index].begin();
        for(; it!=edges[index].end(); it++){
            Relax(index,(*it)->to,(*it)->weight);
        }
    }
    cout << endl;
    // 印出距離
    for(int j = 0; j < vertex; j++){
    	cout << s + 1 << "<->" << j + 1 << ":" << distance[j] << endl;
    }
    cout << endl;
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
    g.DAG(1);
    // 找 1 到 7 的最短路徑
	g.Print_Path(7);
    return 0;
}
