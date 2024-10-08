#include "..\Containers.hpp"

const vector2   Containers::Sprites::IntrectValues::btOn            ={ 0  , 0 },
                Containers::Sprites::IntrectValues::btOff           ={ 100, 0 },
                Containers::Sprites::IntrectValues::fxOn            ={ 0  , 100 },
                Containers::Sprites::IntrectValues::fxOff           ={ 100, 100 },
                Containers::Sprites::IntrectValues::startOn         ={ 0  , 200 },
                Containers::Sprites::IntrectValues::startOff        ={ 100, 200 },
                Containers::Sprites::IntrectValues::knobL           ={ 0  , 300 },
                Containers::Sprites::IntrectValues::knobR           ={ 100, 300 },
                Containers::Sprites::IntrectValues::sizeBigSquare   ={ 100, 100 },
                Containers::Sprites::IntrectValues::sizeSmallSquare ={ 75 , 75 },
                Containers::Sprites::IntrectValues::sizeRectangle   ={ 100, 50 };

const char Containers::Sprites::TextStrings::indicatorTextsArray[10][10] = { "btA","btB","btC","btD","fxL","fxR","start","knobL","knobR","" };

const sf::Color Containers::Sprites::Colors::flickingColors[2] = { sf::Color::Color(255,255,255,0),sf::Color::Color(255,255,255,255) };

/*
initializing fuction of spritesArray and textsArray
*/
int Containers::Sprites::DrawableObjects::ContainerInitializer()
{

    if (!_font.loadFromFile(_ttfFilePath))
    {
        return ERR_IN_LOAD_FILE;
    }

    if (!_texture.loadFromFile(_imgFilePath))
    {
        return ERR_IN_LOAD_FILE;
    }

    for (int i = 0; i < 9; i++)
    {
        spritesArray[i].setTexture(_texture);
    }

    for (int i = 0; i < 10; i++)
    {
        textsArray[i].setFont(_font);
    }




#pragma region Text
    textsArray[0].setString("btA: \nbtB: \nbtC: \nbtD: \nfxL: \nfxR: ");
    textsArray[1].setString("TOTAL");
    for (int i = 0; i < 9; i++)
    {
        textsArray[i].setCharacterSize(24);
    }
    for (int i = 2, ypos = 250; i < 9; i++, ypos += 28)
    {
        textsArray[i].setString("0");
        textsArray[i].setPosition(65, ypos);
    }
    textsArray[8].setPosition(400,450);

    textsArray[0].setPosition(10, 250);
    textsArray[1].setPosition(455, 410);

    textsArray[9].setPosition(480,50);
    textsArray[9].setString("");

#pragma endregion


#pragma region SpriteInitialize

    for (int i = 0, xpos = 250; i < 4; i++, xpos += 120)
    {
        spritesArray[i].setTextureRect(sf::IntRect(IntrectValues::btOff, IntrectValues::sizeBigSquare));
        spritesArray[i].setPosition(xpos, 260);
    }

    spritesArray[4].setTextureRect(sf::IntRect(IntrectValues::fxOff, IntrectValues::sizeRectangle));
    spritesArray[5].setTextureRect(sf::IntRect(IntrectValues::fxOff, IntrectValues::sizeRectangle));

    spritesArray[6].setTextureRect(sf::IntRect(IntrectValues::startOff, IntrectValues::sizeSmallSquare));

    spritesArray[7].setTextureRect(sf::IntRect(IntrectValues::knobL, IntrectValues::sizeBigSquare));
    spritesArray[8].setTextureRect(sf::IntRect(IntrectValues::knobR, IntrectValues::sizeBigSquare));


    spritesArray[4].setPosition(300, 395);
    spritesArray[5].setPosition(540, 395);

    spritesArray[6].setPosition(445, 95);

    spritesArray[7].setPosition(180+50, 120);
    spritesArray[8].setPosition(680+50, 120);

    spritesArray[7].setOrigin(50, 50);
    spritesArray[8].setOrigin(50, 50);

#pragma endregion

    return 0;
}

//initial value
int Containers::Joystick::Codes::Buttons::btA = 0,
    Containers::Joystick::Codes::Buttons::btB = 1,
    Containers::Joystick::Codes::Buttons::btC = 2,
    Containers::Joystick::Codes::Buttons::btD = 3,
    Containers::Joystick::Codes::Buttons::fxL = 4,
    Containers::Joystick::Codes::Buttons::fxR = 5,
    Containers::Joystick::Codes::Buttons::start = 8;

sf::Joystick::Axis  Containers::Joystick::Codes::Knobs::knobL = sf::Joystick::Axis::X,
                    Containers::Joystick::Codes::Knobs::knobR = sf::Joystick::Axis::Y;

int Containers::System::System::flickeringSpeed = 1000;

unsigned int Containers::Joystick::Codes::Index::JoystickIndex = 0;