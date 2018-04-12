#include <fstream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"
#include "animator.h"

TEST(animator, basic)
{
    EXPECT_EQ(1, 1);
}

TEST(animator, step_forward_once)
{
    // Load the animation
    Animator animator;
    std::string animation_path = "../samples/animation_1";
    animator.load(animation_path);

    // Capture the result of stepping forward once
    std::stringstream ss;
    animator.set_stream(ss);
    animator.forward(1);

    // Open the frame buffer
    std::ifstream fin;
    std::ifstream::open("../samples/animation_1/00.txt", fin);

    // Make line-by-line comparisons between captured output and frame buffer
    std::string expected_line;
    std::string actual_line;
    while (getline(fin, expected_line)) {
        getline(ss, actual_line);
        EXPECT_EQ(expected_line, actual_line);
    }
}
