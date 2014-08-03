#include <gtk/gtk.h>

GtkWidget *window;
GtkWidget *messagedialog;

static void info_message(GtkWidget *button, gpointer data)
{
    messagedialog = gtk_message_dialog_new(GTK_WINDOW(window), 0, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "This is a dialog showing an information type message");
    gtk_dialog_run(GTK_DIALOG(messagedialog));
    gtk_widget_destroy(messagedialog);
}

static void warning_message(GtkWidget *button, gpointer data)
{    
    messagedialog = gtk_message_dialog_new(GTK_WINDOW(window), 0, GTK_MESSAGE_WARNING, GTK_BUTTONS_OK_CANCEL, "This is a dialog showing an warning type message");
    gtk_dialog_run(GTK_DIALOG(messagedialog));
    gtk_widget_destroy(messagedialog);
}

static void question_message(GtkWidget *button, gpointer data)
{
    messagedialog = gtk_message_dialog_new(GTK_WINDOW(window), 0, GTK_MESSAGE_QUESTION, GTK_BUTTONS_YES_NO, "This is a dialog showing a question type message");
    gtk_dialog_run(GTK_DIALOG(messagedialog));
    gtk_widget_destroy(messagedialog);
}

static void error_message(GtkWidget *button, gpointer data)
{
    messagedialog = gtk_message_dialog_new(GTK_WINDOW(window), 0, GTK_MESSAGE_ERROR, GTK_BUTTONS_CANCEL, "This is a dialog showing a cancel type message");
    gtk_dialog_run(GTK_DIALOG(messagedialog));
    gtk_widget_destroy(messagedialog);
}

int main(int argc, char *argv[])
{   
    gtk_init(&argc, &argv);
    
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    GtkWidget *hbox = gtk_hbox_new(TRUE, 5);
    gtk_container_add(GTK_CONTAINER(window), hbox);
    
    GtkWidget *button1 = gtk_button_new_with_label("Information");
    g_signal_connect(button1, "clicked", G_CALLBACK(info_message), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), GTK_WIDGET(button1), TRUE, TRUE, 0);
    GtkWidget *button2 = gtk_button_new_with_label("Warning");
    g_signal_connect(button2, "clicked", G_CALLBACK(warning_message), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), GTK_WIDGET(button2), TRUE, TRUE, 0);
    GtkWidget *button3 = gtk_button_new_with_label("Question");
    g_signal_connect(button3, "clicked", G_CALLBACK(question_message), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), GTK_WIDGET(button3), TRUE, TRUE, 0);
    GtkWidget *button4 = gtk_button_new_with_label("Error");
    g_signal_connect(button4, "clicked", G_CALLBACK(error_message), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), GTK_WIDGET(button4), TRUE, TRUE, 0);
    
    gtk_widget_show_all(window);
    
    gtk_main();
    
    return 0;
}
