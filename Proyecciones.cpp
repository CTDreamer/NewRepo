/*
	GRUPO 01 - COMPUTACIÓN VISUAL
	PROF. GUTIERREZ

	OBJETIVO: MODIFICAR LOS PLANOS DE CORTE ANTERIOR Y POSTERIOR USANDO LAS TECLAS A y a PARA INCREMENTAR 
	EL PLANO ANTERIOR Y POSTERIOR RESPECTIVAMENTE. 
*/


#include <GL/glut.h> 
#include <cstdlib>
 
GLfloat anguloEsfera = 0.0f;
GLint ancho, alto;
// Definición de variables globales a usar para modificar los planos
GLfloat planoCorteAnterior = 3.0f; 
GLfloat planoCortePosterior = 5.0f; 


int hazPerspectiva = 1;
void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (hazPerspectiva)
		gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, planoCorteAnterior, planoCortePosterior);
	else
		glOrtho(-4, 4, -4, 4, planoCorteAnterior, planoCortePosterior);

	glMatrixMode(GL_MODELVIEW);

	ancho = width;
	alto = height;
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -5.0f);

	glutWireTeapot(1.5f);

	glFlush();
	glutSwapBuffers();

}

void init()
{
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	ancho = 400;
	alto = 400;
}

void idle()
{
	display();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'p':
	case 'P':
		hazPerspectiva = 1;
		reshape(ancho, alto);
		break;

	case 'o':
	case 'O':
		hazPerspectiva = 0;
		reshape(ancho, alto);
		break;
	// Lo pedido en la tarea => Aumentar los planos de Corte Anterior y Posterior
	case 'A':
		planoCorteAnterior += 0.6f; 
		reshape(ancho, alto); 
		break;

	case 'a':
		planoCortePosterior += 0.6f; 
		reshape(ancho, alto); 
		break;
	// Agregado => Disminuir os planos de Corte Anterior y Posterior
	case 'B':
		planoCorteAnterior -= 0.6f;
		reshape(ancho, alto);
		break;

	case 'b':
		planoCortePosterior -= 0.6f;
		reshape(ancho, alto);
		break;
	case 27:   
		exit(0);
		break;

	}

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(ancho, alto);
	glutCreateWindow("Cubo 1");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}