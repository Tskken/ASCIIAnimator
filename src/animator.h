#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <chrono>
#include <iostream>
#include <ostream>
#include <string>
#include <streambuf>
#include <thread>
#include "framefetcher.h"

class Animator
{
    private:
        std::ostream *m_out = &std::cout;
        FrameFetcher m_fetcher;
        int m_current_frame = 0;

    public:
        Animator();
        ~Animator();
        void enable_colors();
        void disable_colors();
        void load_animation(std::string animation_path);
        void play(int fps, int loops);
        void forward(int step);
        void backward(int step);
        void display_current_frame();
        void reset();
        void set_stream(std::iostream &stream);
};

#endif
