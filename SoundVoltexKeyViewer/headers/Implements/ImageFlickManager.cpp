#include "..\ImageFlickManager.hpp"

void ImageFlickManager::ResetImages(sf::Sprite spritesArray[], const int& count)
{
    for (int i = 0; i < count; i++)
    {
        _drawableObjectManager.SetSpriteColor(spritesArray[i], Containers::Sprites::Colors::flickingColors[1]);
    }
}

void ImageFlickManager::FlickImage(sf::Sprite spritesArray[], const int& index)
{
    _count++;
    if (_count >= Containers::System::System::flickeringSpeed)
    {
        _count = 0;
        
        if (_isChanged)
        {
            _isChanged = 0;
            _drawableObjectManager.SetSpriteColor(spritesArray[index], Containers::Sprites::Colors::flickingColors[_On]);
        }
        else
        {
            _isChanged = 1;
            _drawableObjectManager.SetSpriteColor(spritesArray[index], Containers::Sprites::Colors::flickingColors[_Off]);
        }
    }
}