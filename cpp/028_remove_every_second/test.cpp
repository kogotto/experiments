#include <gtest/gtest.h>

#include "remove_every_second.h"

struct Param {
    std::vector<int> input;
    std::vector<int> expected;
};

class TestRemove : public testing::TestWithParam<Param> {};

auto generateValues() {
    return std::array<Param, 5> {
        Param{
            {},
            {}
        },
        Param{
            { 1 },
            { 1 }
        },
        Param{
            { 1, 2 },
            { 1 }
        },
        Param{
            { 1, 2, 3 },
            { 1, 3 }
        },
        Param{
            { 1, 2, 3, 4, 5, 6, 7, 8 },
            { 1, 3, 5, 7 }
        },
    };
}

TEST_P(TestRemove, Test) {
    auto input = GetParam().input;
    removeEverySecondElement(input);

    ASSERT_EQ(GetParam().expected, input);
}

INSTANTIATE_TEST_SUITE_P(
    TestRemove,
    TestRemove,
    testing::ValuesIn(generateValues()));
