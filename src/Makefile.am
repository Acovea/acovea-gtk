INCLUDES = -DPIXMAPS_DIR=\""$(pkgdatadir)/pixmaps/"\"

bin_PROGRAMS = acovea-gtk

acovea_gtk_SOURCES = \
	acovea-gtk.cc\
	main_window_glade.cc \
	main_window.cc \
	about_box_glade.cc \
	about_box.cc \
	settings_window_glade.cc \
	settings_window.cc

noinst_HEADERS = \
	main_window_glade.hh \
	main_window.hh \
	about_box_glade.hh \
	about_box.hh \
	settings_window_glade.hh \
	settings_window.hh

AM_CXXFLAGS = @GTKMM_CFLAGS@	

acovea_gtk_LDFLAGS =  -pthread -L//usr/lib
acovea_gtk_LDADD = @LIBS@ @GTKMM_LIBS@ -lgthread-2.0 -lglib-2.0 -lcoyotl -levocosm -lacovea -lexpat 
