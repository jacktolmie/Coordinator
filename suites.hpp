#ifndef SUITES_HPP
#define SUITES_HPP

#include "node.hpp"
#include "tests.hpp"

class Suites: public Node<Suites>
{
private:

public:
    using shr_suite     = std::shared_ptr<Suites>;
    using suites_ctn    = std::vector<shr_suite>;
    using tests_ctn     = std::vector<Tests::shr_test>;

    Suites(std::string_view);
    virtual ~Suites() = default;

    std::string_view    name;
    suites_ctn          suites_container;
    tests_ctn           tests_container;
};

#endif // SUITES_HPP
