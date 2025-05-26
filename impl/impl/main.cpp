// 헤더 선언
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "entities.h"
#include "boundaries.h"
#include "controllers.h"

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void program_exit();

// 변수 선언
ofstream out_fp;
ifstream in_fp;

int main()
{
    // 파일 입출력을 위한 초기화
    in_fp.open(INPUT_FILE_NAME);
    if (!in_fp.is_open()) { cerr << "Error: Could not open input file" << "\n"; return 1; }
    out_fp.open(OUTPUT_FILE_NAME);

    doTask();

    out_fp.close();
    in_fp.close();

    return 0;
}

void program_exit() {

}
void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    string line;
    string trash;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        if (!getline(in_fp, line)) {
            cout << menu_level_1 << menu_level_2  << "입력 스트림 종료 또는 실패" << endl;
            break;
        }

        istringstream iss(line);
        stringstream ss(line);
        string trash1, trash2;
        
        if (!(iss >> menu_level_1 >> menu_level_2)) {
            cout << menu_level_1 << menu_level_2 << "메뉴 번호를 읽을 수 없습니다: " << line << endl;
            continue;
        }
        
        
        //if (!(in_fp >> menu_level_1 >> menu_level_2)) { cout << menu_level_1 << menu_level_2 << "읽을 수 없습니다." << endl; continue; }

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1) {
            case 1:
            {
                switch (menu_level_2) {
                    case 1:  
                    {
                        /* 1.1. 회원가입
                        * 입력: [ID] [비밀번호] [전화번호]
                        * 출력: [ID][비밀번호][전화번호]
                        */
                        SignupUI signupUI;
                        string userId, password, phoneNum;
                        if (ss >> trash1 >> trash2 >> userId >> password >> phoneNum) {
                            cout << "1.1. 회원가입" << endl;
                            
                            signupUI.startInterface(userId, password, phoneNum);
                        }
                        else {
                            out_fp << "Error: 1.1. 회원가입" << "\n";
                            is_program_exit = 1;
                        }
                        break;
                    }
                }
                break;
            }
            case 2:
            {
                switch (menu_level_2) {
                case 1:
                {
                    /* 2.1. 로그인
                    * 입력: [ID] [비밀번호]
                    * 출력: [ID] [비밀번호]
                    */
                    LoginUI loginUI;
                    string userId, password;
                    if (ss >> trash1 >> trash2 >> userId >> password) {
                        cout << "2.1. 로그인" << endl;
                        
                        loginUI.startInterface(userId, password);
                    }
                    else {
                        out_fp << "Error: 2.1. 로그인" << "\n";
                        is_program_exit = 1;
                    }
                    break;
                }
                case 2:
                {
                    /* 2.2. 로그아웃
                    * 입력: null
                    * 출력: [ID]
                    */
                    LogoutUI logoutUI;
                    cout << "2.2. 로그아웃" << endl;
                    ss >> trash1 >> trash2;
                    logoutUI.requestLogout();

                    break;
                }
                }
                break;
            }
            case 3:
            {
                switch (menu_level_2) {
                case 1:
                {
                    /* 3.1. 자전거 등록
                    * 입력: [자전거 ID] [자전거 제품명]
                    * 출력: [자전거 ID] [자전거 제품명]
                    */
                    RegisterBikeUI registerBikeUI;
                    string bikeId, bikeName;
                    cout << "3.1. 자전거 등록" << endl;

                    if (ss >> trash1 >> trash2 >> bikeId >> bikeName) {
                        registerBikeUI.startInterface(bikeId, bikeName);
                    }
                    else {
                        out_fp << "Error: 3.1. 자전거 등록" << "\n";
                        is_program_exit = 1;
                    }
                    break;
                }
                }
                break;
            }
            case 4:
            {
                switch (menu_level_2) {
                case 1:
                {
                    /* 4.1. 자전거 대여
                    * 입력: [자전거 ID]
                    * 출력: [자전거 ID] [자전거 제품명]
                    */
                    RentBikeUI rentBikeUI;
                    string bikeId;
                    cout << "4.1. 자전거 대여" << endl;

                    if (ss >> trash1 >> trash2 >> bikeId) {
                        rentBikeUI.startInterface(bikeId);
                    }
                    else {
                        out_fp << "Error: 4.1. 자전거 대여" << "\n";
                        is_program_exit = 1;
                    }
                    break;
                }
                }
                break;
            }
            case 5:
            {
                switch (menu_level_2) {
                case 1:
                {
                    /* 5.1. 자전거 대여 리스트
                    * 입력: null
                    * 출력: { [자전거 ID] [자전거 제품명] }*
                    */
                    cout << "5.1. 자전거 대여 리스트" << endl;
                    ss >> trash1 >> trash2;

                    ShowMemberRentHistoryUI showMemberRentHistoryUI;
                    showMemberRentHistoryUI.requestShowRentHistory();
                    break;
                }
                }
                break;
            }
            case 6:
            {
                switch (menu_level_2) {
                case 1:
                {
                    /* 6.1. 종료
                    * 입력: null
                    * 출력: null
                    */
                    ss >> trash1 >> trash2;

                    cout << "6.1. 종료" << endl;
                    is_program_exit = 1;
                    break;
                }
                }
                break;
            }
        }
        cout << endl;
    }
}

/*

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "entities.h"
#include "boundaries.h"
#include "controllers.h"

using namespace std;

map<string, User> DataStore::userRepository;
map<string, Bike> DataStore::bikeRepository;
Session DataStore::currentSession;

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
*/