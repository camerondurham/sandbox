#include<memory>
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



}
