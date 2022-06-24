#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

class Vehicle {
 private:
  friend class Course;
  char val;
  char bearing;
  int pos_x;
  int pos_y;
  std::vector<int> get_pos();
  char get_char() { return val; };
  void SetPos(int const &, int const &);

 public:
  Vehicle(char const& in_char) { val = in_char; };
  friend std::ostream &operator<<(std::ostream &, Vehicle const &);
  friend bool operator==(Vehicle const &, Vehicle const &);
  friend bool operator<(Vehicle const &, Vehicle const &);
  friend bool operator>(Vehicle const &, Vehicle const &);
  void SetBearing(char const &);
  void MoveForward(int const &in_int = 1);
  void TurnRight();
  void TurnLeft();
};
