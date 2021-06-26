#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

#include<iostream>
using namespace std;

void display();
void reshape(int,int);
void mouse(int,int,int,int);
void timer(int);
void keyboard(unsigned char,int,int);
void motion(int,int);

int arr[50][50]={0};
int arrcopy[50][50];
void init()
{
    glClearColor(0.0, 0, 0.0, 1.0);

}

int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(501,501);

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
    if(startlife==true){
        for(int x=1;x<49;x++){
            for(int y=1;y<49;y++){
                sum=arr[x-1][y+1]+arr[x][y+1]+arr[x+1][y+1]+arr[x+1][y]+arr[x+1][y-1]+arr[x][y-1]+arr[x-1][y-1]+arr[x-1][y];
                if(sum<2)
                    arrcopy[x][y]=0;
                else if(sum==3)
                    arrcopy[x][y]=1;
                else if(sum==2)
                    arrcopy[x][y]=arr[x][y];
                else
                    arrcopy[x][y]=0;

                sum=0;
            }
        }
        for(int i=1;i<49;i++){
            for(int j=1;j<49;j++){
                arr[i][j]=arrcopy[i][j];
            }
        }
        //startlife=false;
    }



    glColor3f(0,0.5,0);
    glBegin(GL_QUADS);

    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){

            if(arr[i][j]==0)
                glColor3f(0,.5,0);
            else if(arr[i][j]==1)
                glColor3f(1,1,0);
            else
                glColor3f(0,0,0);

            glVertex2f(i*10+1,j*10+1);
            glVertex2f(i*10+9,j*10+1);
            glVertex2f(i*10+9,j*10+9);
            glVertex2f(i*10+1,j*10+9);

        }
    }

    glEnd();




    glColor3f(1,1,1);
    /*
    if(checkclick==true){

        glBegin(GL_LINES);
        glVertex2f(mousex,0);
        glVertex2f(mousex,501);
        glVertex2f(0,mousey);
        glVertex2f(501,mousey);
        glEnd();


    }
    */


    glutSwapBuffers();
}

void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity;
    //gluOrtho2D(-250,250,-250,250);
    gluOrtho2D(0,501,0,501);
    glMatrixMode(GL_MODELVIEW);

}



void mouse(int b,int s,int x,int y){

    if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN){
        mousex=x;
        mousey=501-y;
        checkclick=true;
        cout<<"left is clicked "<<x<<" "<<y<<endl;
        arr[int(mousex/10)][int(mousey/10)]=1;
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
    //arr[int(motionx/10)][int(motiony/10)]=2;
}


void keyboard(unsigned char key,int x,int y){

    if(key=='p')
        startlife=true;
    if(key=='o')
        startlife=false;

}
