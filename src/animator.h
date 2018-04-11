#include <string>
#include "framefetcher.h"

class Animator
{
    private:
        FrameFetcher fetcher;
        int current_frame = 0;

    public:
        Animator();
        ~Animator();
        int load(std::string frames_dir_path);
        void play(int fps);
        void forward(int step);
        void backward(int step);
        void reset();
};
