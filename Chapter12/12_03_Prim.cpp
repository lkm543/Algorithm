#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>

using namespace std;

typedef struct{
    int from;
    int to;
    int weight;
}edge;

class Graph{
    private:
        vector<edge> MST_Edges;
        vector<int> MST_Set;
        vector<int> predecessor;
        vector<int> distance;
        vector<bool> finished;
        int vertex;
        vector<list<edge*>> edges;
        int Find_Set(int);
        void Merge_Set(int,int);
        int Find_Minimal_Distance();
    public:
        Graph(int);
        void MST_Kruskal();
        void MST_Prim();
        void Print_Edges();
        void Add_Edge(int,int,int=1);
};

// 自訂邊的排序函式
class cmp{
public:
    bool operator()(edge &e1, edge &e2){
        // 依照邊的權重排序
        // 權重較小的邊排在 Priority Queue 前
        return e1.weight > e2.weight;
    }
};

void Graph::MST_Kruskal(){
    int edges_completed = 0;
    MST_Edges.clear();
    // 根據權重把邊排序
    priority_queue<edge, vector<edge>, cmp> sorted_edges;

    // 初始化
    for(int i = 0; i < vertex; i++){
        MST_Set[i] = -1;
        // 把邊加入 priority_queue
        for (auto iter = edges[i].begin();
                iter!=edges[i].end();
                iter++)
        {
            // iter 本身的類型是 list<edge*>::iterator
            // iter: iterator
            // *iter: edge*
            // **iter: edge
            // 把邊 push 進 queue 中
            sorted_edges.push(**iter);
        }
    }

    // 處理完所有邊，或者取的邊數已經到達頂點數-1時結束迴圈
    while (!sorted_edges.empty() && edges_completed < vertex - 1){
        edge current = sorted_edges.top();
        sorted_edges.pop();
        // current 為 crossing edge
        if(Find_Set(current.from) != Find_Set(current.to)){
            Merge_Set(current.from, current.to);
            MST_Edges.push_back(current);
            edges_completed++;
            cout << edges_completed << endl;
        }
    }

    // 算出最小生成樹權重
    int sum = 0;
    for(int i = 0; i < vertex - 1; i++){
        // 輸出邊的資訊
        cout << MST_Edges[i].from + 1<< "->" << MST_Edges[i].to << "：" << MST_Edges[i].weight << endl;
        sum += MST_Edges[i].weight;
    }
    cout << "Weight of this MST = " << sum << endl;
}


int Graph::Find_Set(int u){
    int root = u;
    while (MST_Set[root] >= 0){
        root = MST_Set[root];
    }
    while (u != root){
        int predecessor = MST_Set[u];
        MST_Set[u] = root;
        u = predecessor;
    }
    return root;
}

void Graph::Merge_Set(int u, int v){
    int u_root = Find_Set(u);
    int v_root = Find_Set(v);
    if (MST_Set[u] <= MST_Set[v]){
        // u 的頂點數比較多時
        MST_Set[u_root] += MST_Set[v_root];
        MST_Set[v_root] = u_root;
    } else {
        // v 的頂點數比較多時
        MST_Set[v_root] += MST_Set[u_root];
        MST_Set[u_root] = v_root;
    }
}



Graph::Graph(int v){
    vertex = v;
    edges.resize(vertex);
    MST_Set.resize(vertex);
}

void Graph::Print_Edges(){
    for(int i = 0; i < vertex; i++){
        cout << i + 1 << "\t";
        auto iter = edges[i].begin();
        // list<edge*>::iterator
        for(; iter != edges[i].end(); iter++){
            cout << "->" << (*iter)->to + 1 << "," << (*iter)->weight;
        }
        cout << endl;
    }
}

void Graph::Add_Edge(int from,int to,int weight){
    edges[from - 1].push_back(new edge{from - 1, to - 1, weight});
    edges[to - 1].push_back(new edge{to - 1, from - 1, weight}); // Undirected graph
}

// 找到目前距離最小生成樹最近的點
int Graph::Find_Minimal_Distance(){
    int minimal = INT_MAX;
    int index = -1;
    for(int i = 0;i < vertex;i++){
        // 必須是 finish 值為 false 的點
        if(distance[i] < minimal && !finished[i]){
            // 回傳的頂點編號
            index = i;
            minimal = distance[i];
        }
    }
    return index;
}

void Graph::MST_Prim(){
    // 初始化
    predecessor.resize(vertex);
    distance.resize(vertex);
    finished.resize(vertex);
    for(int i = 0;i < vertex;i++){
        predecessor[i] = -1;
        distance[i] = INT_MAX;
        finished[i] = false;
    }
    // 任意選一個起點開始，這裡選 0
    distance[0] = 0;
    int index = 0;
    // 目前的總權重
    int sum = 0;
    for(int i = 0;i < vertex;i++){
        // 找到目前最近的未加入頂點
        index = Find_Minimal_Distance();
        // 把要加入的最近頂點標為 true
        finished[index] = true;
        // 加上到該點的邊權重
        sum += distance[index];
        auto iter = edges[index].begin();
        // 檢查 index 的所有出邊以更新距離值
        for(; iter!=edges[index].end(); iter++){
            // 出邊指到的頂點
            int target = (*iter)->to;
            // 該頂點目前離最小生成樹的距離
            int current_weight = distance[target];
            // 從 index 走到該頂點的距離
            int cross_weight = (*iter)->weight;
            // 出邊指向的點已完成時不處理
            if(finished[target]) continue;
            // 需要更新距離時
            if(cross_weight < current_weight){
                // 更新距離
                distance[target] = cross_weight;
                // 更新 predecessor
                predecessor[target] = index;
            }
        } // end of inner for
    } // end of outer for

    // 透過 predecessor 得知 MST 中有哪些邊
    for(int i = 0;i < vertex;i++){
        if(predecessor[i]!=-1){
            cout << i << "->" << predecessor[i] + 1 << endl;
        }
    }
    cout << "Weight of this MST = " << sum << endl;
} // end of MST_Prim


int main() {
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
    g.Add_Edge(5,7,5);
    g.MST_Prim();
    return 0;
}
