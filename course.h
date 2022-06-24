#pragma once

// troubleshooting header issues:
// https://stackoverflow.com/questions/36450235/c-error-code-c2065-class-name-un
// declared-identifier-even-though-it-shoul
#include "vehicle.h"

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>

class Course {
 private:
  std::vector<std::vector<char>> track;     
  std::vector<std::vector<char>> vehicle_track;                                 // 2D vector of the track with Vehicles overlaid
  std::vector<Vehicle *> vehicle_vec;
  std::vector<int> start_pos, finish_pos;                                       // The start/finish positions are stored as y,x computer graphics like coordinates
  void UpdateVehicleTrack();                                                    // Using the vehicle_vec and track, updates vehicle_track with the vehicles on the track
  
 public:
  Course(std::string const &);
  Course(const Course &c1) {
    track = c1.track;
    start_pos = c1.start_pos;
    finish_pos = c1.finish_pos;
  }
  friend std::ostream &operator<<(std::ostream &, Course &);
  void operator=(Course &c1);
  void AddVehicleToStart(Vehicle *);
  std::set<Vehicle> VehiclesAtFinish();
  int ReturnOffTrackVehiclesToStart();
};
