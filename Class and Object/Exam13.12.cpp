#include <iostream>

using namespace std;

int main() {

//    Задача 1: Дадено в числото N. Да се напише програма която определя дали N се дели на 7 и
//    2 едновременно. N се въвежда от клавиатурата. Резултатът се извежда на екрана.


//    int n;  // Въвеждане на число
//    cin >> n;
//
//    if (n % 7 == 0 && n % 2 == 0) {  // Проверка, числото дали се дели на 7 и 2 едновременно
//        cout << n << endl;
//        // Принтираме числото което се дели на 7 и 2.
//    }else{
//        cout << "The number is not divisible by 7 and 2 at the same time!" << endl;
//        // Ако не се дели на 7 и 2, отпечатваме текст
//    }



//    Задача 2: Напишете програма която намира броя на всички четирицифрени числа на които
//    втората и третата цифра са еднакви. Четирицифрените числа са тези в интервала [1000 -
//    9999].
//    Пример:
//    Четирицифрени числа с еднакви втора и трета цифра са:
//    1000 1001 1002 1003 ... 9996 9997 9998
//    Броят е: 899



//    int count = 0;
//    int num1 = 0;  // запазваме цифрите
//    int num2 = 0;  // запазваме цифрите
//
//    for (int i = 1000; i <= 9998; ++i) {
//        num1 = i % 10;      // присвояване на последната цифра
//        num2 = i /10 % 10;  // премахваме последната ццифра /10 и присвояваме следващата с %10
//        if (num1 == num2){   //сравняваме двете цифри
//            count++;
//        }
//    }
//    cout << count << endl;





//Задача 3: Даден е едномерен масив А[n]. Напишете програма която намира произведението
//на елементите с четна стойност. N и елементите на масива се въвеждат от клавиатурата.
//Резултатът се извежда на екрана.

//    int n;
//    cin >> n;
//
//    int arr[n];
//    // масив с данни
//
//    int sum = 0;
//    // съхраняваме сумата
//
//    for (int i = 0; i < n; ++i) {
//        cin >> arr[n];            // въвеждаме елементи
//    }
//
//    for (int i = 0; i < n; ++i) {
//        if (i % 2 == 0) {   // итерира и проверява всяко чило дали е четно
//            sum += i;
//        }
//
//    }
//    cout << sum << endl;
//// принтираме общата стойност





//    Задача 4: Даден е двумерен масив А[n][m]. Напишете програма която намира
//    произведението на елементите с положителна стойност, разположени на колони с нечетни
//    индекси. N, M и елементите на масива се въвеждат от клавиатурата. Резултатът се извежда
//    на екрана.

    int n;
    cin >> n;
    int m;
    cin >> m;


    int arr[n][m];


    int result = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < m; ++col) {
            if (row % 2 != 0) {
                if (arr[n][m] > 0) {
                    result += arr[n][m];
                }
            }
        }
    }
    cout << "Result: " << result << endl;




    return 0;
}