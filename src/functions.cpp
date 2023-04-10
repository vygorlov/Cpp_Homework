#include "../include/functions.hpp"
#include "../include/structures.hpp"

std::vector<std::string>* split(const std::string& line, char split_symbol) {
    std::vector<std::string>* elems = new std::vector<std::string>;
    std::stringstream stringstream;
    std::string item;
    stringstream.str(line);
    while (std::getline(stringstream, item, split_symbol)) {
        if (item == "|") continue;
        elems->push_back(item);
    }
    return elems;
}

bool output(std::vector<std::string>* arguments) {
    IOperation* previous = nullptr;
    for (std::vector<std::string>::iterator it = arguments->begin() ; it!=arguments->end() ; it++) {
        if (*it == "echo") {
            echo_operation* echo = new echo_operation(*(it+1));
            if (previous!=nullptr) previous->SetNextOperation(*echo);
            if (it+2 == arguments->end()) {
                echo->HandleEndOfInput();
                delete previous;
                delete echo;
                break;
            }
            if (previous!=nullptr) delete previous;
            previous = echo;
        }

        if (*it == "cat") {
            cat_operation* cat = new cat_operation(*(it+1));
            if (previous!=nullptr) previous->SetNextOperation(*cat);
            if (it+2 == arguments->end()) {
                cat->HandleEndOfInput();
                delete previous;
                delete cat;
                break;
            }
            if (previous!=nullptr) delete previous;
            previous = cat;
        }

        if (*it == "tail") {
            tail_operation* tail = new tail_operation(stoi(*(it+1)));
            if (previous!=nullptr) previous->SetNextOperation(*tail);
            if (it+2 == arguments->end()) {
                tail->HandleEndOfInput();
                delete previous;
                delete tail;
                break;
            }
            if (previous!=nullptr) delete previous;
            previous = tail;
        }
    }
    return true;
}