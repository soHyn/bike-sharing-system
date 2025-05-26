#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "entities.h"
#include "boundaries.h"
#include "controllers.h"

using namespace std;

//Control Classes

bool Signup::registerUser(string userId, string password, string phoneNum) {
    User newUser = User();
    newUser.createUser(userId, password, phoneNum);
    if (!newUser.getUserId().empty()) { return true; }

    return false;
}


bool Login::login(string userId, string password) {
    User user = User();

    User* userPtr = user.authenticateUser(userId, password);
    if (userPtr) { Session::createSession(*userPtr); return true; }
    else { return false; }
}


void Logout::logout() {
    DataStore::currentSession.removeSession();
}


bool RegisterBike::registerBike(string bikeId, string bikeName) {
    Bike bike = Bike();
    if (!User::checkAdmin()) { return false; }
    if (!bike.createBike(bikeId, bikeName)) { return false; }

    return true;
}

/*
Ã£Áö ¸øÇÏ¸é ºó Bike °´Ã¼ ¹ÝÈ¯*/
Bike RentBike::searchBike(string bikeId) {
    Bike searchedBike = Bike(); 
    searchedBike.findBike(bikeId);

    return searchedBike;
}
bool RentBike::rentBike(Bike bike) {
    bool isAssigned = false;
    User* userPtr = Session::getUserIdFromSession();
    if (!userPtr) { isAssigned = false; }
    else { isAssigned = User::assignBike(userPtr->getUserId(), bike); }

    return isAssigned;
}


vector<BikeInfo> ShowMemberRentHistory::showRentHistory() {
    vector<BikeInfo> bikeInfos;

    User* userPtr = Session::getUserIdFromSession();
    bikeInfos = User::getBikeInfosByUserId(userPtr->getUserId());

    return bikeInfos;
}