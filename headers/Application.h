#ifndef APPLICATION_HEADER_N
#define APPLICATION_HEADER_N
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <SFML/Graphics/RenderWindow.hpp>
#include "..\includes\inicpp.hpp"
#include "..\headers\EventDetector.h"
#include "..\headers\EventHandler.h"
#include "..\headers\AppEvent.h"
#include "..\headers\WindowManager.h"
#include "..\headers\Containers.h"
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
	//~Application();
	void Run();
	int Initialize();

};

#endif // !APPLICATION_HEADER_N
