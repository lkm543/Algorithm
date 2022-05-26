#include <iostream>

using namespace std;

int main()
{
	long long int triple_fibo[30];
	for (int i = 0; i < 30; i++){
		// 根據定義，前三項為 1
		if (i < 3)
			triple_fibo[i] = 1;
		else
			triple_fibo[i] = triple_fibo[i - 1] + 
                            triple_fibo[i - 2] +
                            triple_fibo[i - 3];
	}
	
	cout << triple_fibo[29] << endl;

	return 0;
}
