#include "vehicle.h"
#include "course.h"

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>  
#include <sstream>
#include <stdexcept>
#include <set>

int main(){
  std::string const map_layout_1 = R"(
  ..*****
  ..*...*
  ..*..**
  ..*..F.
  ..S....
  .......
  )";
  std::string const map_layout_2 = R"(
  ..*****
  ..*..**
  ..*..F.
  ..S....
  .......
  )";
  Course c1(map_layout_1);
  Course c2(map_layout_2);
  Vehicle v1('A');
  Vehicle v2('B');
  c1.AddVehicleToStart(&v1);
  c1.AddVehicleToStart(&v2);
  v1.SetBearing('W');
  v2.SetBearing('N');
  v1.MoveForward();
  v2.MoveForward();
  std::ostringstream oss;
  std::cout << "Before Assignment" << std::endl;
  std::cout << "c1" << std::endl;
  std::cout << c1;
  std::cout << "c2" << std::endl;
  std::cout << c2;
  oss << "Before Assignment" << std::endl;
  oss << "c1" << std::endl;
  oss << c1;
  oss << "c2" << std::endl;
  oss << c2;
  oss.str("");
  c2 = c1;
  std::cout << "After Assignment" << std::endl;
  std::cout << "c1" << std::endl;
  std::cout << c1;
  std::cout << "c2" << std::endl;
  std::cout << c2;
  oss << "After Assignment" << std::endl;
  oss << "c1" << std::endl;
  oss << c1;
  oss << "c2" << std::endl;
  oss << c2;
  oss.str("");
  c1 = c1;
  v1.MoveForward();
  std::cout << "After MoveForward" << std::endl;
  std::cout << "c1" << std::endl;
  std::cout << c1;
  std::cout << "c2" << std::endl;
  std::cout << c2;
  oss << "After MoveForward" << std::endl;
  oss << "c1" << std::endl;
  oss << c1;
  oss << "c2" << std::endl;
  oss << c2;
}