#include "tests.hpp"

Tests::Tests(std::string_view sent_name, Runnable::func sent_func)
: Node{sent_name}, name{sent_name}, test{sent_func}
{}
