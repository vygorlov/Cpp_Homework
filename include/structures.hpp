#ifndef STRUCTURES_HPP_
#define STRUCTURES_HPP_
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

struct IOperation{
    virtual void ProcessLine(const std::string& str) = 0;
    virtual void HandleEndOfInput() = 0;
    virtual void SetNextOperation(IOperation& operation) = 0;
};
struct echo_operation: IOperation  {
 public:
    echo_operation();

    echo_operation(const std::string& str);

    void ProcessLine(const std::string& str);

    void HandleEndOfInput();

    void SetNextOperation(IOperation& operation);

 private:
    std::string data;
};
struct cat_operation: IOperation  {
 public:
    cat_operation();

    cat_operation(const std::string& str);

    void ProcessLine(const std::string& str);

    void HandleEndOfInput();

    void SetNextOperation(IOperation& operation);

 private:
    std::string data;
};
struct tail_operation: IOperation  {
 public:
    tail_operation();

    tail_operation(int N);

    void ProcessLine(const std::string& str);

    void HandleEndOfInput();

    void SetNextOperation(IOperation& operation);
    
 private:
    int amount;
    std::string data;
};

#endif // INCLUDE_STRUCTURES_HPP_