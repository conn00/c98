#include <iostream>
#include <fstream>

int guiWelcome();
int guiSelectRole();
void guiCreateRole();
void guiDelRole();
std::string guiCreateRoleName();
std::string guiCreateRoleGender();

struct role {
    std::string roleName;
    std::string roleGender;
    unsigned short roleRank;
    unsigned short roleStrength;
    unsigned short roleStamina;
    unsigned short roleAgility;
};

int main(){
    int flowID, roleID;
    system("chcp 936");
    system("cls");
    flowID = guiWelcome();
    if(flowID == 1){
        roleID = guiSelectRole();
    }
    std::cout << flowID;
    return 0;
}

int guiWelcome(){
    int selection;
    bool flag = false;
    while(!flag){
        std::cout << "\r��������������������������������������������������������������������������������������������������������������������������������������������\n"
                     "��                                                                    ��\n"
                     "��                                                                    ��\n"     
                     "��                            ��  ��  ��  ½                          ��\n"
                     "��                                                                    ��\n" 
                     "��                                                                    ��\n"
                     "��    ��������֮ս�ķ�����������������ܺ����ϲ�Ϊ��֪��һЩ���ܱ�    ��\n"
                     "��                                                                    ��\n" 
                     "��    �������˽硣�ƻ��������ڡ��������ǡ���½�Ĵ�ɢ��������������    ��\n"
                     "��                                                                    ��\n" 
                     "��    �̵Ĺ���������Ϊ���ؽ����ջ���ʱ����������չ����Ŭ������        ��\n"
                     "��                                                                    ��\n"
                     "��                                                                    ��\n"
                     "��                         [1] ��  ʼ  ��  Ϸ                         ��\n"
                     "��                                                                    ��\n"
                     "��                         [2] ��  Ϸ  ��  ��                         ��\n"
                     "��                                                                    ��\n"
                     "��                         [3] ��  ��  ��  Ϸ                         ��\n"
                     "��                                                                    ��\n" 
                     "��                                                              v1.0  ��\n"
                     "��������������������������������������������������������������������������������������������������������������������������������������������\n"
                     "��ѡ�񡿣�";
        std::cin.clear();
        std::cin.sync();
        std::cin >> selection;
        if (selection == 1 || selection == 2 || selection == 3)flag = true;
    }
    
    return selection;
}

int guiSelectRole(){
    char selection;
    bool flag = false;
    while(!flag){
        std::cout << "\r��������������������������������������������������������������������������\n"
                 "��                                   ��\n"
                 "��           ѡ  ��  ��  ��          ��\n"
                 "��                                   ��\n"
                 "��                                   ��\n"
                 "��                 ��                ��\n"
                 "��                                   ��\n"
                 "��                                   ��\n"
                 "��   [a] ��������     [d] ɾ������   ��\n"
                 "��������������������������������������������������������������������������\n"
                 "��ѡ�񡿣�";
        std::cin.clear();
        std::cin.sync();
        std::cin >> selection;
        switch (selection)
        {
            case '1':
                flag = true;
                break;
            case '2':
                flag = true;
                break;
            case '3':
                flag = true;
                break;
            case 'a':
            case 'A':
                guiCreateRole();
                flag = true;
                break;
            case 'd':
            case 'D':
                guiDelRole();
                //flag = true;
                break;
            default:
                break;
        }
    }
    
    return 1;
}

void guiCreateRole(){
    role newRole;
    int selection;
    bool flag = false;
    std::string ch;
    std::ofstream outFile;
    
    newRole.roleName = guiCreateRoleName();
    newRole.roleGender = guiCreateRoleGender();
    newRole.roleRank = 1;
    newRole.roleStrength = 5;
    newRole.roleStamina = 8;
    newRole.roleAgility = 3;

    do{
        ch = "";
        for(int i = 0; i < 23 - newRole.roleName.size(); i++) ch += " ";
        std::cout << "\r��������������������������������������������������������������������������\n"
                     "��                                   ��\n"
                     "��  ������Ϣ                         ��\n"
                     "��                                   ��\n"
                     "��      ���ƣ�" << newRole.roleName << ch << "��\n";  // 17���ո�
        std::cout << "��                                   ��\n"
                     "��      �Ա�" << newRole.roleGender << "                     ��\n";
        std::cout << "��                                   ��\n"
                     "��      �ȼ���" << newRole.roleRank << "                      ��\n";
        std::cout << "��                                   ��\n"
                     "��      �d " << newRole.roleStrength << "  " << "�� " << newRole.roleStamina << "  " << "�� " << newRole.roleAgility << "             ��\n";
        std::cout << "��                                   ��\n"
                     "��                                   ��\n"
                     "��  [1] ��������       [2] �ؽ�����  ��\n"
                     "��                                   ��\n"
                     "��  [3] ��������       [4] �����Ա�  ��\n"
                     "��                                   ��\n"
                     "��������������������������������������������������������������������������\n"
                     "ѡ��";
        std::cin.clear();
        std::cin.sync();
        std::cin >> selection;
        switch (selection)
        {
        case 1:
            std::cout << "\r����������������������������������\n"
                         "�� ���ﴴ���С��� ��\n"
                         "����������������������������������\n";         
            outFile.open("initialization.hxl");
            
            flag = true;
            break;
        case 2:
            newRole.roleName = guiCreateRoleName();
            newRole.roleGender = guiCreateRoleGender();
            //flag = true;
            break;
        case 3:
            newRole.roleName = guiCreateRoleName();
            //flag = true;
            break;
        case 4:
            newRole.roleGender = guiCreateRoleGender();
            //flag = true;
            break;
        default:
            break;
        }
    } while (!flag);
}

std::string guiCreateRoleName(){
    std::string input;
    std::string result = "";
    do{
       std::cout << "\r��������������������������������������������������������������������������\n"
                    "��                                   ��\n"
                    "��  ��������                         ��\n"
                    "��                                   ��\n"
                    "��      ���Ƶ���Ч����Ϊ2��6�����֡� ��\n"
                    "��                                   ��\n"
                    "��������������������������������������������������������������������������\n"
                    "�������ƣ�";
        std::cin.clear();
        std::cin.sync();
        std::cin >> input;
    }while(input.size() <2 || input.size() > 12);
    if(input.size() >= 2 || input.size() <= 12) result = input;
    return result;
}

std::string guiCreateRoleGender(){
    int selection;
    bool flag = false;
    std::string result = "";
    do{
        std::cout << "\r��������������������������������������������������������������������������\n"
                     "��                                   ��\n"
                     "��  �����Ա�                         ��\n"
                     "��                                   ��\n"
                     "��        [1] ��      [2] Ů         ��\n"
                     "��                                   ��\n"
                     "��������������������������������������������������������������������������\n"
                     "ѡ�������Ա�";
        std::cin.clear();
        std::cin.sync();
        std::cin >> selection;
        if(selection == 1){
            result = "��";
            flag = true;
        }else if(selection  == 2){
            result = "Ů";
            flag = true;
        }else{
             std::cout << "\r��������������������������������������������������\n"
                          "�� ��ѡ����ȷ�������Ա𡣩�\n"
                          "��������������������������������������������������\n";
        }
    }while(!flag);
    return result;
}

void guiDelRole(){
    std::cout << "\r��������������������������������������������������������������������������\n"
                 "�� ������ʱδ���š�                  ��\n"
                 "��������������������������������������������������������������������������\n";
}