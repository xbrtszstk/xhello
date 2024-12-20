#include <spdlog/spdlog.h>
#include <gtk/gtk.h>

static void
activate (GtkApplication* app, gpointer user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "xhello-client");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);
  gtk_window_present (GTK_WINDOW (window));
}

int main (int argc, char **argv)
{
  GtkApplication *application{};
  int result{};

  application = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (application, "activate", G_CALLBACK (activate), NULL);
  result = g_application_run (G_APPLICATION (application), argc, argv);
  g_object_unref (application);

  return result;
}
