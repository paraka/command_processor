#ifndef _COMMAND_IMPL_H_
#define _COMMAND_IMPL_H_

#include "ProtocolImpl.h"

using namespace Protocol;

class CommandImpl
{
public:
    void process_command_a(const char *data)
    {
        std::cout << std::string(data).c_str() << std::endl;
        protocol.read_foo();
    }

    void process_command_b(const char *data)
    {
        std::cout << std::string(data).c_str() << std::endl;
        protocol.read_bar();
    }

private:
    ProtocolImpl protocol;
};

#endif //_COMMAND_IMPL_H_
