#include <iostream>

using namespace std;

//Да се състави програма, чрез която се въвеждат 10 естествени числа от интервала [10..999].
//Програмата да изведе числата с най-малка и най-голяма стойност, както и средната стойност от въведените числа.
//Програмата да извършва проверка за валидност на въвежданите данни.
//Пример: 12,19,18,13,15,16,17,10,11,14
//Изход: минимално 10, максимално 19, средна стойност 14.5

int Number(int arr[], int size) {
    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < size; ++i) {
        if (i > min){
            min == i;
        }
    }
    for (int i = 0; i < size; ++i) {
        if (arr[i] < max){
            max == i;
        }
    }
    return min, max;
}

int main() {
    int size = 10;
    int arr[] = {41, 467, 334, 0, 169, 224, 478, 358, 462, 464};


    cout << "Min: " << Number(arr, size);


    return 0;
}