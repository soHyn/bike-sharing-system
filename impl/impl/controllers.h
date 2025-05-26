#pragma once

#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <string>
#include <vector>
#include "entities.h" 

class Signup {
public:
    /* registerUser
    * 입력: 유저 아이디, 비밀번호, 전화번호
    * 출력: 등록성공여부
    */
    bool registerUser(string userId, string password, string phoneNum);
};

class Login {
public:
    bool login(string userId, string password);
};

class Logout {
public:
    void logout();
};

class RegisterBike {
public:
    bool registerBike(string bikeId, string bikeName);
};

class RentBike {
public:
    Bike searchBike(string bikeId);
    bool rentBike(Bike bike);
};

class ShowMemberRentHistory {
public:
    vector<BikeInfo> showRentHistory();
};

#endif