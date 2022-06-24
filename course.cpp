#include "course.h"

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <set>

// Converts a string of characters into a vector of characters (track) and finds
// the start and finish positions as y,x coordinates
Course::Course(std::string const& in_str) {
  std::vector<char> line;
  int x_cord, y_cord = 0;
  for (char a : in_str) {
    if (a == '*' or a == '.') {
      line.push_back(a);
      x_cord++;
    }
    if (a == 'S') {
      line.push_back(a);
      start_pos = {x_cord, y_cord};
    }
    if (a == 'F') {
      line.push_back(a);
      finish_pos = {x_cord, y_cord};
    }
    if (a == '\n') {
      track.push_back(line);
      line = {};
      x_cord = 0;
      y_cord++;
    }
  }
}

// Prints the track with vehicles on them, updates the vehicle_track 2D vector 
// with new vehicles beforehand
std::ostream& operator<<(std::ostream& oss, Course& c1) {
  c1.UpdateVehicleTrack();

  int width = c1.vehicle_track[1].size();
  for (int a = 0; a < width + 2; a++) {                                         // Adds the top border to the stringstream, repeated for the bottom
    oss << '+';
  }
  oss << '\n';
  for (auto line : c1.vehicle_track) {
    if (line.size() > 0) {
      oss << '+';
    }
    for (auto c : line) {
      oss << c;
    }
    if (line.size() > 0) {
      oss << '+' << '\n';
    }
  }
  for (int a = 0; a < width + 2; a++) {
    oss << '+';
  }
  oss << '\n';

  return oss;
}

// Copies all the class variables from lhs to rhs, and removes all the vehicles
// from the rhs
void Course::operator=(Course& c1) {
  track = c1.track;
  vehicle_track = c1.vehicle_track;
  vehicle_vec = c1.vehicle_vec;
  start_pos = c1.start_pos;
  finish_pos = c1.finish_pos;
  c1.vehicle_vec.clear();
}

// Creates a new Vehicle object and places it at the starting position on the 
// course. Bearing is set to 'N' as default
void Course::AddVehicleToStart(Vehicle* new_vehicle) {
  new_vehicle->SetPos(start_pos[0], start_pos[1]);
  new_vehicle->SetBearing('N');
  vehicle_vec.push_back(new_vehicle);
}

// Overlays the Vehicle chars over the map in the the vehicle_track 2D vector
void Course::UpdateVehicleTrack() {
  vehicle_track = track;
  for (auto item : vehicle_vec) {
    int x = item->get_pos()[0];
    int y = item->get_pos()[1];
    vehicle_track[y][x] = item->get_char();
  }
}

// Returns a set Vehicles at the finish position
std::set<Vehicle> Course::VehiclesAtFinish() {
  std::set<Vehicle> finished_vehicles;
  int counter = 0;
  for (auto item : vehicle_vec) {
    int x = item->get_pos()[0];
    int y = item->get_pos()[1];
    if (x == finish_pos[0] and y == finish_pos[1]) {
      finished_vehicles.insert(*item);
      counter++;
    }
  }
  return finished_vehicles;
}

int Course::ReturnOffTrackVehiclesToStart() {
  int off_track_counter = 0;
  for (auto item : vehicle_vec) {
    int x = item->get_pos()[0];
    int y = item->get_pos()[1];
    int track_width = track[1].size();
    int track_height = track.size();
    char char_at_pos;
    if (x < 0 or y < 0 or x > track_width or y > track_height) {                // Checks if the Vehicle is out of the bounds of the track
      char_at_pos = 'O';
    } else {
      char_at_pos = track[y][x];                                                // If on the track, denotes the char the Vehicle is on top of
    }
    if (char_at_pos != 'S' and char_at_pos != 'F' and char_at_pos != '*') {
      item->SetPos(start_pos[0], start_pos[1]);
      off_track_counter++;
    }
  }
  return off_track_counter;
}