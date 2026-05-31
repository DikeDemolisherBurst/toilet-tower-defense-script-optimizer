#include <iostream>
#include "optimizer.h"
#include "roblox_script.h"

int main() {
    std::string script = R"(
        -- Example Roblox script
        local tower = game.Workspace.Tower
        tower:SetPrimaryPartCFrame(CFrame.new(0, 0, 0))
        tower:SetPrimaryPartCFrame(CFrame.new(0, 0, 0)) -- Duplicate call
    )";

    RobloxScript rs(script);
    Optimizer optimizer;
    std::string optimized = optimizer.optimize(rs.getContent());

    std::cout << "Optimized script:\n" << optimized << std::endl;
    return 0;
}