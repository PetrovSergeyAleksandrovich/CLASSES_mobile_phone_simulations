#include <iostream>
#include "Phone_t.h"

int main()
{
    do
    {
        Phone_t* phone = new Phone_t;
        std::string command = "none";

        std::cout << "type the command add/sms/call/exit : ";
        std::cin >> command;
        if(command == "add") phone->add();
        if(command == "call") phone->call();
        if(command == "sms") phone->sms();
        if(command == "exit")
        {
            delete phone;
            break;
        }
    }
    while(true);

    return 0;
}
