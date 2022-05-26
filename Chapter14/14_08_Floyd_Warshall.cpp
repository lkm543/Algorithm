#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Graph{
    private:
        int vertex;
        vector<vector<int>> distance;
        vector<vector<int>> predecessor;
    public:
        Graph(int);
        void Print_Distance();
        void Print_Predecessor();
        void Floyd_Warshall();
        bool Add_Edge(int,int,int=1);
};

void Graph::Floyd_Warshall(){
    for(int k = 0; k < vertex; k++){
        for(int i = 0; i < vertex; i++){
            for(int j = 0; j < vertex; j++){
                if(distance[i][k] == numeric_limits<int>::max())
                    continue;
                else if(distance[k][j] == numeric_limits<int>::max())
                    continue;
                else if(distance[i][j] > distance[i][k] + distance[k][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                    predecessor[i][j] = k;
                }
            }
        }
    }
}

Graph::Graph(int v){
    // 設定頂點數
    vertex = v;
    // 把向量的長度設為 vertex x vertex
    distance.resize(vertex,
                    vector<int>(vertex, numeric_limits<int>::max()));
    predecessor.resize(vertex, vector<int>(vertex, -1));
    for(int i = 0; i < vertex; i++){
        distance[i][i] = 0;
    }
}

bool Graph::Add_Edge(int from, int to, int weight){
    from--;
    to--;
    if(distance[from][to] == numeric_limits<int>::max()){
        distance[from][to] = weight;
        predecessor[from][to] = from;
    }
    if(distance[to][from] == numeric_limits<int>::max()){
        distance[to][from] = weight;
        predecessor[to][from] = to;
    }
}

void Graph::Print_Distance(){
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            if(distance[i][j] == numeric_limits<int>::max())
                cout << "Inf\t";
            else
                cout << distance[i][j] << "\t";
        }
        cout << endl;
    }
}

void Graph::Print_Predecessor(){
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            cout << predecessor[i][j] << "\t";
        }
        cout << endl;
    }
}
int main()
{
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

    cout << "Distance Matrix......" << endl;
    g.Print_Distance();
    cout << "Predecessor Matrix......" << endl;
    g.Print_Predecessor();
    cout << "Floyd Warshall Algorithm......" << endl;
    g.Floyd_Warshall();
    cout << "Distance Matrix......" << endl;
    g.Print_Distance();
    cout << "Predecessor Matrix......" << endl;
    g.Print_Predecessor();

    return 0;
}
