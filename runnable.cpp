#include "runnable.hpp"

Runnable::Runnable(std::string_view sent_name, func sent_test): name{sent_name}, test{sent_test}{}
