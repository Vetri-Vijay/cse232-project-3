#include "vehicle.h"

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

std::ostream& operator<<(std::ostream& oss, Vehicle const& c1) {
  oss << c1.val;
  return oss;
}

bool operator==(Vehicle const& v1, Vehicle const& v2) {
  if (v1.val == v2.val) {
    return true;
  }
  return false;
}

bool operator<(Vehicle const& v1, Vehicle const& v2) {
  if (v1.val < v2.val) {
    return true;
  }
  return false;
}

bool operator>(Vehicle const& v1, Vehicle const& v2) {
  if (v1.val > v2.val) {
    return true;
  }
  return false;
}

// Sets a valid bearing (N S E W) to the Vehicle. Throws an error otherwise
void Vehicle::SetBearing(char const& in_char) {
  if ((in_char != 'N') and (in_char != 'S') and (in_char != 'E') and
      (in_char != 'W')) {
    throw std::invalid_argument("Bearing value invalid");
  } else {
    bearing = in_char;
  }
}

// Moves the vehicle in the direction of the bearing, which is 1 unit by default
void Vehicle::MoveForward(int const& in_int) {
  // Switch statement reference:
  // https://www.tutorialspoint.com/cplusplus/cpp_switch_statement.htm
  switch (bearing) {
    case 'N':
      pos_y -= in_int;
      break;
    case 'S':
      pos_y += in_int;
      break;
    case 'E':
      pos_x += in_int;
      break;
    case 'W':
      pos_x -= in_int;
      break;
  }
}

void Vehicle::TurnRight() {
  switch (bearing) {
    case 'N':
      bearing = 'E';
      break;
    case 'S':
      bearing = 'W';
      break;
    case 'E':
      bearing = 'S';
      break;
    case 'W':
      bearing = 'N';
      break;
  }
}

void Vehicle::TurnLeft() {
  switch (bearing) {
    case 'N':
      bearing = 'W';
      break;
    case 'S':
      bearing = 'E';
      break;
    case 'E':
      bearing = 'N';
      break;
    case 'W':
      bearing = 'S';
      break;
  }
}

// Note that the following 2 functions are private
std::vector<int> Vehicle::get_pos() {
  std::vector<int> return_vec = {pos_x, pos_y};
  return return_vec;
}

void Vehicle::SetPos(int const& x, int const& y) {
  pos_x = x;
  pos_y = y;
}