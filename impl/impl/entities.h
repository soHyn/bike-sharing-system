#pragma once

#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>
#include <map>

using namespace std;

struct BikeInfo {
    string bikeId;
    string bikeName;
};

class Bike {
private:
    string bikeId;
    string bikeName;

public:
    Bike();
    Bike(const string& id, const string& name);

    string getBikeId() const;
    string getBikeName() const;
    BikeInfo getBikeInfo() const;

    static Bike findBike(const string bikeId);
    static Bike createBike(const string& bikeId, const string& bikeName);
};

enum Role { ADMIN, MEMBER, GUEST };

class User {
private:
    string userId;
    string password;
    string phoneNum;
    Role role;
    vector<Bike> bikes;

public:
    User();
    User(string userId, string password, string phoneNum, Role role);

    string getUserId() const;

    static User createUser(string userId, string password, string phoneNum);
    static User findUser(string userId);
    static bool authenticateUser(string userId, string password);
    static bool checkAdmin();
    static bool assignBike(const string& userId, const Bike& findBike);
    static vector<BikeInfo> getBikeInfosByUserId(string userId);
};

class Session {
private:
    string userId;

public:
    Session(); 
    ~Session();

    void setUserId(string newUserId);
    static bool createSession(string userId);
    static bool removeSession();
    static string getUserIdFromSession();
};

#endif // !ENTITIES_H