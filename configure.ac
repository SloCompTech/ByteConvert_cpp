AC_INIT([libbyteconvert], [0.1.0], [slocomptech@gmail.com])

AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([-Wall foreign])
LT_INIT

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADER([stdint.h],[],[AC_MSG_ERROR([sorry, can't do anything for you])])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC

# Config files
AC_CONFIG_FILES([Makefile
                libbyteconvert/Makefile
                libbyteconvert.pc])

AC_OUTPUT
