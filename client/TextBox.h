#include <string>

namespace sf {
    class RenderWindow;
    class Font;
    class Text;
}


struct Vector2 {
    Vector2(int i_x, int i_y) : x(i_x), y(i_y) {};
    int x, y;
};

class TextBox {
public:
    TextBox(sf::RenderWindow& window, Vector2 size, Vector2 position) : m_window(window), m_size(size), m_position(position) {};
    ~TextBox() = default;
    void addText(std::string text);
    void displayText();
    void clearText();
    void wrapText();
protected:

private:
    sf::RenderWindow& m_window;
    Vector2 m_size;
    Vector2 m_position;
    std::string m_text;

};
