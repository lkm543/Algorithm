#include <iostream>
#include <stack>

using namespace std;

void Print_Stack(stack<int>& s){
	// 邊界條件：s 是空的
	if (s.empty()){return;}
	// 取出 s 中最上面的元素
	int col = s.top();
	s.pop();
	// 遞迴取出下一個元素
	Print_Stack(s);
	// 印出當前元素
	cout << col + 1 << " ";
	// 將當前元素放回 stack 中
	s.push(col);
}

// 檢查新皇后在 (row, col) 時，是否會與 stack 裡的皇后衝突
bool Available(stack<int> s, int row, int col){
	// s 為空的時候一定不會衝突
	if (s.empty()){return true;};

	// 檢查新皇后是否會與 stack 最上面的皇后衝突
	// 取出前一個皇后的位置 (s.size(), col_prev_queen)
	int col_prev_queen = s.top();
	s.pop();

	// 先假設不會衝突，可以放該位置
	bool result = true;

	// 新皇后與先前的皇后位置比較
	// 相差 diff_r 個橫列、diff_c 個直行
	int diff_r = row - s.size();
	int diff_c = col - col_prev_queen;

	// 直行相同時代表位置衝突
	if (col == col_prev_queen)
		result = false;
	// 新皇后在先前皇后右下角對角線上時
	if (diff_c == diff_r)
		result = false;
	// 新皇后在先前皇后左下角對角線上時
	if (diff_c == -1*diff_r)
		result = false;
	// 如果與現在比對的先前皇后沒有衝突
	if (result){
		// 繼續跟上一個橫列的皇后比對
		// 注意上面執行過 s.pop()
		// 因此傳入的 s 中，最上面是「再上一個橫列」的皇后
		result = Available(s,row,col);
	}
	return result;
}

int KQueens(stack<int>& s, int N){
	// stack 已有 N 個元素，代表找到一組可行解
	if (s.size() == N){
		// 印出目前這組可行解
		Print_Stack(s);
		cout << endl;
		return 1;
	}

	// stack 還未放滿時，往下執行
	// 計算在不更動目前的皇后下，還有幾組解
	int counts = 0;

	// 檢查下一個橫列的某種放法是否可行
	for (int i = 0; i < N; i++){
		// s 是已放的前幾個皇后的位置
		// s.size() 和 i 是下一個皇后的「橫列」和「直行」
        if (Available(s, s.size(), i)){
			// 擺放位置可行，把新的皇后放到該位置上
			s.push(i);
			// 放了新的皇后之後，往下繼續放下一橫列的皇后
			counts += KQueens(s,N);
			// 下一個橫列可能有好幾個可以放
			// 因此要 pop 掉，才能接續試下一個可行位置
			s.pop();
		}
	}
	return counts;
}

int main(){
    int N;
    cout << "Please enter N:";
    cin >> N;

    stack<int> position;
    cout << "Possibility: " << KQueens(position, N);
    return 0;
}
