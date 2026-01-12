#pragma once

#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <gtkmm/grid.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow() {
        set_title("DevEnv");
        set_default_size(600, 450);
    }
    ~MainWindow() {

    }

private:
    Gtk::Grid grid;
};