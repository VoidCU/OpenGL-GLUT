#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

#include<math.h>
#include<cmath>

#define PI 3.14159265358979323846


#include<iostream>
#include<ctime>
using namespace std;

void display();
void reshape(int,int);
void mouse(int,int,int,int);
void timer(int);
void keyboard(unsigned char,int,int);
void motion(int,int);
void draw();


time_t now=time(0);
int sec,miu,hour;
int r1=230,r2=200,r3=100;
int clockradius=250;
int cover=10;
int n;



void init()
{
    glClearColor(0.0, 0, 0.0, 1.0);

}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("My First");
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();
    return 0;
}

bool startlife=false;
float mousex;
float mousey;
float motionx;
float motiony;
bool checkclick=false;
int sum;

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    now=time(0);
    tm *ltm = localtime(&now);
    sec=ltm->tm_sec;
    miu=ltm->tm_min;
    hour=ltm->tm_hour;


    //cout<<miu<<" "<<sec<<endl;
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0,0);
    for(int a=0-clockradius;a<0+clockradius;a++){
        n=0-sqrt(clockradius*clockradius-(a-0)*(a-0));
        glVertex2f(a,n);
    }
    glVertex2f(0+clockradius,0);
    for(int a=0-clockradius;a<0+clockradius;a++){
        n=0+sqrt(clockradius*clockradius-(a-0)*(a-0));
        glVertex2f(a,n);
    }
    glVertex2f(0+clockradius,0);
    glEnd();
    draw();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0,0);
    for(int a=0-cover;a<0+cover;a++){
        n=0-sqrt(cover*cover-(a-0)*(a-0));
        glVertex2f(a,n);
    }
    glVertex2f(0+cover,0);
    for(int a=0-cover;a<0+cover;a++){
        n=0+sqrt(cover*cover-(a-0)*(a-0));
        glVertex2f(a,n);
    }
    glVertex2f(0+cover,0);
    glEnd();

    //points
    glColor3f(0,0,0);
    glPointSize(20);
    glBegin(GL_POINTS);
    glVertex2f(0,240);
    glVertex2f(0,-240);
    glVertex2f(240,0);
    glVertex2f(-240,0);
    glEnd();

    glRotated(30,0,0,1);
    glBegin(GL_POINTS);
    glVertex2f(0,240);
    glVertex2f(0,-240);
    glVertex2f(240,0);
    glVertex2f(-240,0);
    glEnd();

    glRotated(30,0,0,1);
    glBegin(GL_POINTS);
    glVertex2f(0,240);
    glVertex2f(0,-240);
    glVertex2f(240,0);
    glVertex2f(-240,0);
    glEnd();



    glutSwapBuffers();
}

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity;
    //gluOrtho2D(-250,250,-250,250);
    gluOrtho2D(-250,250,-250,250);
    glMatrixMode(GL_MODELVIEW);

}



void mouse(int b,int s,int x,int y){

    if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN){
        mousex=x;
        mousey=500-y;
        checkclick=true;
        cout<<"left is clicked "<<x<<" "<<y<<endl;
    }

}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/10,timer,0);

}

void motion(int x,int y){
    cout<<x<<" "<<y<<endl;
    motionx=x;
    motiony=501-y;
}


void keyboard(unsigned char key,int x,int y){

    if(key=='p')
        startlife=true;
    if(key=='o')
        startlife=false;

}


void draw(){
    glColor3f(1,0,0);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(0,0);
    glEnd();

    //hour

    glRotatef(hour*(-30),0,0,1);
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-8,0);
    glVertex2f(8,0);
    glVertex2f(8,r3);
    glVertex2f(-8,r3);
    glEnd();

    glLoadIdentity();


    //min
    glRotatef(miu*(-6),0,0,1);
    glColor3f(0,0,1);
    glBegin(GL_QUADS);
    glVertex2f(-4,0);
    glVertex2f(4,0);
    glVertex2f(4,r2);
    glVertex2f(-4,r2);
    glEnd();

    glLoadIdentity();
    //glRotatef(miu*6,0,0,0);



    //sec

    //glTranslatef(-50,-50,0);
    glRotatef(sec*(-6),0,0,1);
    //glTranslatef(-50,-50,0);

    glColor3f(0,1,0);
    glBegin(GL_QUADS);
    glVertex2f(-2,0);
    glVertex2f(2,0);
    glVertex2f(2,r1);
    glVertex2f(-2,r1);
    glEnd();
    glLoadIdentity();


}
