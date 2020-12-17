//
// Created by rudri on 12/16/2020.
//

#ifndef POO2_2020_2_UI_REACTIVA_MY_APP_H
#define POO2_2020_2_UI_REACTIVA_MY_APP_H

#include "app.h"
#include "button.h"
#include "label.h"

class my_app: public app_t {
    shared_ptr<button_t> button_1;
    shared_ptr<button_t> button_2;
    shared_ptr<label_t> label_1;
public:
    my_app(int width, int height, const string &title): app_t(width, height, title) {
        // Create Components
        button_1 = make_shared<button_t>("Boton 1", 200, 100, 100, 40);
        button_2 = make_shared<button_t>("Boton 2", 200, 160, 100, 40);
        label_1 = make_shared<label_t>("Texto", 340, 135, 100, 40);
        // Asignar la accion
        button_1->click = [this](mouse_event_params_t e){ on_click_button_1(e); };
        button_2->click = [this](mouse_event_params_t e){ on_click_button_2(e); };
        // Atachar componentes a applicacion
        attach(button_1);
        attach(button_2);
        attach(label_1);
    }

    void on_click_button_1(mouse_event_params_t e) {
        label_1->set_caption("Boton 1");
    }

    void on_click_button_2(mouse_event_params_t e) {
        label_1->set_caption("Boton 2");
    }
};


#endif //POO2_2020_2_UI_REACTIVA_MY_APP_H
