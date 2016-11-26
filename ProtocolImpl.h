#ifndef _PROTOCOLIMPL_H_
#define _PROTOCOLIMPL_H_

#include "Protocol.h"

namespace Protocol
{
    namespace V1
    {
        class ProtocolImpl
        {
            public:
                ProtocolImpl() = default;

                ~ProtocolImpl() = default;

                void read_foo()
                {
                    std::cout << "read_foo()" << std::endl;
                }

                void read_bar()
                {
                    std::cout << "read_bar()" << std::endl;
                }
        };
    }
}

#endif // _PROTOCOLIMPL_H_
