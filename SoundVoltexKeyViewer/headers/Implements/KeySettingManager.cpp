#include "..\KeySettingManager.hpp"

void KeySettingManager::SetKeyConfig(Containers::AppEvent& appEvent, Containers::Sprites::DrawableObjects& drawableObjects)
{
    if (appEvent.SettingModeEntryEvent)
    {
        appEvent.SettingModeEntryEvent = false;
        appEvent.SettingModeOn = true;
        _index = 1;
    }

    if (_index > 9)
    {
        appEvent.SettingModeOn = false;
        _drawableObjectManager.SetNowSelectedKeyIndicatorText(" ",drawableObjects.textsArray[9]);
        _index = 10;
        _imageFlickManager.ResetImages(drawableObjects.spritesArray, 9);
    }


    if (appEvent.SettingModeGoNextEvent)
    {
        _imageFlickManager.ResetImages(drawableObjects.spritesArray, 9);
        _index++;
        appEvent.SettingModeGoNextEvent = false;
    }

    _imageFlickManager.FlickImage(drawableObjects.spritesArray, _index - 1);
    

    if (_index < 10)
    {
        _drawableObjectManager.SetNowSelectedKeyIndicatorText(Containers::Sprites::TextStrings::indicatorTextsArray[_index - 1], drawableObjects.textsArray[9]);
    }

    switch (_index)
    {
    case 1:
        Containers::Joystick::Codes::Buttons::btA = appEvent.SettingModeButtonIndex;
        break;
    case 2:
        Containers::Joystick::Codes::Buttons::btB = appEvent.SettingModeButtonIndex;
        break;
    case 3:
        Containers::Joystick::Codes::Buttons::btC = appEvent.SettingModeButtonIndex;
        break;
    case 4:
        Containers::Joystick::Codes::Buttons::btD = appEvent.SettingModeButtonIndex;
        break;
    case 5:
        Containers::Joystick::Codes::Buttons::fxL = appEvent.SettingModeButtonIndex;
        break;
    case 6:
        Containers::Joystick::Codes::Buttons::fxR = appEvent.SettingModeButtonIndex;
        break;
    case 7:
        Containers::Joystick::Codes::Buttons::start = appEvent.SettingModeButtonIndex;
        break;
    case 8:
        Containers::Joystick::Codes::Knobs::knobL = static_cast<sf::Joystick::Axis>(appEvent.SettingModeKnobIndex);
        break;
    case 9:
        Containers::Joystick::Codes::Knobs::knobR = static_cast<sf::Joystick::Axis>(appEvent.SettingModeKnobIndex);
        break;
    }
}