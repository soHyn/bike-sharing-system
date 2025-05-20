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
ofstream out_fp;
ofstream in_fp;


int main()
{
    // 파일 입출력을 위한 초기화
    in_fp.open(INPUT_FILE_NAME);
    out_fp.open(OUTPUT_FILE_NAME);

    doTask();

    out_fp.close();
    in_fp.close();

    return 0;
}

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
                    */
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
                    */
                    {
                        break;
                    }
                    case 2:   
                    /* 2.2. 로그아웃
                    * 입력: null
                    * 출력: [ID]
                    */
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
                    */
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
                    */
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
                    */
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
                    */
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