#ifndef WINDOW_MANAGER_HEADER_N
#define WINDOW_MANAGER_HEADER_N
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include "..\headers\Containers.hpp"
#include "..\headers\AppEvent.hpp"

class WindowManager
{
private:
    inline void ClearWindow(sf::RenderWindow& window)
    {
        window.clear();
    }
public:
    inline void CreateWindow(int width, int height, sf::RenderWindow& window)
    {
        window.create(sf::VideoMode(width, height), "TmpName");
    }

    inline void SetWindowName(const std::string& name, sf::RenderWindow& window)
    {
        window.setTitle(name);
    }

    void RenderToWindow(sf::Sprite spritesArray[], sf::Text textsArray[], sf::RenderWindow& window, sf::Text& indicator, Containers::AppEvent& events);
};
#endif // !WINDOW_MANAGER_HEADER_N