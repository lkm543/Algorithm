#include <iostream>

using namespace std;

int gold_1(int lower,int upper){
    return lower + (upper - lower) * 0.382;
}

int gold_2(int lower,int upper){
    return lower + (upper - lower) * 0.618;
}

int Gold_Search(int data[], int len) {
    // 極值不會出現在開頭或結尾
    // i 從 1 到 len - 2
    int lower = 1;
    int upper = len - 2;
    int cut_1 = gold_1(lower, upper);
    int cut_2 = gold_2(lower, upper);
    while(cut_2 > cut_1){
        if(data[cut_1] > data[cut_2]){
            upper = cut_2;
            cut_2 = cut_1;
            cut_1 = gold_2(lower, upper);
        }
        else{
            lower = cut_1;
            cut_1 = cut_2;
            cut_2 = gold_1(lower, upper);
        }
    }
    for(int i = lower; i <= upper; i++){
        if(data[i] > data[i-1] && data[i] > data[i + 1])
            return i;
    }
    return -1;
}

int main()
{
    int arr[10] = {56,86,104,128,135,124,109,96,81,72};
    cout << "Index of maximum is: " << Gold_Search(arr, 10);

    return 0;
}
