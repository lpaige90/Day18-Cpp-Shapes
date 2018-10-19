#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(1280, 680, "Shapes", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;

        glfwGetFramebufferSize(window, &width, &height);

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);//Buffer enabled for color writing

        glMatrixMode(GL_PROJECTION);//Projection matrix stack
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.0f, 1.0f, 1.0f, -1.0f);//Projection

        glMatrixMode(GL_MODELVIEW);//Modelview matrix stack
        glLoadIdentity();

        glBegin(GL_LINE_LOOP);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.2f);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.3f, -0.2f);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.4f, 0.2f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.1f, -0.2f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.1f, 0.2f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.1f, 0.2f);

        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.1f, -0.2f);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 1.0f);
        for (int i=0; i<360; ++i) {
            float degToRad = i*(3.14159/180.0);
            glVertex2f(0.4+cos(degToRad)*0.1f,sin(degToRad)*0.2f);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
