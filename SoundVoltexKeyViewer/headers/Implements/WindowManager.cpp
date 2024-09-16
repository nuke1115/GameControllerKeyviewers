#include "..\WindowManager.hpp"

inline void ClearWindow(sf::RenderWindow& window)
{
    window.clear();
}

void WindowManager::RenderToWindow(std::vector<sf::Sprite>& spriteArray, std::vector<sf::Text>& textArray, sf::RenderWindow& window,sf::Text& indicator ,Containers::AppEvent& events)
{
    ClearWindow(window);

    for (auto& i : spriteArray)
    {
        window.draw(i);
    }

    if (events.SettingModeOn)
    {
        window.draw(indicator);
    }
    else
    {
        

        for (auto& i : textArray)
        {
            window.draw(i);
        }
    }

    window.display();
}