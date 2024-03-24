#include <iostream>
#include <array>
#include <string>


#define  DEFAULT_VAL        1
#define  MAX_USER_NUM       100
#define  INIT_ARR           0
#define  INIT_VAL           0
#define  TRUE               1
#define  FALSE              0


int condition = TRUE;

class User
{
    private:
        std::string name; 
        int age;
    public: 
        void Add_Record();
        void Fetch_Record();
        void Qiut(); 
};

typedef enum 
{   
    DEFAULT,
    ADD_USER,
    FETCH_USER,
    QUIT
}Option;


void print_msg(std::string str);
void print_msg(std::string s, int val);




int main(void)
{
    print_msg("User SignUp Application");    
    std::array <User, MAX_USER_NUM> users;
    int index_num = INIT_ARR;
    int option = Option:: DEFAULT;
    int id_num = INIT_VAL;

    while(condition)
    {
        print_msg("\n\nPlease select an option of those: \n1: Add Record\n2: Fetch Record\n3: Quit\noption: ");
        std::cin >> option;
        switch (option)
        {
            case Option:: ADD_USER:
                users[index_num].Add_Record();
                print_msg("Here is your ID: ", index_num);
                ++index_num;
                break;
            case Option:: FETCH_USER:
                if(index_num == INIT_ARR)
                {
                    print_msg("Sorry there is no users\n");
                } 
                else
                {
                    print_msg("Please Enter the user id: ");
                    std::cin >> id_num;
                    if(id_num > index_num-1)
                    {
                    print_msg("Sorry this invalid id\n");
                    }
                    else
                    {
                        users[id_num].Fetch_Record();
                    }
                }
                break;
            case Option:: QUIT:
                users[index_num].Qiut();
                break;    
            default:
                print_msg("Sorry, Invalid Option\n");
                break;
        }
    }

    return 0;
}


void print_msg(std::string str)
{
    std::cout << str;
}
void print_msg(std::string s, int val)
{
    std::cout << s << val;
}

void User:: Add_Record()
{
    print_msg("Please Enter user name: ");
    std::cin >> name;
    print_msg("Please Enter user age: ");
    std::cin >> age;
    print_msg("User record added successfully\n");
}
void User:: Fetch_Record()
{
    print_msg("The user name is: ");
    print_msg(name);
    print_msg("\nThe user age is: ", age);
}
void User:: Qiut()
{
    print_msg("Thank You :)\n");
    condition = FALSE;
}
