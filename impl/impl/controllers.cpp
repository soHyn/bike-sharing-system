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
    Session session;

    User* userPtr = user.authenticateUser(userId, password);
    if (userPtr) { session.createSession(*userPtr); return true; }
    else { return false; }
}


void Logout::logout() {
    DataStore& dataStore = DataStore::getInstance();
    dataStore.currentSession.removeSession();
}


bool RegisterBike::registerBike(string bikeId, string bikeName) {
    Bike bike = Bike();
    Session session;

    User* userPtr = session.getUserIdFromSession();
    if (!userPtr->checkAdmin()) { return false; }
    if (!bike.createBike(bikeId, bikeName)) { return false; }

    return true;
}

/*
ã�� ���ϸ� �� Bike ��ü ��ȯ*/
Bike RentBike::searchBike(string bikeId) {
    Bike searchedBike = Bike(); 
    searchedBike.findBike(bikeId);

    return searchedBike;
}
bool RentBike::rentBike(Bike bike) {
    bool isAssigned = false;
    Session session;

    User* userPtr = session.getUserIdFromSession();
    if (!userPtr) { isAssigned = false; }
    else { isAssigned = userPtr->assignBike(userPtr->getUserId(), bike); }

    return isAssigned;
}


vector<BikeInfo> ShowMemberRentHistory::showRentHistory() {
    vector<BikeInfo> bikeInfos;
    Session session;

    User* userPtr = session.getUserIdFromSession();
    bikeInfos = userPtr->getBikeInfosByUserId(userPtr->getUserId());

    return bikeInfos;
}