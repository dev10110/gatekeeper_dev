# generated from
# ament_cmake_core/cmake/symlink_install/ament_cmake_symlink_install.cmake.in

# create empty symlink install manifest before starting install step
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/symlink_install_manifest.txt")

#
# Reimplement CMake install(DIRECTORY) command to use symlinks instead of
# copying resources.
#
# :param cmake_current_source_dir: The CMAKE_CURRENT_SOURCE_DIR when install
#   was invoked
# :type cmake_current_source_dir: string
# :param ARGN: the same arguments as the CMake install command.
# :type ARGN: various
#
function(ament_cmake_symlink_install_directory cmake_current_source_dir)
  cmake_parse_arguments(ARG "OPTIONAL" "DESTINATION" "DIRECTORY;PATTERN;PATTERN_EXCLUDE" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "ament_cmake_symlink_install_directory() called with "
      "unused/unsupported arguments: ${ARG_UNPARSED_ARGUMENTS}")
  endif()

  # make destination absolute path and ensure that it exists
  if(NOT IS_ABSOLUTE "${ARG_DESTINATION}")
    set(ARG_DESTINATION "/root/colcon_ws/install/px4_msgs/${ARG_DESTINATION}")
  endif()
  if(NOT EXISTS "${ARG_DESTINATION}")
    file(MAKE_DIRECTORY "${ARG_DESTINATION}")
  endif()

  # default pattern to include
  if(NOT ARG_PATTERN)
    set(ARG_PATTERN "*")
  endif()

  # iterate over directories
  foreach(dir ${ARG_DIRECTORY})
    # make dir an absolute path
    if(NOT IS_ABSOLUTE "${dir}")
      set(dir "${cmake_current_source_dir}/${dir}")
    endif()

    if(EXISTS "${dir}")
      # if directory has no trailing slash
      # append folder name to destination
      set(destination "${ARG_DESTINATION}")
      string(LENGTH "${dir}" length)
      math(EXPR offset "${length} - 1")
      string(SUBSTRING "${dir}" ${offset} 1 dir_last_char)
      if(NOT dir_last_char STREQUAL "/")
        get_filename_component(destination_name "${dir}" NAME)
        set(destination "${destination}/${destination_name}")
      else()
        # remove trailing slash
        string(SUBSTRING "${dir}" 0 ${offset} dir)
      endif()

      # glob recursive files
      set(relative_files "")
      foreach(pattern ${ARG_PATTERN})
        file(
          GLOB_RECURSE
          include_files
          RELATIVE "${dir}"
          "${dir}/${pattern}"
        )
        if(NOT include_files STREQUAL "")
          list(APPEND relative_files ${include_files})
        endif()
      endforeach()
      foreach(pattern ${ARG_PATTERN_EXCLUDE})
        file(
          GLOB_RECURSE
          exclude_files
          RELATIVE "${dir}"
          "${dir}/${pattern}"
        )
        if(NOT exclude_files STREQUAL "")
          list(REMOVE_ITEM relative_files ${exclude_files})
        endif()
      endforeach()
      list(SORT relative_files)

      foreach(relative_file ${relative_files})
        set(absolute_file "${dir}/${relative_file}")
        # determine link name for file including destination path
        set(symlink "${destination}/${relative_file}")

        # ensure that destination exists
        get_filename_component(symlink_dir "${symlink}" PATH)
        if(NOT EXISTS "${symlink_dir}")
          file(MAKE_DIRECTORY "${symlink_dir}")
        endif()

        _ament_cmake_symlink_install_create_symlink("${absolute_file}" "${symlink}")
      endforeach()
    else()
      if(NOT ARG_OPTIONAL)
        message(FATAL_ERROR
          "ament_cmake_symlink_install_directory() can't find '${dir}'")
      endif()
    endif()
  endforeach()
endfunction()

