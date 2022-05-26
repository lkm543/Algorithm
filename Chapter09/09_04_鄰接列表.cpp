#include <iostream>
#include <stdlib.h>
#include <vector>
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
    public:
        Graph(int);
        void Print_Edges();
        bool Add_Edge(int, int, int=1);
};

Graph::Graph(int v){
	// 設定頂點數
	vertex = v;
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

int main(){
	Graph g(10);
	g.Add_Edge(1,5,5);
	g.Add_Edge(2,6,3);
	g.Add_Edge(2,8,4);
	g.Add_Edge(7,5,2);
	g.Print_Edges();
	return 0;
}
