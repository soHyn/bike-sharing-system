/*
// 헤더 선언
#include <stdio.h>
#include <string.h>

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void program_exit();

// 변수 선언
//ofstream out_fp;
//ofstream in_fp;

void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        in_fp >> menu_level_1 >> menu_level_2;


        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1) {
            case 1:
            {
                switch (menu_level_2) {
                    case 1:   //
                    /* 1.1. 회원가입
                    * 입력: [ID] [비밀번호] [전화번호]
                    * 출력: [ID][비밀번호][전화번호]
                    *
                    {
                    break;
                    }
                }
                break;
            }
            case 2:
            {
                switch (menu_level_2) {
                case 1:
                    /* 2.1. 로그인
                    * 입력: [ID] [비밀번호]
                    * 출력: [ID] [비밀번호]
                    *
                {
                    break;
                }
                case 2:
                    /* 2.2. 로그아웃
                    * 입력: null
                    * 출력: [ID]
                    *
                {
                    break;
                }
                }
                break;
            }
            case 3:
            {
                switch (menu_level_2) {
                case 1:
                    /* 3.1. 자전거 등록
                    * 입력: [자전거 ID] [자전거 제품명]
                    * 출력: [자전거 ID] [자전거 제품명]
                    *
                {
                    break;
                }
                }
                break;
            }
            case 4:
            {
                switch (menu_level_2) {
                case 1:
                    /* 4.1. 자전거 대여
                    * 입력: [자전거 ID]
                    * 출력: [자전거 ID] [자전거 제품명]
                    *
                {
                    break;
                }
                }
                break;
            }
            case 5:
            {
                switch (menu_level_2) {
                case 1:
                    /* 5.1. 자전거 대여 리스트
                    * 입력: null
                    * 출력: { [자전거 ID] [자전거 제품명] }*
                    *
                {
                    break;
                }
                }
                break;
            }
            case 6:
            {
                switch (menu_level_2) {
                case 1:
                    /* 6.1. 종료
                    * 입력: null
                    * 출력: null
                    *
                {
                    is_program_exit = 1;

                    break;
                }
                }
                break;
            }
        }
    }
}
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "entities.h"
#include "boundaries.h"
#include "controllers.h"

using namespace std;

// Storage
class DataStore {
public:
    static map<string, User> userRepository;
    static map<string, Bike> bikeRepository;
    static Session currentSession;
};

map<string, User> DataStore::userRepository;
map<string, Bike> DataStore::bikeRepository;
Session DataStore::currentSession;

struct BikeInfo {
    string bikeId;
    string bikeName;
};

// Entity Classes
class Bike {
private:
    string bikeId;
    string bikeName;

public:
    Bike() {} // 기본 생성자 추가
    Bike(const string& id, const string& name) : bikeId(id), bikeName(name) {}

    string getBikeId() const { return bikeId; } //
    string getBikeName() const { return bikeName; }
    BikeInfo getBikeInfo() const { return { bikeId, bikeName }; }

    /*
    * bikeId로 bike 객체 탐색 후 반환
    * 탐색 실패 시 빈 BIke 생성 후 반환
    */
    static Bike findBike(const string bikeId) { 
        Bike findBike;

        auto iter = DataStore::bikeRepository.find(bikeId);
        if (iter != DataStore::bikeRepository.end()) {
            //찾은 경우
            findBike = iter->second;
        }
        else { 
            cout << "Bike not found" << "\n"; 
            findBike = Bike(); }
        return findBike; 
    }
    /*
    bikeId, bikeName으로 bike 객체 생성
    */
    static Bike createBike(const string& bikeId, const string& bikeName) {
        if (bikeId.empty()) { return Bike(); }
        Bike newBike = Bike(bikeId, bikeName);
        DataStore::bikeRepository.emplace(bikeId, newBike);
        
        return newBike;
    }
};

enum Role { ADMIN, MEMBER, GUEST };

