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
ofstream out_fp;
ofstream in_fp;


int main()
{
    // ���� ������� ���� �ʱ�ȭ
    in_fp.open(INPUT_FILE_NAME);
    out_fp.open(OUTPUT_FILE_NAME);

    doTask();

    out_fp.close();
    in_fp.close();

    return 0;
}

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
                    /* 2.1. �α���
                    * �Է�: [ID] [��й�ȣ]
                    * ���: [ID] [��й�ȣ] 
                    */
                    {
                        break;
                    }
                    case 2:   
                    /* 2.2. �α׾ƿ�
                    * �Է�: null
                    * ���: [ID]
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
                    /* 3.1. ������ ���
                    * �Է�: [������ ID] [������ ��ǰ��]
                    * ���: [������ ID] [������ ��ǰ��]
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
                    /* 4.1. ������ �뿩
                    * �Է�: [������ ID]
                    * ���: [������ ID] [������ ��ǰ��]
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
                    /* 5.1. ������ �뿩 ����Ʈ 
                    * �Է�: null
                    * ���: { [������ ID] [������ ��ǰ��] }*
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
                    /* 6.1. ����
                    * �Է�: null
                    * ���: null
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