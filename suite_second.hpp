#ifndef SUITE_SECOND_HPP
#define SUITE_SECOND_HPP

#include "suites.hpp"
#include "suite1.hpp"
#include "suite2.hpp"

class Suite_Second: public Suites
{
public:
    Suite_Second();
    virtual ~Suite_Second() = default;

    std::string name{"Suite_Second"};
    Suite1 suite1;
    Suite2 suite2;
};

#endif // SUITE_SECOND_HPP
