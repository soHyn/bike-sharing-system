/* 1.1. 회원가입
* 입력: [ID] [비밀번호] [전화번호]
 출력: [ID][비밀번호][전화번호]
*/
class Signup {

public:
    void registerUser(String id, String password, String phoneNum, Role role) {
        createUser()
        msg = "success";
        showResult(msg)
    }
};
/*
void Signup()
{

    
     * 단순히 파일을 통해 입출력하는 방법을 보이기 위한 것이므로 실제 이 함수를 사용하면 안됨.
     * 위의 switch 문에서 control 및 boundary class를 이용해서 이 기능이 구현되도록 해야 함.
     

    char user_type[MAX_STRING], name[MAX_STRING], SSN [[MAX_STRING], address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];

    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    in_fp >> name >> SSN >> ID >> password;


    // 해당 기능 수행  
    //...

    // 출력 형식
    out_fp << "1.1. 회원가입" << endl;
    out_fp << name << SSN << ID << password << endl;
}
*/