#include "controllonumber.h"


bool is_number(const std::string &s) const{
    char* end = 0;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && val != DBL_MAX;
}
