#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "../include/functions.hpp"

int main(int argc, char *argv[])
{
    std::vector<std::string>* arguments = split(argv[1], ' ');
    output(arguments);
    delete arguments;
    return 0;
}
