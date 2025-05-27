#pragma once

#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <string>
#include <vector>
#include "entities.h" 

/*Signup 클래스
*/
class Signup {
public:
    /* registerUser
    * 입력: 유저 아이디, 비밀번호, 전화번호
    * 출력: 등록성공여부
    */
    bool registerUser(string userId, string password, string phoneNum);
};

/*Login 클래스
*/
class Login {
public:
    /* login
    * 입력: 유저 아이디, 비밀번호
    * 출력: 로그인성공여부
    */
    bool login(string userId, string password);
};

/*Logout 클래스
*/
class Logout {
public:
    /* logout
    * 입력: void
    * 출력: void
    */
    void logout();
};

/*RegisterBike 클래스
*/
class RegisterBike {
public:
    /* registerBike
    * 입력: 자전거 아이디, 자전거 이름
    * 출력: 자전거 등록 성공 여부
    */
    bool registerBike(string bikeId, string bikeName);
};

/*RentBike 클래스
*/
class RentBike {
public:
    /* searchBike
    * 입력: 자전거 아이디
    * 출력: 자전거 객체
    */
    Bike searchBike(string bikeId);
    /* rentBike
    * 입력: 자전거 객체
    * 출력: 자전거 렌트 성공여부
    */
    bool rentBike(Bike bike);
};

/*ShowMemberRentHistory 클래스
*/
class ShowMemberRentHistory {
public:
    /* showRentHistory
    * 입력: void
    * 출력: 자전거 아이디, 자전거 이름 저장 객체 벡터
    */
    vector<BikeInfo> showRentHistory();
};

#endif