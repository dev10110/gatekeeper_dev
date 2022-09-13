# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_gatekeeper_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED gatekeeper_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(gatekeeper_FOUND FALSE)
  elseif(NOT gatekeeper_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(gatekeeper_FOUND FALSE)
  endif()
  return()
endif()
set(_gatekeeper_CONFIG_INCLUDED TRUE)

# output package information
if(NOT gatekeeper_FIND_QUIETLY)
  message(STATUS "Found gatekeeper: 0.0.0 (${gatekeeper_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'gatekeeper' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${gatekeeper_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(gatekeeper_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${gatekeeper_DIR}/${_extra}")
endforeach()
