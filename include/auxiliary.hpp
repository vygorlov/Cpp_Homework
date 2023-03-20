#ifndef AUXILIARY_HPP_
#define AUXILIARY_HPP_
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <fstream>

int check_input(int argc);
std::vector<std::string> split(std::string, char);
void print_info(std::vector<std::string>, std::map<std::string, std::string>);
std::map<std::string, std::string> get_gender_map(std::string);
void show_artist_info(std::string, std::string, std::map<std::string, std::string>);
std::string get_artist_name(int, char*[]);
#endif  // INCLUDE_AUXILIARY_HPP_
