#ifndef OPTIMIZER_H
#define OPTIMIZER_H

#include <string>
#include <vector>

class Optimizer {
public:
    std::string optimize(const std::string& script);
    std::vector<std::string> findRedundantCalls(const std::string& script);
private:
    std::string removeComments(const std::string& script);
};

#endif