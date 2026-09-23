#include<stdio.h>
#include<GLUT/glut.h>
#include<string>
#include<cmath>

void background ();
void sun (float, float, float);
void bus ();
void road ();
void signal (std::string);
void car ();
void display ();
void update ();
void output(int, int, std::string  );
int s = 0;
GLint a = 300, b = -300;
GLfloat p = 0, q = 0, r = 0;
int count = 200;
void update (int value){
  a = a - 20;
  b = b + 20;
  count--;

  if (!count)
    {
      a = 300;
      b = -300;
      count =200;
    }

  glutPostRedisplay ();
}
void display (void){
  glClear (GL_COLOR_BUFFER_BIT);
  glutTimerFunc (50, update, 0);
  glClear (GL_COLOR_BUFFER_BIT);
  background ();
    glColor3f(0,0,0);
    output(1000,700,"Project Name: Road Rules");
    output(1000,680,"Made By: ");
    output(1000,660,"Jahnvi Gangwar 102003372");
    output(1000,640,"Aditi Nirwan   102003380");
    output(1000,620,"Mukul Singhal  102003370");
  sun (1,5,15);
  road ();
  bus ();
    switch(s)
    {
        case 0  :signal ("press number keys ");  break;
        case 1  :signal ("Drive slower, live longer.");  break;
        case 2  :signal ("Do not use phone while driving.");  break;
        case 3  :signal ("Speed thrills but kills!.");  break;
        case 4  :signal ("Better Late than Never!");  break;
        case 5  :signal ("Do not mix drinking and driving.");  break;
        default :break;
    }
  car ();
  glFlush ();
  glutSwapBuffers ();
}
void background () {
  glPushMatrix ();
  glScaled (40.0, 40.0, 0.0);
  glColor3f (0.529, 0.808, 0.922);    // sky
  glBegin (GL_POLYGON);
  glVertex2f (0, 10);
  glVertex2f (0, 20);
  glVertex2f (40, 20);
  glVertex2f (40, 10);
  glEnd ();
  glColor3f (0.133, 0.545, 0.133);    //grass field
  glBegin (GL_POLYGON);
  glVertex2f (0, 10);
  glVertex2f (0, 0);
  glVertex2f (40, 0);
  glVertex2f (40, 10);
  glEnd ();
  glPopMatrix ();
}
void sun (float radius, float cx,float cy) {
  glPushMatrix ();
  glScaled (40.0, 40.0, 0.0);
  glBegin (GL_POLYGON);
  glColor3f (1, 1, 0);
  for (int i = 0; i < 50; i++)
    {
      float theta = i * 2.0f * 3.14159f / 50;
      float x = radius * cos (theta) + cx;
      float y = radius * sin (theta) + cy;
      glVertex2f (x, y);
    }
  glEnd ();
  glPopMatrix ();
}
void road () {
  glPushMatrix ();
  glScaled (40.0, 40.0, 0.0);
  glBegin (GL_POLYGON);        //road
  glColor3f (0.1, 0.1, 0.1);
  glVertex2f (0, 5);
  glVertex2f (40, 5);
  glVertex2f (40, 9);
  glVertex2f (0, 9);
  glEnd ();
  glPopMatrix ();
}
void output (int x, int y, std::string string) {
  int len, i;

  glRasterPos2f (x, y);
  len = (int) string.length ();
  for (i = 0; i < len; i++)
    glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
}
void signal (std::string stt) {
  glPushMatrix ();
  glScaled (40.0, 40.0, 0.0);
  glColor3f (0.545, 0.271, 0.075);    //stand
  glBegin (GL_POLYGON);
  glVertex2f (16, 7);
  glVertex2f (16, 8);
  glVertex2f (19, 8);
  glVertex2f (19, 7);
  glEnd ();
  glBegin (GL_POLYGON);        //pole
  glVertex2f (17, 7);
  glVertex2f (18, 8);
  glVertex2f (18, 15);
  glVertex2f (17, 15);
  glEnd ();
  glBegin (GL_POLYGON);        //board
  glVertex2f (12.5, 15);
  glVertex2f (22.5, 15);
  glVertex2f (22.5, 10);
  glVertex2f (12.5, 10);
  glEnd ();
  glColor3f (1, 1, 1);
  output (14, 14, stt);
  glPopMatrix ();
}
void bus () {
  glPushMatrix ();
  glTranslated (a, 50.0, 0.0);
  glScaled (40.0, 40.0, 0.0);
  glColor3f (0.698, 0.133, 0.133);    //bus body - fill
  glBegin (GL_POLYGON);
  glVertex2f (25, 8);
  glVertex2f (25, 9.5);
  glVertex2f (26, 11);
  glVertex2f (32, 11);
  glVertex2f (32, 8);
  glEnd ();
  glColor3f (1.000, 0.894, 0.882);    //Doors
  glBegin (GL_POLYGON);
  glVertex2f (27, 8.4);
  glVertex2f (27, 10.4);
  glVertex2f (27.7, 10.4);
  glVertex2f (27.7, 8.4);
  glEnd ();
  glColor3f (0, 0, 0);        //window-frame
  glBegin (GL_POLYGON);
  glVertex2f (27.7, 9.5);
  glVertex2f (27.7, 10.5);
  glVertex2f (31.8, 10.5);
  glVertex2f (31.8, 9.5);
  glEnd ();
    glColor3f(0,1,1); // back windows
        glBegin(GL_POLYGON);
        glVertex2f(27.8,9.6);
        glVertex2f(27.8,10.4);
        glVertex2f(29,10.4);
        glVertex2f(29,9.6);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(29.1,9.6);
        glVertex2f(29.1,10.4);
        glVertex2f(30.2,10.4);
        glVertex2f(30.2,9.6);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(30.3,9.6);
        glVertex2f(30.3,10.4);
        glVertex2f(31.7,10.4);
        glVertex2f(31.7,9.6);
        glEnd();
  glColor3f (0, 1, 1);        // front window
  glBegin (GL_POLYGON);
  glVertex2f (25, 9.5);
  glVertex2f (26, 11);
  glVertex2f (26, 9.5);
  glEnd ();
  glPopMatrix ();
  glPushMatrix (); //front tyre
  glTranslated (a + 970, 320, 0.0);
  glScaled (10.0, 10.0, 0.0);
  glBegin (GL_POLYGON);
  glColor3f (0, 0, 0);
  for (int i = 0; i < 50; i++){
      float theta = i * 2.0f * 3.14159f / 50;
      float x = 2.5 * cos (theta) + 7.2;
      float y = 2.5 * sin (theta) + 4.5;
      glVertex2f (x, y);
    }
  glEnd ();
  glPopMatrix ();
  glPushMatrix ();//back tyre
  glTranslated (a + 1140, 320, 0.0);
  glScaled (10.0, 10.0, 0.0);
  glBegin (GL_POLYGON);
  glColor3f (0, 0, 0);
  for (int i = 0; i < 50; i++){
      float theta = i * 2.0f * 3.14159f / 50;
      float x = 2.5 * cos (theta) + 7.2;
      float y = 2.5 * sin (theta) + 4.5;
      glVertex2f (x, y);
    }
  glEnd ();
    glPopMatrix ();
}
void car () {
  glPushMatrix ();        //making color for outer line
  glTranslated (b, 220.0, 0.0);
  glScaled (20.0, 20.0, 0.0);
  glColor3f (0.580, 0.000, 0.827);
  glBegin (GL_POLYGON);        //inner car - fill
  glVertex2f (2.5, 2.5);
  glVertex2f (3.0, 3.5);
  glVertex2f (3.5, 3.75);
  glVertex2f (4.0, 4.0);
  glVertex2f (4.5, 4.0);
  glVertex2f (5.0, 3.75);
  glVertex2f (5.5, 3.5);
  glVertex2f (5.75, 3.0);
  glVertex2f (6.0, 2.5);
  glVertex2f (16.5, 2.5);
  glVertex2f (16.75, 3.0);
  glVertex2f (17.0, 3.5);
  glVertex2f (17.5, 3.75);
  glVertex2f (18.0, 4.0);
  glVertex2f (18.5, 4.0);
  glVertex2f (19.0, 3.75);
  glVertex2f (19.5, 3.5);
  glVertex2f (19.75, 3.0);
  glVertex2f (20.0, 2.5);
  glVertex2f (21.0, 2.5);
  glVertex2f (21.0, 4.0);
  glVertex2f (21.5, 4.0);
  glVertex2f (21.0, 4.5);
  glVertex2f (20.0, 5.0);
  glVertex2f (15.0, 5.0);
  glVertex2f (14.0, 5.5);
  glVertex2f (13.0, 6.0);
  glVertex2f (12.0, 6.5);
  glVertex2f (11.0, 7.0);
  glVertex2f (6.0, 7.0);
  glVertex2f (5.0, 6.5);
  glVertex2f (4.5, 6.25);
  glVertex2f (4.25, 6.0);
  glVertex2f (4.0, 5.75);
  glVertex2f (3.5, 5.5);
  glVertex2f (3.0, 5.5);
  glVertex2f (1.9, 5.45);
  glVertex2f (1.8, 5.4);
  glVertex2f (1.7, 5.35);
  glVertex2f (1.6, 5.3);
  glVertex2f (1.5, 5.25);
  glVertex2f (1.4, 5.15);
  glVertex2f (1.3, 5.0);
  glVertex2f (1.2, 4.85);
  glVertex2f (1.1, 4.7);
  glVertex2f (1.0, 4.3);
  glVertex2f (1.0, 3.2);
  glVertex2f (1.1, 3.05);
  glVertex2f (1.2, 2.9);
  glVertex2f (1.3, 2.9);
  glVertex2f (1.4, 2.75);
  glVertex2f (1.5, 2.65);
  glVertex2f (1.6, 2.6);
  glVertex2f (1.7, 2.55);
  glVertex2f (1.8, 2.5);
  glVertex2f (1.9, 2.45);
  glVertex2f (2.0, 2.5);
  glEnd ();

  glColor3f (1.0, 1.0, 1.0);    //window color
  glBegin (GL_POLYGON);
  glVertex2f (5.0, 5.0);
  glVertex2f (14.0, 5.0);
  glVertex2f (11.5, 6.5);
  glVertex2f (10.5, 6.75);
  glVertex2f (7.0, 6.75);
  glEnd ();

  glBegin (GL_POLYGON);
  glColor3f (0, 0, 0);
  for (int i = 0; i < 50; i++)
    {
      float theta = i * 2.0f * 3.14159f / 50;
      float x = 1.5 * cos (theta) + 6.2;
      float y = 1.5 * sin (theta) + 2.5;
      glVertex2f (x, y);
    }
  glEnd ();

  glBegin (GL_POLYGON);
  glColor3f (0, 0, 0);
  for (int i = 0; i < 50; i++)
    {
      float theta = i * 2.0f * 3.14159f / 50;
      float x = 1.5 * cos (theta) + 16.2;
      float y = 1.5 * sin (theta) + 2.5;
      glVertex2f (x, y);
    }
  glEnd ();

  glPopMatrix ();
}
void keyboard( unsigned char key, int x, int y ){
    switch(key)
    {
        case 49 :s=1; glutDisplayFunc (display);  break;
        case 50 :s=2; glutDisplayFunc (display);  break;
        case 51 :s=3; glutDisplayFunc (display);  break;
        case 52 :s=4; glutDisplayFunc (display);  break;
        case 53 :s=5; glutDisplayFunc (display);  break;
        default:break;
    }
}
void myinit () {
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluOrtho2D (0.0, 1346.0, 0.0, 728.0);
}
int main (int argc, char *argv[]){
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (1346, 728);
  glutInitWindowPosition (0, 0);
  glutCreateWindow ("Cars in a traffic signal");
  glutDisplayFunc (display);
  myinit ();
  glutKeyboardFunc (keyboard);
  glutMainLoop ();
  return 0;
}
