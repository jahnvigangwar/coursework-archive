//
//  main.cpp
//  Jahnvi_102003372_3CO15
//
//  Created by Apple on 24/02/23.
//
//  main.cpp
//  prac_cg
//  Created by Apple on 23/02/23.

#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include<iostream>
using namespace std;


void init()
{
    glClearColor(1.0, 1.0, 0.0, 0.0);
    glColor3f(1, 0, 0);
    glLoadIdentity();
    gluOrtho2D(-800,800,-800,800);
    glMatrixMode(GL_PROJECTION);
}



void put_pixel(float x, float y)
{
   glBegin(GL_POINTS);
   glVertex2f(x,y);
   glEnd();
}


void liine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int s;
    if (abs(dx) > abs(dy))
        s = abs(dx);
    else
        s = abs(dy);
    float xinc = float(dx) / float(s);
    float yinc = float(dy) / float(s);
    
    float x = x1, y = y1;

    put_pixel(x, y);
    for (int i = 0; i < s; i++)
    {
        x += xinc;
        y += yinc;
        put_pixel(x,y);
    }
}

void line(float x1, float y1, float x2, float y2)
{
    float m = (y2-y1)/(x2-x1);
    float c = y2-m*x2;
   
   for(float x= x1; x<x2; x=x+0.005)
   {
       float y = m*x + c;
       put_pixel(x,y);
   }
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

    
    line(0,600,300,600);
    line(0,600,150,700);
    line(150,700,300,600);
    
   liine(600,300,600,0);
   liine(600,300,700,150);
   liine(700,150,600,0);
    
    
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-100.0f,400.0f);
    glVertex2f(0.0f,500.0f);
    glVertex2f(100.0f,400.0f);
    glVertex2f(0.0f,0.0f);
    
    glColor3f(0.0,1.0,0.0);
    glVertex2f(0.0f,0.0f);
    glVertex2f(400.0f,100.0f);
    glVertex2f(500.0f,0.0f);
    glVertex2f(400.0f,-100.0f);
    glVertex2f(0.0f,0.0f);
    
    glColor3f(1.0,0.0,1.0);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-400.0f,100.0f);
    glVertex2f(-500.0f,0.0f);
    glVertex2f(-400.0f,-100.0f);
    glVertex2f(0.0f,0.0f);
    
    glColor3f(0.0,0.0,1.0);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-100.0f,-400.0f);
    glVertex2f(0.0f,-500.0f);
    glVertex2f(100.0f,-400.0f);
    glVertex2f(0.0f,0.0f);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0.0f,0.0f);
    glVertex2f(-100.0f,400.0f);
    glVertex2f(0.0f,500.0f);
    glVertex2f(100.0f,400.0f);
    
    glVertex2f(0.0f,400.0f);
    glVertex2f(-100.0f,400.0f);
    glVertex2f(0.0f,500.0f);
    
    glVertex2f(0.0f,0.0f);
    glVertex2f(400.0f,100.0f);
    glVertex2f(500.0f,0.0f);
    glVertex2f(400.0f,-100.0f);
    glVertex2f(0.0f,0.0f);
    glVertex2f(400.0f,100.0f);
    
    glVertex2f(400.0f,0.0f);
    glVertex2f(400.0f,100.0f);
    glVertex2f(400.0f,-100.0f);
    glVertex2f(500.0f,0.0f);
   
    glVertex2f(0.0f,0.0f);
    glVertex2f(-400.0f,100.0f);
    glVertex2f(-500.0f,0.0f);
    glVertex2f(-400.0f,-100.0f);
    glVertex2f(0.0f,0.0f);
    
    glVertex2f(0.0f,-400.0f);
    glVertex2f(-100.0f,-400.0f);
    glVertex2f(100.0f,-400.0f);
    glVertex2f(0.0f,-500.0f);
    
    glVertex2f(0.0f,0.0f);
    glVertex2f(-100.0f,-400.0f);
    glVertex2f(0.0f,-500.0f);
    glVertex2f(100.0f,-400.0f);
    glVertex2f(0.0f,0.0f);
    
    glVertex2f(-400.0f,0.0f);
    glVertex2f(-400.0f,100.0f);
    glVertex2f(-400.0f,-100.0f);
    glVertex2f(-500.0f,0.0f);
    glColor3f(0.0,0.0,0.0);
    glEnd();
    
   glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Lab_Eval");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
