#include <iostream>
#include "OpenGLCube.h"
#include "OpenGLCubeMesh.h"


using namespace std;

int main()
{
    //OpenGLCube c1 = OpenGLCube();
    int x = 50;
    int y = 50;
    int z = 50;
    cout << x*y*z*180 << endl;
    OpenGLCubeMesh m1 = OpenGLCubeMesh(x,y,z,0.0);
    m1.normalizeVertices();
    m1.saveToFile();
    //m1.printVertices();

    cout << "Dzialam" << endl;
    return 0;
}
