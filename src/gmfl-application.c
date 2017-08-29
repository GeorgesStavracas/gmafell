/* gmfl-application.c
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

#define G_LOG_DOMAIN "GmflApplication"

#include "gmfl-application.h"
#include "gmfl-window.h"

#include <gwords/gwords.h>

struct _GmflApplication
{
  GtkApplication      parent;

  GmflWindow         *window;
  GwLanguage         *language;
};

G_DEFINE_TYPE (GmflApplication, gmfl_application, GTK_TYPE_APPLICATION)

enum
{
  PROP_0,
  PROP_LANGUAGE,
  N_PROPS
};

static GParamSpec *properties [N_PROPS] = { NULL, };

/*
 * GObject overrides
 */

static void
gmfl_application_dispose (GObject *object)
{
  GmflApplication *self = (GmflApplication *)object;

  g_clear_object (&self->language);

  G_OBJECT_CLASS (gmfl_application_parent_class)->dispose (object);
}

static void
gmfl_application_get_property (GObject    *object,
                               guint       prop_id,
                               GValue     *value,
                               GParamSpec *pspec)
{
  GmflApplication *self = GMFL_APPLICATION (object);

  switch (prop_id)
    {
    case PROP_LANGUAGE:
      g_value_set_object (value, self->language);
      break;

    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
    }
}

static void
gmfl_application_set_property (GObject      *object,
                               guint         prop_id,
                               const GValue *value,
                               GParamSpec   *pspec)
{
  G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
}

/*
 * GApplication overrides
 */

static void
gmfl_application_activate (GApplication *application)
{
  GmflApplication *self = GMFL_APPLICATION (application);

  if (!self->window)
    self->window = gmfl_window_new (self);

  gtk_window_present (GTK_WINDOW (self->window));
}

static void
gmfl_application_class_init (GmflApplicationClass *klass)
{
  GApplicationClass *application_class = G_APPLICATION_CLASS (klass);
  GObjectClass *object_class = G_OBJECT_CLASS (klass);

  object_class->dispose = gmfl_application_dispose;
  object_class->get_property = gmfl_application_get_property;
  object_class->set_property = gmfl_application_set_property;

  application_class->activate = gmfl_application_activate;

  /**
   * GmflApplication:language:
   *
   * The system language.
   */
  properties[PROP_LANGUAGE] = g_param_spec_object ("language",
                                                   "System language",
                                                   "The system language",
                                                   GW_TYPE_LANGUAGE,
                                                   G_PARAM_READABLE | G_PARAM_STATIC_STRINGS);

  g_object_class_install_properties (object_class, N_PROPS, properties);
}

static void
gmfl_application_init (GmflApplication *self)
{
  self->language = gw_language_new_sync (NULL, NULL, NULL);

  g_debug ("Initializing with system language (%s)", gw_language_get_language_code (self->language));
}

GmflApplication *
gmfl_application_new (void)
{
  return g_object_new (GMFL_TYPE_APPLICATION,
                       "application-id", "com.feaneron.Gmafell",
                       "flags", G_APPLICATION_FLAGS_NONE,
                       NULL);
}
