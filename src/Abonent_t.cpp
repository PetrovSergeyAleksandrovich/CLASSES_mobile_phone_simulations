#include "Abonent_t.h"

void Abonent_t::emptyFunction()
{
    Abonent_t* tmp_abonent = new Abonent_t;
    std::cout << "from Abonent.h -> new default object generated: " << tmp_abonent->name << " +"
              << tmp_abonent->region_code << "<" << tmp_abonent->number  << ">" << std::endl;
    delete tmp_abonent;
}