// first argument - path to artist file
// second argument - path to gender file, third and further - artist name.

#include <map>
#include <string>
#include "../include/auxiliary.hpp"


int main(int argc, char *argv[]) {
    if (!check_input(argc)) return 1;
    std::string artist_name = get_artist_name(argc, argv);
    std::map<std::string, std::string> gender_map = get_gender_map(argv[2]);
    show_artist_info(argv[1], artist_name, gender_map);
    return 0;
}
