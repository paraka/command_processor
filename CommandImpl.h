#ifndef _COMMAND_IMPL_H_
#define _COMMAND_IMPL_H_

#include "ProtocolImpl.h"

using namespace Protocol;

class CommandImpl
{
public:
    void process_command_a(const char *data)
    {
        // Do whatever with rest of data and use protocol
        protocol.read_foo();
    }

    void process_command_b(const char *data)
    {
        // Do whatever with rest of data and use protocol
        protocol.read_bar();
    }

private:
    ProtocolImpl protocol;
};

#endif //_COMMAND_IMPL_H_
