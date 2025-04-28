#include <iostream>
#include "Calculator.h"
using namespace std;

int main() {
    Calculator calc;
    cout << "2 + 3 = " << calc.add(2, 3) << endl;
    return 0;
}
