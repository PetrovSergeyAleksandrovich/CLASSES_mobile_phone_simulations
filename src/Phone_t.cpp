#include "Phone_t.h"

void Phone_t::emptyFunction()
{
    std::cout << "from Phone.h -> new object generated" << std::endl;
}

std::string Phone_t::input_sms_text()
{
    //below are different types of possible input for miltiply words in the string
    std::string message;
    std::cout << "type your message: ";
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //this helps
    //std::cin >> std::ws; //this helps
    std::getline(std::cin >> std::ws, message); // this also helps
    //std::getline(std::cin, message); // main message input
    return message;
}

void Phone_t::add()
{
    while(true)
    {
        Abonent_t* abonent = new Abonent_t;
        abonent->emptyFunction();
        std::string user_input;

        std::cout << "type name: ";
        std::cin >> user_input;
        abonent->name = user_input;
        std::cout << "type number (10 digits): ";
        std::cin >> user_input;
        abonent->number = user_input;
        std::cout << "do you want change region +7? y/n: ";
        std::cin >> user_input;
        if(user_input == "y")
        {
            std::cout << "type number region code: ";
            std::cin >> user_input;
            abonent->region_code = user_input;
        }
        std::cout << "check info: " << abonent->name <<
                  " +" << abonent->region_code <<
                  "<" << abonent->number <<">" << std::endl;

        std::cout << "confirm? y/n: ";
        std::cin >> user_input;

        if(user_input == "y")
        {
            list.push_back(*abonent);
            delete abonent;
            return;
        }
        else{
            std::cout << "type 'exit' to exit or any symbol to continue: ";
            std::cin >> user_input;
            if(user_input == "exit")
            {
                delete abonent;
                return;
            }
            else continue;
        }
    }
}

void Phone_t::call()
{
    std::string user_input;
    std::cout << "YOUR CONTACTS:\n";
    for(int i = 0; i < list.size(); i++)
    {
        std::cout << list[i].name <<
                  " +" << list[i].region_code <<
                  "<" << list[i].number << ">\n";
    }
    std::cout << "WHOM DO YOU WANT TO CALL?: ";
    std::cin >> user_input;
    for(int i = 0; i < list.size(); i++)
    {
        if(user_input == list[i].name || user_input == list[i].number)
        {
            std::cout << "YOUR CALL TO: "   << list[i].name <<
                      " +" << list[i].region_code <<
                      "<" << list[i].number << ">\n";
            return;
        }
    }
    std::cout << "NO SUCH CONTACT or NUMBER" << std::endl;
}

void Phone_t::sms()
{
    std::string user_input;
    std::cout << "YOUR CONTACTS:\n";
    for(int i = 0; i < list.size(); i++)
    {
        std::cout << list[i].name <<
                  " +" << list[i].region_code <<
                  "<" << list[i].number << ">\n";
    }
    std::cout << "\nWHOM DO YOU WANT TO SEND SMS?: ";
    std::cin >> user_input;
    for(int i = 0; i < list.size(); i++)
    {
        if(user_input == list[i].name || user_input == list[i].number)
        {
            std::string message = input_sms_text();
            std::cout << "\nYOUR SMS \n<" << message << ">\nTO: " << list[i].name <<
                      " +" << list[i].region_code <<
                      "<" << list[i].number << "> was sent\n\n";
            return;
        }
    }
    std::cout << "NO SUCH CONTACT or NUMBER" << std::endl;
}
