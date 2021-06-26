#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

#include<iostream>

using namespace std;


void display();
void reshape(int,int);
void timer(int);
void input();
int x=0;
int mina=x;

int j=x;
int temp;
//int change1=38,change2=38;

bool inputTaken = true;
int arr[37]={445,360,240,380,120,186,400,320,175,225,164,239,323,259,118,290,175,432,324,244,180,294,410,380,322,159,441,320,128,161,409,299,135,226,261,196,229};

void draw();

void init(){

    glClearColor(0,0,0,1);

}

int main(int argc,char**argv){

    if(inputTaken==0)
        input();

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowSize(750,500);
    glutInitWindowPosition(10,10);

    glutCreateWindow("visual");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();
    return 0;

}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(0,5);
    glVertex2f(700,5);
    glEnd();


    draw();

    glutSwapBuffers();

    if(x<36){

        if(j<37){
            mina=arr[mina]<arr[j]?mina:j;
            j++;
        }
        else{
            temp=arr[mina];
            arr[mina]=arr[x];
            arr[x]=temp;
            x++;
            mina=x;
            j=x;
        }
    }

}


void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,700,0,500);
    glMatrixMode(GL_MODELVIEW);
}


void timer(int){
    glutPostRedisplay();

    glutTimerFunc(1000/60,timer,0);
}



void input(){
    inputTaken=true;
    cout<<"Enter 10 datas(100~450) : ";
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }

}

void draw(){

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    for(int i=0;i<37;i++){

        if(i<x)
            glColor3f(1,1,1);
        else if(i==j)
            glColor3f(0,0,1);
        else
            glColor3f(1,0,0);


        glVertex2f(i*20 +5,arr[i]);
        glVertex2f(i*20 +5,5);
        glVertex2f(i*20 +15,5);
        glVertex2f(i*20 +15,arr[i]);

    }

    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex2f(0,arr[mina]);
    glVertex2f(750,arr[mina]);
    glEnd();



}
