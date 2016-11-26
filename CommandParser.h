#ifndef _COMMAND_PARSER_H_
#define _COMMAND_PARSER_H_

#include "Command.h"

class CommandParser
{
public:
    static Command read_command_from_data(const char *data)
    {
        uint8_t command;
        memcpy(&command, data, 1);
        return Utils::to_enum<Command>(command);
    }
};

#endif // _COMMAND_PARSER_H_
