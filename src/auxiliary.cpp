#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <fstream>

std::vector<std::string> split(std::string line, char split_symbol) {
    std::vector<std::string> elems;
    std::stringstream stringstream;
    std::string item;
    stringstream.str(line);
    while (std::getline(stringstream, item, split_symbol)) {
        elems.push_back(item);
    }
    return elems;
}

int check_input(int argc) {
    if (argc < 4) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }
    return 0;
}

void print_info(std::vector<std::string> elems, std::map<std::string, std::string> gender) {
    std::string info = "Artist Name: " + elems[2];

    if (elems[4] ==" " || elems[4] == "\\N") info += "\nYear of birth: None";
    else
        info += "\nYear of birth: " + elems[4];

    if (elems[5] == "" || elems[5] == "\\N") info += "\nMonth of birth: None";
    else
        info += "\nMonth of birth: " + elems[5];

    if (elems[6] == "" || elems[6] == "\\N") info += "\nDay of birth: None";
    else
        info += "\nDay of birth: " + elems[6];

    if (elems[12] == "" || elems[12] == "\\N") info += "\nGender: None";
    else
        info += "\nGender: " + gender[elems[12]];

    std::cout << info << std::endl;
}

std::string get_artist_name(int argc, char *argv[]) {
    std::string artist_name = argv[3];
    if (argc > 3) {
        for (int i=4; i < argc; i++) {
            artist_name += " ";
            artist_name += argv[i];
        }
    }
    return artist_name;
}

std::map<std::string, std::string> get_gender_map(std::string gender_filename) {
    std::map<std::string, std::string> gender;
    std::string line;
    std::ifstream gender_instream(gender_filename);
    if (gender_instream.is_open()) {
        while (getline(gender_instream, line)) {
            std::vector<std::string> elems = split(line, '\t');
            gender[elems[0]] = elems[1];
        }
    }
    gender_instream.close();
    return gender;
}

void show_artist_info(std::string artist_filename, std::string artist_name, std::map<std::string, std::string> gender_map) {
    std::string line;
    std::ifstream artist_instream(artist_filename);
    if (artist_instream.is_open()) {
        while (getline(artist_instream, line)) {
            std::vector<std::string> elems = split(line, '\t');
            if (elems[2] == artist_name) {
                print_info(elems, gender_map);
                break;
            }
        }
    }
    artist_instream.close();
}
