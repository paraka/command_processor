#include <iostream>
#include "CommandParser.h"
#include "CommandProcessor.h"

int main(int argc, char **argv)
{
    CommandProcessor cmd_processor;

    char data[3] = {0x01, 0x03, 0x04 };

    cmd_processor.process(CommandParser::read_command_from_data(data), data);

    data[0] = 0x02;

    cmd_processor.process(CommandParser::read_command_from_data(data), data);

    return 0;
}
