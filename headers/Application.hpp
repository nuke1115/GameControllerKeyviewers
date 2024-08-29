#ifndef APPLICATION_HEADER_N
#define APPLICATION_HEADER_N
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <SFML/Graphics/RenderWindow.hpp>
#include "..\includes\inicpp.hpp"
#include "..\headers\EventDetector.hpp"
#include "..\headers\EventHandler.hpp"
#include "..\headers\AppEvent.hpp"
#include "..\headers\WindowManager.hpp"
#include "..\headers\Containers.hpp"
#include <iostream>

class Application
{
private:
    sf::RenderWindow window;
    WindowManager windowManager;
    Containers::Sprites::DrawableObjects drawableObjects;
    EventDetector eventDetector;
    EventHandler eventHandler;
    Containers::AppEvent appEvent;
public:
    Application(int width, int height, std::string WindowName);
    bool CheckController();
    void Run();
    int Initialize();
};

#endif // !APPLICATION_HEADER_N