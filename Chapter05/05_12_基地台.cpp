/*

APCS：基地台 (2017/03/04 P4)

A. 題目

為因應資訊化與數位化的發展趨勢，某市長想要在城市的一些服務點上提供無線網路服務，因此他委託電信公司架設無線基地台。某電信公司負責其中 N 個服務點，這 N個服務點位在一條筆直的大道上，它們的位置(座標)係以與該大道一端的距離 P[i]來表示，其中 i=0~N-1。由於設備訂製與維護的因素，每個基地台的服務範圍必須都一樣，當基地台架設後，與此基地台距離不超過 R (稱為基地台的半徑)的服務點都可以使用無線網路服務，也就是說每一個基地台可以服務的範圍是 D=2R(稱為基地台的直徑)。現在電信公司想要計算，如果要架設 K 個基地台，那麼基地台的最小直徑是多少才能使每個服務點都可以得到服務。

基地台架設的地點不一定要在服務點上，最佳的架設地點也不唯一，但本題只需要求最小直徑即可。以下是一個 N=5 的例子，五個服務點的座標分別是 1、2、5、7、8。
 
假設 K=1，最小的直徑是 7，基地台架設在座標 4.5 的位置，所有點與基地台的距離都在半徑 3.5 以內。假設 K=2，最小的直徑是 3，一個基地台服務座標 1 與 2 的點，另一個基地台服務另外三點。在 K=3 時，直徑只要 1 就足夠了。

B. 題目出處
2017/03/04 APCS 實作題#4
本題可以到 zerojudge 上提交程式碼，網址為：
https://zerojudge.tw/ShowProblem?problemid=c575

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,K;
vector<int> City;

// 檢查半徑 R 是否可行
bool Covered(int R) {
    // available 為手上還剩幾個基地台堪用
    // limit 為目前的基地台最遠覆蓋到的位置
    int available = K, limit = -1;
    // 每個城市從左到右處理一次
    for (int i = 0; i < N; i++) {
        // 如果目前的城市覆蓋不到，就新增一個基地台
        if (limit < City.at(i)) {
            limit = (City.at(i) + R);
            available--;
        }
        // 如果基地台用罄就回傳 false
        if (available < 0)
            return false;
    }
    // 此半徑可行，基地台夠用，回傳 True
    return true;
}

int Binary_Search (int lower, int upper) {
    // 從 lower 到 upper 中找可行的半徑解
    while(true){
        if(upper <= lower + 1){
            if(Covered(lower))
                return lower;
            else
                return upper;
        }
        int middle = (lower + upper) / 2;
        // 中位數可行，搜尋左半部
        if(Covered(middle))
            upper = middle;
        // 中位數不可行，搜尋右半部
        else
            lower = middle + 1;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    City.resize(N);
    for (int i = 0; i < N; i++)
        cin >> City.at(i);
    sort(City.begin(), City.end());
    // 上界是最遠兩城市的距離
    // 下界是 1
    cout << Binary_Search(1, (City.back() - City.front())) << endl;
    return 0;
}
