#include <gtkmm/application.h>
#include <gtkmm/window.h>
#include <DevEnvUI.h>
#include <devenv_utils.h>

int main(int argc, char* argv[])
{
	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("org.wtdawson.devenv_ui");

    MainWindow window;
    window.show();

    app->make_window_and_run<MainWindow>(argc, argv);
    return 0;
}