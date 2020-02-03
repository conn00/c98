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
        std::cout << "\r┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n"
                     "│                                                                    │\n"
                     "│                                                                    │\n"     
                     "│                            勇  者  大  陆                          │\n"
                     "│                                                                    │\n" 
                     "│                                                                    │\n"
                     "│    由于天上之战的发生，创造世界的秘密和天上不为人知的一些秘密被    │\n"
                     "│                                                                    │\n" 
                     "│    流传到人界。破坏的旋风在“阿尔弥亚”大陆四处散开，在漫长的隐    │\n"
                     "│                                                                    │\n" 
                     "│    忍的过程中人们为了重建往日华丽时代的荣誉而展开了努力……        │\n"
                     "│                                                                    │\n"
                     "│                                                                    │\n"
                     "│                         [1] 开  始  游  戏                         │\n"
                     "│                                                                    │\n"
                     "│                         [2] 游  戏  介  绍                         │\n"
                     "│                                                                    │\n"
                     "│                         [3] 退  出  游  戏                         │\n"
                     "│                                                                    │\n" 
                     "│                                                              v1.0  │\n"
                     "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n"
                     "【选择】：";
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
        std::cout << "\r┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n"
                 "│                                   │\n"
                 "│           选  择  人  物          │\n"
                 "│                                   │\n"
                 "│                                   │\n"
                 "│                 无                │\n"
                 "│                                   │\n"
                 "│                                   │\n"
                 "│   [a] 创建人物     [d] 删除人物   │\n"
                 "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n"
                 "【选择】：";
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
        std::cout << "\r┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n"
                     "│                                   │\n"
                     "│  人物信息                         │\n"
                     "│                                   │\n"
                     "│      名称：" << newRole.roleName << ch << "│\n";  // 17个空格
        std::cout << "│                                   │\n"
                     "│      性别：" << newRole.roleGender << "                     │\n";
        std::cout << "│                                   │\n"
                     "│      等级：" << newRole.roleRank << "                      │\n";
        std::cout << "│                                   │\n"
                     "│      ヾ " << newRole.roleStrength << "  " << "◎ " << newRole.roleStamina << "  " << "¤ " << newRole.roleAgility << "             │\n";
        std::cout << "│                                   │\n"
                     "│                                   │\n"
                     "│  [1] 创建人物       [2] 重建人物  │\n"
                     "│                                   │\n"
                     "│  [3] 更改名称       [4] 更改性别  │\n"
                     "│                                   │\n"
                     "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n"
                     "选择：";
        std::cin.clear();
        std::cin.sync();
        std::cin >> selection;
        switch (selection)
        {
        case 1:
            std::cout << "\r┍━━━━━━━━━━━━━━━┑\n"
                         "│ 人物创建中…… │\n"
                         "┕━━━━━━━━━━━━━━━┙\n";         
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
       std::cout << "\r┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n"
                    "│                                   │\n"
                    "│  人物名称                         │\n"
                    "│                                   │\n"
                    "│      名称的有效长度为2到6个汉字。 │\n"
                    "│                                   │\n"
                    "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n"
                    "人物名称：";
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
        std::cout << "\r┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n"
                     "│                                   │\n"
                     "│  人物性别                         │\n"
                     "│                                   │\n"
                     "│        [1] 男      [2] 女         │\n"
                     "│                                   │\n"
                     "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n"
                     "选择人物性别：";
        std::cin.clear();
        std::cin.sync();
        std::cin >> selection;
        if(selection == 1){
            result = "男";
            flag = true;
        }else if(selection  == 2){
            result = "女";
            flag = true;
        }else{
             std::cout << "\r┍━━━━━━━━━━━━━━━━━━━━━━━┑\n"
                          "│ 请选择正确的人物性别。│\n"
                          "┕━━━━━━━━━━━━━━━━━━━━━━━┙\n";
        }
    }while(!flag);
    return result;
}

void guiDelRole(){
    std::cout << "\r┍━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┑\n"
                 "│ 功能暂时未开放。                  │\n"
                 "┕━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┙\n";
}