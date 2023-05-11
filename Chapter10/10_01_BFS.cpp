#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>

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
        void BFS(int);
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

void Graph::BFS(int start){
	// 起點 start 對應到索引值 start-1
	start--;

	// 顏色與 int 的對應
	// 0：白色 white
	// 1：灰色 gray
	// 2：黑色 black

	// 把所有頂點塗成白色
	vector<int> color(vertex, 0);
    // BFS 使用的佇列
	queue<int> BFS_Q;

	// 把起點放進 Queue 中並塗成灰色
	BFS_Q.push(start);
	color[start] = 1;

	// 印出頂點
	cout << start + 1 << "->";

	// 當 Queue 中還有資料
	while(!BFS_Q.empty()){
		// 取出 Queue 中最前面的資料再刪除
		int current = BFS_Q.front();
		BFS_Q.pop();

		// 針對 current 的相鄰節點處理
		for(auto iter = edges[current].begin();
                iter != edges[current].end();
                iter++
        ){
			// 只處理相鄰頂點中白色者
			if (color[(*iter)->to] == 0){
				// 印出目前處理的節點
				cout << (*iter)->to + 1 << "->";
				// 放入 Queue 中
				BFS_Q.push((*iter)->to);
				// 塗成灰色
				color[(*iter)->to] = 1;
			}
		} // end of for
		// current 處理完後把 current 塗成黑色
		color[current] = 2;
	} // end of while
} // end of BFS

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
	g.BFS(1);
	return 0;
}
