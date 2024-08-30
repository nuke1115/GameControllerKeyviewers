#ifndef ALERT_IMPLEMENT_N
#define ALERT_IMPLEMENT_N
#include "..\Alert.h"
void Alert::ShowAlert(int code)
{
    sf::RenderWindow window(sf::VideoMode(500,250),"error");
    sf::Event event;

    sf::Font font;
    font.loadFromFile("./SoundVoltexKeyViewer/assets/font/KCC-Hanbit.ttf");
    sf::Text text;
    text.setCharacterSize(20);
    text.setFont(font);
    
    if (code == ErrorCode::ERR_IN_LOAD_FILE)
    {
        text.setString("ERR IN LOAD FILE");
    }
    else if (code == ErrorCode::ERR_IN_CONTROLLER_CONNECTION)
    {
        text.setString("ERR IN CONTROLLER CONNECTION");
    }

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(text);
        window.display();
    }
}

#endif // !ALERT_IMPLEMENT_N
