/* gmfl-application.h
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

#ifndef GMFL_APPLICATION_H
#define GMFL_APPLICATION_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GMFL_TYPE_APPLICATION (gmfl_application_get_type())

G_DECLARE_FINAL_TYPE (GmflApplication, gmfl_application, GMFL, APPLICATION, GtkApplication)

GmflApplication*     gmfl_application_new                        (void);

G_END_DECLS

#endif /* GMFL_APPLICATION_H */

