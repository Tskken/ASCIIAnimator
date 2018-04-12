#include "gtest/gtest.h"
#include "animator.h"
#include "baseline.h"
#include "frame.h"
#include "framefetcher.h"

TEST(baseline, one) {
    int expected = 1;
    int actual = baseline_function(1);
    ASSERT_EQ(expected, actual);
}
