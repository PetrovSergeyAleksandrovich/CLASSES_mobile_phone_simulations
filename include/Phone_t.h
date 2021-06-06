#include "Abonent_t.h"
#include <vector>
#include <string>

class Phone_t
{
private:
    std::vector<Abonent_t> list = {{"petrov", "1587465987", "7"},
                                   {"ivanov", "1563248905", "7"},
                                   {"sidorov", "1541058917", "7"}};
public:
    void add()
    {
        while(true)
        {
            Abonent_t* abonent = new Abonent_t;
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

    void call()
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

    void sms()
    {
        std::string user_input;
        std::cout << "YOUR CONTACTS:\n";
        for(int i = 0; i < list.size(); i++)
        {
            std::cout << list[i].name <<
                      " +" << list[i].region_code <<
                      "<" << list[i].number << ">\n";
        }
        std::cout << "WHOM DO YOU WANT TO SEND SMS?: ";
        std::cin >> user_input;
        for(int i = 0; i < list.size(); i++)
        {
            if(user_input == list[i].name || user_input == list[i].number)
            {
                std::string message;
                std::cout << "type your message: ";
                std::getline(std::cin, message); // DOESN'T WORK NOW
                std::cout << "\nYOUR sms <" << message << "> TO: " << list[i].name <<
                          " +" << list[i].region_code <<
                          "<" << list[i].number << "> was sent\n";
                return;
            }
        }
        std::cout << "NO SUCH CONTACT or NUMBER" << std::endl;
    }

};