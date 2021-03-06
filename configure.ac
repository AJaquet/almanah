AC_PREREQ(2.63)
AC_INIT([almanah],[0.12.0],[https://bugzilla.gnome.org/enter_bug.cgi?product=almanah],[almanah],[https://wiki.gnome.org/Apps/Almanah_Diary])

AC_CONFIG_AUX_DIR([config])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src])
AC_USE_SYSTEM_EXTENSIONS

AM_INIT_AUTOMAKE([1.9 dist-bzip2 no-dist-gzip check-news subdir-objects])

# Enable silent build when available (Automake 1.11)
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

GETTEXT_PACKAGE=AC_PACKAGE_TARNAME
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, ["$GETTEXT_PACKAGE"], [Define to the Gettext package name])
AC_SUBST(GETTEXT_PACKAGE)
IT_PROG_INTLTOOL([0.50.1])

AC_PROG_CXX
AM_PROG_CC_C_O
LT_INIT([])
PKG_PROG_PKG_CONFIG
GLIB_GSETTINGS

AC_PATH_PROG([GLIB_MKENUMS],[glib-mkenums])

APPDATA_XML

dnl ***************************************************************************
dnl Options
dnl ***************************************************************************

dnl Debugging
AC_ARG_ENABLE([debug],
	AS_HELP_STRING([--enable-debug],[turn on debugging]),
	[case "${enableval}" in
		yes) debug=true ;;
		no)  debug=false ;;
		*) AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
	esac],[debug=false])

if test $debug = "true"; then
	AC_DEFINE([ENABLE_DEBUG],[1],[Define if you want debugging enabled])
fi

AM_CONDITIONAL([DEBUG], [test x$debug = xtrue])

dnl Spell checking
AC_ARG_ENABLE([spell-checking],
	AS_HELP_STRING([--enable-spell-checking],[enable spell checking support]),
	[case "${enableval}" in
		yes) spell_checking=true ;;
		no)  spell_checking=false ;;
		*) AC_MSG_ERROR([bad value ${enableval} for --enable-spell-checking]) ;;
	esac],[spell_checking=true])

if test $spell_checking = "true"; then
	AC_DEFINE([ENABLE_SPELL_CHECKING],[1],[Define if you want spell checking support])
fi

AM_CONDITIONAL([SPELL_CHECKING], [test x$spell_checking = xtrue])

dnl ***************************************************************************
dnl Dependencies
dnl ***************************************************************************

GTK_MIN_VERSION=3.15
GIO_MIN_VERSION=2.32

dnl Required dependencies
PKG_CHECK_MODULES(STANDARD, glib-2.0
                            gtk+-3.0 >= $GTK_MIN_VERSION
                            gmodule-2.0
                            gthread-2.0
                            gio-2.0 >= $GIO_MIN_VERSION
                            gtksourceview-3.0
                            sqlite3
                            cairo
                            atk
                            gcr-base-3
                            cryptui-0.0)

dnl Check for GPGME, which doesn't provide a pkgconfig file
dnl This code courtesy of seahorse
min_gpgme_version=1.0.0
AC_PATH_PROG(GPGME_CONFIG, gpgme-config, "failed")
if test $GPGME_CONFIG != "failed" ; then
        AC_MSG_CHECKING(for GPGME)
        req_major=`echo $min_gpgme_version | \
                sed 's/\([[0-9]]*\)\.\([[0-9]]*\)\.\([[0-9]]*\)/\1/'`
        req_minor=`echo $min_gpgme_version | \
                sed 's/\([[0-9]]*\)\.\([[0-9]]*\)\.\([[0-9]]*\)/\2/'`
        req_micro=`echo $min_gpgme_version | \
                sed 's/\([[0-9]]*\)\.\([[0-9]]*\)\.\([[0-9]]*\)/\3/'`
        gpgme_config_version=`$GPGME_CONFIG --version`
        major=`echo $gpgme_config_version | \
                sed 's/\([[0-9]]*\)\.\([[0-9]]*\)\.\([[0-9]]*\).*/\1/'`
        minor=`echo $gpgme_config_version | \
                sed 's/\([[0-9]]*\)\.\([[0-9]]*\)\.\([[0-9]]*\).*/\2/'`
        micro=`echo $gpgme_config_version | \
                sed 's/\([[0-9]]*\)\.\([[0-9]]*\)\.\([[0-9]]*\).*/\3/'`

        if test "$major" -eq "$req_major"; then
                if test "$minor" -ge "$req_minor"; then
                        if test "$micro" -ge "$req_micro"; then
                                ok="yes"
                        fi
                fi
        fi
fi

AC_DEFINE_UNQUOTED([MIN_GPGME_VERSION],"${min_gpgme_version}",[The minimum required version of GPGME])

if test $ok = "yes"; then
        STANDARD_CFLAGS="$STANDARD_CFLAGS `$GPGME_CONFIG --cflags`"
        STANDARD_LIBS="$STANDARD_LIBS `$GPGME_CONFIG --libs`"
        AC_MSG_RESULT(yes)
else
        AC_MSG_ERROR(GPGME $min_gpgme_version or later needed)
fi

AC_SUBST(STANDARD_CFLAGS)
AC_SUBST(STANDARD_LIBS)

dnl Evolution
EDS_MIN_VERSION=2.28
PKG_CHECK_MODULES(EVO, libecal-1.2 >= 3.5.91 libedataserver-1.2 >= $EDS_MIN_VERSION, have_evo=yes, have_evo=no)
if test "x$have_evo" = "xyes"; then
	AC_DEFINE(HAVE_EVO, 1, [Defined if libecal-1.2 is installed])
fi
AM_CONDITIONAL([HAVE_EVO], [test x$have_evo = xyes])

EVO_CFLAGS="$EVO_CFLAGS -DE_BOOK_DISABLE_DEPRECATED -DE_CAL_DISABLE_DEPRECATED"
AC_SUBST(EVO_CFLAGS)
AC_SUBST(EVO_LIBS)

dnl Spell checking
if test $spell_checking = "true"; then
	PKG_CHECK_MODULES(SPELL_CHECKING, gtkspell3-3.0)
	AC_SUBST(SPELL_CHECKING_CFLAGS)
	AC_SUBST(SPELL_CHECKING_LIBS)
fi

# Various required functions and headers
AC_CHECK_HEADERS([libintl.h])
AC_C_INLINE
AC_FUNC_MKTIME
AC_TYPE_SIZE_T
AC_SYS_LARGEFILE

dnl GResource
GLIB_COMPILE_RESOURCES=`$PKG_CONFIG --variable glib_compile_resources gio-2.0`
AC_SUBST(GLIB_COMPILE_RESOURCES)

AC_CONFIG_FILES([
Makefile
src/Makefile
po/Makefile.in
data/Makefile
data/icons/Makefile
data/icons/16x16/Makefile
data/icons/22x22/Makefile
data/icons/32x32/Makefile
data/icons/48x48/Makefile
data/icons/256x256/Makefile
data/icons/scalable/Makefile
data/org.gnome.almanah.gschema.xml
tests/Makefile
])
AC_OUTPUT
