#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "entities.h"
#include "boundaries.h"
#include "controllers.h"

using namespace std;

// Boundary Classes (UI)

/* 
SigunupUI
*/
void SignupUI::startInterface(string userId, string password, string phoneNum) {
    string msg;
    Signup signup;
    //inputData(userId, password, phoneNum);
    
    if (signup.registerUser(userId, password, phoneNum)) {
        msg = "> " + userId + " " + password + " " + phoneNum;
    }
    else {
        msg = "User registration failed";
    }

    showResult(msg);

    return;
}
void SignupUI::inputData(string& userId, string& password, string& phoneNum) {
    cout << "\n=== User Signup ===" << "\n";

    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Phone Number: ";
    cin >> phoneNum;

    return;
}
void SignupUI::showResult(string msg) { cout << msg << "\n"; return;  }

/* 
LoginUI
*/
void LoginUI::startInterface(string userId, string password) {
    string msg;
    Login login;
    //inputData(userId, password);

    if (login.login(userId, password)) {
        msg = "> " + userId + " " + password;
    }
    else {
        msg = "Logged in failed";
    }
    showResult(msg);

    return;
}
void LoginUI::inputData(string& userId, string& password) {
    cout << "\n=== User Login ===" << "\n";

    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Password: ";
    cin >> password;

    return;
}
void LoginUI::showResult(string msg) { cout << msg << "\n"; return; }

/*
LogoutUI
*/
void LogoutUI::requestLogout() {
    DataStore dataStore;
    string msg;
    Session session;
    User* userPtr = dataStore.currentSession.getUserIdFromSession();

    if (!userPtr) {
        msg = "Please login first!";
        showResult(msg);
        return;
    }

    if (session.removeSession()) {
        msg = "> " + userPtr->getUserId();
    }
    else {
        msg = "Logged out failed";
    }

    showResult(msg);

    return;
}

void LogoutUI::showResult(string msg) { cout << msg << "\n"; return; }

/*
RegisterBIkeUI
*/
void RegisterBikeUI::startInterface(string bikeId, string bikeName) {
    RegisterBike registerBIke;
    string msg;

    //inputData(bikeId, bikeName);

    if (registerBIke.registerBike(bikeId, bikeName)) {
        msg = "> " + bikeId + " " + bikeName;
    }
    else {
        msg = "Bike registration failed";
    }
    showResult(msg);

    return;
}
void RegisterBikeUI::inputData(string& bikeId, string& bikeName) {
    cout << "\n=== Register Bike ===" << "\n";

    cout << "Enter Bike ID: ";
    cin >> bikeId;
    cout << "Enter Bike Name: ";
    cin >> bikeName;

    return;
}
void RegisterBikeUI::showResult(string msg) { cout << msg << "\n"; return; }

/*
RentBikeUI
*/
void RentBikeUI::startInterface(string bikeId) {
    string msg;
    string bikeName;
    RentBike rentBIke;

    //inputData(bikeId, bikeName);

    Bike searchedBike = rentBIke.searchBike(bikeId);

    if (!showSearchedBike(searchedBike.getBikeName())) { msg = "Bike not found"; }

    requestRentBike(searchedBike);

    showResult(msg);

    return;
}
void RentBikeUI::inputData(string& bikeId, string& bikeName) {
    cout << "\n=== Register Bike ===" << "\n";

    cout << "Enter Bike ID to search: ";
    cin >> bikeId;
    cout << "Enter Bike Name to search: ";
    cin >> bikeName;

    return;
}
bool RentBikeUI::showSearchedBike(string bikeName) {
    if (bikeName.empty()) { return false; }
    
    return true;
}
void RentBikeUI::requestRentBike(Bike bike) {
    RentBike rentBike;
    bool isrented = false;
    isrented = rentBike.rentBike(bike);
    if (isrented) { cout << "> " + bike.getBikeId() + " " + bike.getBikeName(); }

    return;
}
void RentBikeUI::showResult(string msg) { cout << msg << "\n"; return; }

/*
* ShowMemberRentHistoryUI
*/
void ShowMemberRentHistoryUI::requestShowRentHistory() {
    DataStore dataStore;
    ShowMemberRentHistory showMemberRentHistory;
    string msg;
    if (!dataStore.currentSession.getUserIdFromSession()) {
        msg = "Please login first!";
        showResult({}, msg);
        return;
    }

    //cout << "\n=== Rent History ===" << "\n";
    vector<BikeInfo> history = showMemberRentHistory.showRentHistory();

    showResult(history, msg);

    return;
}
void ShowMemberRentHistoryUI::showResult(vector<BikeInfo> history, string msg) {
    if (history.empty()) {
        cout << "No rent history found." << "\n";
    }
    else {
        for (const auto& bike : history) {
            cout << "> " + bike.bikeId << " " << bike.bikeName << "\n";
        }
    }

    return;
}