class User {
private:
    string userId;
    string password;
    string phoneNum;
    Role role;
    vector<Bike> bikes;

public:
    User() {}
    User(string userId, string password, string phoneNum, Role role) : userId(userId), password(password), phoneNum(phoneNum), role(role) {}
    
    string getUserId() const { return userId; }

    static User createUser(string userId, string password, string phoneNum) {
        if (userId.empty()) { return User(); }
        Role role = Role::MEMBER;
        User newUser = User(userId, password, phoneNum, role);

        DataStore::userRepository.emplace(userId, newUser);

        return newUser;
    }

    static User findUser(string userId) {
        User findUser;

        auto iter = DataStore::userRepository.find(userId);
        if (iter != DataStore::userRepository.end()) {
            //찾은 경우
            findUser = iter->second;
        }
        else {
            cout << "User not found" << "\n";
            findUser = User();
        }

        return findUser;
    }

    static bool authenticateUser(string userId, string password) {
        bool isAuthenticated = false;

        User findUser = User::findUser(userId);

        if (findUser.password == password) { isAuthenticated = true; } else {
            cout << "User not found" << "\n";
        }

        return isAuthenticated;
    }

    static bool checkAdmin() {
        string userId = Session::getUserIdFromSession();
        User user = findUser(userId);
        if (user.role == ADMIN) { return true; }
        return false;
    }

    static bool assignBike(const string& userId, const Bike& findBike) {
        User rentUser = findUser(userId);
        if (!rentUser.getUserId().empty()) { rentUser.bikes.push_back(findBike); return true; }
        
        return false;
    }

    static vector<BikeInfo> getBikeInfosByUserId(string userId) {
        User user = findUser(userId);
        vector<BikeInfo> bikeInfos;
        for (Bike bike : user.bikes) {
            bikeInfos.push_back(bike.getBikeInfo());
        }

        return bikeInfos;
    }
};

class Session {
private:
    string userId;

public:
    Session() : userId("") {}
    ~Session() {}

    void setUserId(string newUserId) {
        userId = newUserId;
    }

    static bool createSession(string userId) {
        DataStore::currentSession.setUserId(userId);

        return true;
    }

    static bool removeSession() {
        DataStore::currentSession;

        return true;
    }

    static string getUserIdFromSession() {
        if (DataStore::currentSession.getUserIdFromSession.empty()) { return DataStore::currentSession.userId; }
        return "session removed";
    }
};

// Control Classes
class Signup {
public:
    static bool registerUser(string userId, string password, string phoneNum) {
        User newUser = User::createUser(userId, password, phoneNum);
        if (!newUser.getUserId().empty()) { return true; } 

        return false;
    }
};

class Login {
public:
    static bool login(string userId, string password) {
        bool isAuthenticated = User::authenticateUser(userId, password);   

        if (isAuthenticated) { Session::createSession(userId); return true; }

        return false;
    }
};

class Logout {
public:
    void logout() {
        DataStore::currentSession.removeSession();
    }
};

class RegisterBike {
public:
    static bool registerBike(string bikeId, string bikeName) {
        if (!User::checkAdmin()) { return false; }
        if (Bike::createBike(bikeId, bikeName).getBikeId().empty()) { return false; }

        return true;
    }
};
/*
찾지 못하면 빈 Bike 객체 반환*/
class RentBike {
public:
    static Bike searchBike(string bikeId, string bikeName) {
        Bike searchedBike = Bike::findBike(bikeId);
        if (searchedBike.getBikeName() != bikeName) { return Bike(); }

        return searchedBike;
    }
    bool rentBike(Bike bike) {
        bool isAssigned = false;
        string userId = Session::getUserIdFromSession();
        if (userId.empty()) { isAssigned = false; }
        isAssigned = User::assignBike(userId, bike);

        return isAssigned;
    }
};

class ShowMemberRentHistory {
public:
    static vector<BikeInfo> showRentHistory() {
        vector<BikeInfo> bikeInfos;

        string userId = Session::getUserIdFromSession();
        bikeInfos = User::getBikeInfosByUserId(userId);

        return bikeInfos;
    }
};

