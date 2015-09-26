// generated 2005/4/21 19:44:30 EDT by scott@Corwin.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to main_window.cc_new

// This file is for your program, I won't touch it again!

#include <glibmm/thread.h>
#include <gtkmm.h>
#include <gtkmm/main.h>
#include <iomanip>
#include "config.h"
#include "main_window.hh"

//------------------------------------------------------------------------------
// THREADING
thread_acovea::thread_acovea(main_window * window)
  : world(NULL),
    thread(NULL),
    settings(window->get_settings()),
    ui(window),
    gen_no(0),
    pop_no(0),
    test_no(0),
    drop_dead(false),
    text("Nothing to see here."),
    gen_no_ptr(&gen_no),
    pop_no_ptr(&pop_no),
    test_no_ptr(&test_no),
    text_ptr(&text)
{
    signal_run_complete.connect(sigc::mem_fun(*window, &main_window::catch_run_complete));
    signal_progress.connect(sigc::bind<size_t *,size_t *,size_t *>(sigc::mem_fun(*window, &main_window::catch_fitness_test_end),gen_no_ptr,pop_no_ptr,test_no_ptr));
    signal_report.connect(sigc::bind<string *>(sigc::mem_fun(*window, &main_window::catch_report),text_ptr));
}

thread_acovea::~thread_acovea()
{
    delete world;
}

void thread_acovea::launch()
{
    thread = Glib::Thread::create(sigc::mem_fun(*this, &thread_acovea::thread_function),true);
}

void thread_acovea::join()
{
    thread->join();
}

void thread_acovea::thread_function()
{
    // define a application from config file
    application target(settings.config);
    
    // initialize random number generator if required
    if (settings.use_seed)
        libevocosm::globals::set_random_seed(settings.seed);

    // create a world
    world = new acovea_world(*this,
                             settings.benchmark,
                             settings.mode,
                             target,
                             settings.num_pops,
                             settings.pop_size,
                             settings.srate,
                             settings.irate,
                             settings.mrate,
                             settings.crate,
                             settings.scaling,
                             settings.num_runs);
                       
    // start running
    world->run();
}

void thread_acovea::terminate()
{
    world->terminate();
    drop_dead = true;
}

// these functions listen for acovea events
void thread_acovea::ping_generation_begin(size_t a_generation_number)
{
    pop_no = 0;
    signal_progress();
}

void thread_acovea::ping_generation_end(size_t a_generation_number)
{
    gen_no = a_generation_number;
    signal_progress();
}

void thread_acovea::ping_population_begin(size_t a_population_number)
{
    test_no = 0;
    signal_progress();
}

void thread_acovea::ping_population_end(size_t a_population_number)
{
    pop_no = a_population_number;
    signal_progress();
}

void thread_acovea::ping_fitness_test_begin(size_t a_organism_number)
{
    // nada
}

void thread_acovea::ping_fitness_test_end(size_t a_organism_number)
{
    test_no = a_organism_number;
    signal_progress();
}

void thread_acovea::report(const string & a_text)
{
    // text = a_text;
    // signal_report();
}

void thread_acovea::report_error(const string & a_text)
{
    // In a future version, I'll have an option error display
    // text = a_text;
    // signal_report();
}

void thread_acovea::run_complete()
{
    signal_run_complete();
}

void thread_acovea::yield()
{
    if (drop_dead)
    {
        signal_run_complete();
        throw Glib::Thread::Exit();
    }
    else
        Glib::usleep(50000);
}

void thread_acovea::report_config(const string & a_text)
{
    text = a_text;
    g_print(text.c_str());
    signal_report();
}

void thread_acovea::report_generation(size_t a_gen_no, double  a_avg_fitness)
{
    ostringstream output;
    
    output << "generation " << a_gen_no
           << " complete, average fitness: " << a_avg_fitness
           << endl;
    
    text = output.str();
    signal_report();
}

