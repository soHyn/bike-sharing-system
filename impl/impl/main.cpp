/*
// ��� ����
#include <stdio.h>
#include <string.h>

// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();
void program_exit();

// ���� ����
//ofstream out_fp;
//ofstream in_fp;

void doTask()
{
    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // �Է����Ͽ��� �޴� ���� 2���� �б�
        in_fp >> menu_level_1 >> menu_level_2;


        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1) {
            case 1:
            {
                switch (menu_level_2) {
                    case 1:   //
                    /* 1.1. ȸ������
                    * �Է�: [ID] [��й�ȣ] [��ȭ��ȣ]
                    * ���: [ID][��й�ȣ][��ȭ��ȣ]
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
                    /* 2.1. �α���
                    * �Է�: [ID] [��й�ȣ]
                    * ���: [ID] [��й�ȣ]
                    *
                {
                    break;
                }
                case 2:
                    /* 2.2. �α׾ƿ�
                    * �Է�: null
                    * ���: [ID]
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
                    /* 3.1. ������ ���
                    * �Է�: [������ ID] [������ ��ǰ��]
                    * ���: [������ ID] [������ ��ǰ��]
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
                    /* 4.1. ������ �뿩
                    * �Է�: [������ ID]
                    * ���: [������ ID] [������ ��ǰ��]
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
                    /* 5.1. ������ �뿩 ����Ʈ
                    * �Է�: null
                    * ���: { [������ ID] [������ ��ǰ��] }*
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
                    /* 6.1. ����
                    * �Է�: null
                    * ���: null
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

// Entity Classes
Bike::Bike() {} // �⺻ ������ �߰�
Bike::Bike(const string& id, const string& name) : bikeId(id), bikeName(name) {}

string Bike::getBikeId() const { return bikeId; } //
string Bike::getBikeName() const { return bikeName; }
BikeInfo Bike::getBikeInfo() const { return { bikeId, bikeName }; }

/*
    * bikeId�� bike ��ü Ž�� �� ��ȯ
    * Ž�� ���� �� �� BIke ���� �� ��ȯ
    */
Bike Bike::findBike(const string bikeId) {
    Bike findBike;

    auto iter = DataStore::bikeRepository.find(bikeId);
    if (iter != DataStore::bikeRepository.end()) {
        //ã�� ���
        findBike = iter->second;
    }
    else {
        cout << "Bike not found" << "\n";
        findBike = Bike();
    }
    return findBike;
}
/*bikeId, bikeName���� bike ��ü ����
*/
Bike Bike::createBike(const string& bikeId, const string& bikeName) {
    if (bikeId.empty()) { return Bike(); }
    Bike newBike = Bike(bikeId, bikeName);
    DataStore::bikeRepository.emplace(bikeId, newBike);

    return newBike;
}


User::User() {}
User::User(string userId, string password, string phoneNum, Role role) : userId(userId), password(password), phoneNum(phoneNum), role(role) {}

string User::getUserId() const { return userId; }

User User::createUser(string userId, string password, string phoneNum) {
    if (userId.empty()) { return User(); }
    Role role = Role::MEMBER;
    User newUser = User(userId, password, phoneNum, role);

    DataStore::userRepository.emplace(userId, newUser);

    return newUser;
}

User User::findUser(string userId) {
    User findUser;

    auto iter = DataStore::userRepository.find(userId);
    if (iter != DataStore::userRepository.end()) {
        //ã�� ���
        findUser = iter->second;
    }
    else {
        cout << "User not found" << "\n";
        findUser = User();
    }

    return findUser;
}

bool User::authenticateUser(string userId, string password) {
    bool isAuthenticated = false;

    User findUser = User::findUser(userId);

    if (findUser.password == password) { isAuthenticated = true; }
    else {
        cout << "User not found" << "\n";
    }

    return isAuthenticated;
}

bool User::checkAdmin() {
    string userId = Session::getUserIdFromSession();
    User user = findUser(userId);
    if (user.role == ADMIN) { return true; }
    return false;
}

bool User::assignBike(const string& userId, const Bike& findBike) {
    User rentUser = findUser(userId);
    if (!rentUser.getUserId().empty()) { rentUser.bikes.push_back(findBike); return true; }

    return false;
}

vector<BikeInfo> User::getBikeInfosByUserId(string userId) {
    User user = findUser(userId);
    vector<BikeInfo> bikeInfos;
    for (Bike bike : user.bikes) {
        bikeInfos.push_back(bike.getBikeInfo());
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
    return DataStore::currentSession.userId;
}


// Control Classes

bool Signup::registerUser(string userId, string password, string phoneNum) {
    User newUser = User::createUser(userId, password, phoneNum);
    if (!newUser.getUserId().empty()) { return true; }

    return false;
}


bool Login::login(string userId, string password) {
    bool isAuthenticated = User::authenticateUser(userId, password);

    if (isAuthenticated) { Session::createSession(userId); return true; }

    return false;
}


void Logout::logout() {
    DataStore::currentSession.removeSession();
}


bool RegisterBike::registerBike(string bikeId, string bikeName) {
    if (!User::checkAdmin()) { return false; }
    if (Bike::createBike(bikeId, bikeName).getBikeId().empty()) { return false; }

    return true;
}

/*
ã�� ���ϸ� �� Bike ��ü ��ȯ*/
Bike RentBike::searchBike(string bikeId, string bikeName) {
    Bike searchedBike = Bike::findBike(bikeId);
    if (searchedBike.getBikeName() != bikeName) { return Bike(); }

    return searchedBike;
}
bool RentBike::rentBike(Bike bike) {
    bool isAssigned = false;
    string userId = Session::getUserIdFromSession();
    if (userId.empty()) { isAssigned = false; }
    isAssigned = User::assignBike(userId, bike);

    return isAssigned;
}


vector<BikeInfo> ShowMemberRentHistory::showRentHistory() {
    vector<BikeInfo> bikeInfos;

    string userId = Session::getUserIdFromSession();
    bikeInfos = User::getBikeInfosByUserId(userId);

    return bikeInfos;
}


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

    string rentBikeName = RentBike::searchBike(bikeId, bikeName).getBikeId();

    if (!rentBikeName.empty()) {
        msg = "Bike(id:" + rentBikeName + ") registered successfully";
    }
    else {
        msg = "Bike registration failed";
    }

    showResult(msg);
}
void RentBikeUI::inputData(string& bikeId, string& bikeName) {
    cout << "\n=== Register Bike ===" << "\n";

    cout << "Enter Bike ID to search: ";
    cin >> bikeId;
    cout << "Enter Bike Name to search: ";
    cin >> bikeName;
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
            cout << "- " << bike.bikeId << " : " << bike.bikeName << "\n";
        }
    }
}


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