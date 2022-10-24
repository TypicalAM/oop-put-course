#include "first.h"
#include <cstdio>
#include <iostream>

int main() {
  Student uczen;
  uczen.firstname = "marcin";
  uczen.knowsVCS = true;
  uczen.resolvesMergeConflicts = false;
  std::cout << uczen.firstname << "\n";
  return 0;
}
