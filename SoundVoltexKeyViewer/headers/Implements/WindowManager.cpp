#include "..\WindowManager.hpp"

void WindowManager::RenderToWindow(sf::Sprite spritesArray[], sf::Text textsArray[], sf::RenderWindow& window, Containers::AppEvent& events)
{
    ClearWindow(window);

    for (int i = 0; i < 9; i++)
    {
        window.draw(spritesArray[i]);
    }

    if (events.SettingModeOn)
    {
        window.draw(textsArray[9]);
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