#
# Reimplement CMake install(FILES) command to use symlinks instead of copying
# resources.
#
# :param cmake_current_source_dir: The CMAKE_CURRENT_SOURCE_DIR when install
#   was invoked
# :type cmake_current_source_dir: string
# :param ARGN: the same arguments as the CMake install command.
# :type ARGN: various
#
function(ament_cmake_symlink_install_files cmake_current_source_dir)
  cmake_parse_arguments(ARG "OPTIONAL" "DESTINATION;RENAME" "FILES" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "ament_cmake_symlink_install_files() called with "
      "unused/unsupported arguments: ${ARG_UNPARSED_ARGUMENTS}")
  endif()

  # make destination an absolute path and ensure that it exists
  if(NOT IS_ABSOLUTE "${ARG_DESTINATION}")
    set(ARG_DESTINATION "/root/colcon_ws/install/px4_msgs/${ARG_DESTINATION}")
  endif()
  if(NOT EXISTS "${ARG_DESTINATION}")
    file(MAKE_DIRECTORY "${ARG_DESTINATION}")
  endif()

  if(ARG_RENAME)
    list(LENGTH ARG_FILES file_count)
    if(NOT file_count EQUAL 1)
    message(FATAL_ERROR "ament_cmake_symlink_install_files() called with "
      "RENAME argument but not with a single file")
    endif()
  endif()

  # iterate over files
  foreach(file ${ARG_FILES})
    # make file an absolute path
    if(NOT IS_ABSOLUTE "${file}")
      set(file "${cmake_current_source_dir}/${file}")
    endif()

    if(EXISTS "${file}")
      # determine link name for file including destination path
      get_filename_component(filename "${file}" NAME)
      if(NOT ARG_RENAME)
        set(symlink "${ARG_DESTINATION}/${filename}")
      else()
        set(symlink "${ARG_DESTINATION}/${ARG_RENAME}")
      endif()
      _ament_cmake_symlink_install_create_symlink("${file}" "${symlink}")
    else()
      if(NOT ARG_OPTIONAL)
        message(FATAL_ERROR
          "ament_cmake_symlink_install_files() can't find '${file}'")
      endif()
    endif()
  endforeach()
endfunction()

#
# Reimplement CMake install(PROGRAMS) command to use symlinks instead of copying
# resources.
#
# :param cmake_current_source_dir: The CMAKE_CURRENT_SOURCE_DIR when install
#   was invoked
# :type cmake_current_source_dir: string
# :param ARGN: the same arguments as the CMake install command.
# :type ARGN: various
#
function(ament_cmake_symlink_install_programs cmake_current_source_dir)
  cmake_parse_arguments(ARG "OPTIONAL" "DESTINATION" "PROGRAMS" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "ament_cmake_symlink_install_programs() called with "
      "unused/unsupported arguments: ${ARG_UNPARSED_ARGUMENTS}")
  endif()

  # make destination an absolute path and ensure that it exists
  if(NOT IS_ABSOLUTE "${ARG_DESTINATION}")
    set(ARG_DESTINATION "/root/colcon_ws/install/px4_msgs/${ARG_DESTINATION}")
  endif()
  if(NOT EXISTS "${ARG_DESTINATION}")
    file(MAKE_DIRECTORY "${ARG_DESTINATION}")
  endif()

  # iterate over programs
  foreach(file ${ARG_PROGRAMS})
    # make file an absolute path
    if(NOT IS_ABSOLUTE "${file}")
      set(file "${cmake_current_source_dir}/${file}")
    endif()

    if(EXISTS "${file}")
      # determine link name for file including destination path
      get_filename_component(filename "${file}" NAME)
      set(symlink "${ARG_DESTINATION}/${filename}")
      _ament_cmake_symlink_install_create_symlink("${file}" "${symlink}")
    else()
      if(NOT ARG_OPTIONAL)
        message(FATAL_ERROR
          "ament_cmake_symlink_install_programs() can't find '${file}'")
      endif()
    endif()
  endforeach()
endfunction()

