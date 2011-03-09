#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>

#include "vtkEllipsoidSource.h"
#include "vtkSphereSource2.h"

void EllipsoidDemo();
void SphereDemo();

int main (int argc, char *argv[])
{
  //SphereDemo();
  EllipsoidDemo();
  
  return EXIT_SUCCESS;
}

void EllipsoidDemo()
{
  vtkSmartPointer<vtkEllipsoidSource> ellipsoidSource = 
      vtkSmartPointer<vtkEllipsoidSource>::New();
  ellipsoidSource->SetCenter(0.0, 0.0, 0.0);
      
  ellipsoidSource->SetXRadius(5.0);
  ellipsoidSource->SetYRadius(3.0);
  ellipsoidSource->SetZRadius(1.0);
  
  double XAxis[3] = {.5, .5, 0};
  ellipsoidSource->SetXAxis(XAxis);
  
  double YAxis[3] = {-.5, .5, 0};
  ellipsoidSource->SetYAxis(YAxis);
  
  ellipsoidSource->Update();
  
  // map the contours to graphical primitives
  vtkSmartPointer<vtkPolyDataMapper> mapper = 
      vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(ellipsoidSource->GetOutputPort());
  
  // create an actor for the contours
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  
  // a renderer and render window
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = 
      vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  
  // an interactor
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
      vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
  
  // add the actors to the scene
  renderer->AddActor(actor);
  renderer->SetBackground(1,1,1); // Background color white
  
  // render an image (lights and cameras are created automatically)
  renderWindow->Render();
  
  // begin mouse interaction
  renderWindowInteractor->Start();
}


void SphereDemo()
{
  vtkSmartPointer<vtkSphereSource2> sphere = 
      vtkSmartPointer<vtkSphereSource2>::New();
  double center[3] = {0,0,0};
  //sphere->SetCenter(0.0, 0.0, 0.0);
  sphere->SetCenter(center);
  sphere->SetRadius(2.0);
  sphere->Update();
  
  vtkPolyData* polydata = sphere->GetOutput();
  
  // map the contours to graphical primitives
  vtkSmartPointer<vtkPolyDataMapper> mapper = 
      vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInput(polydata);
  
  // create an actor for the contours
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  
  // a renderer and render window
  vtkSmartPointer<vtkRenderer> renderer = 
      vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow = 
      vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  
  // an interactor
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
      vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
  
  // add the actors to the scene
  renderer->AddActor(actor);
  renderer->SetBackground(1,1,1); // Background color white
  
  // render an image (lights and cameras are created automatically)
  renderWindow->Render();
  
  // begin mouse interaction
  renderWindowInteractor->Start();
  
}
