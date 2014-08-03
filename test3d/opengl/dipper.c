#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void myInit(void) {
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< MyDisplay >>>>>>>>>>>>>>>>>>>>>>>>>>
void myDisplay(void) {
	struct dipper
	{
		char *name;
		int  x,y;
	} mydipper[] = {
		{"Duhhe",289,190},
		{"Merak",320,128},
		{"Phecda",239,67},
		{"Megrez",194,101},
		{"Alioth",129,83},
		{"Mizar",75,73},
		{"Alcor",74,74},
		{"Alkaid",29,10}
	};
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for(i = 0;i < sizeof(mydipper);i++)
	       glVertex2i(mydipper[i].x,mydipper[i].y);
	glEnd();
	glFlush();
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100,150);
	glutCreateWindow("my first attempt");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