#
# Reimplement CMake install(TARGETS) command to use symlinks instead of copying
# resources.
#
# :param TARGET_FILES: the absolute files, replacing the name of targets passed
#   in as TARGETS
# :type TARGET_FILES: list of files
# :param ARGN: the same arguments as the CMake install command except that
#   keywords identifying the kind of type and the DESTINATION keyword must be
#   joined with an underscore, e.g. ARCHIVE_DESTINATION.
# :type ARGN: various
#
function(ament_cmake_symlink_install_targets)
  cmake_parse_arguments(ARG "OPTIONAL" "ARCHIVE_DESTINATION;DESTINATION;LIBRARY_DESTINATION;RUNTIME_DESTINATION"
    "TARGETS;TARGET_FILES" ${ARGN})
  if(ARG_UNPARSED_ARGUMENTS)
    message(FATAL_ERROR "ament_cmake_symlink_install_targets() called with "
      "unused/unsupported arguments: ${ARG_UNPARSED_ARGUMENTS}")
  endif()

  # iterate over target files
  foreach(file ${ARG_TARGET_FILES})
    if(NOT IS_ABSOLUTE "${file}")
      message(FATAL_ERROR "ament_cmake_symlink_install_targets() target file "
        "'${file}' must be an absolute path")
    endif()

    # determine destination of file based on extension
    set(destination "")
    get_filename_component(fileext "${file}" EXT)
    if(fileext STREQUAL ".a" OR fileext STREQUAL ".lib")
      set(destination "${ARG_ARCHIVE_DESTINATION}")
    elseif(fileext STREQUAL ".dylib" OR fileext MATCHES "\\.so(\\.[0-9]+)?(\\.[0-9]+)?(\\.[0-9]+)?$")
      set(destination "${ARG_LIBRARY_DESTINATION}")
    elseif(fileext STREQUAL "" OR fileext STREQUAL ".dll" OR fileext STREQUAL ".exe")
      set(destination "${ARG_RUNTIME_DESTINATION}")
    endif()
    if(destination STREQUAL "")
      set(destination "${ARG_DESTINATION}")
    endif()

    # make destination an absolute path and ensure that it exists
    if(NOT IS_ABSOLUTE "${destination}")
      set(destination "/root/colcon_ws/install/px4_msgs/${destination}")
    endif()
    if(NOT EXISTS "${destination}")
      file(MAKE_DIRECTORY "${destination}")
    endif()

    if(EXISTS "${file}")
      # determine link name for file including destination path
      get_filename_component(filename "${file}" NAME)
      set(symlink "${destination}/${filename}")
      _ament_cmake_symlink_install_create_symlink("${file}" "${symlink}")
    else()
      if(NOT ARG_OPTIONAL)
        message(FATAL_ERROR
          "ament_cmake_symlink_install_targets() can't find '${file}'")
      endif()
    endif()
  endforeach()
endfunction()

function(_ament_cmake_symlink_install_create_symlink absolute_file symlink)
  # register symlink for being removed during install step
  file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/symlink_install_manifest.txt"
    "${symlink}\n")

  # avoid any work if correct symlink is already in place
  if(EXISTS "${symlink}" AND IS_SYMLINK "${symlink}")
    get_filename_component(destination "${symlink}" REALPATH)
    get_filename_component(real_absolute_file "${absolute_file}" REALPATH)
    if(destination STREQUAL real_absolute_file)
      message(STATUS "Up-to-date symlink: ${symlink}")
      return()
    endif()
  endif()

  message(STATUS "Symlinking: ${symlink}")
  if(EXISTS "${symlink}" OR IS_SYMLINK "${symlink}")
    file(REMOVE "${symlink}")
  endif()

  execute_process(
    COMMAND "/usr/bin/cmake" "-E" "create_symlink"
      "${absolute_file}"
      "${symlink}"
  )
  # the CMake command does not provide a return code so check manually
  if(NOT EXISTS "${symlink}" OR NOT IS_SYMLINK "${symlink}")
    get_filename_component(destination "${symlink}" REALPATH)
    message(FATAL_ERROR
      "Could not create symlink '${symlink}' pointing to '${absolute_file}'")
  endif()
endfunction()

# end of template

message(STATUS "Execute custom install script")

# begin of custom install code

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/px4_msgs" "DESTINATION" "share/ament_index/resource_index/rosidl_interfaces")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/px4_msgs" "DESTINATION" "share/ament_index/resource_index/rosidl_interfaces")

