//
// Created by rudri on 12/16/2020.
//

#ifndef POO2_2020_2_UI_REACTIVA_APP_H
#define POO2_2020_2_UI_REACTIVA_APP_H

#include <vector>
#include "component.h"

using namespace std;

class app_t {
    vector<shared_ptr<component_t>> components;
    sf::RenderWindow window;
public:
    app_t(int width, int height, const string& title):
        window(sf::VideoMode(width, height), title) {}
    void run();
    void attach(const shared_ptr<component_t>& c);
};


#endif //POO2_2020_2_UI_REACTIVA_APP_H
