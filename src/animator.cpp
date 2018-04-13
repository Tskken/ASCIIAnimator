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

void Animator::load(std::string animation_path) {}

void Animator::play(int fps)
{
    int counter = 0;
    while (true) {
        if (counter == 1000) {
            return;
        }
        *m_out << m_fetcher.get_frame(m_current_frame).get_data();
        forward(1);
        counter++;
        std::this_thread::sleep_for(std::chrono::seconds(1 / fps));
    }
}

void Animator::forward(int step) {
    m_current_frame += step;
}

void Animator::backward(int step) {
    m_current_frame -= step;
}

void Animator::reset() {}

void Animator::set_stream(std::iostream &stream) {
    m_out = new std::ostream(stream.rdbuf());
}
