// generated 2005/4/21 19:44:30 EDT by scott@Corwin.(none)
// using glademm V2.6.0
//
// newer (non customized) versions of this file go to about_box.hh_new

// you might replace
//    class foo : public foo_glade { ... };
// by
//    typedef foo_glade foo;
// if you didn't make any modifications to the widget

#ifndef _ABOUT_BOX_HH
#  include "about_box_glade.hh"
#  define _ABOUT_BOX_HH
class about_box : public about_box_glade
{  
    public:
        about_box();
    
    private:
        void on_about_close_button_clicked();
        void on_about_box_realize();
};
#endif
