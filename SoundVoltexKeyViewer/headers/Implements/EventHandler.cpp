
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
        
        keySettingManager.SetKeyConfig(events,drawableObjectManager, drawableObjects);
    }
    else
    {
        
        for (int i = 0; i < 6; i++)
        {
            counting.counts[i] += events.ButtonCountValues[i];
            events.ButtonCountValues[i] = 0;
        }

        drawableObjectManager.UpdateButtonImage(drawableObjects.spritesArray, events.ButtonStates, events.KnobStates);
        drawableObjectManager.UpdateCountingText(drawableObjects.textsArray, counting.counts, calculationUtility.GetSum(counting.counts));
    }
}