//
// Created by Alan Ta on 1/27/21.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <zconf.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ctime>
#include <time.h>
#ifndef CARRENTALSYSTEM_MAIN_H
#define CARRENTALSYSTEM_MAIN_H

std::string invoiceNum();

int sortFileData(const std::string& fileName, int whichData);

int checkFileData(const std::string& fileName, const std::string& fileLine);

int removeFileData(const std::string& fileName, const std::string& fileLine, int whichData);

void printFileToScreen(const std::string& fileName);

void loadingScreen();

void ClearScreen();

void addCar();

void removeCar();

void editCar();

void carListScreen();

void rentOptions();

void invoiceCreate();

void rentCarAssignment();

void rentUpdate();

void rentCheck();

int constructHistory(const std::string& fileName, const std::string& fileLine, int whichData);

void printHistory();


#endif //CARRENTALSYSTEM_MAIN_H
