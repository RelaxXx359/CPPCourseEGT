#include <iostream>

void bubbleSort(int arr[], int size){

    for (int i = 0; i < size -1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {

    int arr[10] = {23, 34, 2, 5, 66, 3, 6, 111, 3, 67};

    bubbleSort(arr,10);

    for (int i = 0; i < 10; ++i) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
