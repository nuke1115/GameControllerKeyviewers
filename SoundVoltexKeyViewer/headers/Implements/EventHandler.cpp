#include "..\EventHandler.hpp"

void EventHandler::HandleEvents(Containers::AppEvent& events, Containers::Sprites::DrawableObjects& drawableObjects, sf::RenderWindow& window)
{
    if (events.TerminateEvent)
    {
        window.close();
        return;
    }

    if (events.SettingModeEntryEvent || events.SettingModeOn)
    {
        
        _keySettingManager.SetKeyConfig(events,drawableObjects);
    }
    else
    {
        
        for (int i = 0; i < 6; i++)
        {
            _counting.counts[i] += events.ButtonCountValues[i];
            events.ButtonCountValues[i] = 0;
        }

        _drawableObjectManager.UpdateButtonImage(drawableObjects.spritesArray, events.ButtonStates, events.KnobStates);
        _drawableObjectManager.UpdateCountingText(drawableObjects.textsArray, _counting.counts, _calculationUtility.GetSum(_counting.counts));
    }
}