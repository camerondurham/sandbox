#include<memory>
#include<string>
#include<iostream>
int main()
{

    auto num = std::make_unique<int>(42);
    std::unique_ptr<int> thief;
    // thief = num; // error: use of deleted function

    auto owner = std::make_unique<std::string>("Foo");

    std::unique_ptr<std::string> newOwner;
    std::unique_ptr<std::string> newOwner2(std::move(owner));

    // newOwner = owner; // error!
    /* auto origOwner = std::make_unique<std::string>("A Foo"); */
    /* std::unique_ptr<std::string> newOwner((origOwner)); */
    std::shared_ptr<std::string> shrd = std::make_shared<std::string>("hello");

    std::cout << shrd.use_count() << std::endl;

    std::shared_ptr<std::string> anotherOne(shrd);

    std::cout << shrd.use_count() << std::endl;
    std::cout << anotherOne.use_count() << std::endl;
}
