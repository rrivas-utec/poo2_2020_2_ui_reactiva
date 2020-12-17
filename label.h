//
// Created by rudri on 12/16/2020.
//

#ifndef POO2_2020_2_UI_REACTIVA_LABEL_H
#define POO2_2020_2_UI_REACTIVA_LABEL_H

#include "component.h"

class label_t: public component_t {
    string caption;
    sf::Color color = sf::Color::Yellow;
    void draw() override {
        sf::Font font;
        sf::Text txt;
        if (font.loadFromFile("./Oxanium-Regular.ttf"))
        {
            txt.setFont(font);
            txt.setFillColor(color);
            txt.setCharacterSize(20);
            txt.setString(caption);
            txt.setPosition(left , top);
        }
        window_ref->draw(txt);
    }

public:
    label_t(string caption, float left, float top, float width, float height):
            caption{std::move(caption)}, component_t(left, top, width, height) {}

    void set_caption(const string& value) { caption = value; }
};


#endif //POO2_2020_2_UI_REACTIVA_LABEL_H
