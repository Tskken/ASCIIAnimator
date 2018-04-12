#ifndef FRAMEFETCHER_H
#define FRAMEFETCHER_H

#include <string>
#include <vector>
#include "frame.h"

class FrameFetcher
{
    private:
        std::vector<std::string> frame_file_paths;
        std::vector<Frame> frame_buffer;
        int buffer_limit;

    public:
        FrameFetcher();
        ~FrameFetcher();
        int get_count();
        Frame get_frame(int index);
        void load(std::string animation_path);
};

#endif
