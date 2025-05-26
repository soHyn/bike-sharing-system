// ��� ����
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

// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void doTask();
void program_exit();

// ���� ����
ofstream out_fp;
ifstream in_fp;

int main()
{
    // ���� ������� ���� �ʱ�ȭ
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
    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;
    string line;
    string trash;

    while (!is_program_exit)
    {
        // �Է����Ͽ��� �޴� ���� 2���� �б�
        if (!getline(in_fp, line)) {
            cout << menu_level_1 << menu_level_2  << "�Է� ��Ʈ�� ���� �Ǵ� ����" << endl;
            break;
        }

        istringstream iss(line);
        stringstream ss(line);
        string trash1, trash2;
        
        if (!(iss >> menu_level_1 >> menu_level_2)) {
            cout << menu_level_1 << menu_level_2 << "�޴� ��ȣ�� ���� �� �����ϴ�: " << line << endl;
            continue;
        }
        
        
        //if (!(in_fp >> menu_level_1 >> menu_level_2)) { cout << menu_level_1 << menu_level_2 << "���� �� �����ϴ�." << endl; continue; }

        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1) {
            case 1:
            {
                switch (menu_level_2) {
                    case 1:  
                    {
                        /* 1.1. ȸ������
                        * �Է�: [ID] [��й�ȣ] [��ȭ��ȣ]
                        * ���: [ID][��й�ȣ][��ȭ��ȣ]
                        */
                        SignupUI signupUI;
                        string userId, password, phoneNum;
                        if (ss >> trash1 >> trash2 >> userId >> password >> phoneNum) {
                            cout << "1.1. ȸ������" << endl;
                            
                            signupUI.startInterface(userId, password, phoneNum);
                        }
                        else {
                            out_fp << "Error: 1.1. ȸ������" << "\n";
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
                    /* 2.1. �α���
                    * �Է�: [ID] [��й�ȣ]
                    * ���: [ID] [��й�ȣ]
                    */
                    LoginUI loginUI;
                    string userId, password;
                    if (ss >> trash1 >> trash2 >> userId >> password) {
                        cout << "2.1. �α���" << endl;
                        
                        loginUI.startInterface(userId, password);
                    }
                    else {
                        out_fp << "Error: 2.1. �α���" << "\n";
                        is_program_exit = 1;
                    }
                    break;
                }
                case 2:
                {
                    /* 2.2. �α׾ƿ�
                    * �Է�: null
                    * ���: [ID]
                    */
                    LogoutUI logoutUI;
                    cout << "2.2. �α׾ƿ�" << endl;
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
                    /* 3.1. ������ ���
                    * �Է�: [������ ID] [������ ��ǰ��]
                    * ���: [������ ID] [������ ��ǰ��]
                    */
                    RegisterBikeUI registerBikeUI;
                    string bikeId, bikeName;
                    cout << "3.1. ������ ���" << endl;

                    if (ss >> trash1 >> trash2 >> bikeId >> bikeName) {
                        registerBikeUI.startInterface(bikeId, bikeName);
                    }
                    else {
                        out_fp << "Error: 3.1. ������ ���" << "\n";
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
                    /* 4.1. ������ �뿩
                    * �Է�: [������ ID]
                    * ���: [������ ID] [������ ��ǰ��]
                    */
                    RentBikeUI rentBikeUI;
                    string bikeId;
                    cout << "4.1. ������ �뿩" << endl;

                    if (ss >> trash1 >> trash2 >> bikeId) {
                        rentBikeUI.startInterface(bikeId);
                    }
                    else {
                        out_fp << "Error: 4.1. ������ �뿩" << "\n";
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
                    /* 5.1. ������ �뿩 ����Ʈ
                    * �Է�: null
                    * ���: { [������ ID] [������ ��ǰ��] }*
                    */
                    cout << "5.1. ������ �뿩 ����Ʈ" << endl;
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
                    /* 6.1. ����
                    * �Է�: null
                    * ���: null
                    */
                    ss >> trash1 >> trash2;

                    cout << "6.1. ����" << endl;
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