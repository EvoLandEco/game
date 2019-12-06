#ifndef ENVIRONMENT_TYPE_H
#define ENVIRONMENT_TYPE_H

#include <string>

enum class environment_type
{
  empty,
  quiet,
  random,
  attractive,
  repellent,
  wormhole
};

void test_environment_type();
inline const std::string to_str_env_type(environment_type this_env_type)
{
    switch (this_env_type)
    {
        case environment_type::empty:   return "empty";
        case environment_type::quiet:   return "quiet";
        case environment_type::random:   return "random";
        case environment_type::attractive:   return "attractive";
        case environment_type::repellent:   return "repellent";
        case environment_type::wormhole:   return "wormhole";
    }
    return "[Unknown environment_type]";
}

#endif // ENVIRONMENT_H
