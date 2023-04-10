#include "../include/structures.hpp"

echo_operation::echo_operation() {}

echo_operation::echo_operation(const std::string& str) {
    data = str;
}

void echo_operation::ProcessLine(const std::string& str) {}

void echo_operation::HandleEndOfInput() {
    std::cout << data << std::endl;
}

void echo_operation::SetNextOperation(IOperation& operation) {
    operation.ProcessLine(data);
}



cat_operation::cat_operation() {}

cat_operation::cat_operation(const std::string& filename) {
    std::string file_data;
    std::ifstream file_instream(filename);
    if (file_instream.is_open()) {
        std::string line;
        while (getline(file_instream, line)) {
            data += line+"\n";
        }
        data.pop_back();
        file_instream.close();
    }
}

void cat_operation::ProcessLine(const std::string& str) {
    data = str+"\n"+data;
}

void cat_operation::HandleEndOfInput()  {
    std::cout << data << std::endl;
}

void cat_operation::SetNextOperation(IOperation& operation)  {
    operation.ProcessLine(data);
}


tail_operation::tail_operation() {}

tail_operation::tail_operation(int N) {
    amount = N;
}
void tail_operation::ProcessLine(const std::string& str)  {
    std::vector<std::string> elems;
    std::stringstream stringstream;
    std::string item;
    stringstream.str(str);
    while (std::getline(stringstream, item, '\n')) {
        elems.push_back(item);
    }
    int max_lenth = amount < elems.size() ? amount : elems.size();

    for (int i = max_lenth; i>=0; i--) {
        if (i==1) {
            data+=elems[elems.size()-i];
            break;
        }
        data+=elems[elems.size()-i]+"\n";
    }
}

void tail_operation::HandleEndOfInput()  {
    std::cout << data << std::endl;
}

void tail_operation::SetNextOperation(IOperation& operation)  {
    operation.ProcessLine(data);
}
