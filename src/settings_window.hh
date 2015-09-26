// generated 2005/4/21 19:44:30 EDT by scott@Corwin.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to settings_window.hh_new

// you might replace
//    class foo : public foo_glade { ... };
// by
//    typedef foo_glade foo;
// if you didn't make any modifications to the widget

#ifndef _settings_WINDOW_HH
#  include "settings_window_glade.hh"
#  define _settings_WINDOW_HH

// Acovea library
#include <libacovea/acovea.h>
using namespace acovea;

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
    char   config[256];
    bool   scaling;
    bool   use_seed;
    size_t seed;
    optimization_mode mode;
}
settings_t;

class settings_window : public settings_window_glade
{  
    public:
        settings_window(settings_t & s);
            
    private:        
        void on_settings_benchmark_browse_button_clicked();
        void on_settings_config_browse_button_clicked();
        void on_settings_seed_check_toggled();
        void on_settings_cancel_button_clicked();
        void on_settings_okay_button_clicked();
        
        settings_t & settings;
};
#endif
