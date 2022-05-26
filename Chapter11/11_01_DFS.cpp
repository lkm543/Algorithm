#include <iostream>
#include <stdlib.h>
#include <queue>
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
        vector<int> color;
        void DFS_Visit(int);
    public:
        Graph(int);
        void Print_Edges();
        bool Add_Edge(int, int, int=1);
        void DFS(int);
};

Graph::Graph(int v){
	// 設定頂點數
	vertex = v;
    color.resize(vertex);
	// 把向量的長度設為 vertex
	edges.resize(vertex);
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

int main(){
	Graph g(7);
	g.Add_Edge(1,3);
	g.Add_Edge(1,2);
	g.Add_Edge(1,6);
	g.Add_Edge(3,4);
	g.Add_Edge(2,4);
	g.Add_Edge(2,7);
	g.Add_Edge(6,5);
	g.Add_Edge(4,5);
	g.Add_Edge(7,5);
	g.Add_Edge(5,3);
	g.DFS(1);
	return 0;
}
