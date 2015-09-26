// generated 2005/4/21 19:44:30 EDT by scott@Corwin.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to settings_window.cc_new

// This file is for your program, I won't touch it again!

#include <gtkmm.h>
#include "config.h"
#include "settings_window.hh"

/*
typedef struct
{
    size_t num_pops;
    size_t pop_size;
    size_t num_runs;
    double srate;
    double mrate;
    double irate;
    double crate;
    char   benchmark[256];
    bool   scaling;
    bool   use_seed;
    size_t seed;
    optimization_mode mode;
}
settings_t;
*/

settings_window::settings_window(settings_t & s)
  : settings(s)
{
    // set our icon
    set_icon_from_file(PIXMAPS_DIR "acovea_icon_032.png");
    
    // fill the controls
    settings_config_entry->set_text(settings.config);
    settings_benchmark_entry->set_text(settings.benchmark);
    
    char buffer[16];
    snprintf(buffer,16,"%lu",settings.num_pops);
    settings_num_pops_entry->set_text(buffer);
    
    snprintf(buffer,16,"%lu",settings.pop_size);
    settings_pop_size_entry->set_text(buffer);
    
    snprintf(buffer,16,"%lu",settings.num_runs);
    settings_num_runs_entry->set_text(buffer);
    
    settings_srate_spin->set_value(100.0 * settings.srate);
    settings_mrate_spin->set_value(100.0 * settings.mrate);
    settings_irate_spin->set_value(100.0 * settings.irate);
    settings_crate_spin->set_value(100.0 * settings.crate);
    
    settings_scaling_check->set_active(settings.scaling);
    
    settings_seed_check->set_active(settings.use_seed);
    
    snprintf(buffer,16,"%lu",settings.seed);
    settings_seed_entry->set_text(buffer);
    settings_seed_entry->set_sensitive(settings.use_seed);
    
    switch (settings.mode)
    {
        case OPTIMIZE_SPEED:
            settings_opt_speed_rbutton->set_active(true);
            break;
        case OPTIMIZE_SIZE:
            settings_opt_size_rbutton->set_active(true);
            break;
        case OPTIMIZE_RETVAL:
            settings_opt_return_rbutton->set_active(true);
            break;
    }
}

void settings_window::on_settings_benchmark_browse_button_clicked()
{  
    Gtk::FileChooserDialog dialog("Select a Benchmark", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button("Select", Gtk::RESPONSE_OK);
    
    if (Gtk::RESPONSE_OK == dialog.run())
        settings_benchmark_entry->set_text(dialog.get_filename());
}

void settings_window::on_settings_config_browse_button_clicked()
{  
    Gtk::FileChooserDialog dialog("Select a Compiler Configuration", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button("Select", Gtk::RESPONSE_OK);
    
    if (Gtk::RESPONSE_OK == dialog.run())
        settings_config_entry->set_text(dialog.get_filename());
}

void settings_window::on_settings_seed_check_toggled()
{
    settings_seed_entry->set_sensitive(settings_seed_check->get_active());
}

void settings_window::on_settings_cancel_button_clicked()
{  
    destroy_();  
}

void settings_window::on_settings_okay_button_clicked()
{
    // get settings
    strncpy(settings.benchmark,settings_benchmark_entry->get_text().c_str(),256);
    strncpy(settings.config,settings_config_entry->get_text().c_str(),256);
    
    settings.num_pops = strtoul(settings_num_pops_entry->get_text().c_str(),NULL,10);
    settings.pop_size = strtoul(settings_pop_size_entry->get_text().c_str(),NULL,10);
    settings.num_runs = strtoul(settings_num_runs_entry->get_text().c_str(),NULL,10);
    
    settings.srate = settings_srate_spin->get_value()/ 100.0;
    settings.mrate = settings_mrate_spin->get_value() / 100.0;
    settings.irate = settings_irate_spin->get_value() / 100.0;
    settings.crate = settings_crate_spin->get_value() / 100.0;
    
    settings.scaling = settings_scaling_check->get_active();
    
    settings.use_seed = settings_seed_check->get_active();
    settings.seed = strtoul(settings_seed_entry->get_text().c_str(),NULL,10);
    
    if (settings_opt_speed_rbutton->get_active())
        settings.mode = OPTIMIZE_SPEED;
    else if (settings_opt_size_rbutton->get_active())
        settings.mode = OPTIMIZE_SIZE;
    else
        settings.mode = OPTIMIZE_RETVAL;
    
    // close window
    destroy_();  
}
