#include <iostream>
#include <GL/glew.h> // this is just a extension
#include <GLUT/glut.h>
#include <math.h>

/* Global variables */
char title[] = "3D Shapes with animation";
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid [NEW]
GLfloat angleCube = 0.0f;     // Rotational angle for cube [NEW]
int refreshMills = 15;        // refresh interval in milliseconds [NEW]
int radius = 2;

#define PI 3.1415926535897932384626433832795

#define WIDTH 640
#define HEIGHT 480

/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    
    // Render a color-cube consisting of 6 quads with different colors
    glLoadIdentity();                 // Reset the model-view matrix
    glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]
    
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
    // Top face (y = 1.0f)
    // Define vertices in counter-clockwise (CCW) order with normal pointing out
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);
    
    // Bottom face (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    
    // Front face  (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f( 1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);
    
    // Back face (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);
    
    // Left face (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    
    // Right face (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();  // End of drawing color-cube
    
    
    // Triangle
    
    glLoadIdentity();
    glTranslatef(-1.0f, -2.9f, -12.0f);
    
    
    //Set Drawing Color - Will Remain this color until otherwise specified
    glColor3f(0.2, 0.3, 0.5);  //Some type of blue
    
    //Draw Circle
    glBegin(GL_POLYGON);
    //Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
    //Note that anything above 24 will have little affect on the circles appearance
    //Play with the numbers till you find the result you are looking for
    //Value 1.5 - Draws Triangle
    //Value 2 - Draws Square
    //Value 3 - Draws Hexagon
    //Value 4 - Draws Octagon
    //Value 5 - Draws Decagon
    //Notice the correlation between the value and the number of sides
    //The number of sides is always twice the value given this range
    for(double i = 0; i < 2 * PI; i += PI / 12) //<-- Change this Value
        glVertex3f(cos(i) * radius, sin(i) * radius, 0.0);
    
    
    
    glEnd();
    
    glPushMatrix();
    
    //Tells the camera where to be and where to look
    //Format (camera position x,y,z, focal point x,y,z, camera orientation x,y,z)
    //Remember that by default the camera points toward negative Z
    
    
    glLoadIdentity();
    glTranslatef(-1.0f, 3.0f, -12.0f);
    
    
    //Set Drawing Color - Will Remain this color until otherwise specified
    glColor3f(0.2, 0.3, 0.5);  //Some type of blue
    
    //Draw HEXAGON
    glBegin(GL_POLYGON);
    //Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
    //Note that anything above 24 will have little affect on the circles appearance
    //Play with the numbers till you find the result you are looking for
    //Value 1.5 - Draws Triangle
    //Value 2 - Draws Square
    //Value 3 - Draws Hexagon
    //Value 4 - Draws Octagon
    //Value 5 - Draws Decagon
    //Notice the correlation between the value and the number of sides
    //The number of sides is always twice the value given this range
    for(double i = 0; i < 2 * PI; i += PI / 3) //<-- Change this Value
        glVertex3f(cos(i) * radius, sin(i) * radius, 0.0);
    
    
    
    glEnd();
    //Draw Circle
    //Draw Circle
    glPushMatrix();
    
    //Tells the camera where to be and where to look
    //Format (camera position x,y,z, focal point x,y,z, camera orientation x,y,z)
    //Remember that by default the camera points toward negative Z
    
    glLoadIdentity();
    glTranslatef(-4.5f, 0.0f, -12.0f);
    
    
    //Set Drawing Color - Will Remain this color until otherwise specified
    glColor3f(0.2, 0.3, 0.5);  //Some type of blue
    glBegin(GL_TRIANGLES);
    //Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
    //Note that anything above 24 will have little affect on the circles appearance
    //Play with the numbers till you find the result you are looking for
    //Value 1.5 - Draws Triangle
    //Value 2 - Draws Square
    //Value 3 - Draws Hexagon
    //Value 4 - Draws Octagon
    //Value 5 - Draws Decagon
    //Notice the correlation between the value and the number of sides
    //The number of sides is always twice the value given this range
    for(double i = 0; i < 2 * PI; i += PI / 1.5) //<-- Change this Value
        glVertex3f(cos(i) * radius, sin(i) * radius, 0.0);
    
    
    
    glEnd();
    //Draw Circle
    
    
    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
    
    // Update the rotational angle after each refresh [NEW]
    angleCube -= 0.15f;
}

/* Called back when timer expired [NEW] */
void timer(int value) {
    glutPostRedisplay();      // Post re-paint request to activate display()
    glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

/* Handler for window re-size event. Called back when the window first appears and
 whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    
    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);
    
    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}

