#include "handy.h"

int main() {
    HandyArray <int> myarray("[1, 2, 3]");

    std::vector <std::string> nums = myarray.Parse();

    for (const auto& i : nums) {
        std::cout << i << std::endl;
    }
}