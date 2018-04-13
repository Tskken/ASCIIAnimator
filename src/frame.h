#ifndef FRAME_H
#define FRAME_H

#include <fstream>
#include <sstream>
#include <string>

class Frame
{
    private:
        std::string m_data;
        std::string m_path;
        int m_index;
    public:
        Frame(std::string path, int index);
        ~Frame();
        std::string get_data();
};

#endif
