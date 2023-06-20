#include "coordinator.hpp"

// Function to add test_container elements to tree.
void process_test_container(Coordinator::shrptr_suite node);

// Temporary function to process string into vector. Delete when done.
std::deque<std::string> process_path(std::string& path);

//void Coordinator::fill_tree(std::string_view name, Suites::suites_ctn& suites, Node<Suites>::shr_nodeptr node)
void Coordinator::fill_tree(std::string_view name, Suites::suites_ctn& suites, Suites::shr_suite node)
{
std::cout<<"Path: "<<name <<'\n';
    std::string path{std::string(name)};
    auto tokens{process_path(path)};
std::cout<< "first token: " <<tokens.front()<<'\n';

    if(tokens.size()){
        tokens.pop_front();
        auto searched_node = std::find_if(node->children.begin() , node->children.end(), [&tokens](auto& node_){return tokens.front() == node_->name;});

        if(searched_node != node->children.end())
        {
            path = std::string();
std::cout<< "first token after pop: " <<tokens.front()<<'\n';
            if(!tokens.empty())
            {
                for(auto& token: tokens)
                {
                    // If not the last token, add '.' to word, else just the token.
                    (&token != &tokens.back())? path += token + "." : path += token;
                }
            }
            else
            {
                path = node->name;
            }
std::cout<<path<<'\n';
            std::cout<<node->name <<" was already in the tree\n";
//            if(!searched_node->get()->suite->suites_container.empty())
//            {
                Coordinator::fill_tree(path, *searched_node);
//                Coordinator::fill_tree(path, suites, *searched_node);
//            }

        }
        else if(searched_node == node->children.end())
        {
            if(!suites.empty())
            {
                for(auto& suite: suites)
                {
                    // Add suite to current node.
                    Coordinator::add_node(suite, node);

                    // Check for tests in test_container.
                    if(!suites.front()->tests_container.empty())
                    {
                        Coordinator::fill_tree(suites.front()->tests_container, node);
                    }
                    Coordinator::fill_tree(path + "." + std::string(suite->name), suite->suites_container, node);
                }
            }
        }

    }
    else
    {

    }

}

void Coordinator::fill_tree(std::string_view name, Node<Suites>::shr_nodeptr node)
{

//    auto test {std::find_if(suites_tests.main_suite.suites_container.begin(), suites_tests.main_suite.suites_container.end(),
        //[](auto& hello){return hello->name == "Suite_First";})};
//    if(test != suites_tests.main_suite.suites_container.end()){std::cout<<"Hello matched\n";}

    std::cout<<"Running fill_tree suites\n";
    for(auto& suite: node->suite->suites_container)
    {
        Coordinator::add_node(suite, node);
        if(!node->suite->suites_container.empty())
        {
            Coordinator::fill_tree(name, suite);
        }
    }
}

//void Coordinator::fill_tree(std::string_view name, Suites::tests_ctn& tests,  Node<Suites>::shr_nodeptr node)
void Coordinator::fill_tree(Suites::tests_ctn& tests,  Node<Suites>::shr_nodeptr node)
{

    for(auto& test: tests){
std::cout<<"Running fill_tree tests\n";
//        node->children.emplace_back(std::make_shared<Node<Suites>>(node->name));
//        node->children.back()->name = node->name;
//        node->children.back()->func = node->func;
    }

}

std::deque<std::string> process_path(std::string& path)
{
    std::deque<std::string>     vec;
    std::string                 word;

    std::for_each(path.begin(), path.end(), [&vec, &word](char ch)
    {
        if(ch != '.') word.push_back(ch);
        else{
            vec.emplace_back(word);
            word = std::string();
        }
     });

    vec.emplace_back(word);

    return vec;
}

//    for(auto& token: tokens)
//    {
//        auto searched_node = std::find_if(node->children.begin(), node->children.end(), [&token](auto& node_){return token == node_->name;});

//        //Check if node is already in the tree. If not, add it.
//        if(searched_node == node->children.end())
//        {
//            Coordinator::add_node(node);
//            for(auto& suite: suites)
//            {
//                std::cout<<"newly added node name: "<< node->name<<'\n';
//                Coordinator::fill_tree(token + "." + std::string(suite->name), suite->suites_container, node);
//            }

//        }
//        else
//        {
//            node = *searched_node;
//            std::cout<<"Node changed to: "<< node->name<<'\n';
//            for(auto& suite: suites)
//            {
//                Coordinator::fill_tree(token + "." + std::string(suite->name), suite->suites_container, node);
//            }
//        }
//    }
