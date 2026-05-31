#ifndef ROBLOX_SCRIPT_H
#define ROBLOX_SCRIPT_H

#include <string>

class RobloxScript {
public:
    RobloxScript(const std::string& content);
    std::string getContent() const;
    void setContent(const std::string& content);
private:
    std::string content;
};

#endif