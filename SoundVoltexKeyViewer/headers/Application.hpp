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
    WindowManager _windowManager;
    Containers::Sprites::DrawableObjects _drawableObjects;
    EventDetector _eventDetector;
    EventHandler _eventHandler;
    Containers::AppEvent _appEvent;
    std::string _iniFilePath = "../SoundVoltexKeyviewer/assets/settings/Settings.ini";
    BidirectionalMap<std::string, sf::Joystick::Axis> _bidirectionalMap;
public:
    Application(int width, int height);
    ~Application();
    bool CheckController();
    void Run();
    int Initialize();
};

#endif // !APPLICATION_HEADER_N