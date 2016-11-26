#include <gtest/gtest.h>
#include <cstdint>
#include "../CommandParser.h"

struct CommandCase;

class CommandParserTest : public ::testing::TestWithParam<CommandCase> {};

struct CommandCase
{
    uint8_t data;
    uint8_t expected;

    CommandCase(uint8_t data, uint8_t expected) : data(data), expected(expected) {}
};

TEST_P(CommandParserTest, parser_parse_commands_ok_for_input)
{
    CommandCase c = GetParam();
    uint8_t data[3];
    data[0] = c.data;
    data[1] = 0x00;
    data[2] = 0x00;
    Command ret = CommandParser::read_command_from_data((char *)data);
    ASSERT_EQ(Utils::underlying_value(ret), c.expected);
}

CommandCase commands[] = {
    CommandCase(0x01, 0x01),
    CommandCase(0x82, 0x82),
};

INSTANTIATE_TEST_CASE_P(CommandParser, CommandParserTest, ::testing::ValuesIn(commands));

