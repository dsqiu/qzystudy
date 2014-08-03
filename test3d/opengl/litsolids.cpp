// This program shows threes cyan objects illuminated with a single yellow
// light source. It illustrates several of the lighting parameters.

#include <GL/glut.h>

// Clears the window and depth and draws three solids.
//
// The solids are placed so that they either sit or float above the x-z plane;
// therefore note one of the first things that is done is to rotate the whole
// scene 20 degrees about x to turn the top of the scene toward the viewer.
// This lets the viewer see how the tours goes around the cone.

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	// Rotate the scene so we can see the tops of the shapes.
	glRotatef(-20.0,1.0,0.0,0.0);

	// Make a torus floating 0.5 above the x-z plane. The standard torus in
	// the GLUT library is, perhaps surprisingly, a stack of circles which
	// encircle the z-axis, so we need to rotate it 90 degrees about x to
	// get it the way we want.
	glPushMatrix();
	glTranslatef(-0.75,0.5,0.0);
	glRotatef(90.0,1.0,0.0,0.0);
	glutSolidTorus(0.275,0.85,16,40);
	glPopMatrix();

	// Make a cone. The standard cone "points" along z; we want it pointing
	// along y, hence the 270 degree rotation about x.
	glPushMatrix();
	glTranslatef(-0.75,-0.5,0.0);
	glRotatef(270.0,1.0,0.0,0.0);
	glutSolidCone(1.0,2.0,70,12);
	glPopMatrix();

	// Add a sphere to the scene.
	glPushMatrix();
	glTranslatef(0.75,0.0,-1.0);
	glutSolidSphere(1.0,30,30);
	glPopMatrix();

	glPopMatrix();
	glFlush();
}

// We don't want the scene to get distorted when the window size changes,so
// We need a reshape callback. We'll always maintain a range of -2.5..2.5 in
// the smaller of the width and height for our viewbox,and a range of -1.0..10
// for the viewbox depth.

void reshape(GLint w,GLint h) {
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	GLfloat aspect = GLfloat(w) / GLfloat(h);
	glLoadIdentity();
	if(w <= h) {
		// width is smaller,so stretch out the height
		glOrtho(-2.5,2.5,-2.5/aspect,2.5/aspect,-10.0,10.0);
	} else {
		glOrtho(-2.5*aspect,2.5*aspect,-2.5,2.5,-10.0,10.0);
	}
}

// Performs application specific initialization. It defines lighting
// parameters for light source GL_LIGHT0: black for ambient,yellow for
// diffuse,white for specular, and makes it a directional source
// shining along <-1,-1,-1>. It also sets a couple material properties
// to make cyan colored objects with a fairly low shininess value, Lighting
// and depth buffer hidden surface removal are enable here.


// （1）GL_AMBIENT、GL_DIFFUSE、GL_SPECULAR属性。这三个属性与光源的三个对应属性类似，每一属性都由四个值组成。GL_AMBIENT表示各种光线照射到该材质上，经过很多次反射后最终遗留在环境中的光线强度（颜色）。GL_DIFFUSE表示光线照射到该材质上，经过漫反射后形成的光线强度（颜色）。GL_SPECULAR表示光线照射到该材质上，经过镜面反射后形成的光线强度（颜色）。通常，GL_AMBIENT和GL_DIFFUSE都取相同的值，可以达到比较真实的效果。使用GL_AMBIENT_AND_DIFFUSE可以同时设置GL_AMBIENT和GL_DIFFUSE属性。
// （2）GL_SHININESS属性。该属性只有一个值，称为“镜面指数”，取值范围是0到128。该值越小，表示材质越粗糙，点光源发射的光线照射到上面，也可以产生较大的亮点。该值越大，表示材质越类似于镜面，光源照射到上面后，产生较小的亮点。
// （3）GL_EMISSION属性。该属性由四个值组成，表示一种颜色。OpenGL认为该材质本身就微微的向外发射光线，以至于眼睛感觉到它有这样的颜色，但这光线又比较微弱，以至于不会影响到其它物体的颜色。
// （4）GL_COLOR_INDEXES属性。该属性仅在颜色索引模式下使用，由于颜色索引模式下的光照比RGBA模式要复杂，并且使用范围较小，这里不做讨论。

void init() {
	GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat yellow[] = {1.0, 1.0, 0.0, 1.0 };
	GLfloat cyan[] = {0.0 , 1.0, 1.0, 1.0 };
	GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat direction[] = { 1.0, 1.0, 1.0, 0.0 };

	glMaterialfv(GL_FRONT,GL_AMBIENT_AND_DIFFUSE,cyan);
	glMaterialfv(GL_FRONT,GL_SPECULAR,white);
	glMaterialf(GL_FRONT,GL_SHININESS,30);

	glLightfv(GL_LIGHT0,GL_AMBIENT,black);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,yellow);
	glLightfv(GL_LIGHT0,GL_SPECULAR,white);
	glLightfv(GL_LIGHT0,GL_POSITION,direction);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

// The usual application statup code.

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(80,80);
	glutInitWindowSize(800,600);
	glutCreateWindow("Cyan Shapes in Yellow Light");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
    return 0;
}
