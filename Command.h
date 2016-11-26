#ifndef _COMMAND_H_
#define _COMMAND_H_ 

enum class Command
{
    COMMAND_A = 0x01,
    COMMAND_B = 0x02,
    INVALID = 0xFF,
};

namespace Utils
{

template <typename E>
using enable_enum_t = typename std::enable_if<std::is_enum<E>::value,
                                                typename std::underlying_type<E>::type>::type;

template <typename E>
constexpr inline enable_enum_t<E> underlying_value(E e) noexcept
{
    return static_cast<typename std::underlying_type<E>::type>(e);
}

template <typename E , typename T>
constexpr inline typename std::enable_if<std::is_enum<E>::value &&
                                             std::is_integral<T>::value, E>::type to_enum(T value) noexcept
{
    return static_cast<E>(value);
}

} // namespace Utils

#endif // _COMMAND_H_
