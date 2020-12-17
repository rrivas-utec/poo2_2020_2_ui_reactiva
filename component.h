//
// Created by rudri on 12/16/2020.
//

#ifndef POO2_2020_2_UI_REACTIVA_COMPONENT_H
#define POO2_2020_2_UI_REACTIVA_COMPONENT_H

#include <functional>
#include "SFML/Graphics.hpp"

using namespace std;

struct mouse_event_params_t {
    float x;
    float y;
    mouse_event_params_t(float x, float y): x{x}, y{y} {}
};

struct keypress_event_params_t {
    char key_char;
    keypress_event_params_t(char key_char): key_char{key_char} {}
};

class component_t {
protected:
    float left = 0;
    float top = 0;
    float width = 0;
    float height = 0;
    sf::RenderWindow* window_ref = nullptr;
    virtual void click_pressed_event(mouse_event_params_t e) {}
    virtual void click_released_event(mouse_event_params_t e) {}
    virtual void mouse_move_event(mouse_event_params_t e) {}
    virtual void mouse_enter_event(mouse_event_params_t e) {}
    virtual void mouse_leave_event(mouse_event_params_t e) {}
    virtual void keypress_event(keypress_event_params_t e) {}
    virtual void draw() = 0;
    bool is_on_bound(float x, float y) const {
       return (x > left && x < left + width) && (y > top && y < top + height);
    }
    friend class app_t;
public:
    // Constructor y Destructor
    component_t(float left, float top, float width, float height):
        left{left}, top{top}, width{width}, height{height} {}
    virtual ~component_t() = default;

    // Callables
    function<void(mouse_event_params_t)> click;
    function<void(mouse_event_params_t)> mouse_move;
    function<void(keypress_event_params_t)> key_press;
};


#endif //POO2_2020_2_UI_REACTIVA_COMPONENT_H
