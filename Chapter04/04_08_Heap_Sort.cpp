#include <iostream>

using namespace std;

void Max_Heapify(int *data, int root, int len){
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    int largest = root;
    // 左節點為最大值
    if(left < len && data[left] > data[largest]){
        largest = left;
    }
    // 右節點為最大值
    if(right < len && data[right] > data[largest]){
        largest = right;
    }
    // 把最大值與根節點做互換
    if(largest != root){
        // Swap data[root] and data[largest]
        int tmp = data[root];
        data[root] = data[largest];
        data[largest] = tmp;
        Max_Heapify(data, largest, len);
    }
}

void Min_Heapify(int *data, int root, int len){
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    int smallest = root;

    if(left < len && data[left] < data[smallest]){
        smallest = left;
    }

    if(right < len && data[right] < data[smallest]){
        smallest = right;
    }

    if(smallest != root){
        // Swap data[root] and data[smallest]
        int tmp = data[root];
        data[root] = data[smallest];
        data[smallest] = tmp;
        Min_Heapify(data, smallest, len);
    }
}

void Build_Max_Heap(int *data, int len){
    for(int i = len / 2 - 1; i >= 0; i--){
        Max_Heapify(data, i, len);
    }
}

void Build_Min_Heap(int *data, int len){
    for(int i = len / 2 - 1; i >= 0; i--){
        Min_Heapify(data, i, len);
    }
}

void Print_Array(int *data, int len){
    cout << "Array: ";
    for(int i=0;i<len;i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

void Heap_Sort(int *data, int len){
    // Step 1: Make max heap
    Build_Max_Heap(data, len);

    for(int i=len-1;i>0;i--){
        // Step 2: Swap data[i] and data[0]
        int tmp = data[0];
        data[0] = data[i];
        data[i] = tmp;
        // Step 3: Max heapify again
        Max_Heapify(data, 0, i);
    }
}

int main(){
    int arr[10] = {35,52,68,12,47,52,36,52,74,27};
    cout << "Origin data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    Heap_Sort(arr,10);

    cout << "Sorted data:";
    for(int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}