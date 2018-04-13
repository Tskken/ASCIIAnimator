#include "framefetcher.h"

FrameFetcher::FrameFetcher()
{

}

FrameFetcher::~FrameFetcher()
{
    for (Frame *frame : m_frames)
    {
        delete frame;
        frame = NULL;
    }
}

void FrameFetcher::load_frames()
{
    for (int i = 0; i < m_frame_paths.size(); i++)
    {
        std::string path = m_frame_paths[i];
        Frame *frame = new Frame(path, i);
        m_frames.push_back(frame);
    }
}

int FrameFetcher::get_count()
{
    return m_frame_paths.size();
}

Frame *FrameFetcher::get_frame(int index)
{
    // Check for out-of-bounds access
    if (index > m_frame_paths.size())
    {
        exit(1);
    }
    // Wait until frame is buffered
    while (index >= m_frames.size())
    {
        
    }
    return m_frames[index];
}

void FrameFetcher::load_animation (std::string animation_path)
{
    struct dirent *ent = NULL;
    DIR *dir = opendir(animation_path.c_str());
    while ((ent = readdir(dir)) != NULL)
    {
        // Get dirent name
        std::string name = ent->d_name;

        // Append an illegal character to dirent name
        std::string name_test = name + '?';

        // See if dirent name ends with .txt
        if (name_test.find(".txt?") != std::string::npos)
        {
            m_frame_paths.push_back(animation_path + '/' + name);
        }
    }
    closedir(dir);
    dir = NULL;
    ent = NULL;

    std::thread worker(&FrameFetcher::load_frames, this);
    worker.join();
}
