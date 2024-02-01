#include <iostream>
#include <string>

int main() {
    // insert number
    int n;
    std::cout << "How many numbers:";
    std::cin >> n;
// iteration "n"
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin>> num;
      std::cout << (num %2 ==0 ? "even" : "odd") << std::endl;
    }


    return 0;
}
