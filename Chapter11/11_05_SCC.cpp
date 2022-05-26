#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <list>
using namespace std;

// 代表邊的結構
// 只需要紀錄指到的頂點即可
typedef struct{
    int to;
    int weight;
}edge;

class Graph{
    private:
        int vertex;
        // 每個邊對應的 list 形成的向量
        vector<list<edge*>> edges;
        // 顛倒圖，尋找強連通元件時會用到
        vector<list<edge*>> edges_inverse;
        vector<int> color;
        stack<int> topological_sort;
        void DFS_Visit(int);
        void DFS_Visit_Topological(int);
    public:
        Graph(int);
        void Print_Edges();
        bool Add_Edge(int, int, int=1);
        void DFS(int);
        void Get_Topological_Sort(int);
        void DFS_SCC(int);
        void Print_SCC();
};

Graph::Graph(int v){
    // 設定頂點數
    vertex = v;
    // 把向量的長度設為 vertex
    color.resize(vertex);
    edges.resize(vertex);
    edges_inverse.resize(vertex);
}

// 印出所有邊
void Graph::Print_Edges(){
    for (int i = 0; i < vertex; i++){
        // 印出 from
        cout << i + 1 << "\t";
        // 資料型別可以使用 auto 代替
        list<edge*>::iterator iter = edges[i].begin();
        // 處理從 from 出發的所有邊
        for(;iter != edges[i].end();iter++){
            // 印出 to 和權重
            cout << "->" << (*iter)->to + 1 << "," << (*iter)->weight;
        }
        cout << endl;
    }
}

bool Graph::Add_Edge(int from, int to, int weight){
    // 在 from 對應的鏈結串列
    // 索引值是 from - 1 中加上新的邊
    edges[from - 1].push_back(new edge{to - 1, weight});
    edges_inverse[to - 1].push_back(new edge{from - 1, weight});
    // 如果是無向邊，要加上反向
    // edges[to - 1].push_back(new edge{from - 1, weight});
}

void Graph::DFS(int start){
    start--;
    // 把所有顏色塗成白色，0: 白色
    fill(color.begin(), color.end(), 0);
    // 從起點開始做深度優先搜尋
    DFS_Visit(start);
}

void Graph::DFS_Visit(int current){
    // 印出目前所在的位置 current
    cout << current + 1 << "->";
    // 把目前所在位置塗成灰色，1: 灰色
    color[current] = 1;

    // 往 current 的相鄰頂點走
    for(auto iter = edges[current].begin();
        iter != edges[current].end();
        iter++)
    {
        int neighbor = (*iter)->to;
        // 但只能往相鄰的白點走
        if(color[neighbor] == 0){
            DFS_Visit(neighbor);
        }
    }
    // 處理完 vertex 後把 vertex 變為黑色
    color[vertex] = 2;
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
    start--;
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

void Graph::DFS_SCC(int current){
    // 進入時塗成灰色
    color[current] = 1;
    // 印出目前的頂點
    cout << current + 1 << " ";
    // 在 GT 上搜尋所有 current 的相鄰節點
    for(auto iter = edges_inverse[current].begin();
        iter != edges_inverse[current].end();
        iter++)
    {
        int neighbor = (*iter)->to;
        // 如果相鄰節點是白色，就對該點繼續進行 DFS
        if(color[neighbor] == 0){
            DFS_SCC(neighbor);
        }
    }
    // 處理完時塗成黑色
    color[current] = 2;
}

void Graph::Print_SCC(){
    // 從頂點 1 開始取得拓樸排序
    Get_Topological_Sort(1);
    // 把所有頂點塗成白色
    fill(color.begin(), color.end(), 0);

    int SCC = 1;
    // 以拓樸排序，在顛倒圖上跑深度優先搜尋
    while(!topological_sort.empty()){
        int current = topological_sort.top();
        topological_sort.pop();
        // 找到還沒探索過的點進行深度優先搜尋
        // 每一輪深度優先搜尋跑遍的頂點都屬於同個強連通元件
        if(color[current] == 0){
            // 印出目前是第幾個強連通元件
            cout << "SCC #" << SCC << ":" << endl;
            DFS_SCC(current);
            SCC++;
            cout << endl;
        }
    }
}

int main(){
    Graph g(7);
    g.Add_Edge(2,1);
    g.Add_Edge(1,2);
    g.Add_Edge(3,2);
    g.Add_Edge(1,3);
    g.Add_Edge(6,4);
    g.Add_Edge(3,5);
    g.Add_Edge(3,6);
    g.Add_Edge(4,6);
    g.Add_Edge(5,6);
    g.Add_Edge(7,6);
    g.Add_Edge(4,7);
    g.Print_SCC();
    return 0;
}
