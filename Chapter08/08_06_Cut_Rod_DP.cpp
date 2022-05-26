#include <iostream>
#include <vector>

using namespace std;

// *p：價格陣列
// p_len：p 的長度（即木頭種類）
// p[0]：長度 1 的價格、p[1]：長度 2 的價格、...
// n：木頭長度
int Cut_Rod(int* p, int p_len, int n){
	if (n == 0)
		return 0;
	// 儲存每種長度木頭的最大價值
	int revenue_array[n + 1] = {0};
	for (int i = 1; i <= n; i++){
        // 初始化為負無限大
		int max_revenue = -2147483648;
		for (int j = 0; j < p_len; j++){
			// 要切割的長度為 j + 1
			// 切割長度大於目前有的木頭長度時
			if (j + 1 > i) break;
			// 一般情形，注意 p[0] 對應長度 1 的價格
			int revenue_j = 
                p[j] + revenue_array[i - j - 1];
			max_revenue = max_revenue > revenue_j ?
                            max_revenue : revenue_j;
		}
		// 每次都記錄下算出的（長度 i 的木頭）結果
		revenue_array[i] = max_revenue;
	}
	return revenue_array[n];
}

int main(){
    int p[5] = {10, 22, 35, 45, 56};
    int len;
	cout << "Please enter len:" << endl;
	cin >> len;

	cout << "Max Profit = " << Cut_Rod(p, 5, len) << endl;
	return 0;
}
