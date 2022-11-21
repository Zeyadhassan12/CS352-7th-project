#include <iostream>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <iostream>
#include <stdlib.h>


#include <math.h>

const int steps = 100;
const float angle = 3.1415926*2.f / steps;

float x,y,i;
float PI = 3.1416;
//float step=0;

float cloud_x = 0;
float cloud_y = 0;
float cloud_x2 = 0;
float cloud_y2 = 0;
int cloudstatus = 1;
float Step=0;
float Angle = 0.0;

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    Step+=0.025;
    
    Angle += 0.8;
    if(Angle>360.0){
        Angle = Angle - 360.0;
    }
    


}


void drawCircle( float cx , float cy, float r, int num_segments){
    glBegin(GL_POLYGON);
    for ( int i = 0; i<num_segments; i++){
        float theta = 2.0f * 3.14 * float(i) / float(num_segments);
        float x = r*cosf(theta);
        float y = r*sinf(theta);
        
        glVertex2f(x + cx, y + cy);
    }
    
    glEnd();
}


void drawsun(){
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    drawCircle(-6.7, 8, 1.5, 100);
    
    glRotatef(Angle, 1.0, 1.0, 1.0);
    
    glPopMatrix();
}




void drawtree(){
    glPushMatrix();
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCircle(6.75, 0.8, 1, 1000);
    glPopMatrix();
}

void drawCloud(){
    //glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    drawCircle(1.2+Step, 8, 0.5, 500);
    drawCircle(1.5+Step, 8.5, 0.5, 500);//first cloud
    drawCircle(2+Step, 8, 0.5, 500);
    drawCircle(2+Step, 7.5, 0.5, 500);
    
    
    
    drawCircle(6.00+Step, 5.90, 0.75, 1000);
    drawCircle(6.30+Step, 6.00, 0.75, 1000);
    drawCircle(5.80+Step, 6.00, 0.75, 1000);//second cloud
    drawCircle(6.10+Step, 6.20, 0.75, 1000);
    
    
    
    
    
    
    //glPopMatrix();
   // glFlush();
}





void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    //cloud();
    //cloud2();
    drawCloud();
    drawtree();
    drawsun();
    
    
    
    
    
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glLineWidth(0.5);
    
    
    //House
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f );
    glVertex2f(-2.6f,0.24f);
    glVertex2f(2.6f,0.24f);
    glVertex2f(0.0f,2.1f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.95f,0.18f);
    glVertex2f(1.95f,0.18f);
    glVertex2f(1.95f,-2.55f);
    glVertex2f(-1.95f,-2.55f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.6f,-0.76f);
    glVertex2f(0.6f,-0.75f);
    glVertex2f(0.6f,-2.55f);
    glVertex2f(-0.6f,-2.55f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-1.8f,-1.65f);
    glVertex2f(-0.9f,-1.65f);
    glVertex2f(-0.9f,-1.05f);
    glVertex2f(-1.8f,-1.05f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.90f,-1.65f);
    glVertex2f(1.80f,-1.65f);
    glVertex2f(1.80f,-1.05f);
    glVertex2f(0.90f,-1.05f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex2f(1.95f,-2.55f);
    glVertex2f(-1.95f,-2.55f);
    glVertex2f(-2.04f,-2.7f);
    glVertex2f(2.04f,-2.7f);
    glEnd();
    
    
    //Road
    
    glLineWidth(5.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-9.9,-3);
    glVertex2f(9.9,-3);
    
    glLineWidth(5.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-9.8,-4.9);
    glVertex2f(-5.4,-4.9);
    
    glLineWidth(5.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-4.4,-4.9);
    glVertex2f(0.4,-4.9);
    
    glLineWidth(5.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(1.5,-4.9);
    glVertex2f(5.9,-4.9);
    
    glLineWidth(5.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(6.5,-4.9);
    glVertex2f(10.9,-4.9);
    
    glLineWidth(5.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2f(-9.9,-6.8);
    glVertex2f(9.9,-6.8);
    
    glEnd();
    
    //Tree
    
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);// brown
    glVertex2f(6.5f,-2.7f);
    glVertex2f(7.0f,-2.7f);
    glVertex2f(7.0f,0.8f);
    glVertex2f(6.5f,0.8f);
    glEnd();

    //airplane
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f ); // booz eel tayara
    glVertex2f(-6.7f+Step,4.0f);
    glVertex2f(-6.3+Step,4.0f);
    glVertex2f(-6.7+Step,4.5f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);//nos el tyara
    glVertex2f(-7.7f+Step,4.5f);
    glVertex2f(-6.7f+Step,4.5f);
    glVertex2f(-7.7f+Step,4.0f);
    glVertex2f(-6.7f+Step,4.0f);
    glEnd();
    
    
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);// mosaw3d el gena7 1
    glVertex2f(-7.2+Step,4.0f);
    glVertex2f(-7.0f+Step,4.0f);
    glVertex2f(-7.2f+Step,3.5f);
    glVertex2f(-7.0f+Step,3.5f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);// mosa3ed el genah 2
    glVertex2f(-7.2f+Step,5.0f);
    glVertex2f(-7.0f+Step,5.0f);
    glVertex2f(-7.2f+Step,4.5f);
    glVertex2f(-7.0f+Step,4.5f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f ); //el gena7 1
    glVertex2f(-7.2f+Step,3.5f);
    glVertex2f(-7.0f+Step,3.5f);
    glVertex2f(-7.4f+Step,3.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f ); //el gena7 2
    glVertex2f(-7.4f+Step,5.5f);
    glVertex2f(-7.2f+Step,5.0f);
    glVertex2f(-7.0f+Step,5.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f );// el warahh
    glVertex2f(-7.7f+Step,4.5f);
    glVertex2f(-7.0f+Step,4.5f);
    glVertex2f(-7.7f+Step,4.75f);
    glEnd();
    
    
    
    
    
    
    glutSwapBuffers();
    
}

void reshape(int w,int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    
}

void init(){
    glClearColor(0.12, 0.63, 0.82, 1.0);
}






int main(int argc, char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    
    glutInitWindowPosition(200,0 );
    glutInitWindowSize(1200, 800);
    
    glutCreateWindow("20101209");
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();
}
