#ifndef WINDOW_MANAGER_HEADER_N
#define WINDOW_MANAGER_HEADER_N
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include "..\headers\Containers.hpp"

class WindowManager
{
private:
    const int arrayMaxSize = 9;
public:
    WindowManager();

    inline void CreateWindow(int width, int height, std::string WindowName, sf::RenderWindow& window)
    {
        window.create(sf::VideoMode(width, height), WindowName);
    }

    void RenderToWindow(sf::Sprite SpriteArray[], sf::Text TextArray[], sf::RenderWindow& window);
};
#endif // !WINDOW_MANAGER_HEADER_N