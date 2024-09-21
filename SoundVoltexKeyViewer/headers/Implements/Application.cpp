#include "..\Application.hpp"

Application::Application(int width, int height)
{
    _windowManager.CreateWindow(width, height, _window);
    _bidirectionalMap.SetValue("X", sf::Joystick::Axis::X);
    _bidirectionalMap.SetValue("Y", sf::Joystick::Axis::Y);
    _bidirectionalMap.SetValue("Z", sf::Joystick::Axis::Z);
    _bidirectionalMap.SetValue("R", sf::Joystick::Axis::R);
    _bidirectionalMap.SetValue("U", sf::Joystick::Axis::U);
    _bidirectionalMap.SetValue("V", sf::Joystick::Axis::V);
    _bidirectionalMap.SetValue("PovX", sf::Joystick::Axis::PovX);
    _bidirectionalMap.SetValue("PovY", sf::Joystick::Axis::PovY);
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
    _ini.modify("KNOBS", "KNOB_L", _bidirectionalMap.GetKey(Containers::Joystick::Codes::Knobs::knobL));
    _ini.modify("KNOBS", "KNOB_R", _bidirectionalMap.GetKey(Containers::Joystick::Codes::Knobs::knobR));
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

    Containers::Joystick::Codes::Knobs::knobL = _bidirectionalMap.GetValue(_ini["KNOBS"].toString("KNOB_L"));
    Containers::Joystick::Codes::Knobs::knobR = _bidirectionalMap.GetValue(_ini["KNOBS"].toString("KNOB_R"));

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