void thread_acovea::report_final(vector<test_result> & a_results, vector<option_zscore> & a_zscores)
{
    ostringstream output;
    
    static const double THRESHOLD = 1.5;
    
    // format time
    char time_text[256];
    time_t now = time(NULL);
    strftime(time_text,256,"%Y %b %d %X",localtime(&now));

    output << "\nAcovea completed its analysis at " << time_text << endl;
    
    // report optimistic options
    bool flag = false;
        
    output << "\nOptimistic options:\n\n";
    for (int n = 0; n < a_zscores.size(); ++n)
    {
        if (a_zscores[n].m_zscore >= THRESHOLD)
        {
            flag = true;
            
            output << right << setw(40) << a_zscores[n].m_name
                 << "  (" << a_zscores[n].m_zscore << ")\n";
        }
    }
        
    if (!flag)
        output << "        none" << endl;
    
    flag = false;
        
    output << "\nPessimistic options:\n\n";
    for (int n = 0; n < a_zscores.size(); ++n)
    {
        if (a_zscores[n].m_zscore <= -THRESHOLD)
        {
            flag = true;
            
            output << right << setw(40) << a_zscores[n].m_name
                 << "  (" << a_zscores[n].m_zscore << ")\n";
        }
    }
        
    if (!flag)
        output << "        none" << endl;
    
    // graph test results
    double big_fit = numeric_limits<double>::min();
        
    for (int n = 0; n < a_results.size(); ++n)
    {
        output << "\n" << a_results[n].m_description << ":\n"
             << a_results[n].m_detail
             << endl;

        if (a_results[n].m_fitness > big_fit)
            big_fit = a_results[n].m_fitness;
    }
    
    output << "\n\nA relative graph of fitnesses:\n";
    
    for (int n = 0; n < a_results.size(); ++n)
    {
        output << "\n" << right << setw(30) << a_results[n].m_description << ": ";
        
        int count = int(a_results[n].m_fitness / big_fit * 50.1);
        
        for (int i = 0; i < count; ++i)
            output << "*";
        
        output << right << setw(55 - count) << " ("
             << a_results[n].m_fitness
             << ")";
    }
    
    output << "\n\nAcovea is done.\n" << endl;
    
    text = output.str();
    signal_report();
}

//------------------------------------------------------------------------------
// MAIN WINDOW CLASS
static bool save_settings(const string & name, const settings_t & settings)
{
    bool result = false;
    
    FILE * settings_file = fopen(name.c_str(),"w+b");

    if (settings_file != NULL)
    {
        if (1 == fwrite(&settings,sizeof(settings_t),1,settings_file))
            result = true;
        
        fclose(settings_file);
    }
            
    return result;
}

static bool load_settings(const string & name, settings_t & settings)
{
    bool result = false;
    
    FILE * settings_file = fopen(name.c_str(),"rb");
    
    if (settings_file != NULL)
    {
        if (1 == fread(&settings,sizeof(settings_t),1,settings_file))
            result = true;
        
        fclose(settings_file);
    }
    
    return result;
}

static string get_default_settings_name()
{
    static char setting_name[1024] = { 0 };

    if (setting_name[0] == 0)
    {
        // find home directory
        char * home_dir = getenv("HOME");

        // create a directory
        snprintf(setting_name,1024,"%s/.acovea-gtk",home_dir);
        mkdir(setting_name,0777);

        // now generate the file name
        snprintf(setting_name,1024,"%s/.acovea-gtk/settings",home_dir);
    }

    return string(setting_name);
}

static bool create_default_settings(settings_t & settings)
{
    settings.num_pops  =   5;
    settings.pop_size  =  40;
    settings.num_runs  =  20;
    settings.srate     =   0.10;
    settings.irate     =   0.05;
    settings.mrate     =   0.01;
    settings.crate     =   1.00;
    strcpy(settings.benchmark,"You need to pick one");
    strcpy(settings.config,"You need to pick one");
    settings.scaling   = true;
    settings.use_seed  = false;
    settings.seed      = 1701;
    settings.mode      = OPTIMIZE_SPEED;
            
    return save_settings(get_default_settings_name(),settings);
}

