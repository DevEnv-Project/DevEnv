#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include "DevEnvUI.h"

int main(int argc, char* argv[])
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("org.wtdawson.devenv_ui");


    return 0;
}