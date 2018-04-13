#include "animator.h"

Animator::Animator() {}

Animator::~Animator()
{
    if (m_out != &std::cout)
    {
        delete m_out;
        m_out = NULL;
    }
}

void Animator::enable_colors() {}

void Animator::disable_colors() {}

void Animator::load_animation(std::string animation_path)
{
    m_fetcher.load_animation(animation_path);
}

void Animator::play(int fps, int loops)
{
    int delay = (1.0 / fps) * 1000;
    int count = m_fetcher.get_count();
    for (int i = 0; i < count * loops; i++)
    {
        forward(1);
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void Animator::forward(int step)
{
    if (m_current_frame + step >= m_fetcher.get_count())
    {
        return;
    }
    m_current_frame += step;
    display_current_frame();
}

void Animator::backward(int step)
{
    if (m_current_frame - step < 0)
    {
        return;
    }
    m_current_frame -= step;
    display_current_frame();
}

void Animator::display_current_frame()
{
    Frame *frame = m_fetcher.get_frame(m_current_frame);
    *m_out << frame->get_data();
    frame = NULL;
}

void Animator::reset()
{
    m_current_frame = -1;
}

void Animator::set_stream(std::iostream &stream) {
    m_out = new std::ostream(stream.rdbuf());
}
