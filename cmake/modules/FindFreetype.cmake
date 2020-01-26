
if(UNIX)
  set(FREETYPE_INCLUDE_DIRS "/usr/include/freetype2/")
  set(FREETYPE_LIBRARIES "/usr/lib/x86_64-linux-gnu/libfreetype.so")
elseif(WIN32)
  message("Windows")
else()
  message(FATAL_ERROR "Unknown OS")
endif()
