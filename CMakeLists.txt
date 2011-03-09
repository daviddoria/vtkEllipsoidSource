cmake_minimum_required(VERSION 2.6)

PROJECT(EllipsoidSource)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

ADD_EXECUTABLE(EllipsoidSource Test.cpp vtkEllipsoidSource.cxx vtkSphereSource2.cxx)
TARGET_LINK_LIBRARIES(EllipsoidSource vtkHybrid )
