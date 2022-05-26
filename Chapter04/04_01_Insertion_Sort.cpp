#include<iostream>

using namespace std;

void Insertion_Sort(int data[], int len){
    for (int i = 1; i < len; i++) {
        // i is the index of X
        int value = data[i];
        // j is the index of Y
        int j = i - 1;
        // shift elements > X to right
        while(value < data[j] && j >= 0) {
            data[j+1] = data[j];
            j--;
        }
        // insert X to its position
        data[j+1] = value;
    }
}

int main(){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Insertion_Sort(arr,10);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
