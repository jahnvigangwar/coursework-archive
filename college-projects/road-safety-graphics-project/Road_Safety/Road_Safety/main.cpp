#include<stdio.h>
#include<GLUT/glut.h>
#include<cmath>
#include<string.h>

void background();
void sun();
void bus();
void road();
void car();
void signal();
void mydisplay();
void display();
void update();
void myKeyboard();

GLint a=200,b=-100;
GLfloat cx = 5,cy=15,radius=1;
//GLfloat p=0,q=0,r=0;

int count = 200,flag=1;

int rule_counter=0,rules_length=5;
char* rules[5] = {"Drive slower, live longer.","Do not use phone while driving.","Speed thrills but kills!.","Better Late than Never!","Do not mix drinking and driving."};


void output(int x, int y, char *string,void *font)
{
    int len, i;
    flag?glColor3f(1, 1, 1):glColor3f(0,0,0);
    glRasterPos2f(x,y);
    len=(int) strlen(string);
    for (i = 0; i < len; i++)
    {
        glutBitmapCharacter(font,string[i]);
    }
}


void mydisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    display();
    glutSwapBuffers();
}

void myKeyboard( unsigned char key, int x, int y )
{
    switch(key)
    {
        case 13: {rule_counter = (rule_counter+1)%rules_length;break;}
        case 'd':
        case 'D':flag=0;break;
        case 'N':
        case 'n':flag=1; break;
        default:break;
    }
}

void update(int value)
{
    a=a-15;
    b=b+15;
    count--;
    
    if(!count){
        a=300;
        b=-300;
        count=200;
    }
    
    glutPostRedisplay();
}

void display(void)
{
    glutTimerFunc(50,update,0);
    glClear(GL_COLOR_BUFFER_BIT);
    background();
    output(1200,700,"Project Name: Highway",GLUT_BITMAP_TIMES_ROMAN_10);
    output(1200,680,"Made By: ",GLUT_BITMAP_TIMES_ROMAN_10);
    output(1200,660,"Jahnvi Gangwar 102003372",GLUT_BITMAP_TIMES_ROMAN_10);
    output(1200,640,"Aditi Nirwan  102003380",GLUT_BITMAP_TIMES_ROMAN_10);
    output(1200,620,"Mukul Singhal 102003370",GLUT_BITMAP_TIMES_ROMAN_10);
    output(70,100,"INSTRUCTIONS: ",GLUT_BITMAP_TIMES_ROMAN_24);
    output(100,70,"Press D for Day View",GLUT_BITMAP_TIMES_ROMAN_24);
    output(100,45,"Press N for Night View",GLUT_BITMAP_TIMES_ROMAN_24);
    output(400,70,"Press Enter for new rules",GLUT_BITMAP_TIMES_ROMAN_24);
    output(665,640,"NH-8",GLUT_BITMAP_TIMES_ROMAN_24);
    sun();
    road();
    bus();
    signal();
    output(510, 550, rules[rule_counter], GLUT_BITMAP_TIMES_ROMAN_24);
    car();
    glFlush();
}

void background(){
    glPushMatrix();
    glScaled(40.0,40.0,0.0);
    
    !flag?glColor3f(0.529, 0.808, 0.922):glColor3f(0,0,0.5);; // sky
    glBegin(GL_POLYGON);
    glVertex2f(0,10);
    glVertex2f(0,20);
    glVertex2f(40,20);
    glVertex2f(40,10);
    glEnd();
    
    glColor3f(0.133, 0.545, 0.133); //grass field
    glBegin(GL_POLYGON);
    glVertex2f(0,10);
    glVertex2f(0,0);
    glVertex2f(40,0);
    glVertex2f(40,10);
    glEnd();
    
    glPopMatrix();
}

