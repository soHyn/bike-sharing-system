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
void SignupUI::startInterface() {
    string userId, password, phoneNum;
    string msg;

    inputData(userId, password, phoneNum);

    if (Signup::registerUser(userId, password, phoneNum)) {
        msg = "User registered successfully";
    }
    else {
        msg = "User registration failed";
    }
    showResult(msg);
}
void SignupUI::inputData(string& userId, string& password, string& phoneNum) {
    cout << "\n=== User Signup ===" << "\n";

    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Phone Number: ";
    cin >> phoneNum;
}
void SignupUI::showResult(string msg) { cout << msg << "\n"; }


void LoginUI::startInterface() {
    string userId, password;
    string msg;

    inputData(userId, password);

    if (Login::login(userId, password)) {
        msg = "Logged in successfully";
    }
    else {
        msg = "Logged in failed";
    }
    showResult(msg);
}
void LoginUI::inputData(string& userId, string& password) {
    cout << "\n=== User Login ===" << "\n";

    cout << "Enter User ID: ";
    cin >> userId;
    cout << "Enter Password: ";
    cin >> password;
}
void LoginUI::showResult(string msg) { cout << msg << "\n"; }


void LogoutUI::requestLogout() {
    string msg;

    if (DataStore::currentSession.getUserIdFromSession().empty()) {
        msg = "Please login first!";
        showResult(msg);
        return;
    }

    if (Session::removeSession()) {
        msg = "Logged out successfully";
    }
    else {
        msg = "Logged out failed";
    }

    showResult(msg);
}

void LogoutUI::showResult(string msg) { cout << msg << "\n"; }


void RegisterBikeUI::startInterface() {
    string bikeId, bikeName;
    string msg;

    inputData(bikeId, bikeName);

    if (RegisterBike::registerBike(bikeId, bikeName)) {
        msg = "Bike registered successfully";
    }
    else {
        msg = "Bike registration failed";
    }
    showResult(msg);
}
void RegisterBikeUI::inputData(string& bikeId, string& bikeName) {
    cout << "\n=== Register Bike ===" << "\n";

    cout << "Enter Bike ID: ";
    cin >> bikeId;
    cout << "Enter Bike Name: ";
    cin >> bikeName;
}
void RegisterBikeUI::showResult(string msg) { cout << msg << "\n"; }


void RentBikeUI::startInterface() {
    string bikeId, bikeName;
    string msg;

    inputData(bikeId, bikeName);

    Bike searchedBike = RentBike::searchBike(bikeId, bikeName);

    showSearchedBike(searchedBike.getBikeName());

    requestRentBike(searchedBike);

    showResult(msg);
}
void RentBikeUI::inputData(string& bikeId, string& bikeName) {
    cout << "\n=== Register Bike ===" << "\n";

    cout << "Enter Bike ID to search: ";
    cin >> bikeId;
    cout << "Enter Bike Name to search: ";
    cin >> bikeName;
}
void RentBikeUI::showSearchedBike(string bikeName) {
    if (bikeName.empty()) { cout << "Not found" << "\n"; }
    cout << bikeName << "(bike name) searched" << "\n";
}
void RentBikeUI::requestRentBike(Bike bike) {
    bool isrented = false;
    cout << "Do you want to rent?(if you don't, enter '0')" << "\n";
    isrented = RentBike::rentBike(bike);
    if (isrented) { cout << bike.getBikeName() << " is rented" << "\n"; }
}
void RentBikeUI::showResult(string msg) { cout << msg << "\n"; }

void ShowMemberRentHistoryUI::requestShowRentHistory() {
    string msg;
    if (DataStore::currentSession.getUserIdFromSession().empty()) {
        msg = "Please login first!";
        showResult({}, msg);
        return;
    }

    cout << "\n=== Rent History ===" << "\n";
    vector<BikeInfo> history = ShowMemberRentHistory::showRentHistory();

    showResult(history, msg);

}
void ShowMemberRentHistoryUI::showResult(vector<BikeInfo> history, string msg) {
    if (history.empty()) {
        cout << "No rent history found." << "\n";
    }
    else {
        cout << "Your rented bikes:" << "\n";
        for (const auto& bike : history) {
            cout << bike.bikeId << " : " << bike.bikeName << "\n";
        }
    }
}