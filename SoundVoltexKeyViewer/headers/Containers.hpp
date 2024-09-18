#ifndef CONTAINERS_HEADER_N
#define CONTAINERS_HEADER_N
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Joystick.hpp>
#include <iostream>
#include "..\headers\ErrorCode.hpp"

using vector2 = sf::Vector2<int>;

namespace Containers
{
    /*
    this namespace contains drawable objects(ex. sprite , text) and it's initializing function
    */
    namespace Sprites
    {
        struct IntrectValues
        {
             static const vector2   btOn            ,
                                    btOff           ,
                                    fxOn            ,
                                    fxOff           ,
                                    startOn         ,
                                    startOff        ,
                                    knobL           ,
                                    knobR           ,
                                    sizeBigSquare   ,//size section
                                    sizeRectangle   ,
                                    sizeSmallSquare ;
        };

        class DrawableObjects
        {
        private:
            sf::Texture _texture;
            sf::Font _font;
        public:
            
            sf::Sprite spritesArray[9];//0~3 => button 4=> fx_l 5=>fx_r 6 => start 7=> knob_l 8=>knob_r
            sf::Text textsArray[9];//0~1 => info text 2~8 => count 2~5 => bt 6~7 = fx 8 => total
            sf::Text nowSelectedKeyIndicator;
            

            /*
            initializing fuction of spritesArray and textsArray
            */
            int ContainerInitializer();
        };

        struct TextStrings
        {
            const static char indicatorTextsArray[10][10];
        };

        struct Colors
        {
            const static sf::Color flickingColors[2];
        };

    }
    
    namespace Joystick
    {
        namespace Codes
        {
            
            struct Buttons
            {
                static int  btA,
                            btB,
                            btC,
                            btD,
                            fxL,
                            fxR,
                            start;
            };

            struct Knobs
            {
                static sf::Joystick::Axis   knobL,
                                            knobR;
            };

            struct Index
            {
                static unsigned int JoystickIndex;
            };
        }

        struct Counting
        {
            unsigned int counts[6] = {0}; // 0~3 => bt 4~5 => fx
        };
    }

    namespace System
    {
        struct System
        {
            static int flickeringSpeed;
        };
    }
}

#endif // !CONTAINERS_HEADER_N