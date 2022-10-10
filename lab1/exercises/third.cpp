#include "first.h"

int main() {
  Dog euzebiusz;
  euzebiusz.weight = 100;
  euzebiusz.height = 50;
  euzebiusz.name = "euzek"; // TODO: znaleźć lepsze zdrobnienie
  Person andyWarhol;
  andyWarhol.dog = euzebiusz;
  std::cout << andyWarhol.dog.name << "\n";
}
