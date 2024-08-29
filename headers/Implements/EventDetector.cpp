#ifndef EVENT_DETECTOR_IMPLEMENT_N
#define EVENT_DETECTOR_IMPLEMENT_N
#include "..\EventDetector.hpp"

void EventDetector::DetectEvents(Containers::AppEvent& eventContainer, sf::RenderWindow& window)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            eventContainer.TerminateEvent = true;
            break;
        }

        if (event.type == sf::Event::JoystickButtonPressed)
        {
            if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::btA)
            {
                eventContainer.ButtonStates[0] = true;
                eventContainer.ButtonCountValues[0] = 1;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::btB)
            {
                eventContainer.ButtonStates[1] = true;
                eventContainer.ButtonCountValues[1] = 1;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::btC)
            {
                eventContainer.ButtonStates[2] = true;
                eventContainer.ButtonCountValues[2] = 1;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::btD)
            {
                eventContainer.ButtonStates[3] = true;
                eventContainer.ButtonCountValues[3] = 1;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::fxL)
            {
                eventContainer.ButtonStates[4] = true;
                eventContainer.ButtonCountValues[4] = 1;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::fxR)
            {
                eventContainer.ButtonStates[5] = true;
                eventContainer.ButtonCountValues[5] = 1;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::start)
            {
                eventContainer.ButtonStates[6] = true;
            }
            continue;
        }

        if (event.type == sf::Event::JoystickButtonReleased)
        {
            if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::btA)
            {
                eventContainer.ButtonStates[0] = false;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::btB)
            {
                eventContainer.ButtonStates[1] = false;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::btC)
            {
                eventContainer.ButtonStates[2] = false;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::btD)
            {
                eventContainer.ButtonStates[3] = false;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::fxL)
            {
                eventContainer.ButtonStates[4] = false;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::fxR)
            {
                eventContainer.ButtonStates[5] = false;
            }
            else if (event.joystickButton.button == Containers::Joystick::Codes::Buttons::start)
            {
                eventContainer.ButtonStates[6] = false;
            }
            continue;
        }
    }

    eventContainer.KnobStates[0] = sf::Joystick::getAxisPosition(Containers::Joystick::Codes::Index::JoystickIndex, Containers::Joystick::Codes::Knobs::knobL) * knobAngleCalibrationNum;
    eventContainer.KnobStates[1] = sf::Joystick::getAxisPosition(Containers::Joystick::Codes::Index::JoystickIndex, Containers::Joystick::Codes::Knobs::knobR) * knobAngleCalibrationNum;
}

#endif // !EVENT_DETECTOR_IMPLEMENT_N