void sun(){
    glPushMatrix();
    glScaled(40.0,40.0,0.0);
    glBegin(GL_POLYGON);
    !flag?glColor3f(1,1,0):glColor3f(1,1,1);
    for (int i = 0; i < 50; i++)
    {
        float theta = i * 2.0f * 3.14159f / 50;
        float x = radius * cos(theta) + cx;
        float y = radius * sin(theta) + cy;
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

void signal()
{
    glPushMatrix();
    glScaled(40.0,40.0,0.0);
    
    glColor3f(0.545, 0.271, 0.075); //stand
    glBegin(GL_POLYGON);
    glVertex2f(15,7);
    glVertex2f(15,8);
    glVertex2f(18,8);
    glVertex2f(18,7);
    glEnd();
    
    glBegin(GL_POLYGON); //pole
    glVertex2f(16,7);
    glVertex2f(17,8);
    glVertex2f(17,15);
    glVertex2f(16,15);
    glEnd();
    
    glBegin(GL_POLYGON); //board
    glVertex2f(11.5,15);
    glVertex2f(22,15);
    glVertex2f(22,10);
    glVertex2f(11.5,10);
    glEnd();
    glPopMatrix();
}

void road()
{
    glPushMatrix();
    glScaled(40.0,40.0,0.0);
    glBegin(GL_POLYGON); //road
    glColor3f(0.1,0.1,0.1);
    glVertex2f(0,5);
    glVertex2f(40,5);
    glVertex2f(40,9);
    glVertex2f(0,9);
    glEnd();
    glPopMatrix();
}

void bus () {
    glPushMatrix ();
    
//    glTranslated (a, 50.0, 0.0);
    glTranslated (b, 50.0, 0.0);
    glScaled (40.0, 40.0, 0.0);
    glColor3f (0.698, 0.133, 0.133);    //bus body - fill
    glBegin (GL_POLYGON);
    glVertex2f (-25, 8);
    glVertex2f (-25, 9.5);
    glVertex2f (-26, 11);
    glVertex2f (-32, 11);
    glVertex2f (-32, 8);
    glEnd ();
    glColor3f (1.000, 0.894, 0.882);    //Doors
    glBegin (GL_POLYGON);
    glVertex2f (-27, 8.4);
    glVertex2f (-27, 10.4);
    glVertex2f (-27.7, 10.4);
    glVertex2f (-27.7, 8.4);
    glEnd ();
    glColor3f (0, 0, 0);        //window-frame
    glBegin (GL_POLYGON);
    glVertex2f (-27.7, 9.5);
    glVertex2f (-27.7, 10.5);
    glVertex2f (-31.8, 10.5);
    glVertex2f (-31.8, 9.5);
    glEnd ();
    glColor3f(0,1,1); // back windows
    glBegin(GL_POLYGON);
    glVertex2f(-27.8,9.6);
    glVertex2f(-27.8,10.4);
    glVertex2f(-29,10.4);
    glVertex2f(-29,9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-29.1,9.6);
    glVertex2f(-29.1,10.4);
    glVertex2f(-30.2,10.4);
    glVertex2f(-30.2,9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-30.3,9.6);
    glVertex2f(-30.3,10.4);
    glVertex2f(-31.7,10.4);
    glVertex2f(-31.7,9.6);
    glEnd();
    glColor3f (0, 1, 1);        // front window
    glBegin (GL_POLYGON);
    glVertex2f (-25, 9.5);
    glVertex2f (-26, 11);
    glVertex2f (-26, 9.5);
    glEnd ();
    glPopMatrix ();
    glPushMatrix (); //front tyre
//    glTranslated (a + 970, 320, 0.0);
    glTranslated (b - 1300, 320, 0.0);
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
//    glTranslated (a + 1140, 320, 0.0);
    glTranslated (b - 1140, 320, 0.0);
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
//    glTranslated (b, 220.0, 0.0);
    glTranslated (1400 + a, 220.0, 0.0);
    glScaled (-20.0, 20.0, 0.0);
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
    //rounded back
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
void myinit()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPointSize(1.0);
    gluOrtho2D(0.0,1346.0,0.0,728.0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1346,728);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Road safety on highway");
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(myKeyboard);
    myinit();
    glutMainLoop();
    return 0;
}

