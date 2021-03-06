#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

int main(int argc, char *argv[])
{    
    gtk_init(&argc, &argv);
    
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);
    
    GtkWidget *hsv = gtk_hsv_new();
    gtk_hsv_set_metrics(GTK_HSV(hsv), 200, 20);
    gtk_container_add(GTK_CONTAINER(window), hsv);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
