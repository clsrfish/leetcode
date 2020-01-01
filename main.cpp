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
using namespace std;

int main(int argc, char const *argv[])
{

    map<string, int (*)()> leetcodes{
        {leetcode_0001::key, leetcode_0001::main},
        {leetcode_0002::key, leetcode_0002::main},
        {leetcode_0003::key, leetcode_0003::main},
        {leetcode_0004::key, leetcode_0004::main},
        {leetcode_0005::key, leetcode_0005::main},
        {leetcode_0006::key, leetcode_0006::main},
        {leetcode_0007::key, leetcode_0007::main},
        {leetcode_0008::key, leetcode_0008::main},
        {leetcode_0009::key, leetcode_0009::main},
        {leetcode_0010::key, leetcode_0010::main},
        {leetcode_0011::key, leetcode_0011::main},
        {leetcode_0012::key, leetcode_0012::main},
        {leetcode_0013::key, leetcode_0013::main},
        {leetcode_0014::key, leetcode_0014::main},
        {leetcode_0015::key, leetcode_0015::main},
    };

    string lckey = "0015";
    if (argc > 1)
    {
        string input = string(argv[1]);
        if (leetcodes.count(input) > 0)
        {
            lckey = input;
        }
        else
        {
            std::cout << "invalid input:" << input << ", running " << lckey << " instead" << std::endl;
        }
    }

    std::cout << "running:" << lckey << std::endl;
    leetcodes[lckey]();
    return 0;
}