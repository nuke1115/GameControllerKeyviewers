#ifndef IMAGE_FLICK_MANAGER_HEADER_N
#define IMAGE_FLICK_MANAGER_HEADER_N
#include <SFML/Graphics/Sprite.hpp>
#include "..\headers\Containers.hpp"
#include "..\headers\DrawableObjectManager.hpp"

class ImageFlickManager
{
private:
    const int _On = 1, _Off = 0;
    int _isChanged = 0;
    int _count = 0;
    DrawableObjectManager _drawableObjectManager;
public:
    void ResetImages(sf::Sprite spritesArray[],const int& count);
    void FlickImage(sf::Sprite spritesArray[],const int& index);
};

#endif // !IMAGE_FLICK_MANAGER_HEADER_N