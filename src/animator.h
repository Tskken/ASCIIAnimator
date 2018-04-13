#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <chrono>
#include <iostream>
#include <ostream>
#include <string>
#include <streambuf>
#include <thread>
#include "framefetcher.h"
#include <time.h>
#include <stdlib.h>

const std::string CL_RESET   = "\033[0m";
const std::string BG_RED     = "\033[1;41m";
const std::string BG_YELLOW  = "\033[1;43m";
const std::string BG_GREEN   = "\033[1;42m";
const std::string BG_CYAN    = "\033[1;46m";
const std::string BG_BLUE    = "\033[1;44m";
const std::string BG_MAGENTA = "\033[1;45m";
const std::string FG_WHITE   = "\033[1;37m";

class Animator
{
    private:
        std::ostream *m_out = &std::cout;
        FrameFetcher m_fetcher;
        int m_current_frame = -1;
        std::string m_color = CL_RESET;

    public:
        Animator();
        ~Animator();
        void enable_colors();
        void disable_colors();
        void load_animation(std::string animation_path);
        void play(int fps, int loops);
        void reverse(int fps, int loops);
        void forward(int step);
        void backward(int step);
        void display_current_frame();
        void reset();
        void set_stream(std::iostream &stream);
};

#endif
