/*

質數伴侶問題

如果兩正整數的和為一質數，則可以稱這兩正整數為「質數伴侶」，比如說 3 + 4 = 7，這時候 3 與 4 互為質數伴侶。質數伴侶可以應用在密碼學上，現在的問題是要從多個整數中挑選出多對「質數伴侶」，比方如果現在有四個整數：3、4、6、7，這時候可以挑出兩對「質數伴侶」分別為3、4與6、7。

「質數伴侶」問題指的是若給你一堆數字，請問最多能從這些數字中找出幾對「質數伴侶」？

*/

#include<iostream>
#include<vector>

using namespace std;

// 判斷 input 是否為質數
bool Is_Prime(int input){
    for(int i = 2; i * i <= input; i++){
        // 找到 input 的因數，回傳 false
        if(input % i == 0)
            return false;
    }
    return true;
}

// 從奇數 odd 找尋增廣路徑
bool Find(int odd, vector<int>& even, vector<bool>& used, vector<int>& match){
    // 試圖與每個偶數都配對看看
    for(int i = 0; i < even.size(); i++){
        // 看與目前的偶數 even[i] 能否合成質數
        if(Is_Prime(odd + even[i]) && !used[i]){
            used[i] = true; 
            // 如果該偶數還沒配對過
            // 或與該偶數配對的奇數還有其他選擇
            if(match[i] == 0 ||
                Find(match[i], even, used, match))
            {
                match[i] = odd;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int N;
    // 輸入有幾個整數
    cin >> N;

    // 存放所有數的集合
    vector<int> data(N);
    // 存放奇數與偶數的集合
    vector<int> odd;
    vector<int> even;

    // 輸入所有數字
    for(int i = 0; i < N; i++){
        cin >> data[i];
        if(data[i] % 2)
            odd.push_back(data[i]);
        else
            even.push_back(data[i]);
    }
    // 質數伴侶的數目
    int counts = 0;

    // 紀錄每個偶數的配對狀況
    vector<int> match(even.size(), 0);
    // 依序從每個奇數開始搜尋增廣路徑
    for(int i = 0; i < odd.size(); i++){
        // 開始時，所有偶數都沒用過
        vector<bool> used(even.size(), false);
        // 是否能從第 i 個奇數出發找出增廣路徑
        if(Find(odd[i], even, used, match))
            // 能找到增廣路徑，質數伴侶數目 +1
            counts++;
    }
    cout << counts << endl;
    return 0;
}
