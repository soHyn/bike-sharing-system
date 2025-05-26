#pragma once

#ifndef BOUNDARIES_H
#define BOUNDARIES_H

#include <string>
#include "controllers.h" 
#include "entities.h"    

// using namespace std; // Avoid in headers if possible

class SignupUI {
public:
    void startInterface(string userId, string password, string phoneNum);
    void inputData(string& userId, string& password, string& phoneNum);
    void showResult(string msg);
};

class LoginUI {
public:
    void startInterface(string userId, string password);
    void inputData(string& userId, string& password);
    void showResult(string msg);
};

class LogoutUI {
public:
    void requestLogout();
    void showResult(string msg);
};

class RegisterBikeUI {
public:
    void startInterface(string bikeId, string bikeName);
    void inputData(string& bikeId, string& bikeName);
    void showResult(string msg);
};

class RentBikeUI {
public:
    void startInterface(string bikeId);
    void inputData(string& bikeId, string& bikeName);
    bool showSearchedBike(string bikeName);
    void showResult(string msg);
    void requestRentBike(Bike bike);
};

class ShowMemberRentHistoryUI {
public:
    void requestShowRentHistory();
    void showResult(vector<BikeInfo> history, string msg);
};

#endif // !BOUNDARIES_H