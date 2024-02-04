#include <iostream>
#include <string>
#include "Drinks.h"
#include "Alcoholic.h"
#include "NonAlcoholic.h"
#include "User.h"
#include "vector"
#include <algorithm>
using namespace std;


//14:12 започвам задачата



//bool CompareUsersByOrderAmount(const User *user1, const User *user2) {
//    return user1->() > user2->();
//}
int main() {
//
//    Drinks *aPtr1 = new Alcoholic("Jim Beam", 15, 1, "asd", 39, 20);
//
//
//
//    if (Alcoholic* derivedPtr = dynamic_cast<Alcoholic*>(aPtr1)){
//        aPtr1->print();
//    }else{
//        cout << "We don't have any of this drink" << endl;
//    }
//    vector<Drinks*> drinks;
//    drinks.push_back(aPtr1);

    Drinks *aPtr1 = new Alcoholic("Jim Beam", 15, 1, "whiskey", 39, 20);
    Drinks *aPtr2 = new Alcoholic("Jack Daniels", 35, 1, "whiskey", 39, 20);

    Drinks *naPtr1 = new NonAlcoholic("Water", 3, 1, "noAlkoholic", 0.5, 5);
    Drinks *naPtr2 = new NonAlcoholic("Coca cola", 3, 1, "noAlkoholic", 2, 5);

    vector<Drinks *> myDrinks;
    myDrinks.push_back(aPtr1);
    myDrinks.push_back(aPtr2);

    myDrinks.push_back(naPtr1);
    myDrinks.push_back(naPtr2);





    return 0;
}
