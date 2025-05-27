#pragma once

#ifndef BOUNDARIES_H
#define BOUNDARIES_H

#include <string>
#include "controllers.h" 
#include "entities.h"    

using namespace std;

/*SignupUI 클래스
*/
class SignupUI {
public:
    /*startInterface
    * 입력: 유저 아이디, 비밀번호, 전화번호
    * 출력: void
    * 시작 인터페이스
    */
    void startInterface(string userId, string password, string phoneNum);
    /*inputData
    * 입력: 유저 아이디, 비밀번호, 전화번호
    * 출력: void
    * 파일 입출력 혹은 이 방법 둘 중 하나를 선택해서 사용자의 입력을 받는다.
    */
    void inputData(string& userId, string& password, string& phoneNum);
    /*showResult
   * 입력: 문자열
   * 출력: void
   * 화면에 결과를 출력한다.
   */
    void showResult(string msg);
};

/*LoginUI 클래스
*/
class LoginUI {
public:
    /*startInterface
    * 입력: 유저 아이디, 비밀번호
    * 출력: void
    * 시작 인터페이스
    */
    void startInterface(string userId, string password);
    /*inputData
    * 입력: 유저 아이디, 비밀번호
    * 출력: void
    * 파일 입출력 혹은 이 방법 둘 중 하나를 선택해서 사용자의 입력을 받는다.
    */
    void inputData(string& userId, string& password);
    /*showResult
   * 입력: 문자열
   * 출력: void
   * 화면에 결과를 출력한다.
   */
    void showResult(string msg);
};

/*LogoutUI 클래스
*/
class LogoutUI {
public:
    /*requestLogout
    * 입력: void
    * 출력: void
    * 로그아웃을 요청한다.
    */
    void requestLogout();
    /*showResult
   * 입력: 문자열
   * 출력: void
   * 화면에 결과를 출력한다.
   */
    void showResult(string msg);
};

/*RegisterBikeUI 클래스
*/
class RegisterBikeUI {
public:
    /*startInterface
    * 입력: 자전거 아이디, 자전거 이름
    * 출력: void
    * 시작 인터페이스
    */
    void startInterface(string bikeId, string bikeName);

    /*inputData
    * 입력: 자전거 아이디, 자전거 이름
    * 출력: void
    * 파일 입출력 혹은 이 방법 둘 중 하나를 선택해서 사용자의 입력을 받는다.
    */
    void inputData(string& bikeId, string& bikeName);

    /*showResult
   * 입력: 문자열
   * 출력: void
   * 화면에 결과를 출력한다.
   */
    void showResult(string msg);
};

/*RentBikeUI 클래스
*/
class RentBikeUI {
public:
    /*startInterface
    * 입력: 자전거 아이디
    * 출력: void
    * 시작 인터페이스
    */
    void startInterface(string bikeId);

    /*inputData
    * 입력: 자전거 아이디, 자전거 이름
    * 출력: void
    * 파일 입출력 혹은 이 방법 둘 중 하나를 선택해서 사용자의 입력을 받는다.
    */
    void inputData(string& bikeId, string& bikeName);
    
    /*showSearchedBike
    * 입력: 자전거 이름
    * 출력: bool
    * 자전거 이름을 검색해 자전거를 찾으면 true, 못 찾으면 false를 반환한다.
    */
    bool showSearchedBike(string bikeName);

   /*showResult
    * 입력: 문자열
    * 출력: void
    * 화면에 결과를 출력한다.
    */
    void showResult(string msg);

    /* requestRentBike
    * 입력: 자전거 객체
    * 출력: void
    자전거 렌트를 요청한다.*/
    void requestRentBike(Bike bike);
};

/*ShowMemberRentHistoryUI 클래스
*/
class ShowMemberRentHistoryUI {
public:
    /*requestShowRentHistory
    * 입력: void
    * 출력: void
    * 렌트 기록 출력을 요청한다.
    */
    void requestShowRentHistory();

    /*showResult
    * 입력: 문자열
    * 출력: void
    * 화면에 결과를 출력한다.
    */
    void showResult(vector<BikeInfo> history, string msg);
};

#endif // !BOUNDARIES_H