#pragma once

#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <string>
#include <vector>
#include "entities.h" 

/*Signup Ŭ����
*/
class Signup {
public:
    /* registerUser
    * �Է�: ���� ���̵�, ��й�ȣ, ��ȭ��ȣ
    * ���: ��ϼ�������
    */
    bool registerUser(string userId, string password, string phoneNum);
};

/*Login Ŭ����
*/
class Login {
public:
    /* login
    * �Է�: ���� ���̵�, ��й�ȣ
    * ���: �α��μ�������
    */
    bool login(string userId, string password);
};

/*Logout Ŭ����
*/
class Logout {
public:
    /* logout
    * �Է�: void
    * ���: void
    */
    void logout();
};

/*RegisterBike Ŭ����
*/
class RegisterBike {
public:
    /* registerBike
    * �Է�: ������ ���̵�, ������ �̸�
    * ���: ������ ��� ���� ����
    */
    bool registerBike(string bikeId, string bikeName);
};

/*RentBike Ŭ����
*/
class RentBike {
public:
    /* searchBike
    * �Է�: ������ ���̵�
    * ���: ������ ��ü
    */
    Bike searchBike(string bikeId);
    /* rentBike
    * �Է�: ������ ��ü
    * ���: ������ ��Ʈ ��������
    */
    bool rentBike(Bike bike);
};

/*ShowMemberRentHistory Ŭ����
*/
class ShowMemberRentHistory {
public:
    /* showRentHistory
    * �Է�: void
    * ���: ������ ���̵�, ������ �̸� ���� ��ü ����
    */
    vector<BikeInfo> showRentHistory();
};

#endif