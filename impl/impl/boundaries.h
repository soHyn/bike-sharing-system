#pragma once

#ifndef BOUNDARIES_H
#define BOUNDARIES_H

#include <string>
#include "controllers.h" 
#include "entities.h"    

using namespace std;

/*SignupUI Ŭ����
*/
class SignupUI {
public:
    /*startInterface
    * �Է�: ���� ���̵�, ��й�ȣ, ��ȭ��ȣ
    * ���: void
    * ���� �������̽�
    */
    void startInterface(string userId, string password, string phoneNum);
    /*inputData
    * �Է�: ���� ���̵�, ��й�ȣ, ��ȭ��ȣ
    * ���: void
    * ���� ����� Ȥ�� �� ��� �� �� �ϳ��� �����ؼ� ������� �Է��� �޴´�.
    */
    void inputData(string& userId, string& password, string& phoneNum);
    /*showResult
   * �Է�: ���ڿ�
   * ���: void
   * ȭ�鿡 ����� ����Ѵ�.
   */
    void showResult(string msg);
};

/*LoginUI Ŭ����
*/
class LoginUI {
public:
    /*startInterface
    * �Է�: ���� ���̵�, ��й�ȣ
    * ���: void
    * ���� �������̽�
    */
    void startInterface(string userId, string password);
    /*inputData
    * �Է�: ���� ���̵�, ��й�ȣ
    * ���: void
    * ���� ����� Ȥ�� �� ��� �� �� �ϳ��� �����ؼ� ������� �Է��� �޴´�.
    */
    void inputData(string& userId, string& password);
    /*showResult
   * �Է�: ���ڿ�
   * ���: void
   * ȭ�鿡 ����� ����Ѵ�.
   */
    void showResult(string msg);
};

/*LogoutUI Ŭ����
*/
class LogoutUI {
public:
    /*requestLogout
    * �Է�: void
    * ���: void
    * �α׾ƿ��� ��û�Ѵ�.
    */
    void requestLogout();
    /*showResult
   * �Է�: ���ڿ�
   * ���: void
   * ȭ�鿡 ����� ����Ѵ�.
   */
    void showResult(string msg);
};

/*RegisterBikeUI Ŭ����
*/
class RegisterBikeUI {
public:
    /*startInterface
    * �Է�: ������ ���̵�, ������ �̸�
    * ���: void
    * ���� �������̽�
    */
    void startInterface(string bikeId, string bikeName);

    /*inputData
    * �Է�: ������ ���̵�, ������ �̸�
    * ���: void
    * ���� ����� Ȥ�� �� ��� �� �� �ϳ��� �����ؼ� ������� �Է��� �޴´�.
    */
    void inputData(string& bikeId, string& bikeName);

    /*showResult
   * �Է�: ���ڿ�
   * ���: void
   * ȭ�鿡 ����� ����Ѵ�.
   */
    void showResult(string msg);
};

/*RentBikeUI Ŭ����
*/
class RentBikeUI {
public:
    /*startInterface
    * �Է�: ������ ���̵�
    * ���: void
    * ���� �������̽�
    */
    void startInterface(string bikeId);

    /*inputData
    * �Է�: ������ ���̵�, ������ �̸�
    * ���: void
    * ���� ����� Ȥ�� �� ��� �� �� �ϳ��� �����ؼ� ������� �Է��� �޴´�.
    */
    void inputData(string& bikeId, string& bikeName);
    
    /*showSearchedBike
    * �Է�: ������ �̸�
    * ���: bool
    * ������ �̸��� �˻��� �����Ÿ� ã���� true, �� ã���� false�� ��ȯ�Ѵ�.
    */
    bool showSearchedBike(string bikeName);

   /*showResult
    * �Է�: ���ڿ�
    * ���: void
    * ȭ�鿡 ����� ����Ѵ�.
    */
    void showResult(string msg);

    /* requestRentBike
    * �Է�: ������ ��ü
    * ���: void
    ������ ��Ʈ�� ��û�Ѵ�.*/
    void requestRentBike(Bike bike);
};

/*ShowMemberRentHistoryUI Ŭ����
*/
class ShowMemberRentHistoryUI {
public:
    /*requestShowRentHistory
    * �Է�: void
    * ���: void
    * ��Ʈ ��� ����� ��û�Ѵ�.
    */
    void requestShowRentHistory();

    /*showResult
    * �Է�: ���ڿ�
    * ���: void
    * ȭ�鿡 ����� ����Ѵ�.
    */
    void showResult(vector<BikeInfo> history, string msg);
};

#endif // !BOUNDARIES_H