const char * main_window::MSG_RUNNING("<span foreground=\"darkgreen\" weight = \"bold\">Running</span>");
const char * main_window::MSG_FINISHED("<span foreground=\"blue\" weight = \"bold\">Finished</span>");
const char * main_window::MSG_TERMINATED("<span foreground=\"red\" weight = \"bold\">Run Terminated</span>");

main_window::main_window()
  : main_window_glade()
{
    // set our icon
    set_icon_from_file(PIXMAPS_DIR "acovea_icon_032.png");
    
    // set scrollbar colors
    /*
    Gdk::Color blue1, blue2, blue3, gray;
    blue1.set_rgb_p(0.0,0.0,0.8);
    blue2.set_rgb_p(0.2,0.0,0.6);
    blue3.set_rgb_p(0.4,0.0,0.4);
    gray.set_rgb_p(0.95,0.95,0.95);
    
    Glib::RefPtr<Gdk::Colormap> colormap = get_default_colormap();
    colormap->alloc_color(blue1);
    colormap->alloc_color(blue2);
    colormap->alloc_color(blue3);
    colormap->alloc_color(gray);
    
    main_generation_progressbar->modify_bg(Gtk::STATE_NORMAL,gray);
    main_population_progressbar->modify_bg(Gtk::STATE_NORMAL,gray);
    main_testing_progressbar->modify_bg(Gtk::STATE_NORMAL,gray);
    
    main_generation_progressbar->modify_fg(Gtk::STATE_NORMAL,blue1);
    main_population_progressbar->modify_fg(Gtk::STATE_NORMAL,blue2);
    main_testing_progressbar->modify_fg(Gtk::STATE_NORMAL,blue3);
    */
            
    // set label for markup
    main_whatsup->set_use_markup(true);
    
    // set a better font
    Pango::FontDescription fd;
    fd.set_size(10000);
    fd.set_stretch(Pango::STRETCH_NORMAL);
    fd.set_style(Pango::STYLE_NORMAL);
    fd.set_variant(Pango::VARIANT_NORMAL);
    fd.set_weight(Pango::WEIGHT_NORMAL);
    fd.set_family("monospace"); // Vera Sans Mono, Monospace, Courier");
    main_window_output->modify_font(fd);
    
    // we haven't created these windows yet
    settings_dialog = NULL;
    about_dialog    = NULL;
     
    if (!load_settings(get_default_settings_name(),settings))
    {
        if (!create_default_settings(settings))
        {
            Gtk::MessageDialog dialog(*this, "Unable to open or create default settings file.");
            dialog.run();
        }
    }
    
    // set inital ui state
    set_ui_running(false);
}

main_window::~main_window()
{
    if (settings_dialog != NULL)
        delete settings_dialog;
    
    if (about_dialog != NULL)
        delete about_dialog;
}

void main_window::on_menu_quit_activate()
{
    Gtk::Main::quit();  
}

void main_window::on_menu_set_run_options_activate()
{  
    if (settings_dialog != NULL)
        delete settings_dialog;
    
    settings_window * dialog = new settings_window(settings);
}

void main_window::on_menu_save_options_default_activate()
{  
    if (!save_settings(get_default_settings_name(),settings))
    {
        if (!create_default_settings(settings))
        {
            Gtk::MessageDialog dialog(*this, "Unable to open or create default settings file.");
            dialog.run();
        }
    }
}

void main_window::on_menu_load_default_options_activate()
{  
    if (!load_settings(get_default_settings_name(),settings))
    {
        if (!create_default_settings(settings))
        {
            Gtk::MessageDialog dialog(*this, "Unable to open or create default settings file.");
            dialog.run();
        }
    }
}

