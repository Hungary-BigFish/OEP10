#include "center.h"

using namespace std;

// ÚJ

Bank* Center::bankSearch(const std::string& bankCode) const
{
    Bank* bank;
    bool l = false;
    for(Bank* b : _banks){
        l = (b->_code == bankCode);
        bank = b;
        if( l ) break;
    }
    if(!l) throw CARD_ERROR;
    return bank;
}

