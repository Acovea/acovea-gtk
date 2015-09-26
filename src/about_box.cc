// generated 2005/4/21 19:44:30 EDT by scott@Corwin.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to about_box.cc_new

// This file is for your program, I won't touch it again!

#include "config.h"
#include "about_box.hh"

static const char * ABOUT_TEXT =
    "<span foreground=\"blue\" size=\"x-large\">Acovea-GTK %s</span>\n\n"
    "A tool for evolving better software.\n\n"
    "Copyright 2005 Scott Robert Ladd.\n"
    "All rights reserved.\n\n"
    "<span foreground=\"blue\"><b>scott.ladd@coyotegulch.com</b></span>\n"
    "<span foreground=\"blue\"><b>http://www.coyotegulch.com</b></span>\n\n"
    "This software is licensed under the\n"
    "GNU General Public License.\n\n"
    "(A closed-license is also available.)";
        
about_box::about_box()
  : about_box_glade()
{
    // set our icon
    set_icon_from_file(PIXMAPS_DIR "acovea_icon_032.png");
    
    // generate text
    char text[512];
    snprintf(text,512,ABOUT_TEXT,VERSION);
    
    // set the label
    about_description_label->set_use_markup(true);
    about_description_label->set_label(text);
}

void about_box::on_about_close_button_clicked()
{
    destroy_();  
}

void about_box::on_about_box_realize()
{
    // didn't need this, but don't care to remove it either!  
}
