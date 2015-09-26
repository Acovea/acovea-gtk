// generated 2005/4/24 15:46:13 EDT by scott@Corwin.(none)
// using glademm V2.6.0
//
// DO NOT EDIT THIS FILE ! It was created using
// glade-- /home/scott/projects/acovea-gtk/acovea-gtk.glade
// for gtk 2.4.14 and gtkmm 2.4.8
//
// Please modify the corresponding derived classes in ./src/settings_window.hh and./src/settings_window.cc

#ifndef _SETTINGS_WINDOW_GLADE_HH
#  define _SETTINGS_WINDOW_GLADE_HH


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
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/table.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/alignment.h>
#include <gtkmm/frame.h>
#include <gtkmm/checkbutton.h>
#include <gtkmm/box.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/separator.h>
#include <gtkmm/buttonbox.h>

class settings_window_glade : public Gtk::Window
{  
        
        GlademmData *gmm_data;
public:
        class Gtk::Window * settings_window;
        class Gtk::Button * settings_benchmark_browse_button;
        class Gtk::Entry * settings_benchmark_entry;
        class Gtk::Label * label10;
        class Gtk::Label * label41;
        class Gtk::Entry * settings_config_entry;
        class Gtk::Button * settings_config_browse_button;
        class Gtk::Table * table3;
        class Gtk::Label * label11;
        class Gtk::Label * label12;
        class Gtk::Label * label13;
        class Gtk::Entry * settings_num_pops_entry;
        class Gtk::Entry * settings_pop_size_entry;
        class Gtk::Entry * settings_num_runs_entry;
        class Gtk::Label * label14;
        class Gtk::Label * label15;
        class Gtk::Label * label16;
        class Gtk::Label * label17;
        class Gtk::SpinButton * settings_srate_spin;
        class Gtk::SpinButton * settings_mrate_spin;
        class Gtk::SpinButton * settings_crate_spin;
        class Gtk::SpinButton * settings_irate_spin;
        class Gtk::Table * table2;
        class Gtk::Alignment * alignment6;
        class Gtk::Label * label32;
        class Gtk::Frame * frame6;
        class Gtk::CheckButton * settings_scaling_check;
        class Gtk::Alignment * alignment8;
        class Gtk::Label * label40;
        class Gtk::Frame * frame8;
        class Gtk::CheckButton * settings_seed_check;
        class Gtk::Entry * settings_seed_entry;
        class Gtk::HBox * hbox4;
        class Gtk::Alignment * alignment5;
        class Gtk::Label * label31;
        class Gtk::Frame * frame5;
        class Gtk::RadioButton * settings_opt_speed_rbutton;
        class Gtk::RadioButton * settings_opt_size_rbutton;
        class Gtk::RadioButton * settings_opt_return_rbutton;
        class Gtk::HBox * hbox5;
        class Gtk::Alignment * alignment2;
        class Gtk::Label * label19;
        class Gtk::Frame * frame2;
        class Gtk::VBox * vbox21;
        class Gtk::HBox * hbox3;
        class Gtk::VBox * vbox9;
        class Gtk::HSeparator * hseparator3;
        class Gtk::Button * settings_cancel_button;
        class Gtk::Button * settings_okay_button;
        class Gtk::HButtonBox * hbuttonbox3;
        class Gtk::VBox * vbox6;
protected:
        
        settings_window_glade();
        
        ~settings_window_glade();
private:
        virtual void on_settings_benchmark_browse_button_clicked() = 0;
        virtual void on_settings_config_browse_button_clicked() = 0;
        virtual void on_settings_seed_check_toggled() = 0;
        virtual void on_settings_cancel_button_clicked() = 0;
        virtual void on_settings_okay_button_clicked() = 0;
};
#endif