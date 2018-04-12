#include "gtest/gtest.h"
#include "baseline.h"

TEST(baseline, one) {
    int expected = 1;
    int actual = baseline_function(1);
    ASSERT_EQ(expected, actual);
}
