//first argument - path to artist file, second argument - path to gender file, third and further - artist name.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

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

void print_info(std::vector<std::string> elems, std::map<std::string, std::string> gender){
    std::cout << "Artist Name: " << elems[2] << std::endl;

    if (elems[4] ==" " || elems[4] == "\\N") std::cout << "Year of birth: None" << std::endl;
    else std::cout << "Year of birth: " << elems[4] << std::endl;

    if (elems[5] == "" || elems[5] == "\\N") std::cout << "Month of birth: None" << std::endl;
    else std::cout << "Month of birth: " << elems[5] << std::endl;

    if (elems[6] == "" || elems[6] == "\\N") std::cout << "Day of birth: None" << std::endl;
    else std::cout << "Day of birth: " << elems[6] << std::endl;

    if (elems[12] == "" || elems[12] == "\\N") std::cout << "Gender: None" << std::endl;
    else std::cout << "Gender: " << gender[elems[12]] << std::endl;
}

std::string get_artist_name(int argc, char *argv[]){
    std::string artist_name = argv[3];
    if (argc>3) for (int i=4; i<argc; i++){
        artist_name = artist_name + " " + argv[i];
    }
    return artist_name;
}

std::map<std::string, std::string> get_gender_map(std::string gender_filename){
    std::map<std::string, std::string> gender;
    std::string line;
    std::ifstream gender_instream(gender_filename);
    if (gender_instream.is_open())
    {
        while (getline(gender_instream, line))
        {
            std::vector<std::string> elems = split(line, '\t');
            gender[elems[0]] = elems[1];
        }
    }
    gender_instream.close();
    return gender;
}

void show_artist_info(std::string artist_filename, std::string artist_name, std::map<std::string, std::string> gender_map){
    std::string line;
    std::ifstream artist_instream(artist_filename);
    if (artist_instream.is_open())
    {
        while (getline(artist_instream, line))
        {
            std::vector<std::string> elems = split(line, '\t');
            if (elems[2]==artist_name) {
                print_info(elems, gender_map);
                break;
            }
        }
    }
    artist_instream.close();
}

int main(int argc, char *argv[])
{
    std::string artist_name = get_artist_name(argc, argv);
    std::map<std::string, std::string> gender_map = get_gender_map(argv[2]);
    show_artist_info(argv[1], artist_name, gender_map);
    return 0;
}