#pragma once

#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <string>
#include <vector>
#include "entities.h" 

class Signup {
public:
    static bool registerUser(string userId, string password, string phoneNum);
};

class Login {
public:
    static bool login(string userId, string password);
};

class Logout {
public:
    void logout();
};

class RegisterBike {
public:
    static bool registerBike(string bikeId, string bikeName);
};

class RentBike {
public:
    static Bike searchBike(string bikeId, string bikeName);
    bool rentBike(Bike bike);
};

class ShowMemberRentHistory {
public:
    static vector<BikeInfo> showRentHistory();
};

#endif