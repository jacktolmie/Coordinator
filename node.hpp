#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "runnable.hpp"


/* This is a CTRP (Curiously recurring template pattern)
 * class. Making it to have access to both Tests and
 * Suites information even though it is just a Node class. */
template<class Derived>
class Node
{
public:
    using shr_nodeptr = std::shared_ptr<Node<Derived>>;

    Node(std::string_view sent_name): name{sent_name}{};//{std::cout<<sent_name <<" node was added.\n";}
    virtual ~Node() = default;

    std::string_view            name;
    std::vector<shr_nodeptr>    children;
    std::shared_ptr<Derived>    suite;
    std::function<void(void)>   func{[] {return "Empty function\n";}};
};

#endif // NODE_HPP
