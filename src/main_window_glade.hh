// generated 2005/4/25 13:00:34 EDT by scott@Corwin.(none)
// using glademm V2.6.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/scott/projects/acovea-gtk/acovea-gtk.glade
// for gtk 2.4.14 and gtkmm 2.4.8
//
// Please modify the corresponding derived classes in ./src/main_window.hh and./src/main_window.cc

#ifndef _MAIN_WINDOW_GLADE_HH
#  define _MAIN_WINDOW_GLADE_HH

// Since all your widgets were private I made them all public.
// To differentiate between accessable (e.g. entries, output labels)
// and unaccessible widgets (e.g. static labels, containers)
// you should use the 'visibility' property (only visible in C++ mode)


#if !defined(GLADEMM_DATA)
#define GLADEMM_DATA 
#include <gtkmm/accelgroup.h>

class GlademmData
{  
        
        Glib::RefPtr<Gtk::AccelGroup> accgrp;
public:
        
        GlademmData(Glib::RefPtr<Gtk::AccelGroup> ag) : accgrp(ag)
        {  
        }
        
        Glib::RefPtr<Gtk::AccelGroup>  getAccelGroup()
        {  return accgrp;
        }
};
#endif //GLADEMM_DATA

#include <gtkmm/window.h>
#include <gtkmm/tooltips.h>
#include <gtkmm/image.h>
#include <gtkmm/imagemenuitem.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/menu.h>
#include <gtkmm/menubar.h>
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#include <gtkmm/toolbutton.h>
#else //
#include <gtkmm/button.h>
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
#include <gtkmm/separatortoolitem.h>
#endif //
#include <gtkmm/toolbar.h>
#include <gtkmm/box.h>
#include <gtkmm/label.h>
#include <gtkmm/progressbar.h>
#include <gtkmm/textview.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/statusbar.h>

class main_window_glade : public Gtk::Window
{  
        
        GlademmData *gmm_data;
public:
        Gtk::Tooltips _tooltips;
        class Gtk::Window * main_window;
        class Gtk::Image * image28;
        class Gtk::ImageMenuItem * menu_set_run_options;
        class Gtk::MenuItem * separator6;
        class Gtk::MenuItem * menu_save_options_default;
        class Gtk::MenuItem * menu_load_default_options;
        class Gtk::MenuItem * separator5;
        class Gtk::MenuItem * menu_save_options;
        class Gtk::MenuItem * save_load_options;
        class Gtk::MenuItem * separator7;
        class Gtk::MenuItem * menu_quit;
        class Gtk::Menu * menuitem2_menu;
        class Gtk::MenuItem * menuitem2;
        class Gtk::Image * image29;
        class Gtk::ImageMenuItem * menu_run;
        class Gtk::Image * image30;
        class Gtk::ImageMenuItem * menu_stop;
        class Gtk::MenuItem * separator8;
        class Gtk::MenuItem * menu_save_output;
        class Gtk::Menu * menuitem3_menu;
        class Gtk::MenuItem * menuitem3;
        class Gtk::MenuItem * menu_about;
        class Gtk::Menu * menuitem4_menu;
        class Gtk::MenuItem * menuitem4;
        class Gtk::MenuBar * menubar1;
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::ToolButton * toolbar_settings_button;
#else //
        class Gtk::Button * toolbar_settings_button;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::SeparatorToolItem * separatortoolitem1;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::ToolButton * toolbar_run_button;
#else //
        class Gtk::Button * toolbar_run_button;
#endif //
#if GTKMM_MAJOR_VERSION==2 && GTKMM_MINOR_VERSION>2
        class Gtk::ToolButton * toolbar_stop_button;
#else //
        class Gtk::Button * toolbar_stop_button;
#endif //
        class Gtk::Toolbar * toolbar1;
        class Gtk::VBox * vbox13;
        class Gtk::VBox * vbox2;
        class Gtk::Label * label35;
        class Gtk::Label * label36;
        class Gtk::ProgressBar * main_generation_progressbar;
        class Gtk::Label * label37;
        class Gtk::ProgressBar * main_population_progressbar;
        class Gtk::Label * label38;
        class Gtk::ProgressBar * main_testing_progressbar;
        class Gtk::Label * main_whatsup;
        class Gtk::Image * main_logo_icon;
        class Gtk::VBox * vbox20;
        class Gtk::Label * label34;
        class Gtk::TextView * main_window_output;
        class Gtk::ScrolledWindow * scrolledwindow2;
        class Gtk::VBox * vbox19;
        class Gtk::HBox * hbox12;
        class Gtk::Statusbar * main_status;
        class Gtk::VBox * vbox1;
protected:
        
        main_window_glade();
        
        ~main_window_glade();
private:
        virtual void on_menu_set_run_options_activate() = 0;
        virtual void on_menu_save_options_default_activate() = 0;
        virtual void on_menu_load_default_options_activate() = 0;
        virtual void on_menu_save_options_activate() = 0;
        virtual void on_load_options_activate() = 0;
        virtual void on_menu_quit_activate() = 0;
        virtual void on_menu_run_activate() = 0;
        virtual void on_menu_stop_activate() = 0;
        virtual void on_menu_save_output_activate() = 0;
        virtual void on_about1_activate() = 0;
        virtual void on_toolbar_settings_button_clicked() = 0;
        virtual void on_toolbar_run_button_clicked() = 0;
        virtual void on_toolbar_stop_button_clicked() = 0;
};
#endif