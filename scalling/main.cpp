#include <GL/gl.h>
#include <GL/glut.h>

// Titik A dan B
float Ax = 8.0f, Ay = 3.0f;
float Bx = 1.0f, By = 3.0f;

// Faktor scaling
float sx = 2.0f;
float sy = 1.0f;

void drawPoint(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Gambar Titik A sebelum scaling
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah
    drawPoint(Ax, Ay);

    // Scaling Titik A
    Ax = Bx + (Ax - Bx) * sx;
    Ay = By + (Ay - By) * sy;

    // Gambar Titik A setelah scaling
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru
    drawPoint(Ax, Ay);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scaling Grafik");

    glOrtho(0, 10, 0, 10, -1, 1);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
