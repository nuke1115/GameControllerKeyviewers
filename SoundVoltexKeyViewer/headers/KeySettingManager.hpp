#ifndef KEY_SETTING_MANAGER_HEADER_N
#define KEY_SETTING_MANAGER_HEADER_N
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Joystick.hpp>
#include <string>
#include "..\headers\AppEvent.hpp"
#include "..\headers\DrawableObjectManager.hpp"
#include "..\headers\ImageFlickManager.hpp"
#include "..\headers\Containers.hpp"

class KeySettingManager
{
private:
    DrawableObjectManager _drawableObjectManager;
    ImageFlickManager _imageFlickManager;
    int _index = 1;
public:
    void SetKeyConfig(Containers::AppEvent& appEvent, Containers::Sprites::DrawableObjects& drawableObjects);
};

#endif // !KEY_SETTING_MANAGER_HEADER_N