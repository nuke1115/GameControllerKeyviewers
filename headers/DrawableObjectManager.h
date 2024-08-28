#ifndef DRAWABLE_OBJECT_MANAGER_HEADER_N
#define DRAWABLE_OBJECT_MANAGER_HEADER_N
#include "..\headers\Containers.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
class DrawableObjectManager
{
private:
	Containers::Sprites::IntrectValues intrectValues;

	const sf::IntRect	btA[2] = { sf::IntRect(Containers::Sprites::IntrectValues::btOff, Containers::Sprites::IntrectValues::sizeBigSquare),sf::IntRect(Containers::Sprites::IntrectValues::btOn, Containers::Sprites::IntrectValues::sizeBigSquare) },

						btB[2] = { sf::IntRect(Containers::Sprites::IntrectValues::btOff, Containers::Sprites::IntrectValues::sizeBigSquare),sf::IntRect(Containers::Sprites::IntrectValues::btOn, Containers::Sprites::IntrectValues::sizeBigSquare) },

						btC[2] = { sf::IntRect(Containers::Sprites::IntrectValues::btOff, Containers::Sprites::IntrectValues::sizeBigSquare), sf::IntRect(Containers::Sprites::IntrectValues::btOn, Containers::Sprites::IntrectValues::sizeBigSquare) },

						btD[2] = { sf::IntRect(Containers::Sprites::IntrectValues::btOff, Containers::Sprites::IntrectValues::sizeBigSquare), sf::IntRect(Containers::Sprites::IntrectValues::btOn, Containers::Sprites::IntrectValues::sizeBigSquare) },

						fxL[2] = { sf::IntRect(Containers::Sprites::IntrectValues::fxOff , Containers::Sprites::IntrectValues::sizeRectangle),sf::IntRect(Containers::Sprites::IntrectValues::fxOn , Containers::Sprites::IntrectValues::sizeRectangle) },

						fxR[2] = { sf::IntRect(Containers::Sprites::IntrectValues::fxOff, Containers::Sprites::IntrectValues::sizeRectangle), sf::IntRect(Containers::Sprites::IntrectValues::fxOn, Containers::Sprites::IntrectValues::sizeRectangle) },

						start[2] = { sf::IntRect(Containers::Sprites::IntrectValues::startOff, Containers::Sprites::IntrectValues::sizeSmallSquare), sf::IntRect(Containers::Sprites::IntrectValues::startOn, Containers::Sprites::IntrectValues::sizeSmallSquare) };
public:
	inline void ChangeSpriteTexture(sf::Sprite spritesArray[] , bool buttonStates[] , float knobStates[])
	{
		spritesArray[0].setTextureRect(btA[buttonStates[0]]);
		spritesArray[1].setTextureRect(btB[buttonStates[1]]);
		spritesArray[2].setTextureRect(btC[buttonStates[2]]);
		spritesArray[3].setTextureRect(btD[buttonStates[3]]);

		spritesArray[4].setTextureRect(fxL[buttonStates[4]]);
		spritesArray[5].setTextureRect(fxR[buttonStates[5]]);

		spritesArray[6].setTextureRect(start[buttonStates[6]]);

		spritesArray[7].setRotation(knobStates[0]);
		spritesArray[8].setRotation(knobStates[1]);
	}

	inline void ChangeText(sf::Text textsArray[] , unsigned int counts[], unsigned long long totalClickCnt)
	{
		for (int i = 2; i < 8; i++)
		{
			textsArray[i].setString(std::to_string(counts[i - 2]));
		}
		textsArray[8].setString(std::to_string(totalClickCnt));
	}
};

#endif // !DRAWABLE_OBJECT_MANAGER_HEADER_N
