#ifndef KEY_SETTING_MANAGER_N_HEADER
#define KEY_SETTING_MANAGER_N_HEADER
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Joystick.hpp>
#include "..\headers\AppEvent.hpp"
#include "..\headers\DrawableObjectManager.hpp"
#include "..\headers\Containers.hpp"
#include <string>


class KeySettingManager
{
private:
    int _index = 1;
    int _counter = 0;
    bool _isColorChanged = false;
    sf::Joystick::Axis getAxisCode(unsigned int key);
    sf::Color _spriteColor;
    void FlickImage(Containers::Sprites::DrawableObjects& drawableObjects, DrawableObjectManager& drawableObjectManager); //index가 범위 안에 있는동안 반복하고, 범위를 벗어나면, 다시 모든 이미지를 원래대로 돌리고, 종료
public:
    void SetKeyConfig(Containers::AppEvent& appEvent, DrawableObjectManager& drawableObjectManager, Containers::Sprites::DrawableObjects& drawableObjects);
};


#endif // !KEY_SETTING_MANAGER_N_HEADER
