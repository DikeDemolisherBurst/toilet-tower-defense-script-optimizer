#include "roblox_script.h"

RobloxScript::RobloxScript(const std::string& content) : content(content) {}

std::string RobloxScript::getContent() const {
    return content;
}

void RobloxScript::setContent(const std::string& content) {
    this->content = content;
}