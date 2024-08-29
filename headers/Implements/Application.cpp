#ifndef APPLICATION_IMPLEMENT_N
#define APPLICATION_IMPLEMENT_N
#include "..\Application.hpp"

Application::Application(int width, int height, std::string WindowName)
{
    windowManager.CreateWindow(width, height, WindowName,window);
}

sf::Joystick::Axis GetKnobValues(const std::string& key)
{
    if (!key.compare("X"))
    {
        return sf::Joystick::Axis::X;
    }
    else if (!key.compare("Y"))
    {
        return sf::Joystick::Axis::Y;
    }
    else if (!key.compare("Z"))
    {
        return sf::Joystick::Axis::Z;
    }
    else if (!key.compare("R"))
    {
        return sf::Joystick::Axis::R;
    }
    else if (!key.compare("U"))
    {
        return sf::Joystick::Axis::U;
    }
    else if (!key.compare("V"))
    {
        return sf::Joystick::Axis::V;
    }
    else if (!key.compare("PovX"))
    {
        return sf::Joystick::Axis::PovX;
    }
    else if (!key.compare("PovY"))
    {
        return sf::Joystick::Axis::PovY;
    }

}

bool Application::CheckController()
{
    return sf::Joystick::isConnected(Containers::Joystick::Codes::Index::JoystickIndex);
}

int Application::Initialize()
{
    inicpp::IniManager _ini("assets\\settings\\Settings.ini");

    Containers::Joystick::Codes::Buttons::btA = _ini["BUTTONS"].toInt("BT_A");
    Containers::Joystick::Codes::Buttons::btB = _ini["BUTTONS"].toInt("BT_B");
    Containers::Joystick::Codes::Buttons::btC = _ini["BUTTONS"].toInt("BT_C");
    Containers::Joystick::Codes::Buttons::btD = _ini["BUTTONS"].toInt("BT_D");
    Containers::Joystick::Codes::Buttons::fxL = _ini["BUTTONS"].toInt("FX_L");
    Containers::Joystick::Codes::Buttons::fxR = _ini["BUTTONS"].toInt("FX_R");

    Containers::Joystick::Codes::Knobs::knobL = GetKnobValues(_ini["KNOBS"].toString("KNOB_L"));
    Containers::Joystick::Codes::Knobs::knobR = GetKnobValues(_ini["KNOBS"].toString("KNOB_R"));

    Containers::Joystick::Codes::Index::JoystickIndex = _ini["CONTROLLER"].toInt("CONTROLLER_INDEX");
    return drawableObjects.ContainerInitializer();
}

void Application::Run()
{
    while (window.isOpen())
    {
        
        eventDetector.DetectEvents(appEvent, window);
        eventHandler.HandleEvents(appEvent, drawableObjects, window);
        windowManager.RenderToWindow(drawableObjects.spritesArray, drawableObjects.textsArray, window);
    }
}

#endif // !APPLICATION_IMPLEMENT_N