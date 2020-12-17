//
// Created by rudri on 12/16/2020.
//

#include "app.h"

void app_t::run() {
    while (window.isOpen())
    {
        // Posiciones anteriores del mouse
        float prior_x = 0;
        float prior_y = 0;
        float actual_x = 0;
        float actual_y = 0;

        sf::Event event{};
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    for (auto& c: components)
                        c->keypress_event({static_cast<char>('A' + event.key.code)});
                    break;
                case sf::Event::MouseMoved:
                    actual_x = static_cast<float>(event.mouseMove.x);
                    actual_y = static_cast<float>(event.mouseMove.y);
                    for (auto& c: components) {
                        if (c->is_on_bound(static_cast<float>(event.mouseMove.x),
                                           static_cast<float>(event.mouseMove.y)))
                            c->mouse_enter_event({static_cast<float>(event.mouseMove.x),
                                                  static_cast<float>(event.mouseMove.y)});
                        else if (c->is_on_bound(prior_x, prior_y))
                            c->mouse_leave_event({static_cast<float>(event.mouseMove.x),
                                                  static_cast<float>(event.mouseMove.y)});
                    }
                    prior_x = static_cast<float>(event.mouseMove.x);
                    prior_y = static_cast<float>(event.mouseMove.y);
                    break;
                case sf::Event::MouseButtonPressed:
                    for (auto& c: components)
                        if (c->is_on_bound(prior_x, prior_y))
                            c->click_pressed_event({prior_x, prior_y});
                    break;
                case sf::Event::MouseButtonReleased:
                    for (auto& c: components)
                        if (c->is_on_bound(prior_x, prior_y))
                            c->click_released_event({prior_x, prior_y});
                    break;
                default:
                    break;
            }
        }

        window.clear(sf::Color::Blue);
        for (auto& c: components)
            c->draw();
        window.display();
    }
}

void app_t::attach(const shared_ptr<component_t> &c) {
    c->window_ref = &window;
    components.push_back(c);
}
