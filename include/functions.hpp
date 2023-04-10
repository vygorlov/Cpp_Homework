#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

std::vector<std::string>* split(const std::string& line, char split_symbol);
bool output(std::vector<std::string>* arguments);

#endif // INCLUDE_FUNCTIONS_HPP_