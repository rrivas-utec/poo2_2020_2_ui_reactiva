//
// Created by rudri on 12/16/2020.
//

#include "button.h"

void button_t::click_pressed_event(mouse_event_params_t e) {
    if (click) click(e);
}

void button_t::click_released_event(mouse_event_params_t e) {
    if (click) click(e);
}

void button_t::mouse_move_event(mouse_event_params_t e) {
    if (mouse_move) mouse_move(e);
}

void button_t::mouse_enter_event(mouse_event_params_t e) {
    sf::Cursor crs;
    if (crs.loadFromSystem(sf::Cursor::Hand))
        window_ref->setMouseCursor(crs);
    color = sf::Color::Yellow;
}

void button_t::mouse_leave_event(mouse_event_params_t e) {
    sf::Cursor crs;
    if (crs.loadFromSystem(sf::Cursor::Arrow))
        window_ref->setMouseCursor(crs);
    color = sf::Color::White;
}

void button_t::draw() {
    // Crear el recuadro
    sf::RectangleShape shape;
    shape.setPosition(left, top);
    shape.setSize({width, height});
    shape.setFillColor(color);
    // Crear el texto
    sf::Font font;
    sf::Text txt;
    if (font.loadFromFile("./Oxanium-Regular.ttf"))
    {
        txt.setFont(font);
        txt.setFillColor(sf::Color::Blue);
        txt.setCharacterSize(20);
        txt.setString(title);
        txt.setPosition(left , top);
        // Para centrar el texto en el recuadro
        const auto bounds(txt.getLocalBounds());
        const auto box(shape.getSize());
        txt.setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);
    }
    window_ref->draw(shape);
    window_ref->draw(txt);
}
