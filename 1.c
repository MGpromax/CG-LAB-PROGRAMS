#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLint X1, Y1, X2, Y2;

void LineBres(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int dx = abs(X2 - X1);
    int dy = abs(Y2 - Y1);
    int twoDy = 2 * dy;
    int twoDyDx = 2 * (dy - dx);
    int p;
    int x, y;

    if (X1 > X2)
    {
        x = X2;
        y = Y2;
        X2 = X1;
        Y2 = Y1;
    }
    else
    {
        x = X1;
        y = Y1;
    }

    glBegin(GL_POINTS);
    glVertex2i(x, y);

    if (dx > dy)
    {
        p = 2 * dy - dx;
        int incr1 = 2 * dy;
        int incr2 = 2 * (dy - dx);
        int stepx = 1;

        if (X1 > X2)
            stepx = -1;

        while (x != X2)
        {
            x += stepx;

            if (p < 0)
                p += incr1;
            else
            {
                y += (Y2 > Y1 ? 1 : -1);
                p += incr2;
            }

            glVertex2i(x, y);
        }
    }
    else
    {
        p = 2 * dx - dy;
        int incr1 = 2 * dx;
        int incr2 = 2 * (dx - dy);
        int stepy = 1;

        if (Y1 > Y2)
            stepy = -1;

        while (y != Y2)
        {
            y += stepy;

            if (p < 0)
                p += incr1;
            else
            {
                x += (X2 > X1 ? 1 : -1);
                p += incr2;
            }

            glVertex2i(x, y);
        }
    }

    glEnd();
    glFlush();
}

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 1);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glViewport(0, 0, 500, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char **argv)
{
    printf("Enter two points for drawing a line using Bresenham's algorithm:\n");
    printf("\nEnter points (X1, Y1): ");
    scanf("%d %d", &X1, &Y1);
    printf("\nEnter points (X2, Y2): ");
    scanf("%d %d", &X2, &Y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("LINE BRESENHAM: C Tathva");
    Init();
    glutDisplayFunc(LineBres);
    glutMainLoop();

    return 0;
}
