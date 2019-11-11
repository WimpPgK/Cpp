#include <iostream>
#include "OpenGLCube.h"
#include "OpenGLCubeMesh.h"


using namespace std;

int main()
{
    //OpenGLCube c1 = OpenGLCube();
    OpenGLCubeMesh m1 = OpenGLCubeMesh(3,3,3,0.0);
    m1.printVertices();

    cout << "Dzialam" << endl;
    return 0;
}
