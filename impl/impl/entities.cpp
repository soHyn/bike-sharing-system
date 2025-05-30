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

/*
Bike
*/
Bike::Bike() {} // 기본 생성자 추가
Bike::Bike(const string& id, const string& name) : bikeId(id), bikeName(name) {}

string Bike::getBikeId() const { return bikeId; } 
string Bike::getBikeName() const { return bikeName; }
BikeInfo Bike::getBikeInfo() const { return { bikeId, bikeName }; }


/*
    * bikeId로 bike 객체 탐색 후 반환
    * 탐색 실패 시 빈 BIke 생성 후 반환
    */
void Bike::findBike(const string bikeId) {
    DataStore& dataStore = DataStore::getInstance();
    auto iter = dataStore.bikeRepository.find(bikeId);
    if (iter != dataStore.bikeRepository.end()) {
        //찾은 경우
        this->bikeId = iter->second.bikeId;
        this->bikeName = iter->second.bikeName;
    }
    else {
        cout << "Bike not found" << "\n";
    }
    return;
}
/*bikeId, bikeName으로 bike 객체 생성
*/
bool Bike::createBike(const string& bikeId, const string& bikeName) {
    DataStore& dataStore = DataStore::getInstance();
    if (bikeId.empty()) { return false; }
    this->bikeId = bikeId; this->bikeName = bikeName;
    dataStore.bikeRepository.emplace(bikeId, *this);

    return true;
}

/*
User
*/
User::User() : role(Role::GUEST) {}
User::User(string userId, string password, string phoneNum, Role role) : userId(userId), password(password), phoneNum(phoneNum), role(role) {}

string User::getUserId() const { return userId; }

void User::createUser(string userId, string password, string phoneNum) {
    Role role = Role::MEMBER;
    DataStore& dataStore = DataStore::getInstance();

    if (userId == "admin" && password == "admin") { role = Role::ADMIN; }
    this->userId = userId;
    this->password = password;
    this->phoneNum = phoneNum;
    this->role = role;

    dataStore.userRepository.emplace(userId, *this);

    return;
}

User* User::authenticateUser(string userId, string password) {
    User* findUserPtr = nullptr;
    bool isAuthenticated = false;
    DataStore& dataStore = DataStore::getInstance();
    
    auto iter = dataStore.userRepository.find(userId);
    if (iter != dataStore.userRepository.end()) {
        findUserPtr = &(iter->second);

        if (!findUserPtr) { return nullptr; }
        else if (findUserPtr -> password == password) {
        return findUserPtr;
        }
    }
    else {
        cout << "User not found" << "\n"; return nullptr;
    }

    return findUserPtr;
}

bool User::checkAdmin() {
    if (!this) { cout << "login please" << "\n"; return false; }
    else if (this->role == Role::ADMIN) { return true; }
    else { cout << "Only for admin." << "\n"; return false; }
}

bool User::assignBike(const string& userId, const Bike& findBike) {
    if (this) { this->bikes.insert(this->bikes.begin(), findBike); return true; }

    return false;
}

vector<BikeInfo> User::getBikeInfosByUserId(string userId) {
    vector<BikeInfo> bikeInfos;

    if (!this) { return {}; }

    for (const Bike& bike : this->bikes) {
        bikeInfos.emplace_back(bike.getBikeInfo());
    }

    return bikeInfos;
}

/*
Session
*/
Session::Session() : userPtr(nullptr) {}
Session::~Session() {}

bool Session::createSession(User& user) {
    DataStore& dataStore = DataStore::getInstance();
    dataStore.currentSession.userPtr = &user;

    return true;
}

bool Session::removeSession() {
    DataStore& dataStore = DataStore::getInstance();
    dataStore.currentSession.userPtr = nullptr;

    return true;
}

User* Session::getUserIdFromSession() {
    DataStore& dataStore = DataStore::getInstance();
    return dataStore.currentSession.userPtr;
}