// Boundary Classes (UI)
class SignupUI {
public:
    void startInterface() {
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
    void inputData(string& userId, string& password, string& phoneNum) {
        cout << "\n=== User Signup ===" << "\n";

            cout << "Enter User ID: ";
        cin >> userId;
        cout << "Enter Password: ";
        cin >> password;
        cout << "Enter Phone Number: ";
        cin >> phoneNum;
    }
    void showResult(string msg) { cout << msg << "\n"; }
};

class LoginUI {
public:
    void startInterface() {
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
    void inputData(string& userId, string& password) {
        cout << "\n=== User Login ===" << "\n";

        cout << "Enter User ID: ";
        cin >> userId;
        cout << "Enter Password: ";
        cin >> password;
    }
    void showResult(string msg) { cout << msg << "\n"; }
};

class LogoutUI {
public:
    void requestLogout() {
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

    void showResult(string msg) { cout << msg << "\n"; }
};

class RegisterBikeUI {
public:
    void startInterface() {
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
    void inputData(string& bikeId, string& bikeName) {
        cout << "\n=== Register Bike ===" << "\n";

        cout << "Enter Bike ID: ";
        cin >> bikeId;
        cout << "Enter Bike Name: ";
        cin >> bikeName;
    }
    void showResult(string msg) { cout << msg << "\n"; }
};

class RentBikeUI {
public:
    void startInterface() {
        string bikeId, bikeName;
        string msg;

        inputData(bikeId, bikeName);

        string rentBikeName = RentBike::searchBike(bikeId, bikeName).getBikeId();

        if (!rentBikeName.empty()) {
            msg = "Bike(id:" + rentBikeName + ") registered successfully";
        }
        else {
            msg = "Bike registration failed";
        }

        showResult(msg);
    }
    void inputData(string& bikeId, string& bikeName) {
        cout << "\n=== Register Bike ===" << "\n";

        cout << "Enter Bike ID to search: ";
        cin >> bikeId;
        cout << "Enter Bike Name to search: ";
        cin >> bikeName;
    }
    void showResult(string msg) { cout << msg << "\n"; }
};

class ShowMemberRentHistoryUI {
public:
    void requestShowRentHistory() {
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
    void showResult(vector<BikeInfo> history, string msg) {
        if (history.empty()) {
            cout << "No rent history found." << "\n";
        }
        else {
            cout << "Your rented bikes:" << "\n";
            for (const auto& bike : history) {
                cout << "- " << bike.bikeId << " : " << bike.bikeName << "\n";
            }
        }
    }
};

// Main Application
class BikeRentalSystem {
private:
    void showMenu() {
        cout << "\n=== Bike Rental System Menu ===" << endl;
        cout << "1. Sign Up" << endl;
        cout << "2. Login" << endl;
        cout << "3. Logout" << endl;
        cout << "4. Register Bike (Admin only)" << endl;
        cout << "5. Rent Bike" << endl;
        cout << "6. Show Rent History" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
    }

public:
    void run() {
        cout << "Welcome to Bike Rental System!" << endl;

        int choice;
        do {
            showMenu();
            cin >> choice;

            switch (choice) {
            case 1:
                SignupUI signupUI;
                signupUI.startInterface();
                break;
            case 2:
                LoginUI loginUI;
                loginUI.startInterface();
                break;
            case 3:
                LogoutUI logoutUI;
                logoutUI.requestLogout();
                break;
            case 4:
                RegisterBikeUI registerBikeUI;
                registerBikeUI.startInterface();
                break;
            case 5:
                RentBikeUI rentBikeUI;
                rentBikeUI.startInterface();
                break;
            case 6:
                ShowMemberRentHistoryUI historyUI;
                historyUI.requestShowRentHistory();
                break;
            case 0:
                cout << "Thank you for using Bike Rental System" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
            }
        } while (choice != 0);
    }
};

// Main function
int main() {
    BikeRentalSystem system;
    system.run();
    return 0;
}
