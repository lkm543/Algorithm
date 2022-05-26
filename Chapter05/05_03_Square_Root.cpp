#include <iostream>
#include <cmath> // for abs

using namespace std;

// 傳入值 x 是要求根號的數字
// lower 到 upper 是目前的區間
// error 是可容許誤差
double Square(double x, double lower, double upper, double error){
    // 算出中間數值 middle
    double middle = (lower + upper) / 2;

    // 誤差小於容許值時，回傳 middle
    if(abs(middle * middle - x) < error)
        return middle;
    // 搜尋 middle 左邊
    else if(middle * middle > x)
        return Square(x, lower, middle, error);
    // 搜尋 middle 右邊
    else if(middle * middle < x)
        return Square(x, middle, upper, error);
}

int main()
{
    double x,e;
    cout << "Please enter x(x>1) and e:" << endl;
    cin >> x >> e;

    // 下界也可傳入 1，如 Square(x, 1, x, e)
    cout << Square(x,0,x,e);
    return 0;
}
