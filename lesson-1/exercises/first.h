#include <iostream>

class Dog {
public:
  int weight;
  int height;
  std::string name;
};

class Person {
public:
  Dog dog;
  std::string firstname;
  std::string lastname;
  bool isInteresting;
};

class Student : public Person {
public:
  bool knowsVCS;
  bool knowsOOP;
  bool resolvesMergeConflicts;
};
