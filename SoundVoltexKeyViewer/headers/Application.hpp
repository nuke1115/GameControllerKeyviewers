#ifndef APPLICATION_HEADER_N
#define APPLICATION_HEADER_N
#include <iostream>
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Joystick.hpp>
#include "..\includes\inicpp.hpp"
#include "..\headers\EventDetector.hpp"
#include "..\headers\EventHandler.hpp"
#include "..\headers\AppEvent.hpp"
#include "..\headers\WindowManager.hpp"
#include "..\headers\Containers.hpp"
#include "..\headers\BidirectionalMap.hpp"

class Application
{
private:
    sf::RenderWindow _window;
    Containers::Sprites::DrawableObjects _drawableObjects;
    EventDetector _eventDetector;
    EventHandler _eventHandler;
    Containers::AppEvent _appEvent;
    const std::string _iniFilePath = "../SoundVoltexKeyViewer/assets/settings/Settings.ini";
    BidirectionalMap<std::string, sf::Joystick::Axis> _bidirectionalMap;
    WindowManager _windowManager;
public:
    Application(int width, int height);
    ~Application();
    int Initialize();
    void Run();
    inline bool CheckController()
    {
        return sf::Joystick::isConnected(Containers::Joystick::Codes::Index::JoystickIndex);
    }
};

#endif // !APPLICATION_HEADER_N