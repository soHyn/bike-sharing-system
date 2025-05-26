#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "entities.h"
#include "boundaries.h"
#include "controllers.h"

using namespace std;

// Control Classes

bool Signup::registerUser(string userId, string password, string phoneNum) {
    User newUser = User::createUser(userId, password, phoneNum);
    if (!newUser.getUserId().empty()) { return true; }

    return false;
}


bool Login::login(string userId, string password) {
    bool isAuthenticated = User::authenticateUser(userId, password);

    if (isAuthenticated) { Session::createSession(userId); return true; }

    return false;
}


void Logout::logout() {
    DataStore::currentSession.removeSession();
}


bool RegisterBike::registerBike(string bikeId, string bikeName) {
    if (!User::checkAdmin()) { return false; }
    if (Bike::createBike(bikeId, bikeName).getBikeId().empty()) { return false; }

    return true;
}

/*
Ã£Áö ¸øÇÏ¸é ºó Bike °´Ã¼ ¹ÝÈ¯*/
Bike RentBike::searchBike(string bikeId, string bikeName) {
    Bike searchedBike = Bike::findBike(bikeId);
    if (searchedBike.getBikeName() != bikeName) { return Bike(); }

    return searchedBike;
}
bool RentBike::rentBike(Bike bike) {
    bool isAssigned = false;
    string userId = Session::getUserIdFromSession();
    if (userId.empty()) { isAssigned = false; }
    isAssigned = User::assignBike(userId, bike);

    return isAssigned;
}


vector<BikeInfo> ShowMemberRentHistory::showRentHistory() {
    vector<BikeInfo> bikeInfos;

    string userId = Session::getUserIdFromSession();
    bikeInfos = User::getBikeInfosByUserId(userId);

    return bikeInfos;
}