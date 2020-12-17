//
// Created by rudri on 12/16/2020.
//

#ifndef POO2_2020_2_UI_REACTIVA_MY_APP_H
#define POO2_2020_2_UI_REACTIVA_MY_APP_H

#include "app.h"
#include "button.h"

class my_app: public app_t {
    shared_ptr<button_t> button_1;
    shared_ptr<button_t> button_2;
public:
    my_app(int width, int height, const string &title): app_t(width, height, title) {
        // Create Components
        button_1 = make_shared<button_t>("Boton 1", 200, 100, 100, 40);
        button_2 = make_shared<button_t>("Boton 2", 200, 160, 100, 40);

        // Atachar componentes a applicacion
        attach(button_1);
        attach(button_2);
    }
};


#endif //POO2_2020_2_UI_REACTIVA_MY_APP_H
