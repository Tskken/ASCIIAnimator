#ifndef FRAME_H
#define FRAME_H

#include <ostream>
#include <string>

class Frame
{
    private:
        std::string data;
    public:
        Frame(std::string frame_path);
        ~Frame();
        std::string get_data();
};

#endif
