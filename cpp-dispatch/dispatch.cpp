#include <map>
#include <string>
#include <functional>
#include <exception>
#include <iostream>

void handle_action_1()
{
    std::cout << "Action 1" << std::endl;
}

void handle_action_2()
{
    std::cout << "Action 2" << std::endl;
}

void handle_error()
{
    std::cout << "Handled the error" << std::endl;
}

void dispatch(const std::string &action)
{
    const auto dispatch_map =
        std::map<std::string, std::function<void()>>{
            {"action1", &handle_action_1},
            {"action2", &handle_action_2}};
    try {
        dispatch_map.at(action)();
    }
    catch (std::out_of_range) {
        handle_error();
    }
}

int main() {
    dispatch("action1");
    dispatch("action2");
    dispatch("action3");
}
