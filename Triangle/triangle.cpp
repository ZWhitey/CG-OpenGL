#include <iostream> 
#include <GL/freeglut.h>
using namespace std;

void RenderScene(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 1.0f, 0, 0, 0, 0, 1, 0);

	glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0); glVertex3f(-8, -8, 0);
	glColor3f(1, 0, 0); glVertex3f(8, -8, 0);
	glColor3f(1, 0, 0); glVertex3f(0, 8, 0);
	glEnd();

	glutSwapBuffers();
}
void ChangeSize(int w, int h)
{
	cout << "New window size : Width: " << w << " Height: " << h << endl;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(600, 80);
	glutCreateWindow("Simple Rectangle");

	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);
	glutMainLoop();
	return 0;
}



