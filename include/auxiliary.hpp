#ifndef AUXILIARY_HPP_
#define AUXILIARY_HPP_
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <fstream>

int check_input(const int& argc);
std::vector<std::string> split(const std::string& line, const char split_symbol);
void print_info(const std::vector<std::string>& elems, std::map<std::string, std::string>& gender);
std::map<std::string, std::string> get_gender_map(const std::string& gender_filename);
void show_artist_info(const std::string& artist_filename, const std::string& artist_name, std::map<std::string, std::string>& gender_map);
std::string get_artist_name(const int& argc, char *argv[]);
#endif  // INCLUDE_AUXILIARY_HPP_
