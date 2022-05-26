#include <iostream>
using namespace std;

int Fibo(int n){
    // 宣告儲存每個費波那契數的陣列
	int *data = (int*) malloc(sizeof(int) * n);
	data[0] = 1;
	data[1] = 1;
    // 每個費波那契數是用兩個先前已經儲存的結果直接求和得到
	for (int i = 2; i < n; i++){
		data[i] = data[i - 1] + data[i - 2];
	}
	int result = data[n - 1];
	free(data);
	return result;
}

int main()
{
	// 求費波那契數列的前一百項
	for (int i = 1; i <= 100; i++){
		cout << Fibo(i) << " ";
	}
	return 0;
}
