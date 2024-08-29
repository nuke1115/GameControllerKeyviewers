#ifndef WINDOW_MANAGER_IMPLEMENT_N
#define WINDOW_MANAGER_IMPLEMENT_N
#include "..\WindowManager.hpp"

inline void ClearWindow(sf::RenderWindow& window)
{
    window.clear();
}

WindowManager::WindowManager()
{

}

void WindowManager::RenderToWindow(sf::Sprite SpriteArray[], sf::Text TextArray[], sf::RenderWindow& window)
{
    ClearWindow(window);
    for (int i = 0; i < arrayMaxSize; i++)
    {
        window.draw(SpriteArray[i]);
        window.draw(TextArray[i]);
    }
    window.display();
}

#endif // !WINDOW_MANAGER_IMPLEMENT_N