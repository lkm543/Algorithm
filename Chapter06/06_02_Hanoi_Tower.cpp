#include <iostream>
using namespace std;

// 把代表三根棍子的三個堆疊分為 from、to 和 others
int Hanoi (int N, char from, char to, char others){
    // 邊界條件：只有一個盤子（最大的盤子）要搬動
    if (N==1){
        // 把這個盤子由 from 搬到 to
		cout << "Move " << N << " from " << from << " to " << to << endl;
        return 1;
    }
    // 一般情形
    else {
        // 把 n-1 個盤子從 from 移動到 others
        int step_1 = Hanoi(N-1, from, others, to);
        // 把 1 個盤子從 from 移動到 to
		int step_2 = 1;
		cout << "Move " << N << " from " << from << " to " << to << endl;
		// 把 n-1 個盤子從 others 移動到 to
		int step_3 = Hanoi(N-1, others, to, from);
		// 回傳需要移動的總次數
		return step_1 + step_2 + step_3;
    }
}

int main(){
    // 讓使用者輸入 N，代表要移動 N 層河內塔
    int N; 	cout << "Please enter N:" << endl;
    cin >> N;
    int steps = Hanoi(N, 'A', 'C', 'B');
	cout << "Steps:" << steps << endl;
	return 0;
}
