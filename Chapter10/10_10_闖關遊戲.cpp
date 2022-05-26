/*

APCS：闖關路線 (2019/10 P3)

A. 題目
有一個闖關遊戲，遊戲方式是在一條線不斷左右移動角色，直到移動到終點。已知線上有 N 個位置，由左至右以 0 ~ N - 1 表示，開始時，會接收到 D、L、R，分別代表：終點位置、每次按下左鍵時左移的距離、每次按下右鍵時右移的距離，且角色會從位置 0 開始移動。

另外，每個位置 i 都有一扇傳送門可以瞬間移動角色至 P(i)，因此每次按下按鍵後，角色會先跟據按下的按鍵往左或往右移動到位置 i，接著角色就會被瞬間移動至 P(i)。

其中某些點的 P(i)=i，代表會在這些位置上停留不瞬間移動，這些點稱為停留點，並且起點與終點都一定是停留點，另外，瞬間移動後的位置也都一定是停留點，並不會持續瞬間移動。

現在的目標是以用最少的按鍵數來操作角色，讓角色可以從起點到終點，移動過程中也不可以超過範圍 [0, N - 1]，且某些點的瞬間移動後的位置可能會超出範圍，所以移動到這些點同樣會導致闖關失敗。

B. 題目出處

2019/10 APCS實作題 #3
本題可於 一中電腦資訊研究社 Online Judge 中測試，網址如下： https://judge.tcirc.tw/ShowProblem?problemid=d094

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, D, L, R;
    cin >> N >> D >> L >> R;

    vector<int> P(N);
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }
    bool found = false;
    vector<bool> visited(N, false);
    // first: 位置
    // second: 次數
    queue<pair<int, int>> BFS;
    BFS.push(make_pair(0, 0));
    while (!BFS.empty()){
        pair<int, int> current = BFS.front();
        BFS.pop();
        int times = current.first;
        int position = current.second;
        visited[position] = true;

        // 走到終點了
        if(position == D){
            found = true;
            cout << times << endl;
            break;
        }

        // 往左走，合法且未走過
        int left = position - L;
        if(left >= 0 && !visited[left]){
            // 瞬間移動後仍合法
            if(P[left] >= 0 && P[left] < N){
                visited[left] = true;
                BFS.push(make_pair(times + 1, P[left]));
            }
        }

        // 往右走，合法且未走過
        int right = position + R;
        if(right < N && !visited[right]){
            // 瞬間移動後仍合法
            if(P[right] >= 0 && P[right] < N){
                visited[right] = true;
                BFS.push(make_pair(times + 1, P[right]));
            }
        }
    }
    // 沒找到輸出 -1
    if(!found)  cout << -1;

    return 0;
}
