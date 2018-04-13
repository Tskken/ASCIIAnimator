#include "frame.h"

Frame::Frame(std::string path, int index)
{
    m_path = path;
    m_index = index;

    std::fstream fin;
    fin.open(path, std::fstream::in);
    std::stringstream buf;
    buf << fin.rdbuf();
    m_data = buf.str();
    fin.close();
}

Frame::~Frame() {}

std::string Frame::get_data()
{
    return m_data;
}
