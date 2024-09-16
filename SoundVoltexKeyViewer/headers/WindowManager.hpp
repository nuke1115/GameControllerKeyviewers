#ifndef WINDOW_MANAGER_HEADER_N
#define WINDOW_MANAGER_HEADER_N
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <vector>
#include "..\headers\Containers.hpp"
#include "..\headers\AppEvent.hpp"

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

    void RenderToWindow(std::vector<sf::Sprite>& spriteArray, std::vector<sf::Text>& textArray , sf::RenderWindow& window, sf::Text& indicator, Containers::AppEvent& events);
};
#endif // !WINDOW_MANAGER_HEADER_N