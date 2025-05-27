#pragma once

#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>
#include <map>

using namespace std;

/* BikeInfo ����ü
* ������ �� ���� ��� ������ �����ϴ� ����ü
*/
struct BikeInfo {
    string bikeId;
    string bikeName;
};

/* Bike Ŭ����
* ������ �� ���� ������ �����ϴ� Ŭ����
*/
class Bike {
private:
    string bikeId;
    string bikeName;

public:
    /*������*/
    Bike();
    Bike(const string& id, const string& name);

    /*getter*/
    string getBikeId() const;
    string getBikeName() const;

    /* getBikeInfo
    * �Է�: void
    * ���: ������ ���̵�, ������ �̸� ���� ��ü
    */
    BikeInfo getBikeInfo() const;

    /* findBike
    * �Է�: ������ ���̵�
    * ���: void
    */
    void findBike(const string bikeId);

    /* createBike
    * �Է�: ������ ���̵�, ������ �̸�
    * ���: ������ ���� ��������
    */
    bool createBike(const string& bikeId, const string& bikeName);
};

/* Role enum Ŭ����
* User�� role �и�
* ADMIN���� ������ ����� �� �� �ִ�.
* GUEST�� �α����Ͽ� MEMBER�� �Ǿ�߸� �ý����� �̿��� �� �ִ�.
*/
enum class Role { ADMIN=0, MEMBER=1, GUEST=2 };

/* User Ŭ����
* User �� ���� ������ �����ϴ� Ŭ����
* bikes�� ��Ʈ�� �����Ÿ� �����ϴ� �����̴�.
*/
class User {
private:
    string userId;
    string password;
    string phoneNum;
    Role role;
    vector<Bike> bikes;

public:
    /*������*/
    User();
    User(string userId, string password, string phoneNum, Role role);

    /*getter*/
    string getUserId() const;

    /*createUser
    * �Է�: ���� ���̵�, ��й�ȣ, ��ȭ��ȣ
    * ���: void
    * User ��ü�� ����� ������ �� �Ҵ�
    * id�� password�� ��� admin�̸� ADMIN �ڰ� �ο�
    */
    void createUser(string userId, string password, string phoneNum);
    
    /*authenticateUser
    * �Է�: ���� ���̵�, ��й�ȣ
    * ���: User*
    * ���� ���� �õ�. userRepository�� User�� �����ϰ� password�� ����� �Ͱ� �����ϸ� ������ �Ϸ��Ѵ�.
    */
    User* authenticateUser(string userId, string password);

    /*checkAdmin
    * �Է�: void
    * ���: bool
    * ���� ������ ���� ������ ADMIN���� �Ǻ��Ѵ�. ADMIN�̸� true, �ƴϸ� false�� ��ȯ�Ѵ�.
    */
    bool checkAdmin();

    /*assignBike
    * �Է�: ���� ���̵�, ������ ��ü
    * ���: bool
    * �Է����� ���� ���� ���̵� ���� �������� �� ��° �Ķ���ͷ� ���� ������ ��ü�� �Ҵ��Ѵ�.
    */
    bool assignBike(const string& userId, const Bike& findBike);
    vector<BikeInfo> getBikeInfosByUserId(string userId);
};

/*Session Ŭ����
* ���� �α��� ���� ������ �ּҸ� �����ϴ� Ŭ����
*/
class Session {
private:
    User* userPtr;

public:
    /*������ �� �Ҹ���*/
    Session(); 
    ~Session();

    /*createSession
    * �Է�: ���� ��ü �ּ�
    * ���: bool
    * currentSession�� user��ü �ּҸ� �����Ѵ�. �����ϸ� true, �����ϸ� false�� ��ȯ�Ѵ�.
    */
    bool createSession(User& user);

    /*removeSession
    * �Է�: void
    * ���: bool
    * currentSession�� nullptr�� �����Ѵ�. �����ϸ� true, �����ϸ� false�� ��ȯ�Ѵ�.
    */
    bool removeSession();

    /*getUserIdFromSession
    * �Է�: void
    * ���: ���� ��ü �ּ�
    * currentSession�� ����� ���� �����͸� ��ȯ�Ѵ�. �ƹ��� �α������� ���� ���¸� nullptr�� ��ȯ�ȴ�.
    */
    User* getUserIdFromSession();
};

class DataStore {
public:
    /*USer ��ü �����*/
    map<string, User> userRepository;

    /*Bike ��ü �����*/
    map<string, Bike> bikeRepository;

    /*���� Session�� ����ϰ� �ִ� ���� ����*/
    Session currentSession;

    /*�̱��� �������� ��ü ������ ����
    */
    static DataStore& getInstance() {
        static DataStore instance;
        return instance;
    }
private:
    DataStore() = default;
};

#endif // !ENTITIES_H