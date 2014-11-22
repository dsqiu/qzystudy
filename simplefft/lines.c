#include <cairo.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "fix_fft.h"
static void do_drawing(cairo_t *);

static char im[128];
static char data[128];

void gen_data(void) {
	int i;
	srand( (unsigned)time(NULL));
	for (i = 0; i < 128; i++) {
		data[i] = rand() % 256 - 128;
		im[i] = 0;
		i++;
	}

	//this could be done with the fix_fftr function without the im array.
	fix_fft(data,im,7,0);
	//fix_fftr(data,7,0);
	// I am only interessted in the absolute value of the transformation
	for (i=0; i< 64;i++){
		data[i] = sqrt(data[i] * data[i] + im[i] * im[i]);
	}

}
static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr,
			      gpointer user_data)
{
	gen_data();
	do_drawing(cr);

	return FALSE;
}

static void do_drawing(cairo_t *cr)
{
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_set_line_width(cr, 0.5);

	int i, j;

	for (i = 0; i < 64; i++ ) {
		cairo_move_to(cr, 50 + 256 / 64 * i, 256);
		cairo_line_to(cr, 50 + 256 / 64 * i, 256 - data[i]);
	}
	cairo_stroke(cr);
}

static gboolean clicked(GtkWidget *widget, GdkEventButton *event,
			gpointer user_data)
{
	gtk_widget_queue_draw(widget);
	return TRUE;
}


int main(int argc, char *argv[])
{
	GtkWidget *window;
	GtkWidget *darea;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), darea);

	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);

	g_signal_connect(G_OBJECT(darea), "draw",
			 G_CALLBACK(on_draw_event), NULL);
	g_signal_connect(window, "destroy",
			 G_CALLBACK(gtk_main_quit), NULL);

	g_signal_connect(window, "button-press-event",
			 G_CALLBACK(clicked), NULL);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
	gtk_window_set_title(GTK_WINDOW(window), "Lines");

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
