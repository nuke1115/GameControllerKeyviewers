#ifndef WINDOW_MANAGER_HEADER_N
#define WINDOW_MANAGER_HEADER_N
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include "..\headers\Containers.h"

class WindowManager
{
private:
	sf::Color clearColor;
	const int arrayMaxSize = 9;
	inline void ClearWindow(sf::RenderWindow& window)
	{
		window.clear();
	}
public:
	WindowManager();

	inline void CreateWindow(int width, int height, std::string WindowName, sf::RenderWindow& window)
	{
		window.create(sf::VideoMode(width, height), WindowName);
	}

	inline void RenderToWindow(sf::Sprite SpriteArray[] , sf::Text TextArray[] , sf::RenderWindow& window)
	{
		ClearWindow(window);
		for (int i = 0; i < arrayMaxSize; i++)
		{
			window.draw(SpriteArray[i]);
			window.draw(TextArray[i]);
		}
		window.display();
	}
};

#endif // !WINDOW_MANAGER_HEADER_N
