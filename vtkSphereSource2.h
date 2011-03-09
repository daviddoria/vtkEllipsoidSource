/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkSphereSource.h,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSphereSource - create a polygonal sphere centered at the origin
// .SECTION Description
// vtkSphereSource creates a sphere (represented by polygons) of specified
// radius centered at the origin. The resolution (polygonal discretization)
// in both the latitude (phi) and longitude (theta) directions can be
// specified. It also is possible to create partial spheres by specifying
// maximum phi and theta angles. By default, the surface tessellation of
// the sphere uses triangles; however you can set LatLongTessellation to
// produce a tessellation using quadrilaterals.
// .SECTION Caveats
// Resolution means the number of latitude or longitude lines for a complete 
// sphere. If you create partial spheres the number of latitude/longitude 
// lines may be off by one. 

#ifndef __vtkSphereSource2_h
#define __vtkSphereSource2_h

#include "vtkEllipsoidSource.h"
#include "vtkSmartPointer.h"

class VTK_GRAPHICS_EXPORT vtkSphereSource2 : public vtkPolyDataAlgorithm
{
public:
  vtkTypeRevisionMacro(vtkSphereSource2,vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Construct sphere with radius=0.5 and default resolution 8 in both Phi
  // and Theta directions. Theta ranges from (0,360) and phi (0,180) degrees.
  static vtkSphereSource2 *New();
  
  // Description:
  // Set the radius of the sphere. Default is .5.
  void SetRadius(const double rad);
  double GetRadius() { return this->Radius;}
  
  // Description:
  // Set the center of sphere. Default is (0,0,0).
  void SetCenter(double center[3]);
  double* GetCenter() { return this->EllipsoidSource->GetCenter();}

protected:
  vtkSphereSource2(int res=8);
  ~vtkSphereSource2() {}
  
  int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);

private:
  vtkSphereSource2(const vtkSphereSource2&);  // Not implemented.
  void operator=(const vtkSphereSource2&);  // Not implemented.
  
  double Radius;
  
  vtkSmartPointer<vtkEllipsoidSource> EllipsoidSource;
  
};

#endif
