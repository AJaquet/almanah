/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/*
 * Almanah
 * Copyright (C) Philip Withnall 2008 <philip@tecnocode.co.uk>
 * 
 * Almanah is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Almanah is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Almanah.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ALMANAH_CALENDAR_APPOINTMENT_EVENT_H
#define ALMANAH_CALENDAR_APPOINTMENT_EVENT_H

#include <glib.h>
#include <glib-object.h>

#include "event.h"

G_BEGIN_DECLS

#define ALMANAH_TYPE_CALENDAR_APPOINTMENT_EVENT		(almanah_calendar_appointment_event_get_type ())
#define ALMANAH_CALENDAR_APPOINTMENT_EVENT(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), ALMANAH_TYPE_CALENDAR_APPOINTMENT_EVENT, AlmanahCalendarAppointmentEvent))
#define ALMANAH_CALENDAR_APPOINTMENT_EVENT_CLASS(k)	(G_TYPE_CHECK_CLASS_CAST((k), ALMANAH_TYPE_CALENDAR_APPOINTMENT_EVENT, AlmanahCalendarAppointmentEventClass))
#define ALMANAH_IS_CALENDAR_APPOINTMENT_EVENT(o)	(G_TYPE_CHECK_INSTANCE_TYPE ((o), ALMANAH_TYPE_CALENDAR_APPOINTMENT_EVENT))
#define ALMANAH_IS_CALENDAR_APPOINTMENT_EVENT_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), ALMANAH_TYPE_CALENDAR_APPOINTMENT_EVENT))
#define ALMANAH_CALENDAR_APPOINTMENT_EVENT_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), ALMANAH_TYPE_CALENDAR_APPOINTMENT_EVENT, AlmanahCalendarAppointmentEventClass))

typedef struct _AlmanahCalendarAppointmentEventPrivate	AlmanahCalendarAppointmentEventPrivate;

typedef struct {
	AlmanahEvent parent;
	AlmanahCalendarAppointmentEventPrivate *priv;
} AlmanahCalendarAppointmentEvent;

typedef struct {
	AlmanahEventClass parent;
} AlmanahCalendarAppointmentEventClass;

GType almanah_calendar_appointment_event_get_type (void);
AlmanahCalendarAppointmentEvent *almanah_calendar_appointment_event_new (const gchar *summary, GTime start_time);

G_END_DECLS

#endif /* !ALMANAH_CALENDAR_APPOINTMENT_EVENT_H */
