#ifndef EVENT_DETECTOR__HEADER_N
#define EVENT_DETECTOR__HEADER_N
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "..\headers\Containers.hpp"
#include "..\headers\AppEvent.hpp"

class EventDetector
{
private:
    const float knobAngleCalibrationNum = 3.6f;
    sf::Event event;
public:
    void DetectEvents(Containers::AppEvent& eventContainer, sf::RenderWindow& window);
};

#endif // !EVENT_DETECTOR__HEADER_N