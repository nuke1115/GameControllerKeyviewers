#include "..\Application.hpp"

Application::Application(int width, int height)
{
    _windowManager.CreateWindow(width, height, _window);
}

Application::~Application()
{
    inicpp::IniManager _ini(_iniFilePath);
    _ini.modify("BUTTONS", "BT_A", Containers::Joystick::Codes::Buttons::btA);
    _ini.modify("BUTTONS", "BT_B", Containers::Joystick::Codes::Buttons::btB);
    _ini.modify("BUTTONS", "BT_C", Containers::Joystick::Codes::Buttons::btC);
    _ini.modify("BUTTONS", "BT_D", Containers::Joystick::Codes::Buttons::btD);
    _ini.modify("BUTTONS", "FX_L", Containers::Joystick::Codes::Buttons::fxL);
    _ini.modify("BUTTONS", "FX_R", Containers::Joystick::Codes::Buttons::fxR);
    _ini.modify("BUTTONS", "START", Containers::Joystick::Codes::Buttons::start);
    _ini.modify("KNOBS", "KNOB_L", GetKnobStringCodes(Containers::Joystick::Codes::Knobs::knobL));
    _ini.modify("KNOBS", "KNOB_R", GetKnobStringCodes(Containers::Joystick::Codes::Knobs::knobR));
}

std::string Application::GetKnobStringCodes(const sf::Joystick::Axis& key)
{
    switch (key)
    {
    case sf::Joystick::Axis::X:
        return "X";
    case sf::Joystick::Axis::Y:
        return "Y";
    case sf::Joystick::Axis::Z:
        return "Z";
    case sf::Joystick::Axis::R:
        return "R";
    case sf::Joystick::Axis::U:
        return "U";
    case sf::Joystick::Axis::V:
        return "V";
    case sf::Joystick::Axis::PovX:
        return "PovX";
    case sf::Joystick::Axis::PovY:
        return "PovY";
    default:
        return "X";
    }

}

sf::Joystick::Axis Application::GetKnobValues(const std::string& key)
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

    return sf::Joystick::Axis::X;//default
}

bool Application::CheckController()
{
    return sf::Joystick::isConnected(Containers::Joystick::Codes::Index::JoystickIndex);
}

int Application::Initialize()
{
    inicpp::IniManager _ini(_iniFilePath);

    _windowManager.SetWindowName(_ini["WINDOW"].toString("WINDOW_NAME"), _window);

    Containers::Joystick::Codes::Buttons::btA = _ini["BUTTONS"].toInt("BT_A");
    Containers::Joystick::Codes::Buttons::btB = _ini["BUTTONS"].toInt("BT_B");
    Containers::Joystick::Codes::Buttons::btC = _ini["BUTTONS"].toInt("BT_C");
    Containers::Joystick::Codes::Buttons::btD = _ini["BUTTONS"].toInt("BT_D");
    Containers::Joystick::Codes::Buttons::fxL = _ini["BUTTONS"].toInt("FX_L");
    Containers::Joystick::Codes::Buttons::fxR = _ini["BUTTONS"].toInt("FX_R");
    Containers::Joystick::Codes::Buttons::start = _ini["BUTTONS"].toInt("START");

    Containers::Joystick::Codes::Knobs::knobL = GetKnobValues(_ini["KNOBS"].toString("KNOB_L"));
    Containers::Joystick::Codes::Knobs::knobR = GetKnobValues(_ini["KNOBS"].toString("KNOB_R"));

    Containers::Joystick::Codes::Index::JoystickIndex = _ini["CONTROLLER"].toInt("CONTROLLER_INDEX");

    Containers::System::System::flickeringSpeed = _ini["SYSTEM"].toInt("FLICKERING_SPEED");

    return _drawableObjects.ContainerInitializer();
}

void Application::Run()
{
    while (_window.isOpen())
    {
        _eventDetector.DetectEvents(_appEvent, _window);
        _eventHandler.HandleEvents(_appEvent, _drawableObjects, _window);
        _windowManager.RenderToWindow(_drawableObjects.spritesArray, _drawableObjects.textsArray, _window, _appEvent);
    }
}