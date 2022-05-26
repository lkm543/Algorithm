#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <list>
#include <limits>
using namespace std;

// 每個頂點 vertex 有編號、predecessor 和 distance
typedef struct{
    int index;
    int predecessor;
    float distance;
}vertex;

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
        int n;
        // 每個邊對應的 list 形成的向量
        vector<list<edge*>> edges;
        bool Relax(int, int, float);
        vector<int> color;
        void Initialize(int);
    public:
        Graph(int);
        void Print_Edges();
        bool Add_Edge(int, int, int=1);
        void Dijkstra(int);
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
    n = v;
    // 把向量的長度設為 n
    color.resize(n);
    edges.resize(n);
    distance.resize(n);
    predecessor.resize(n);
}

void Graph::Initialize(int s){
    distance.clear();
    predecessor.clear();
    // n 為頂點個數
    for(int i = 0; i < n; i++){
        distance[i] = numeric_limits<int>::max();
        predecessor[i] = -1;
    }
    // 起點距離為 0
    distance[s] = 0;
}

bool Graph::Add_Edge(int from, int to, int weight){
    edges[from - 1].push_back(new edge{to - 1, weight});
}

// 排序函式，供priority_queue 使用
class compare{
    public:
        bool operator()(vertex* v1, vertex* v2){
            return v1->distance > v2->distance;
        }
};

void Graph::Dijkstra(int s){
    s--;
    priority_queue<vertex*, vector<vertex*>, compare> candidates;
    vector<bool> already_shortest(n, false);
    vertex* vertex_now;
    // 初始化
    Initialize(s);
    // 從起點 s 開始
    candidates.push(new vertex{s, -1, 0});
    // 不斷取出距離最近的頂點
    while(!candidates.empty()){
        int index = candidates.top()->index;
        // index 已經在最短路徑組中
        candidates.pop();
        if(already_shortest[index]){
            continue;
        }
        // 把 index 加入最短路徑組
        already_shortest[index] = true;
        cout << index + 1 << "->";
        auto it = edges[index].begin();
        // Relax index 的所有出邊
        for(; it!=edges[index].end(); it++){
            bool relaxed = Relax(index, (*it)->to, (*it)->weight);
            if(relaxed)
                candidates.push(new vertex{(*it)->to, predecessor[(*it)->to], distance[(*it)->to]}                );
        }
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
    g.Dijkstra(1);
    // 找 1 到 7 的最短路徑
    g.Print_Path(7);
    return 0;
}
