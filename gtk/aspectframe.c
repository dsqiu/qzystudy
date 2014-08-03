#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *aspectframe = gtk_aspect_frame_new("Aspect Frame", 0, 0, 1.0, FALSE);
    gtk_container_add(GTK_CONTAINER(window), aspectframe);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
