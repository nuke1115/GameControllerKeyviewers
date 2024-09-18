#include "..\EventDetector.hpp"

void EventDetector::DetectEvents(Containers::AppEvent& eventContainer, sf::RenderWindow& window)
{
    
    eventContainer.SettingModeGoNextEvent = false;
    while (window.pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed)
        {
            eventContainer.TerminateEvent = true;
            break;
        }

        if (eventContainer.SettingModeOn)
        {
            if (_event.type == sf::Event::JoystickButtonPressed)
            {
                eventContainer.SettingModeButtonIndex = _event.joystickButton.button;
                
            }

            if (_event.type == sf::Event::JoystickMoved)
            {
                eventContainer.SettingModeKnobIndex = _event.joystickMove.axis;
            }

            if (_event.type == sf::Event::KeyPressed)
            {
                if (_event.key.code == sf::Keyboard::Enter)
                {
                    eventContainer.SettingModeGoNextEvent = true;
                }
            }

            
        }
        else
        {
            eventContainer.SettingModeEntryEvent = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::S);
            if (_event.type == sf::Event::JoystickButtonPressed)
            {

                if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::btA)
                {
                    eventContainer.ButtonStates[0] = true;
                    eventContainer.ButtonCountValues[0] = 1;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::btB)
                {
                    eventContainer.ButtonStates[1] = true;
                    eventContainer.ButtonCountValues[1] = 1;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::btC)
                {
                    eventContainer.ButtonStates[2] = true;
                    eventContainer.ButtonCountValues[2] = 1;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::btD)
                {
                    eventContainer.ButtonStates[3] = true;
                    eventContainer.ButtonCountValues[3] = 1;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::fxL)
                {
                    eventContainer.ButtonStates[4] = true;
                    eventContainer.ButtonCountValues[4] = 1;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::fxR)
                {
                    eventContainer.ButtonStates[5] = true;
                    eventContainer.ButtonCountValues[5] = 1;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::start)
                {
                    eventContainer.ButtonStates[6] = true;
                }
                continue;
            }

            if (_event.type == sf::Event::JoystickButtonReleased)
            {
                if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::btA)
                {
                    eventContainer.ButtonStates[0] = false;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::btB)
                {
                    eventContainer.ButtonStates[1] = false;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::btC)
                {
                    eventContainer.ButtonStates[2] = false;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::btD)
                {
                    eventContainer.ButtonStates[3] = false;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::fxL)
                {
                    eventContainer.ButtonStates[4] = false;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::fxR)
                {
                    eventContainer.ButtonStates[5] = false;
                }
                else if (_event.joystickButton.button == Containers::Joystick::Codes::Buttons::start)
                {
                    eventContainer.ButtonStates[6] = false;
                }
                continue;
            }
        }
    }
    eventContainer.KnobStates[0] = sf::Joystick::getAxisPosition(Containers::Joystick::Codes::Index::JoystickIndex, Containers::Joystick::Codes::Knobs::knobL) * _knobAngleCalibrationNum;
    eventContainer.KnobStates[1] = sf::Joystick::getAxisPosition(Containers::Joystick::Codes::Index::JoystickIndex, Containers::Joystick::Codes::Knobs::knobR) * _knobAngleCalibrationNum;
}