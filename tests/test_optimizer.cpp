#include <gtest/gtest.h>
#include "optimizer.h"

TEST(OptimizerTest, RemoveComments) {
    Optimizer optimizer;
    std::string script = "local x = 1 -- comment\nlocal y = 2";
    std::string expected = "local x = 1 \nlocal y = 2\n";
    EXPECT_EQ(optimizer.removeComments(script), expected);
}

TEST(OptimizerTest, FindRedundantCalls) {
    Optimizer optimizer;
    std::string script = "tower:Move()\ntower:Move()\ntower:Jump()";
    auto redundant = optimizer.findRedundantCalls(script);
    EXPECT_EQ(redundant.size(), 1);
    EXPECT_EQ(redundant[0], "tower:Move()");
}