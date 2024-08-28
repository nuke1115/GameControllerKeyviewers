#ifndef EVENT_HANDLER_HEADER_N
#define EVENT_HANDLER_HEADER_N
#include <SFML/Graphics/RenderWindow.hpp>
#include "..\headers\Containers.h"
#include "..\headers\AppEvent.h"
#include "..\headers\CalculationUtility.h"
#include "..\headers\DrawableObjectManager.h"
class EventHandler
{
private:
	CalculationUtility calculationUtility;
	Containers::Joystick::Counting counting;
	DrawableObjectManager drawableObjectManager;
	
public:
	inline void HandleEvents(Containers::AppEvent& events, Containers::Sprites::DrawableObjects& drawableObjects, sf::RenderWindow& window)
	{
		if (events.TerminateEvent)
		{
			window.close();
			return;
		}

		for (int i = 0; i < 6; i++)
		{
			counting.counts[i] += events.ButtonCountValues[i];
			events.ButtonCountValues[i] = 0;
		}

		drawableObjectManager.ChangeSpriteTexture(drawableObjects.spritesArray, events.ButtonStates, events.KnobStates);
		drawableObjectManager.ChangeText(drawableObjects.textsArray, counting.counts, calculationUtility.GetSum(counting.counts));
	}
};

#endif // !EVENT_HANDLER_HEADER_N
