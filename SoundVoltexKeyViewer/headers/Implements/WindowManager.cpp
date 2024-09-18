#include "..\WindowManager.hpp"

void WindowManager::RenderToWindow(sf::Sprite spritesArray[], sf::Text textsArray[], sf::RenderWindow& window, sf::Text& indicator, Containers::AppEvent& events)
{
    ClearWindow(window);

    for (int i = 0; i < 9; i++)
    {
        window.draw(spritesArray[i]);
    }

    if (events.SettingModeOn)
    {
        window.draw(indicator);
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            window.draw(textsArray[i]);
        }
    }

    window.display();
}