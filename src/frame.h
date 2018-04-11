#include <ostream>
#include <string>

class Frame
{
    private:
        std::string data;
        std::string color;
    public:
        Frame(std::string path_to_frame);
        ~Frame();
        void display(std::ostream out);
        void set_color(std::string color_code);
};
