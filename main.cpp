#include <iostream>
#include <map>

#include "./src/0001.cpp"
#include "./src/0002.cpp"
#include "./src/0003.cpp"
#include "./src/0004.cpp"
#include "./src/0005.cpp"
#include "./src/0006.cpp"
#include "./src/0007.cpp"
#include "./src/0008.cpp"
#include "./src/0009.cpp"
#include "./src/0010.cpp"
#include "./src/0011.cpp"
#include "./src/0012.cpp"
#include "./src/0013.cpp"
#include "./src/0014.cpp"
#include "./src/0015.cpp"
#include "./src/0016.cpp"
#include "./src/0017.cpp"
#include "./src/0018.cpp"

#define PROBLEM(NS) \
    { NS::key, NS::main }

/**
 * @brief
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const *argv[]) {
    std::map<string, int (*)()> leetcodes{
        PROBLEM(leetcode_0001),
        PROBLEM(leetcode_0002),
        PROBLEM(leetcode_0003),
        PROBLEM(leetcode_0004),
        PROBLEM(leetcode_0005),
        PROBLEM(leetcode_0006),
        PROBLEM(leetcode_0007),
        PROBLEM(leetcode_0008),
        PROBLEM(leetcode_0009),
        PROBLEM(leetcode_0010),
        PROBLEM(leetcode_0011),
        PROBLEM(leetcode_0012),
        PROBLEM(leetcode_0013),
        PROBLEM(leetcode_0014),
        PROBLEM(leetcode_0015),
        PROBLEM(leetcode_0016),
        PROBLEM(leetcode_0017),
        PROBLEM(leetcode_0018),
    };

    std::string lckey = "0018";
    if (argc > 1) {
        std::string input = std::string(argv[1]);
        if (leetcodes.count(input) > 0) {
            lckey = input;
        } else {
            std::cout << "invalid input:" << input << ", running " << lckey << " instead" << std::endl;
        }
    }

    std::cout << "running:" << lckey << std::endl;
    leetcodes[lckey]();
    return 0;
}