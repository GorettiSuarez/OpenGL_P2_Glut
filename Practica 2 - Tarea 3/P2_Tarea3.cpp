#include <stdio.h>

#include <GL\glew.h>
#include <GL\freeglut.h>

int win1, win2;

void InitGlew() {

	GLenum glew_init = glewInit();
	if (glew_init != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_init));
	}
	else {
		fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	}
}


void Init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
}

void Display1() {
	glClear(GL_COLOR_BUFFER_BIT);
	glutWireTeapot(0.5);
	glFlush();
}

void Display2() {
	glClear(GL_COLOR_BUFFER_BIT);
	glutWireTeapot(0.5);
	glFlush();
}

//Todo pasa porque tenemos que manejar el espacio fisico y el espacio logico para que se ajuste a este
void Dimensiones(int ancho, int alto) {
	float dx = 2.0;
	float dy = 2.0;

	if (ancho > alto) {
		dx = 2.0*(float)ancho / (float)alto;
	}

	if (alto > ancho){
		dy = 2.0*(float)alto / (float)ancho;
	}

	glViewport(0, 0, ancho, alto);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, 1.0f, 0.0f);
	glutPostRedisplay();
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 300);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	win1 = glutCreateWindow("OpenGL Practica 2_3. Ventana1 - Maria Goretti Suárez Rivero");
	InitGlew();
	Init();
	glutDisplayFunc(Display1);

	win2 = glutCreateWindow("OpenGL Practica 2_3. Ventana2 - Maria Goretti Suárez Rivero");
	Init();
	glutDisplayFunc(Display2);
	glutReshapeFunc(Dimensiones);

	glutMainLoop();

	return 0;
}