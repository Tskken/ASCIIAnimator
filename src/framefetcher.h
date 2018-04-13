#ifndef FRAMEFETCHER_H
#define FRAMEFETCHER_H

#include <dirent.h>
#include <string>
#include <thread>
#include <vector>
#include "frame.h"

class FrameFetcher
{
    private:
        std::vector<std::string> m_frame_paths;
        std::vector<Frame> m_frames;
        void load_frames();

    public:
        FrameFetcher();
        ~FrameFetcher();
        int get_count();
        Frame get_frame(int index);
        void load(std::string animation_path);
};

#endif
