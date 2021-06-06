#include "Abonent_t.h"
#include <string>
#include <iostream>
#include <vector>

class Phone_t
{
private:
    std::vector<Abonent_t> list = {{"petrov",  "1587465987", "7"},
                                   {"ivanov",  "1563248905", "7"},
                                   {"sidorov", "1541058917", "7"}};
public:
    void add();
    void call();
    void sms();
    std::string input_sms_text();
    void emptyFunction();
};

