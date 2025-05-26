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

    void findBike(const string bikeId);
    bool createBike(const string& bikeId, const string& bikeName);
};

enum class Role { ADMIN=0, MEMBER=1, GUEST=2 };

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
    /*createUser
    * �Է�: ���� ���̵�, ��й�ȣ, ��ȭ��ȣ
    * ���: void
    * User ��ü�� ����� ������ �� �Ҵ�
    * id�� password�� ��� admin�̸� ADMIN �ڰ� �ο�
    */
    void createUser(string userId, string password, string phoneNum);
    User* authenticateUser(string userId, string password);
    bool checkAdmin();
    bool assignBike(const string& userId, const Bike& findBike);
    vector<BikeInfo> getBikeInfosByUserId(string userId);
};

class Session {
private:
    User* userPtr;

public:
    Session(); 
    ~Session();

    bool createSession(User& user);
    bool removeSession();
    User* getUserIdFromSession();
};

class DataStore {
public:
    map<string, User> userRepository;
    map<string, Bike> bikeRepository;
    Session currentSession;
};

#endif // !ENTITIES_H