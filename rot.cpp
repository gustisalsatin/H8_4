#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cmath>
// Titik A dan B
float Ax = 8.0f, Ay = 3.0f;
float Bx = 1.0f, By = 3.0f;

// Sudut rotasi dalam radian
float angleInRadians = M_PI / 4.0f;

void drawPoint(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Gambar Titik A sebelum rotasi
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah
    drawPoint(Ax, Ay);

    // Matriks transformasi rotasi
    float cosTheta = cos(angleInRadians);
    float sinTheta = sin(angleInRadians);
    float x = Ax - Bx;
    float y = Ay - By;
    float xNew = x * cosTheta - y * sinTheta + Bx;
    float yNew = x * sinTheta + y * cosTheta + By;

    // Gambar Titik A setelah rotasi
    glColor3f(0.0f, 0.0f, 1.0f); // Warna biru
    drawPoint(xNew, yNew);

    glFlush();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window;

    window = glfwCreateWindow(800, 600, "Rotasi Grafik", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glOrtho(0, 10, 0, 10, -1, 1);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}