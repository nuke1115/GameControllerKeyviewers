#include "..\KeySettingManager.hpp"

void KeySettingManager::FlickImage( Containers::Sprites::DrawableObjects& drawableObjects, DrawableObjectManager& drawableObjectManager)
{
    _counter++;
    if (_counter> Containers::System::System::flickeringSpeed)
    {
        _counter = 0;
        if (_isColorChanged)
        {
            _spriteColor.r = 255;
            _spriteColor.g = 255;
            _spriteColor.b = 255;
            _isColorChanged = false;
        }
        else
        {
            _spriteColor.r = 0;
            _spriteColor.g = 0;
            _spriteColor.b = 0;
            _isColorChanged = true;
        }

        
        switch (_index)
        {
        case 1:
            drawableObjectManager.SetSpriteColor(drawableObjects.spritesArray[0],_spriteColor);
            break;
        case 2:
            drawableObjectManager.SetSpriteColor(drawableObjects.spritesArray[1], _spriteColor);
            break;
        case 3:
            drawableObjectManager.SetSpriteColor(drawableObjects.spritesArray[2], _spriteColor);
            break;
        case 4:
            drawableObjectManager.SetSpriteColor(drawableObjects.spritesArray[3], _spriteColor);
            break;
        case 5:
            drawableObjectManager.SetSpriteColor(drawableObjects.spritesArray[4], _spriteColor);
            break;
        case 6:
            drawableObjectManager.SetSpriteColor(drawableObjects.spritesArray[5], _spriteColor);
            break;
        case 7:
            drawableObjectManager.SetSpriteColor(drawableObjects.spritesArray[6], _spriteColor);
            break;
        case 8:
            drawableObjectManager.SetSpriteColor(drawableObjects.spritesArray[7], _spriteColor);
            break;
        case 9:
            drawableObjectManager.SetSpriteColor(drawableObjects.spritesArray[8], _spriteColor);
            break;
        default:
            break;
        }
    }
}


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

void KeySettingManager::SetKeyConfig(Containers::AppEvent& appEvent, DrawableObjectManager& drawableObjectManager, Containers::Sprites::DrawableObjects& drawableObjects)
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
        drawableObjectManager.SetNowSelectedKeyIndicatorText("",drawableObjects.nowSelectedKeyIndicator);
        _index = 100;
    }

    if (appEvent.SettingModeGoNextEvent)
    {
        appEvent.SettingModeGoNextEvent = false;

        for (auto& i : drawableObjects.spritesArray)
        {
            drawableObjectManager.SetSpriteColor(i, sf::Color::White);
        }

        _index++;
    }

    FlickImage(drawableObjects, drawableObjectManager);

    switch (_index)
    {
    case 1:
        drawableObjectManager.SetNowSelectedKeyIndicatorText("btA", drawableObjects.nowSelectedKeyIndicator);
        Containers::Joystick::Codes::Buttons::btA = appEvent.SettingModeButtonIndex;
        break;
    case 2:
        drawableObjectManager.SetNowSelectedKeyIndicatorText("btB", drawableObjects.nowSelectedKeyIndicator);
        Containers::Joystick::Codes::Buttons::btB = appEvent.SettingModeButtonIndex;
        break;
    case 3:
        drawableObjectManager.SetNowSelectedKeyIndicatorText("btC", drawableObjects.nowSelectedKeyIndicator);
        Containers::Joystick::Codes::Buttons::btC = appEvent.SettingModeButtonIndex;
        break;
    case 4:
        drawableObjectManager.SetNowSelectedKeyIndicatorText("btD", drawableObjects.nowSelectedKeyIndicator);
        Containers::Joystick::Codes::Buttons::btD = appEvent.SettingModeButtonIndex;
        break;
    case 5:
        drawableObjectManager.SetNowSelectedKeyIndicatorText("fxL", drawableObjects.nowSelectedKeyIndicator);
        Containers::Joystick::Codes::Buttons::fxL = appEvent.SettingModeButtonIndex;
        break;
    case 6:
        drawableObjectManager.SetNowSelectedKeyIndicatorText("fxR", drawableObjects.nowSelectedKeyIndicator);
        Containers::Joystick::Codes::Buttons::fxR = appEvent.SettingModeButtonIndex;
        break;
    case 7:
        drawableObjectManager.SetNowSelectedKeyIndicatorText("start", drawableObjects.nowSelectedKeyIndicator);
        Containers::Joystick::Codes::Buttons::start = appEvent.SettingModeButtonIndex;
        break;
    case 8:
        drawableObjectManager.SetNowSelectedKeyIndicatorText("knobL", drawableObjects.nowSelectedKeyIndicator);
        Containers::Joystick::Codes::Knobs::knobL = getAxisCode(appEvent.SettingModeKnobIndex);
        break;
    case 9:
        drawableObjectManager.SetNowSelectedKeyIndicatorText("knobR", drawableObjects.nowSelectedKeyIndicator);
        Containers::Joystick::Codes::Knobs::knobR = getAxisCode(appEvent.SettingModeKnobIndex);
        break;
    default:
        drawableObjectManager.SetNowSelectedKeyIndicatorText(" ", drawableObjects.nowSelectedKeyIndicator);
        break;
    }
    

    

    
}