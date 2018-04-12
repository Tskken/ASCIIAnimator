#include "framefetcher.h"

FrameFetcher::FrameFetcher() {}

FrameFetcher::~FrameFetcher() {}

int FrameFetcher::get_count()
{
    return 0;
}

Frame FrameFetcher::get_frame(int index)
{
    Frame frame("");
    return frame;
}

void FrameFetcher::load(std::string animation_path) {}
