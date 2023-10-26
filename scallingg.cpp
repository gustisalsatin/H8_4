#include <GL/gl.h>
#include <GLFW/glfw3.h>

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

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window;

    window = glfwCreateWindow(800, 600, "Scaling Grafik", NULL, NULL);
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
