#ifndef EVENT_HANDLER_HEADER_N
#define EVENT_HANDLER_HEADER_N
#include <SFML/Graphics/RenderWindow.hpp>
#include "..\headers\KeySettingManager.hpp"
#include "..\headers\Containers.hpp"
#include "..\headers\AppEvent.hpp"
#include "..\headers\CalculationUtility.hpp"
#include "..\headers\DrawableObjectManager.hpp"

class EventHandler
{
private:
    Containers::Joystick::Counting _counting;
    DrawableObjectManager _drawableObjectManager;
    KeySettingManager _keySettingManager;
    CalculationUtility _calculationUtility;
public:
    void HandleEvents(Containers::AppEvent& events, Containers::Sprites::DrawableObjects& drawableObjects, sf::RenderWindow& window);
};

#endif // !EVENT_HANDLER_HEADER_N