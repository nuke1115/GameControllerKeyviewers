#ifndef WINDOW_MANAGER_HEADER_N
#define WINDOW_MANAGER_HEADER_N
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include "..\headers\Containers.hpp"

class WindowManager
{
public:
    inline void CreateWindow(int width, int height, sf::RenderWindow& window)
    {
        window.create(sf::VideoMode(width, height), "TmpName");
    }

    inline void SetWindowName(const std::string& name, sf::RenderWindow& window)
    {
        window.setTitle(name);
    }

    void RenderToWindow(sf::Sprite SpriteArray[], sf::Text TextArray[], sf::RenderWindow& window);
};
#endif // !WINDOW_MANAGER_HEADER_N