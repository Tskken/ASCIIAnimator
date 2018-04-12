#include <fstream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"
#include "animator.h"

TEST(AnimatorTest, basic)
{
    EXPECT_EQ(1, 1);
}

TEST(AnimatorTest, StepForwardOnce)
{
    // Load the animation
    Animator animator;
    animator.load("../samples/animation_1");

    // Capture the result of stepping forward once
    std::stringstream ss;
    animator.set_stream(ss);
    animator.forward(1);

    // Open the frame buffer
    std::ifstream fin;
    fin.open("../samples/animation_1/00.txt", std::ifstream::in);

    // Make line-by-line comparisons between captured output and frame buffer
    std::string expected_line;
    std::string actual_line;
    while (getline(fin, expected_line))
    {
        getline(ss, actual_line);
        ASSERT_STREQ(expected_line.c_str(), actual_line.c_str());
    }
}

TEST(AnimatorTest, StepForwardAndThrough)
{
    Animator animator;
    animator.load("../samples/animation_1");

    std::stringstream ss;
    animator.set_stream(ss);

    std::ifstream fin;
    for (int i = 0; i < 24; i++)
    {
        animator.forward(1);

        std::string index = std::to_string(i);
        if (i < 10)
        {
            index = "0" + index;
        }
        fin.open("../samples/animation_1/" + index + ".txt", std::ifstream::in);

        std::string expected_line;
        std::string actual_line;
        while (getline(fin, expected_line))
        {
            getline(ss, actual_line);
            ASSERT_STREQ(expected_line.c_str(), actual_line.c_str());
        }
    }
}
