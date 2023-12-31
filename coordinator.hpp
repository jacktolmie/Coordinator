#ifndef COORDINATOR_HPP
#define COORDINATOR_HPP

#include "node.hpp"
#include "test_list.hpp"
#include <deque>

class Coordinator
{
public:

    using shrptr_suite = std::shared_ptr<Suites>;
    using shrptr_test  = std::shared_ptr<Tests>;

    Coordinator();
    virtual ~Coordinator() = default;

    /* Root node for the tree. */
    Node<Suites>::shr_nodeptr   root{std::make_shared<Suites>("root")};

    /* Add node to the tree. */
//    void add_node(std::shared_ptr<Suites>, Node<Suites>::shr_nodeptr);
    void add_node(shrptr_suite&, Node<Suites>::shr_nodeptr);
    void add_node(std::shared_ptr<Tests> test, Node<Suites>::shr_nodeptr node);

    /* Program to find if a node is already in the tree. */
    Node<Suites>::shr_nodeptr   find_node(std::string_view, Node<Suites>::shr_nodeptr);
    Node<Suites>::shr_nodeptr   find_node(std::deque<std::string>&, Node<Suites>::shr_nodeptr);
    shrptr_test                 find_node(std::string_view, shrptr_test);

    /* Program to initially fill the tree with the Tests
     * or Suites added by the programmer. */
    void fill_tree(std::string_view, Suites::suites_ctn&, Suites::shr_suite);
//    void fill_tree(std::string_view, Suites::suites_ctn&, Node<Suites>::shr_nodeptr);
    void fill_tree(std::string_view, Node<Suites>::shr_nodeptr);
    void fill_tree(Suites::tests_ctn&,  Node<Suites>::shr_nodeptr);

    /* Temporary(?) program to print the tree to check if
     * tree was filled successfully. */
    void print_tree(Node<Suites>);

    /* Program to process tests in Suites container. */
    void process_test_container(Coordinator::shrptr_suite);

    /* Program to split the path sent into tokens. */
//    std::deque<std::string> process_path(std::string&);
};

#endif // COORDINATOR_HPP
