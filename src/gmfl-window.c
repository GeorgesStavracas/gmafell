/* gmfl-window.c
 *
 * Copyright (C) 2017 Georges Basile Stavracas Neto <georges.stavracas@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#define G_LOG_DOMAIN "GmflWindow"

#include "gmfl-application.h"
#include "gmfl-window.h"

struct _GmflWindow
{
  GtkApplicationWindow parent;
};

G_DEFINE_TYPE (GmflWindow, gmfl_window, GTK_TYPE_APPLICATION_WINDOW)

static void
gmfl_window_get_property (GObject    *object,
                          guint       prop_id,
                          GValue     *value,
                          GParamSpec *pspec)
{
  G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
}

static void
gmfl_window_set_property (GObject      *object,
                          guint         prop_id,
                          const GValue *value,
                          GParamSpec   *pspec)
{
  G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
}

static void
gmfl_window_class_init (GmflWindowClass *klass)
{
  GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->get_property = gmfl_window_get_property;
  object_class->set_property = gmfl_window_set_property;

  gtk_widget_class_set_template_from_resource (widget_class, "/com/feaneron/gmafell/ui/window.ui");
}

static void
gmfl_window_init (GmflWindow *self)
{
  gtk_widget_init_template (GTK_WIDGET (self));
}

GmflWindow *
gmfl_window_new (GmflApplication *application)
{
  return g_object_new (GMFL_TYPE_WINDOW,
                       "application", application,
                       NULL);
}

