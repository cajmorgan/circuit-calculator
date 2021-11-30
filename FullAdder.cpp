#include <iostream>
#include <stdio.h>

/**
 * @brief 
 * 01 + 
 * 01
 * =
 * 10(0)
 * 11 +
 * 01
 * =
 * 00(1)
 */


class Adder {
  public:
    int Ain = 0, Bin = 0, Cin = 0, Cout = 0, SUM = 0;

  Adder(int A, int B, int C) {
    Ain = A;
    Bin = B;
    Cin = C;
  }  

  void calculate() {
    int firstFlow = Ain ^ Bin;
    int firstCarry = Ain & Bin;
    int secondCarry = firstFlow & Cin;
    Cout = firstCarry | secondCarry;  
    SUM = firstFlow ^ Cin;
  }

  void printValues() {
    std::cout << "A: " << Ain << "\n";
    std::cout << "B: " << Bin << "\n";
    std::cout << "Carry: " << Cout << "\n";
    std::cout << "SUM: " << SUM << "\n";

  };

};

int main() {
  Adder firstAdder(0, 1, 0);
  firstAdder.calculate();
  Adder secondAdder(1, 0, firstAdder.Cout);
  secondAdder.calculate();
  Adder thirdAdder(1, 1, secondAdder.Cout);
  thirdAdder.calculate();
  Adder fourthAdder(0, 0, thirdAdder.Cout);
  fourthAdder.calculate();
  
  std::cout << fourthAdder.SUM;
  std::cout << thirdAdder.SUM;
  std::cout << secondAdder.SUM;
  std::cout << firstAdder.SUM; 

  return 0;
}