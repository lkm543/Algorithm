#include <iostream>
using namespace std;

int Fibo (int n){
	if (n <= 2)
		return 1;
	else
		return Fibo(n - 1) + Fibo(n - 2);
}

int main()
{
	// 求費波那契數列的前一百項
	for (int i = 1; i <= 100; i++){
		cout << Fibo(i) << " ";
	}
	return 0;
}
