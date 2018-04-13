#include "gtest/gtest.h"
#include "framefetcher.h"

TEST(FrameFetcherTest, LoadFrameIntoBuffer)
{
    FrameFetcher fetcher;
    fetcher.load_animation("../samples/animation_1");
    Frame *frame = fetcher.get_frame(0);
    std::string actual_data = frame->get_data();

    std::ifstream fin;
    fin.open("../samples/animation_1/00.txt", std::ifstream::in);
    std::stringstream buf;
    buf << fin.rdbuf();
    std::string expected_data = buf.str();

    ASSERT_EQ(expected_data, actual_data);
}

TEST(FrameFetcherTest, LoadAnimation)
{
    FrameFetcher fetcher;
    fetcher.load_animation("../samples/animation_1");
    int expected_size = 24;
    int actual_size = fetcher.get_count();
    ASSERT_EQ(expected_size, actual_size);
}
