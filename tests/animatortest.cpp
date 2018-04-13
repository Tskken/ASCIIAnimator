#include <fstream>
#include <queue>
#include <sstream>
#include <string>
#include "gtest/gtest.h"
#include "animator.h"

TEST(AnimatorTest, StepForwardOnce)
{
    // Load the animation and capture output
    Animator animator;
    animator.load_animation("../samples/animation_1");
    std::stringstream ss;
    animator.set_stream(ss);

    // Open the frame buffer
    std::ifstream fin;
    fin.open("../samples/animation_1/00.txt", std::ifstream::in);

    // Step forward one frame
    animator.forward(1);

    // Make line-by-line comparisons of frames
    std::string expected_line;
    std::string actual_line;
    while (getline(fin, expected_line))
    {
        getline(ss, actual_line);
        ASSERT_EQ(expected_line, actual_line);
    }
    // Close the frame buffer
    fin.close();
}

TEST(AnimatorTest, StepForwardBig)
{
    // Load the animation and capture output
    Animator animator;
    animator.load_animation("../samples/animation_1");
    std::stringstream ss;
    animator.set_stream(ss);

    // Open the frame buffer
    std::ifstream fin;
    fin.open("../samples/animation_1/01.txt", std::ifstream::in);

    // Step forward two frames
    animator.forward(2);
    
    // Make line-by-line comparisons of frames
    std::string expected_line;
    std::string actual_line;
    while (getline(fin, expected_line))
    {
        getline(ss, actual_line);
        ASSERT_EQ(expected_line, actual_line);
    }
    // Close the frame buffer
    fin.close();
}

TEST(AnimatorTest, StepForwardAndThrough)
{
    // Load the animation and capture output
    Animator animator;
    animator.load_animation("../samples/animation_1");
    std::stringstream ss;
    animator.set_stream(ss);

    // For each frame in the full animation
    for (int i = 0; i < 24; i++)
    {
        // Step forward one frame
        animator.forward(1);

        // Use index to derive filepath to next frame
        std::string index = std::to_string(i);
        if (i < 10)
        {
            index = "0" + index;
        }
        std::string file_path = "../samples/animation_1/" + index + ".txt";

        // Open the frame buffer
        std::ifstream fin;
        fin.open(file_path, std::ifstream::in);

        // Make line-by-line comparisons of frames
        std::string expected_line;
        std::string actual_line;
        while (getline(fin, expected_line))
        {
            getline(ss, actual_line);
            ASSERT_EQ(expected_line, actual_line);
        }
        // Close the frame buffer
        fin.close();
    }
}

TEST(AnimatorTest, StepForwardAndThroughColors)
{
    // Define color cycle
    std::queue<std::string> color_cycle;
    color_cycle.push(std::string(BG_RED));
    color_cycle.push(std::string(BG_YELLOW));
    color_cycle.push(std::string(BG_GREEN));
    color_cycle.push(std::string(BG_GREEN));
    color_cycle.push(std::string(BG_BLUE));
    color_cycle.push(std::string(BG_MAGENTA));

    // Load the animation and capture output
    Animator animator;
    animator.load_animation("../samples/animation_1");
    std::stringstream ss;
    animator.set_stream(ss);

    // For each frame in the full animation
    for (int i = 0; i < 24; i++)
    {
        // Step forward one frame
        animator.forward(1);

        // Use index to derive filepath to next frame
        std::string index = std::to_string(i);
        if (i < 10)
        {
            index = "0" + index;
        }
        std::string file_path = "../samples/animation_1/" + index + ".txt";

        // Open the frame buffer
        std::ifstream fin;
        fin.open(file_path, std::ifstream::in);

        // Make line-by-line comparisons of frames
        std::string expected_line;
        std::string actual_line;
        std::string bg_color;
        while (getline(fin, expected_line))
        {
            // Get next color code from cycle
            bg_color = color_cycle.front();
            color_cycle.pop();
            color_cycle.push(bg_color);

            // Apply coloring to expected line
            expected_line = FG_WHITE + bg_color + expected_line + CL_RESET;

            getline(ss, actual_line);
            ASSERT_EQ(expected_line, actual_line);
        }
        // Close the frame buffer
        fin.close();
    }
}

TEST(AnimatonTest, Play)
{
    // Load the animation and capture output
    Animator animator;
    animator.load_animation("../samples/animation_1");
    std::stringstream ss;
    animator.set_stream(ss);

    // Compile all frames into a single buffer
    std::string expected_buf;
    for (int i = 0; i < 24; i++)
    {        
        // Use index to derive filepath to next frame
        std::string index = std::to_string(i);
        if (i < 10)
        {
            index = "0" + index;
        }
        std::string file_path = "../samples/animation_1/" + index + ".txt";

        // Open the file as a Frame
        Frame frame(file_path, i);
        expected_buf += frame.get_data();
    }

    // Play the animation to get the actual buffer
    animator.play(1, 1);
    std::string actual_buf = ss.str();

    ASSERT_EQ(expected_buf, actual_buf);
}

TEST(AnimationTest, PlayReverse)
{
    // Load the animation and capture output
    Animator animator;
    animator.load_animation("../samples/animation_1");
    std::stringstream ss;
    animator.set_stream(ss);
    
    Frame *frame1 = animator.reverse(2, 1);
    Frame frame2("../samples/animation_1/00.txt", 0);
    std::string data = frame2.get_data();
    std::string reverse_data = "";
    for (int i = 0; i < data.length(); i++)
    {
        reverse_data += data[(data.length()-1) - i];
    }
    ASSERT_EQ(reverse_data, frame1->get_data());
}
