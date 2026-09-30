# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspaces/automatos-finitos/build/_deps/fltk-src"
  "/workspaces/automatos-finitos/build/_deps/fltk-build"
  "/workspaces/automatos-finitos/build/_deps/fltk-subbuild/fltk-populate-prefix"
  "/workspaces/automatos-finitos/build/_deps/fltk-subbuild/fltk-populate-prefix/tmp"
  "/workspaces/automatos-finitos/build/_deps/fltk-subbuild/fltk-populate-prefix/src/fltk-populate-stamp"
  "/workspaces/automatos-finitos/build/_deps/fltk-subbuild/fltk-populate-prefix/src"
  "/workspaces/automatos-finitos/build/_deps/fltk-subbuild/fltk-populate-prefix/src/fltk-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspaces/automatos-finitos/build/_deps/fltk-subbuild/fltk-populate-prefix/src/fltk-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspaces/automatos-finitos/build/_deps/fltk-subbuild/fltk-populate-prefix/src/fltk-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
