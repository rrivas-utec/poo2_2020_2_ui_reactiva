//
// Created by rudri on 12/16/2020.
//

#ifndef POO2_2020_2_UI_REACTIVA_BUTTON_H
#define POO2_2020_2_UI_REACTIVA_BUTTON_H

#include "component.h"

class button_t: public component_t {
    string title;
    sf::Color color = sf::Color::White;
    void click_pressed_event(mouse_event_params_t e) override;
    void click_released_event(mouse_event_params_t e) override;
    void mouse_move_event(mouse_event_params_t e) override;
    void mouse_enter_event(mouse_event_params_t e) override;
    void mouse_leave_event(mouse_event_params_t e) override;
    void draw() override;
public:
    button_t(string title, float left, float top, float width, float height):
            title{std::move(title)}, component_t(left, top, width, height) {}
};


#endif //POO2_2020_2_UI_REACTIVA_BUTTON_H
