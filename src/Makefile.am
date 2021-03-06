bin_PROGRAMS = almanah

BUILT_SOURCES =
EXTRA_DIST =
CLEANFILES =

almanah_SOURCES = \
	main.c					\
	application.c				\
	application.h				\
	interface.c				\
	interface.h				\
	main-window.c				\
	main-window.h				\
	storage-manager.c			\
	storage-manager.h			\
	search-dialog.c				\
	search-dialog.h				\
	preferences-dialog.c			\
	preferences-dialog.h			\
	printing.c				\
	printing.h				\
	entry.c					\
	entry.h					\
	event.c					\
	event.h					\
	event-factory.c				\
	event-factory.h				\
	event-manager.c				\
	event-manager.h				\
	date-entry-dialog.c			\
	date-entry-dialog.h			\
	import-export-dialog.c			\
	import-export-dialog.h			\
	import-operation.c			\
	import-operation.h			\
	export-operation.c			\
	export-operation.h			\
	uri-entry-dialog.c			\
	uri-entry-dialog.h			\
	widgets/calendar.c			\
	widgets/calendar.h			\
	widgets/calendar-button.h		\
	widgets/calendar-button.c		\
	widgets/eggwrapbox.h			\
	widgets/eggwrapbox.c			\
	widgets/eggwrapbox-enums.h		\
	widgets/eggwrapbox-enums.c		\
	widgets/entry-tags-area.h		\
	widgets/entry-tags-area.c		\
	widgets/hyperlink-tag.c			\
	widgets/hyperlink-tag.h			\
	widgets/tag-accessible.c		\
	widgets/tag-accessible.h		\
	widgets/tag.c				\
	widgets/tag.h				\
	widgets/tag-entry.c			\
	widgets/tag-entry.h			\
	vfs.h					\
	vfs.c

if HAVE_EVO
almanah_SOURCES += \
	event-factories/calendar.c		\
	event-factories/calendar.h		\
	event-factories/calendar-client.c	\
	event-factories/calendar-client.h	\
	event-factories/calendar-debug.h	\
	event-factories/calendar-sources.c	\
	event-factories/calendar-sources.h	\
	event-factories/e-cell-renderer-color.c	\
	event-factories/e-cell-renderer-color.h	\
	event-factories/e-source-selector.c	\
	event-factories/e-source-selector.h	\
	events/calendar-appointment.c		\
	events/calendar-appointment.h		\
	events/calendar-task.c			\
	events/calendar-task.h
endif

nodist_almanah_SOURCES = \
	$(almanah_enum_header_file) \
	$(almanah_enum_source_file) \
	$(NULL)

almanah_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(datadir)/locale"\"	\
	-DPACKAGE_DATA_DIR=\""$(datadir)"\"		\
	-I$(srcdir)/events				\
	-I$(srcdir)/event-factories			\
	$(DISABLE_DEPRECATED)				\
	$(AM_CPPFLAGS)

almanah_CFLAGS = \
	$(STANDARD_CFLAGS)		\
	$(EVO_CFLAGS)			\
	$(SPELL_CHECKING_CFLAGS)	\
	$(WARN_CFLAGS)			\
	$(AM_CFLAGS)

almanah_LDADD = \
	$(STANDARD_LIBS)	\
	$(EVO_LIBS)		\
	$(SPELL_CHECKING_LIBS)	\
	$(AM_LDADD)

# GResource
almanah_gresource_xml_deps = $(shell $(GLIB_COMPILE_RESOURCES) --generate-dependencies --sourcedir=$(top_srcdir)/src $(top_srcdir)/src/almanah.gresource.xml)
resources.c: $(almanah_gresource_xml_deps)
	$(AM_V_GEN)$(GLIB_COMPILE_RESOURCES) --target=$@ --c-name almanah --sourcedir=$(top_srcdir)/src --generate-source $(top_srcdir)/src/almanah.gresource.xml

BUILT_SOURCES += resources.c
nodist_almanah_SOURCES += resources.c
EXTRA_DIST += \
	almanah.gresource.xml \
	$(almanah_gresource_xml_deps) \
	$(NULL)
CLEANFILES += resources.c

# Enums
almanah_enum_header_file = enums.h
almanah_enum_source_file = enums.c
almanah_enum_prerequisites = event-factory.h

$(almanah_enum_header_file): $(almanah_enum_header_file:%=%.template) $(almanah_enum_prerequisites)
	$(AM_V_GEN)$(GLIB_MKENUMS) --template $< \
		$(patsubst %,$(srcdir)/%,$(almanah_enum_prerequisites)) \
		> $@.tmp && mv $@.tmp $@

$(almanah_enum_source_file): $(almanah_enum_source_file:%=%.template) $(almanah_enum_prerequisites)
	$(AM_V_GEN)$(GLIB_MKENUMS) --template $< \
		$(patsubst %,$(srcdir)/%,$(almanah_enum_prerequisites)) \
		> $@.tmp && mv $@.tmp $@

EXTRA_DIST += \
	$(almanah_enum_header_file:%=%.template) \
	$(almanah_enum_source_file:%=%.template) \
	$(NULL)
BUILT_SOURCES += \
	$(almanah_enum_header_file) \
	$(almanah_enum_source_file) \
	$(NULL)
CLEANFILES += \
	$(almanah_enum_header_file) \
	$(almanah_enum_source_file) \
	$(NULL)

-include $(top_srcdir)/git.mk
