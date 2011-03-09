/*=========================================================================

  Program:   Visualization Toolkit
  Module:    $RCSfile: vtkSphereSource2.cxx,v $

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkSphereSource2.h"

#include "vtkCellArray.h"
#include "vtkFloatArray.h"
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkMath.h"
#include "vtkObjectFactory.h"
#include "vtkPointData.h"
#include "vtkPoints.h"
#include "vtkPolyData.h"

vtkCxxRevisionMacro(vtkSphereSource2, "$Revision: 1.70 $");
vtkStandardNewMacro(vtkSphereSource2);

//----------------------------------------------------------------------------
// Construct sphere with radius=0.5 and default resolution 8 in both Phi
// and Theta directions. Theta ranges from (0,360) and phi (0,180) degrees.
vtkSphereSource2::vtkSphereSource2(int res)
{
  //this is a source
  this->SetNumberOfInputPorts(0);
  
  this->EllipsoidSource = vtkSmartPointer<vtkEllipsoidSource>::New();
}

void vtkSphereSource2::SetCenter(double center[3])
{
  this->EllipsoidSource->SetCenter(center);
}

void vtkSphereSource2::SetRadius(const double rad)
{
  if(rad < 0.0 || rad > VTK_DOUBLE_MAX)
    {
    cout << "Invalid radius: " << rad << endl;
    return;
    }
    
  this->EllipsoidSource->SetXRadius(rad);
  this->EllipsoidSource->SetYRadius(rad);
  this->EllipsoidSource->SetZRadius(rad);
}


int vtkSphereSource2::RequestData(
  vtkInformation *vtkNotUsed(request),
  vtkInformationVector **vtkNotUsed(inputVector),
  vtkInformationVector *outputVector)
{
  
  // get the info object
  vtkInformation *outInfo = outputVector->GetInformationObject(0);
  
  // get the ouptut
  vtkPolyData *output = vtkPolyData::SafeDownCast(
    outInfo->Get(vtkDataObject::DATA_OBJECT()));
  
  this->EllipsoidSource->Update();
  
  output->ShallowCopy(this->EllipsoidSource->GetOutput());
  
  return 1;
}

//----------------------------------------------------------------------------
void vtkSphereSource2::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
  
  
  //os << indent << "Theta Resolution: " << this->ThetaResolution << "\n";
  //os << indent << "Phi Resolution: " << this->PhiResolution << "\n";
  //os << indent << "Theta Start: " << this->StartTheta << "\n";
  //os << indent << "Phi Start: " << this->StartPhi << "\n";
  //os << indent << "Theta End: " << this->EndTheta << "\n";
  //os << indent << "Phi End: " << this->EndPhi << "\n";
  os << indent << "Center: (" << this->EllipsoidSource->GetCenter()[0] << ", " 
		  << this->EllipsoidSource->GetCenter()[1] << ", " << 
            this->EllipsoidSource->GetCenter()[2] << ")\n";
  //os << indent
	//	  << "LatLong Tessellation: " << this->LatLongTessellation << "\n";

  os << indent << "Radius: " << this->Radius << std::endl;
  
}
