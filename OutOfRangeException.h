#include <stdexcept>
#ifndef OutOfRangeException_H
#define OutOfRangeException_H

using namespace std;

class OutOfRangeException:public runtime_error
{
public:

    OutOfRangeException(string message):runtime_error(message){}
};
#endif
