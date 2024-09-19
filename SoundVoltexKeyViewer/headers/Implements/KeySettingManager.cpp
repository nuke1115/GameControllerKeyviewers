#include "..\KeySettingManager.hpp"

sf::Joystick::Axis KeySettingManager::getAxisCode(unsigned int key)
{
    switch (key)
    {
    case sf::Joystick::Axis::X:
        return sf::Joystick::Axis::X;
    case sf::Joystick::Axis::Y:
        return sf::Joystick::Axis::Y;
    case sf::Joystick::Axis::Z:
        return sf::Joystick::Axis::Z;
    case sf::Joystick::Axis::R:
        return sf::Joystick::Axis::R;
    case sf::Joystick::Axis::U:
        return sf::Joystick::Axis::U;
    case sf::Joystick::Axis::V:
        return sf::Joystick::Axis::V;
    case sf::Joystick::Axis::PovX:
        return sf::Joystick::Axis::PovX;
    case sf::Joystick::Axis::PovY:
        return sf::Joystick::Axis::PovY;
    default:
        return sf::Joystick::X;
    }
}

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

    bool goNextEventTmp = false;
    if (appEvent.SettingModeGoNextEvent)
    {
        goNextEventTmp = appEvent.SettingModeGoNextEvent;
        _index++;
        appEvent.SettingModeGoNextEvent = false;
    }

    FlickImage(drawableObjects.spritesArray, goNextEventTmp);
    

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
        Containers::Joystick::Codes::Knobs::knobL = getAxisCode(appEvent.SettingModeKnobIndex);
        break;
    case 9:
        Containers::Joystick::Codes::Knobs::knobR = getAxisCode(appEvent.SettingModeKnobIndex);
        break;
    }
}