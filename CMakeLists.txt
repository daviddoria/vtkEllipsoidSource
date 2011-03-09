cmake_minimum_required(VERSION 2.6)

PROJECT(EllipsoidSource)

FIND_PACKAGE(ParaView REQUIRED)
INCLUDE(${PARAVIEW_USE_FILE})

ADD_EXECUTABLE(EllipsoidSourceTest Test.cpp vtkEllipsoidSource.cxx vtkSphereSource2.cxx)
TARGET_LINK_LIBRARIES(EllipsoidSourceTest vtkHybrid )

ADD_PARAVIEW_PLUGIN(EllipsoidSource "1.0"
SERVER_MANAGER_XML vtkEllipsoidSource.xml
SERVER_MANAGER_SOURCES vtkEllipsoidSource.cxx vtkSphereSource2.cxx
#GUI_RESOURCE_FILES vtkEllipsoidSource.xml
)
