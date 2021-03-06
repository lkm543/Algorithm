/*

APCS：小群體 (2017/03/04 P2)

A.	題目
Q 同學正在學習程式，P 老師出了以下的題目讓他練習。

一群人在一起時經常會形成一個一個的小群體。假設有 N 個人，編號由 0 到 N-1，每個人都寫下他最好朋友的編號（最好朋友有可能是他自己的編號，如果他自己沒有其他好友），在本題中，每個人的好友編號絕對不會重複，也就是說 0 到 N-1 每個數字都恰好出現一次。

這種好友的關係會形成一些小群體。例如 N=10，好友編號如下，

0 的好友是 4，4 的好友是 6，6 的好友是 8，8 的好友是 5，5 的好友是 0，所以 0、4、 6、8、和 5 就形成了一個小群體。另外，1 的好友是 7 而且 7 的好友是 1，所以 1 和 7 形成另一個小群體，同理，3 和 9 是一個小群體，而 2 的好友是自己，因此他自己 是一個小群體。總而言之，在這個例子裡有 4 個小群體：{0,4,6,8,5}、{1,7}、{3,9}、 {2}。本題的問題是：輸入每個人的好友編號，計算出總共有幾個小群體。 Q 同學想了想卻不知如何下手，和藹可親的 P 老師於是給了他以下的提示：如果你從 任何一人 x 開始，追蹤他的好友，好友的好友，….，這樣一直下去，一定會形成一 個圈回到 x，這就是一個小群體。如果我們追蹤的過程中把追蹤過的加以標記，很容 易知道哪些人已經追蹤過，因此，當一個小群體找到之後，我們再從任何一個還未追 蹤過的開始繼續找下一個小群體，直到所有的人都追蹤完畢。 Q 同學聽完之後很順利的完成了作業。 

在本題中，你的任務與 Q 同學一樣：給定一群人的好友，請計算出小群體個數。

B. 出處
APCS 2017/03/04，實作題第2題
本題可以在zerojudge上測試與繳交，網址如下：
https://zerojudge.tw/ShowProblem?problemid=c291

*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> relationship(N);
    // 輸入每個人的好朋友編號
    for(int i = 0; i < N; i++){
        cin >> relationship[i];
    }

    // 記錄每個點是否有被拜訪過
    // 一開始沒有拜訪過任何點，初始化成 false
    vector<bool> visited(N, false);

    int groups = 0;

    // 把每個還沒拜訪過的點進行深度優先搜尋
    for(int i = 0; i < N; i++){
        // 拜訪過就跳過不處理
        if (visited[i])
            continue;
        // 每一輪深度優先搜尋就代表新的小群體
        groups++;
        // 記錄現在走到哪個點
        int current = i;
        // 開始深度優先搜尋
        while(!visited[current]){
            visited[current] = true;
            current = relationship[current];
        }
    }
    cout << groups;
    return 0;
}
