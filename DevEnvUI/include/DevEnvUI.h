#pragma once

#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/window.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow() {
        set_title("DevEnvUI");
        set_default_size(600, 450);
    }
    ~MainWindow() {

    }
};