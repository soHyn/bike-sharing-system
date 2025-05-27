#pragma once

#ifndef ENTITIES_H
#define ENTITIES_H

#include <string>
#include <map>

using namespace std;

/* BikeInfo 구조체
* 자전거 한 대의 모든 정보를 저장하는 구조체
*/
struct BikeInfo {
    string bikeId;
    string bikeName;
};

/* Bike 클래스
* 자전거 한 대의 정보를 저장하는 클래스
*/
class Bike {
private:
    string bikeId;
    string bikeName;

public:
    /*생성자*/
    Bike();
    Bike(const string& id, const string& name);

    /*getter*/
    string getBikeId() const;
    string getBikeName() const;

    /* getBikeInfo
    * 입력: void
    * 출력: 자전거 아이디, 자전거 이름 저장 객체
    */
    BikeInfo getBikeInfo() const;

    /* findBike
    * 입력: 자전거 아이디
    * 출력: void
    */
    void findBike(const string bikeId);

    /* createBike
    * 입력: 자전거 아이디, 자전거 이름
    * 출력: 자전거 생성 성공여부
    */
    bool createBike(const string& bikeId, const string& bikeName);
};

/* Role enum 클래스
* User의 role 분리
* ADMIN만이 자전거 등록을 할 수 있다.
* GUEST는 로그인하여 MEMBER가 되어야만 시스템을 이용할 수 있다.
*/
enum class Role { ADMIN=0, MEMBER=1, GUEST=2 };

/* User 클래스
* User 한 명의 정보를 저장하는 클래스
* bikes는 렌트한 자전거를 저장하는 백터이다.
*/
class User {
private:
    string userId;
    string password;
    string phoneNum;
    Role role;
    vector<Bike> bikes;

public:
    /*생성자*/
    User();
    User(string userId, string password, string phoneNum, Role role);

    /*getter*/
    string getUserId() const;

    /*createUser
    * 입력: 유저 아이디, 비밀번호, 전화번호
    * 출력: void
    * User 객체의 멤버에 적절한 값 할당
    * id와 password가 모두 admin이면 ADMIN 자격 부여
    */
    void createUser(string userId, string password, string phoneNum);
    
    /*authenticateUser
    * 입력: 유저 아이디, 비밀번호
    * 출력: User*
    * 유저 인증 시도. userRepository에 User가 존재하고 password가 저장된 것과 동일하면 인증을 완료한다.
    */
    User* authenticateUser(string userId, string password);

    /*checkAdmin
    * 입력: void
    * 출력: bool
    * 세션 정보로 얻은 유저가 ADMIN인지 판별한다. ADMIN이면 true, 아니면 false를 반환한다.
    */
    bool checkAdmin();

    /*assignBike
    * 입력: 유저 아이디, 자전거 객체
    * 출력: bool
    * 입력으로 받은 유저 아이디를 가진 유저에게 두 번째 파라미터로 들어온 자전거 객체를 할당한다.
    */
    bool assignBike(const string& userId, const Bike& findBike);
    vector<BikeInfo> getBikeInfosByUserId(string userId);
};

/*Session 클래스
* 현재 로그인 중인 유저의 주소를 저장하는 클래스
*/
class Session {
private:
    User* userPtr;

public:
    /*생성자 및 소멸자*/
    Session(); 
    ~Session();

    /*createSession
    * 입력: 유저 객체 주소
    * 출력: bool
    * currentSession에 user객체 주소를 저장한다. 성공하면 true, 실패하면 false를 반환한다.
    */
    bool createSession(User& user);

    /*removeSession
    * 입력: void
    * 출력: bool
    * currentSession에 nullptr를 대입한다. 성공하면 true, 실패하면 false를 반환한다.
    */
    bool removeSession();

    /*getUserIdFromSession
    * 입력: void
    * 출력: 유저 객체 주소
    * currentSession에 저장된 유저 포인터를 반환한다. 아무도 로그인하지 않은 상태면 nullptr가 반환된다.
    */
    User* getUserIdFromSession();
};

class DataStore {
public:
    /*USer 객체 저장소*/
    map<string, User> userRepository;

    /*Bike 객체 저장소*/
    map<string, Bike> bikeRepository;

    /*현재 Session을 사용하고 있는 유저 저장*/
    Session currentSession;

    /*싱글톤 패턴으로 객체 접근점 제공
    */
    static DataStore& getInstance() {
        static DataStore instance;
        return instance;
    }
private:
    DataStore() = default;
};

#endif // !ENTITIES_H