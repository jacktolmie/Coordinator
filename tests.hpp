#ifndef TESTS_HPP
#define TESTS_HPP
#include "node.hpp"
#include "runnable.hpp"

class Tests: private Node<Tests>
{
public:
    using shr_test = std::shared_ptr<Tests>;

    Tests(std::string_view, Runnable::func);
    virtual  ~Tests() = default;

    std::string_view    name;
    Runnable::func      test;
};

#endif // TESTS_HPP
