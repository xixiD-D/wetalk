# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/QtProjects/wetalk/server/GateServer/cmake-build-debug/_deps/grpc-src"
  "D:/QtProjects/wetalk/server/GateServer/cmake-build-debug/_deps/grpc-build"
  "D:/QtProjects/wetalk/server/GateServer/cmake-build-debug/_deps/grpc-subbuild/grpc-populate-prefix"
  "D:/QtProjects/wetalk/server/GateServer/cmake-build-debug/_deps/grpc-subbuild/grpc-populate-prefix/tmp"
  "D:/QtProjects/wetalk/server/GateServer/cmake-build-debug/_deps/grpc-subbuild/grpc-populate-prefix/src/grpc-populate-stamp"
  "D:/QtProjects/wetalk/server/GateServer/cmake-build-debug/_deps/grpc-subbuild/grpc-populate-prefix/src"
  "D:/QtProjects/wetalk/server/GateServer/cmake-build-debug/_deps/grpc-subbuild/grpc-populate-prefix/src/grpc-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/QtProjects/wetalk/server/GateServer/cmake-build-debug/_deps/grpc-subbuild/grpc-populate-prefix/src/grpc-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/QtProjects/wetalk/server/GateServer/cmake-build-debug/_deps/grpc-subbuild/grpc-populate-prefix/src/grpc-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()