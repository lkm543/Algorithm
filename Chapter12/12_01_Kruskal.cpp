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
        int vertex;
        vector<list<edge*>> edges;
        int Find_Set(int);
        void Merge_Set(int,int);
    public:
        Graph(int);
        void MST_Kruskal();
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
        }
    }

    // 算出最小生成樹權重
    int sum = 0;
    for(int i = 0; i < vertex - 1; i++){
        // 輸出邊的資訊
        cout << MST_Edges[i].from + 1<< "->" << MST_Edges[i].to + 1 << "：" << MST_Edges[i].weight << endl;
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
    g.MST_Kruskal();
    return 0;
}
