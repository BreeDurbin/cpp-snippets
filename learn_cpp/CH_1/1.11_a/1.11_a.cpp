#include<iostream>
#include<memory>
#include <string>

using namespace std;

/*
 * Enter an integer: 4
 * Double 4 is: 8
 * Triple 4 is: 12
 */

int main() {
    int x{};
    cout << "Enter an integer: ";
    cin >> x;
    cout << "Double " << x << " is : " << x*2 << '\n';
    cout << "Triple " << x << " is : " << x*3 << '\n';
    return 0;
}
