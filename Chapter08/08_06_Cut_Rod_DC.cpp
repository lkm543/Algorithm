#include <iostream>
#include <vector>

using namespace std;

// *p：價格陣列
// p_len：p 的長度（即木頭種類）
// p[0]：長度 1 的價格、p[1]：長度 2 的價格、...
// n：木頭長度
int Cut_Rod(int* p, int p_len, int n){
	if(n == 0)
		return 0;
	int revenue = -2147483648;
	for(int i = 0; i < p_len; i++){
		if(n >= i + 1){
            // 注意 p[0] 對應長度 1、p[1] 對應長度 2
			int revenue_i = p[i] +
                Cut_Rod(p, p_len, n - i - 1);
			revenue = revenue > revenue_i ?
                revenue : revenue_i;
		}
	}
	return revenue;
}

int main(){
    int p[5] = {10, 22, 35, 45, 56};
    int len;
	cout << "Please enter len:" << endl;
	cin >> len;

	cout << "Max Profit = " << Cut_Rod(p, 5, len) << endl;
	return 0;
}
