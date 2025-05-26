#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "entities.h"
#include "boundaries.h"
#include "controllers.h"

using namespace std;

// Entity Classes
Bike::Bike() {} // 기본 생성자 추가
Bike::Bike(const string& id, const string& name) : bikeId(id), bikeName(name) {}

string Bike::getBikeId() const { return bikeId; } //
string Bike::getBikeName() const { return bikeName; }
BikeInfo Bike::getBikeInfo() const { return { bikeId, bikeName }; }

/*
    * bikeId로 bike 객체 탐색 후 반환
    * 탐색 실패 시 빈 BIke 생성 후 반환
    */
Bike Bike::findBike(const string bikeId) {
    Bike findBike;

    auto iter = DataStore::bikeRepository.find(bikeId);
    if (iter != DataStore::bikeRepository.end()) {
        //찾은 경우
        findBike = iter->second;
    }
    else {
        cout << "Bike not found" << "\n";
        findBike = Bike();
    }
    return findBike;
}
/*bikeId, bikeName으로 bike 객체 생성
*/
Bike Bike::createBike(const string& bikeId, const string& bikeName) {
    if (bikeId.empty()) { return Bike(); }
    Bike newBike = Bike(bikeId, bikeName);
    DataStore::bikeRepository.emplace(bikeId, newBike);

    return newBike;
}


User::User() : role(Role::GUEST) {}
User::User(string userId, string password, string phoneNum, Role role) : userId(userId), password(password), phoneNum(phoneNum), role(role) {}

string User::getUserId() const { return userId; }

User User::createUser(string userId, string password, string phoneNum) {
    Role role = Role::MEMBER;

    if (userId.empty()) { return User(); }
    if (userId == "admin" && password == "admin") { role = Role::ADMIN; cout << "you are admin" << endl; }
    User newUser = User(userId, password, phoneNum, role);

    DataStore::userRepository.emplace(userId, newUser);

    return newUser;
}

User* User::findUser(string userId) {

    auto iter = DataStore::userRepository.find(userId);
    if (iter != DataStore::userRepository.end()) {
        //찾은 경우
        return &(iter->second);
    }
    else {
        cout << "User not found" << "\n";
        return nullptr;
    }
}

bool User::authenticateUser(string userId, string password) {
    bool isAuthenticated = false;

    User* findUserPtr = User::findUser(userId);

    if (findUserPtr->password == password) { isAuthenticated = true; }
    else {
        cout << "User not found" << "\n";
    }

    return isAuthenticated;
}

bool User::checkAdmin() {
    string userId = Session::getUserIdFromSession();
    if (userId.empty()) { cout << "login please" << "\n"; }

    User* userPtr = findUser(userId);

    if (userPtr->role == Role::ADMIN) { return true; }
    cout << "Only for admin." << "\n";
    return false;
}

bool User::assignBike(const string& userId, const Bike& findBike) {
    User* rentUserPtr = findUser(userId);
    if (rentUserPtr!=nullptr && !rentUserPtr->getUserId().empty()) { rentUserPtr->bikes.emplace_back(findBike); cout << findBike.getBikeName() << " is assigned" << endl;  return true; }

    return false;
}

vector<BikeInfo> User::getBikeInfosByUserId(string userId) {
    User* userPtr = findUser(userId);
    vector<BikeInfo> bikeInfos;
    cout << "count : " << userPtr->bikes.size() << endl;
    for (const Bike& bike : userPtr->bikes) {
        bikeInfos.emplace_back(bike.getBikeInfo());
    }

    return bikeInfos;
}

Session::Session() : userId("") {}
Session::~Session() {}

void Session::setUserId(string newUserId) {
    userId = newUserId;
}

bool Session::createSession(string userId) {
    DataStore::currentSession.setUserId(userId);

    return true;
}

bool Session::removeSession() {
    DataStore::currentSession.setUserId("");

    return true;
}

string Session::getUserIdFromSession() {
    cout << "user id : " << DataStore::currentSession.userId << endl;
    return DataStore::currentSession.userId;
}