/* 1.1. ȸ������
* �Է�: [ID] [��й�ȣ] [��ȭ��ȣ]
 ���: [ID][��й�ȣ][��ȭ��ȣ]
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

    
     * �ܼ��� ������ ���� ������ϴ� ����� ���̱� ���� ���̹Ƿ� ���� �� �Լ��� ����ϸ� �ȵ�.
     * ���� switch ������ control �� boundary class�� �̿��ؼ� �� ����� �����ǵ��� �ؾ� ��.
     

    char user_type[MAX_STRING], name[MAX_STRING], SSN [[MAX_STRING], address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];

    // �Է� ���� : �̸�, �ֹι�ȣ, ID, Password�� ���Ϸκ��� ����
    in_fp >> name >> SSN >> ID >> password;


    // �ش� ��� ����  
    //...

    // ��� ����
    out_fp << "1.1. ȸ������" << endl;
    out_fp << name << SSN << ID << password << endl;
}
*/