# install(DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_generator_c/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN" "*.h")
ament_cmake_symlink_install_directory("/root/colcon_ws/src/px4_msgs" DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_generator_c/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN" "*.h")

# install(FILES "/opt/ros/foxy/lib/python3.8/site-packages/ament_package/template/environment_hook/library_path.sh" "DESTINATION" "share/px4_msgs/environment")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/opt/ros/foxy/lib/python3.8/site-packages/ament_package/template/environment_hook/library_path.sh" "DESTINATION" "share/px4_msgs/environment")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/library_path.dsv" "DESTINATION" "share/px4_msgs/environment")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/library_path.dsv" "DESTINATION" "share/px4_msgs/environment")

# install(DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_typesupport_fastrtps_c/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN_EXCLUDE" "*.cpp")
ament_cmake_symlink_install_directory("/root/colcon_ws/src/px4_msgs" DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_typesupport_fastrtps_c/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN_EXCLUDE" "*.cpp")

# install("TARGETS" "px4_msgs__rosidl_typesupport_fastrtps_c" "ARCHIVE_DESTINATION" "lib" "LIBRARY_DESTINATION" "lib" "RUNTIME_DESTINATION" "bin")
include("/root/colcon_ws/build/px4_msgs/ament_cmake_symlink_install_targets_0_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install(DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_typesupport_fastrtps_cpp/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN_EXCLUDE" "*.cpp")
ament_cmake_symlink_install_directory("/root/colcon_ws/src/px4_msgs" DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_typesupport_fastrtps_cpp/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN_EXCLUDE" "*.cpp")

# install("TARGETS" "px4_msgs__rosidl_typesupport_fastrtps_cpp" "ARCHIVE_DESTINATION" "lib" "LIBRARY_DESTINATION" "lib" "RUNTIME_DESTINATION" "bin")
include("/root/colcon_ws/build/px4_msgs/ament_cmake_symlink_install_targets_1_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install(DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_typesupport_introspection_c/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN" "*.h")
ament_cmake_symlink_install_directory("/root/colcon_ws/src/px4_msgs" DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_typesupport_introspection_c/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN" "*.h")

# install(DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_generator_cpp/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN" "*.hpp")
ament_cmake_symlink_install_directory("/root/colcon_ws/src/px4_msgs" DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_generator_cpp/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN" "*.hpp")

# install(DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_typesupport_introspection_cpp/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN" "*.hpp")
ament_cmake_symlink_install_directory("/root/colcon_ws/src/px4_msgs" DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_typesupport_introspection_cpp/px4_msgs/" "DESTINATION" "include/px4_msgs" "PATTERN" "*.hpp")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/pythonpath.sh" "DESTINATION" "share/px4_msgs/environment")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/pythonpath.sh" "DESTINATION" "share/px4_msgs/environment")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/pythonpath.dsv" "DESTINATION" "share/px4_msgs/environment")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/pythonpath.dsv" "DESTINATION" "share/px4_msgs/environment")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_generator_py/px4_msgs/__init__.py" "DESTINATION" "lib/python3.8/site-packages/px4_msgs")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_generator_py/px4_msgs/__init__.py" "DESTINATION" "lib/python3.8/site-packages/px4_msgs")

# install(DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_generator_py/px4_msgs/msg/" "DESTINATION" "lib/python3.8/site-packages/px4_msgs/msg" "PATTERN" "*.py")
ament_cmake_symlink_install_directory("/root/colcon_ws/src/px4_msgs" DIRECTORY "/root/colcon_ws/build/px4_msgs/rosidl_generator_py/px4_msgs/msg/" "DESTINATION" "lib/python3.8/site-packages/px4_msgs/msg" "PATTERN" "*.py")

# install("TARGETS" "px4_msgs__rosidl_typesupport_fastrtps_c__pyext" "DESTINATION" "lib/python3.8/site-packages/px4_msgs")
include("/root/colcon_ws/build/px4_msgs/ament_cmake_symlink_install_targets_2_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install("TARGETS" "px4_msgs__rosidl_typesupport_introspection_c__pyext" "DESTINATION" "lib/python3.8/site-packages/px4_msgs")
include("/root/colcon_ws/build/px4_msgs/ament_cmake_symlink_install_targets_3_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install("TARGETS" "px4_msgs__rosidl_typesupport_c__pyext" "DESTINATION" "lib/python3.8/site-packages/px4_msgs")
include("/root/colcon_ws/build/px4_msgs/ament_cmake_symlink_install_targets_4_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install("TARGETS" "px4_msgs__python" "ARCHIVE_DESTINATION" "lib" "LIBRARY_DESTINATION" "lib" "RUNTIME_DESTINATION" "bin")
include("/root/colcon_ws/build/px4_msgs/ament_cmake_symlink_install_targets_5_${CMAKE_INSTALL_CONFIG_NAME}.cmake")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/BatteryStatus.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/BatteryStatus.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/DebugArray.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/DebugArray.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/DebugKeyValue.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/DebugKeyValue.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/DebugValue.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/DebugValue.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/DebugVect.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/DebugVect.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/ExternalController.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/ExternalController.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/GpsInjectData.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/GpsInjectData.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/ManualControlSetpoint.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/ManualControlSetpoint.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/OffboardControlMode.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/OffboardControlMode.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/SensorCombined.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/SensorCombined.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/SensorGps.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/SensorGps.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/Timesync.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/Timesync.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/TimesyncStatus.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/TimesyncStatus.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/TrajectorySetpoint.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/TrajectorySetpoint.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleAttitude.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleAttitude.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleAttitudeSetpoint.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleAttitudeSetpoint.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleCommand.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleCommand.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleControlMode.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleControlMode.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleGpsPosition.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleGpsPosition.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleLocalPosition.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleLocalPosition.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleLocalPositionSetpoint.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleLocalPositionSetpoint.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleOdometry.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleOdometry.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleRatesSetpoint.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleRatesSetpoint.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleStatus.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleStatus.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleVisualOdometry.idl" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_adapter/px4_msgs/msg/VehicleVisualOdometry.idl" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/BatteryStatus.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/BatteryStatus.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/DebugArray.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/DebugArray.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/DebugKeyValue.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/DebugKeyValue.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/DebugValue.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/DebugValue.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/DebugVect.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/DebugVect.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/ExternalController.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/ExternalController.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/GpsInjectData.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/GpsInjectData.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/ManualControlSetpoint.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/ManualControlSetpoint.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/OffboardControlMode.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/OffboardControlMode.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/SensorCombined.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/SensorCombined.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/SensorGps.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/SensorGps.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/Timesync.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/Timesync.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/TimesyncStatus.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/TimesyncStatus.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/TrajectorySetpoint.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/TrajectorySetpoint.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleAttitude.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleAttitude.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleAttitudeSetpoint.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleAttitudeSetpoint.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleCommand.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleCommand.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleControlMode.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleControlMode.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleGpsPosition.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleGpsPosition.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleLocalPosition.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleLocalPosition.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleLocalPositionSetpoint.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleLocalPositionSetpoint.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleOdometry.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleOdometry.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleRatesSetpoint.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleRatesSetpoint.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleStatus.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleStatus.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleVisualOdometry.msg" "DESTINATION" "share/px4_msgs/msg")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/msg/VehicleVisualOdometry.msg" "DESTINATION" "share/px4_msgs/msg")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/px4_msgs" "DESTINATION" "share/ament_index/resource_index/package_run_dependencies")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/px4_msgs" "DESTINATION" "share/ament_index/resource_index/package_run_dependencies")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/px4_msgs" "DESTINATION" "share/ament_index/resource_index/parent_prefix_path")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/px4_msgs" "DESTINATION" "share/ament_index/resource_index/parent_prefix_path")

# install(FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh" "DESTINATION" "share/px4_msgs/environment")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh" "DESTINATION" "share/px4_msgs/environment")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/ament_prefix_path.dsv" "DESTINATION" "share/px4_msgs/environment")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/ament_prefix_path.dsv" "DESTINATION" "share/px4_msgs/environment")

# install(FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh" "DESTINATION" "share/px4_msgs/environment")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/opt/ros/foxy/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh" "DESTINATION" "share/px4_msgs/environment")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/path.dsv" "DESTINATION" "share/px4_msgs/environment")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/path.dsv" "DESTINATION" "share/px4_msgs/environment")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/local_setup.bash" "DESTINATION" "share/px4_msgs")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/local_setup.bash" "DESTINATION" "share/px4_msgs")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/local_setup.sh" "DESTINATION" "share/px4_msgs")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/local_setup.sh" "DESTINATION" "share/px4_msgs")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/local_setup.zsh" "DESTINATION" "share/px4_msgs")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/local_setup.zsh" "DESTINATION" "share/px4_msgs")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/local_setup.dsv" "DESTINATION" "share/px4_msgs")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/local_setup.dsv" "DESTINATION" "share/px4_msgs")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/package.dsv" "DESTINATION" "share/px4_msgs")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_environment_hooks/package.dsv" "DESTINATION" "share/px4_msgs")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_index/share/ament_index/resource_index/packages/px4_msgs" "DESTINATION" "share/ament_index/resource_index/packages")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_index/share/ament_index/resource_index/packages/px4_msgs" "DESTINATION" "share/ament_index/resource_index/packages")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_cmake/rosidl_cmake-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_cmake/rosidl_cmake-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")

# install(FILES "/root/colcon_ws/build/px4_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake" "DESTINATION" "share/px4_msgs/cmake")

# install(FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_core/px4_msgsConfig.cmake" "/root/colcon_ws/build/px4_msgs/ament_cmake_core/px4_msgsConfig-version.cmake" "DESTINATION" "share/px4_msgs/cmake")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/build/px4_msgs/ament_cmake_core/px4_msgsConfig.cmake" "/root/colcon_ws/build/px4_msgs/ament_cmake_core/px4_msgsConfig-version.cmake" "DESTINATION" "share/px4_msgs/cmake")

# install(FILES "/root/colcon_ws/src/px4_msgs/package.xml" "DESTINATION" "share/px4_msgs")
ament_cmake_symlink_install_files("/root/colcon_ws/src/px4_msgs" FILES "/root/colcon_ws/src/px4_msgs/package.xml" "DESTINATION" "share/px4_msgs")
