// generated 2005/4/21 19:44:30 EDT by scott@Corwin.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to acovea-gtk.cc_new

// This file is for your program, I won't touch it again!

#include <config.h>
#include <glibmm/thread.h>
#include <gtkmm/main.h>

#include "main_window.hh"

int main(int argc, char **argv)
{  
    Glib::thread_init();
    
    Gtk::Main m(&argc, &argv);

    main_window * main_window = new class main_window();
    m.run(*main_window);

    delete main_window;
    
    return 0;
}
