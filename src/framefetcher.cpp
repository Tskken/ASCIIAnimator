#include "framefetcher.h"

FrameFetcher::FrameFetcher() {}

FrameFetcher::~FrameFetcher() {}

int FrameFetcher::get_count()
{
    return 0;
}

Frame FrameFetcher::get_frame(int index)
{
    return frame_buffer.at(index);
}

void FrameFetcher::load(std::string animation_path) {}
