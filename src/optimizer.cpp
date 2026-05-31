#include "optimizer.h"
#include <algorithm>
#include <sstream>

std::string Optimizer::optimize(const std::string& script) {
    std::string result = removeComments(script);
    auto redundant = findRedundantCalls(result);

    for (const auto& call : redundant) {
        size_t pos = result.find(call);
        if (pos != std::string::npos) {
            result.erase(pos, call.length());
        }
    }

    return result;
}

std::string Optimizer::removeComments(const std::string& script) {
    std::string result;
    std::istringstream iss(script);
    std::string line;

    while (std::getline(iss, line)) {
        size_t commentPos = line.find("--");
        if (commentPos != std::string::npos) {
            line = line.substr(0, commentPos);
        }
        result += line + "\n";
    }

    return result;
}

std::vector<std::string> Optimizer::findRedundantCalls(const std::string& script) {
    std::vector<std::string> redundant;
    std::istringstream iss(script);
    std::string line;
    std::vector<std::string> lines;

    while (std::getline(iss, line)) {
        lines.push_back(line);
    }

    for (size_t i = 0; i < lines.size(); ++i) {
        for (size_t j = i + 1; j < lines.size(); ++j) {
            if (lines[i] == lines[j]) {
                redundant.push_back(lines[j]);
            }
        }
    }

    return redundant;
}