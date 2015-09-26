// generated 2005/4/21 19:44:30 EDT by scott@Corwin.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to main_window.hh_new

// you might replace
//    class foo : public foo_glade { ... };
// by
//    typedef foo_glade foo;
// if you didn't make any modifications to the widget

#ifndef _MAIN_WINDOW_HH
#  include "main_window_glade.hh"
#  define _MAIN_WINDOW_HH

// GUI elements
#include "about_box.hh"
#include "settings_window.hh"

class main_window;

class thread_acovea : acovea_listener
{
    public:
        thread_acovea(main_window * window);
    
        ~thread_acovea();
    
        void thread_function();
        void launch();
        void join();
        void terminate();
        
        // listener functions        
        virtual void ping_generation_begin(size_t a_generation_number);
        virtual void ping_generation_end(size_t a_generation_number);
        virtual void ping_population_begin(size_t a_population_number);
        virtual void ping_population_end(size_t a_population_number);
        virtual void ping_fitness_test_begin(size_t a_organism_number);
        virtual void ping_fitness_test_end(size_t a_organism_number);
        virtual void report(const string & a_text);
        virtual void report_error(const string & a_text);
        virtual void run_complete();
        virtual void yield();
        virtual void report_config(const string & a_text);
        virtual void report_generation(size_t a_gen_no, double a_avg_fitness);
        virtual void report_final(vector<test_result> & a_results, vector<option_zscore> & a_zscores);
        
    private:
        acovea_world *   world;
        settings_t       settings;
        Glib::Thread *   thread;
        Glib::Dispatcher signal_run_complete;
        Glib::Dispatcher signal_progress;
        Glib::Dispatcher signal_report;
        
        size_t gen_no;
        size_t pop_no;
        size_t test_no;
        string text;
        
        size_t * gen_no_ptr;
        size_t * pop_no_ptr;
        size_t * test_no_ptr;
        string * text_ptr;
        
        bool   drop_dead;
        
        main_window * ui;
};

class main_window : public main_window_glade
{  
    public:
        main_window();
    
        virtual ~main_window();
        
        const settings_t & get_settings() const
        {
            return settings;
        }
    
        // threading stuff
        void catch_fitness_test_end(size_t * gen_no, size_t * pop_no, size_t * test_no);
        void catch_run_complete();
        void catch_report(string * text);
        void catch_generation_end(size_t & gen_no, double & avg_fitness);

    private:
        void on_menu_quit_activate();
        void on_menu_set_run_options_activate();
        void on_menu_save_options_default_activate();
        void on_menu_load_default_options_activate();
        void on_menu_save_options_activate();
        void on_load_options_activate();
        void on_menu_run_activate();
        void on_menu_stop_activate();
        void on_menu_save_output_activate();
        void on_about1_activate();
        void on_toolbar_settings_button_clicked();
        void on_toolbar_run_button_clicked();
        void on_toolbar_stop_button_clicked();
        
        // internal functions
        void set_ui_running(bool running);
        
        void start();
        void stop();
        
        // keep track of dialog boxes
        settings_window * settings_dialog;
        about_box *       about_dialog;
        
        // current settings
        settings_t        settings;
        
        // for threading acovea execution
        thread_acovea *   thread;
        
        // messages
        static const char * MSG_RUNNING;
        static const char * MSG_FINISHED;
        static const char * MSG_TERMINATED;
        
        const char * end_message;
};

#endif
