#include <stdio.h>
#include <GL/glut.h>

float house[5][2] = {{200, 100}, {400, 100}, {300, 300}};
float h = 200, k = 100, theta;

void setTriangleColor()
{
    glColor3f(0.5, 0.5, 0.5); // Set color to gray (you can change the RGB values as desired)
}

void drawtriangle()
{
    setTriangleColor(); // Set the color for the triangle
    glBegin(GL_POLYGON);
    glVertex2fv(house[0]);
    glVertex2fv(house[1]);
    glVertex2fv(house[2]);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_COLOR_MATERIAL); // Enable color
    drawtriangle();
    glTranslatef(h, k, 0);
    glRotatef(theta, 0, 0, 1);
    glTranslatef(-h, -k, 0);
    drawtriangle();
    glFlush();
}

void init()
{
    gluOrtho2D(-700, 700, -700, 700);
}

int main(int argc, char **argv)
{
    printf("Enter the rotation angle.\n");
    scanf("%f", &theta);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Add GLUT_RGB flag for color
    glutInitWindowSize(350, 350);
    glutCreateWindow("House: C Tathva");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