void main_window::on_menu_save_options_activate()
{  
    Gtk::FileChooserDialog dialog("Save Settings To...", Gtk::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button("Save", Gtk::RESPONSE_OK);
    
    if (Gtk::RESPONSE_OK == dialog.run())
        save_settings(dialog.get_filename(),settings);
}

void main_window::on_load_options_activate()
{  
    Gtk::FileChooserDialog dialog("Load Settings From...", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button("Load", Gtk::RESPONSE_OK);
    
    if (Gtk::RESPONSE_OK == dialog.run())
        load_settings(dialog.get_filename(),settings);
}

//------------------------------------------------------------------------------
// MAIN WINDOW THREADING
void main_window::catch_fitness_test_end(size_t * gen_no, size_t * pop_no, size_t * test_no)
{
    double percent = double(*gen_no) / double(settings.num_runs);
    main_generation_progressbar->set_fraction(percent);
    
    percent = double(*pop_no) / double(settings.num_pops);
    main_population_progressbar->set_fraction(percent);
    
    percent = double(*test_no) / double(settings.pop_size);
    main_testing_progressbar->set_fraction(percent);

    /*
    Glib::RefPtr<Gtk::TextBuffer> buffer = main_window_output->get_buffer();
    Gtk::TextIter end = buffer->end();
    main_window_output->scroll_to(end);
    */
}

void main_window::catch_run_complete()
{
    set_ui_running(false);
    main_whatsup->set_label(end_message);
    main_generation_progressbar->set_fraction(1.0);
    main_population_progressbar->set_fraction(1.0);
    main_testing_progressbar->set_fraction(1.0);
}

void main_window::catch_report(string * text)
{
    Glib::RefPtr<Gtk::TextBuffer> buffer = main_window_output->get_buffer();
    Gtk::TextIter end = buffer->end();
    buffer->insert(buffer->end(),text->c_str());
} 

void main_window::set_ui_running(bool running)
{
    // when running, these should be off
    menu_set_run_options->set_sensitive(!running);
    menu_save_options_default->set_sensitive(!running);
    menu_load_default_options->set_sensitive(!running);
    menu_save_options->set_sensitive(!running);
    save_load_options->set_sensitive(!running);
    menu_quit->set_sensitive(!running);
    menu_run->set_sensitive(!running);
    menu_save_output->set_sensitive(!running);
    menu_about->set_sensitive(!running);
    toolbar_settings_button->set_sensitive(!running);
    toolbar_run_button->set_sensitive(!running);
    
    // when running, these should be on
    toolbar_stop_button->set_sensitive(running);
    menu_stop->set_sensitive(running);
}

void main_window::start()
{
    // clear the display
    Glib::RefPtr<Gtk::TextBuffer> buffer = main_window_output->get_buffer();
    buffer->erase(buffer->begin(),buffer->end());
    
    // set the termination message
    end_message = MSG_FINISHED;
    main_whatsup->set_label(MSG_RUNNING);
    
    // set ui state
    set_ui_running(true);
    
    // reset progress bars
    main_generation_progressbar->set_fraction(0.0);
    main_population_progressbar->set_fraction(0.0);
    main_testing_progressbar->set_fraction(0.0);
    
    // create thread
    thread = new thread_acovea(this);
    
    // launch the thread
    thread->launch();
}

void main_window::stop()
{
    thread->terminate();
    end_message = MSG_TERMINATED;
}

void main_window::on_menu_run_activate()
{
    start();
}

void main_window::on_menu_stop_activate()
{  
    stop();
}

void main_window::on_menu_save_output_activate()
{
    Gtk::FileChooserDialog dialog("Save Output To...", Gtk::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button("Save", Gtk::RESPONSE_OK);
    
    if (Gtk::RESPONSE_OK == dialog.run())
    {
        FILE * f = fopen(dialog.get_filename().c_str(),"w+");
        Glib::RefPtr<Gtk::TextBuffer> buffer = main_window_output->get_buffer();
        fputs(buffer->get_text().c_str(),f);
        fclose(f);
    }
}

void main_window::on_about1_activate()
{
    if (about_dialog != NULL)
        delete about_dialog;

    about_box * dialog = new class about_box();
}

void main_window::on_toolbar_settings_button_clicked()
{  
    if (settings_dialog != NULL)
        delete settings_dialog;
    
    settings_window * dialog = new settings_window(settings);
}

void main_window::on_toolbar_run_button_clicked()
{  
    start();
}

void main_window::on_toolbar_stop_button_clicked()
{  
    stop();
}
