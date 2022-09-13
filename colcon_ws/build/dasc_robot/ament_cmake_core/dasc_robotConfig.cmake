# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_dasc_robot_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED dasc_robot_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(dasc_robot_FOUND FALSE)
  elseif(NOT dasc_robot_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(dasc_robot_FOUND FALSE)
  endif()
  return()
endif()
set(_dasc_robot_CONFIG_INCLUDED TRUE)

# output package information
if(NOT dasc_robot_FIND_QUIETLY)
  message(STATUS "Found dasc_robot: 0.0.0 (${dasc_robot_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'dasc_robot' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${dasc_robot_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(dasc_robot_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${dasc_robot_DIR}/${_extra}")
endforeach()
