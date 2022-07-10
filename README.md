# Project 3 CSE 232 Fall Semester 2021

This project used classes in C++ to implement a car racing simulator. It contains two classes: course and vehicle. The two classes interact to play the game. The main.cpp file uses characters to represent the course in a 2D vector, with a set of vehicle objects on the track. The vehicles can then be moved through their member functions and the track will manage whether it ended the race or left the track boundry.

The project demonstrates the use of object oriented concepts such as string manipulation, multi dimensional arrays, pointers, friend functions and encapsulation.

A sample game is already present, which is compiled and can be run using ./a.out in the same directory as the file. A new game can be made following the provided template in main.cpp. Start by created a new course in the same format as the sample, instantiating vehicle objects and adding them to the start of the course, and moving them using Vehicle.SetBearing() and Vehicle.MoveForward(). Use Course.VehiclesAtFinish() to get the vechicles that have finished.

The project requirements were created by the MSU CSE232 staff in the fall semester of 2021.
