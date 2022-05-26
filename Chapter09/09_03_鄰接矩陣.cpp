#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

// 圖的類別
class Graph{
    private:
        // 頂點的個數
        int vertex;
        // 用雙重指標來儲存邊
        int **matrix;
        // 也可以使用二維向量
        // vector<vector<int>> matrix;
    public:
        // 建構式
        Graph(int);
        // 印出所有的邊
        void Print_Matrix();
        // 新增一條邊(起點,終點,權重), 成功回傳 true
        // 否則（邊已存在時）回傳 false
        bool Add_Edge(int, int, int=1);
};

// 建構式
Graph::Graph(int v){
	vertex = v;
	// vertex 個指標構成的整數指標陣列
	matrix = (int**) malloc(sizeof(int*) *vertex);

	// 把每個整數指標長度設為 vertex
	// calloc 會把值初始化為 0
	for (int i=0 ; i<vertex ; i++){
		*(matrix+i) = (int*) calloc(vertex, sizeof(int));
	}

	// 若使用二維向量時的初始化
	// matrix.resize(vertex, vector<int>(vertex, 0));
}

// 印出所有的邊，等同於印出一個二維陣列
void Graph::Print_Matrix(){
	for(int i = 0; i < vertex; i++){
		for(int j = 0; j < vertex; j++){
			// 或者寫成 matrix[i][j]
			cout << *((*(matrix+i)+j)) << "\t";
		}
		cout << endl;
	}
}

// 在圖上新增一條邊
// 只傳入兩個參數時，邊的權重預設為 1
bool Graph::Add_Edge(int from, int to, int weight){
	// 邊已存在
	if (matrix[from][to] == 1){
		cout << "Edge already exist." << endl;
		return false;
	}
    // 邊還未存在，進行新增
	else {
		matrix[from][to] = weight;
		// 若為無向邊需補上這一條
		matrix[to][from] = weight;
	}
}

int main(){
	Graph g(10);
	g.Add_Edge(1,5,5);
	g.Add_Edge(2,6,3);
	g.Add_Edge(7,5,2);
	g.Print_Matrix();

	return 0;
}
