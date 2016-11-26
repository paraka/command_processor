#ifndef _COMMAND_PROCESSOR_H_
#define _COMMAND_PROCESSOR_H_

#include <functional>
#include <map>
#include "Command.h"
#include "CommandImpl.h"

class CommandProcessor
{
    using callback_t = std::function<void(const char *data)>;

public:
    CommandProcessor()
    {
        init();
    }

    ~CommandProcessor() = default;

    void process(Command cmd, const char *data)
    {
        const callback_t& fun = map_cmd_fn_[cmd];
        fun(data);
    }

private:
    void init()
    {
        map_cmd_fn_[Command::COMMAND_A] = std::bind(&CommandImpl::process_command_a, cmd_impl_, std::placeholders::_1);
        map_cmd_fn_[Command::COMMAND_B] = std::bind(&CommandImpl::process_command_b, cmd_impl_, std::placeholders::_1);
    }

    CommandImpl cmd_impl_;
    std::map<Command, callback_t> map_cmd_fn_;
};

#endif // _COMMAND_PROCESSOR_H_
