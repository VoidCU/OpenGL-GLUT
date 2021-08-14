#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<cmath>
#include<iostream>

# define PI           3.14159265358979323846

using namespace std;
void display();
void reshape(int,int);
void timer(int);
void makeflag();


float Ax,Ay,By,Cx,Cy,Dx,Dy,Ex,Ey,Fx,Fy,Gx,Gy;
float Hx,Hy,Ix,Iy,Jx,Jy,Kx,Ky,Lx,Ly,Mx,My,Nx,Ny,Ox,Oy,Px,Py,Qx,Qy,Rx,Ry,Sx,Sy,Tx,Ty,Ux,Uy,Vx,Vy,Wx,Wy,Zx,Zy;
float r1,r2,r3,r4,r5,r6,r7,d,a,n,x,y,z,tn;

float Bx=0;


void init(){
    glClearColor(0,0,0,1);
}

int main(int argc,char**argv){

    makeflag();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("Animation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();

}


float scale=0;
int state=1;
void display(){


    Bx=scale;
    makeflag();
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();




    glTranslatef(-Bx/2,-Bx*3/4,0.0);



    //border
    glColor3f(0,.22,.58);
    glBegin(GL_QUADS);
    glVertex2f(Cx-tn,Cy+2*tn);
    glVertex2f(Ax-tn,Ay-tn);
    glVertex2f(Bx+2*tn,By-tn);
    glVertex2f(Ex+2*tn,Ey-tn);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(Fx+2*tn,Fy-tn);
    glVertex2f(Gx+3*tn,Gy-tn);
    glVertex2f(Cx-tn,Cy+2*tn);
    glEnd();


    //red
    glColor3f(.86,.08,.24);
    glBegin(GL_QUADS);
    glVertex2f(Cx,Cy);
    glVertex2f(Ax,Ay);
    glVertex2f(Bx,By);
    glVertex2f(Ex,Ey);
    glEnd();
    glColor3f(.86,.08,.24);
    glBegin(GL_TRIANGLES);
    glVertex2f(Fx,Fy);
    glVertex2f(Gx,Gy);
    glVertex2f(Cx,Cy);
    glEnd();

    //moon
    glColor3f(1,1,1);


    /*glBegin(GL_LINES);
    glVertex2f(Hx,Hy);
    glVertex2f(Ix,Iy);
    glVertex2f(Jx,Jy);
    glVertex2f(Kx,Ky);
    glVertex2f(Bx,By);
    glVertex2f(Dx,Dy);
    glVertex2f(Px,Py);
    glVertex2f(Qx,Qy);
    glEnd();*/

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(Mx,My);
    glVertex2f(Px,Py);
    for(a=Px;a<=Qx;a++){
        n=My-sqrt(r2*r2-(a-Mx)*(a-Mx));
        glVertex2f(a,n);
    }
    glVertex2f(Qx,Qy);
    glEnd();

    glColor3f(.86,.08,.24);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(Lx,Ly);
    glVertex2f(Px,Py);
    for(a=Px;a<=Qx;a++){
        n=Ly-sqrt(r1*r1-(a-Lx)*(a-Lx));
        glVertex2f(a,n);
    }
    glVertex2f(Qx,Qy);
    glEnd();

    glColor3f(.86,.08,.24);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(Tx,Ty);
    glVertex2f(Rx,Ry);
    for(a=round(Rx+1);a<=Sx;a++){
        n=Ty+sqrt(r4*r4-(a-Tx)*(a-Tx));
        glVertex2f(a,n);
    }
    glVertex2f(Sx,Sy);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(Tx,Ty);
    glVertex2f(Rx,Ry-x);
    glVertex2f(Mx-2.15*x,My-x*1.2);
    glVertex2f(Mx,My);
    for(a=round(Tx-r7+1);a<=Tx+r7;a++){
        n=Ty+sqrt(r7*r7-(a-Tx)*(a-Tx));
        glVertex2f(a,n);
    }
    glVertex2f(Sx,Sy-x);
    glEnd();

    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(Nx,Ny);
    glVertex2f(Nx-r3,Ny);
    glVertex2f(Rx,Ry);
    glVertex2f(Tx-r7,Ty);
    glVertex2f(Mx,My);
    glVertex2f(Tx+r7,Ty);
    glVertex2f(Sx,Sy);
    glVertex2f(Nx+r3,Ny);
    glEnd();


    //moon triangles
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    x=((r4/PI)+r7/PI)/2;
    glVertex2f(Mx,My);
    glVertex2f(Mx+x*3/4,My-x/4);
    glVertex2f(Mx+x*.65,My+x);
    glVertex2f(Mx,My);
    glVertex2f(Mx-x*3/4,My-x/4);
    glVertex2f(Mx-x*.65,My+x);

    glColor3f(1,1,1);
    glVertex2f(Mx+x*3/4,My-x/4);
    glVertex2f(Mx+1.5*x,My-x/2);
    glVertex2f(Mx+1.5*x,My+x*3/4);
    glVertex2f(Mx-x*3/4,My-x/4);
    glVertex2f(Mx-1.5*x,My-x/2);
    glVertex2f(Mx-1.5*x,My+x*3/4);

    glColor3f(1,1,1);
    glVertex2f(Mx+1.5*x,My-x/2);
    glVertex2f(Mx+2.15*x,My-x*1.4);
    glVertex2f(Mx+2.5*x,My+x*.25);
    glVertex2f(Mx-1.5*x,My-x/2);
    glVertex2f(Mx-2.15*x,My-x*1.4);
    glVertex2f(Mx-2.5*x,My+x*.25);

    glColor3f(1,1,1);
    glVertex2f(Mx+2.15*x,My-x*1.4);
    glVertex2f(Mx+2.75*x,My-x*2.25);
    glVertex2f(Mx+3.33*x,My-x*1.1);
    glVertex2f(Mx-2.15*x,My-x*1.4);
    glVertex2f(Mx-2.75*x,My-x*2.25);
    glVertex2f(Mx-3.33*x,My-x*1.1);
    glEnd();
    /*
    glPointSize(10);
     glColor3f(0,.22,.58);
    glBegin(GL_LINES);
    //glVertex2f(Tx,Ty);
    //glColor3f(0,1,0);
    glVertex2f(Ux,Uy);
    glVertex2f(Vx,Vy);
    glVertex2f(Fx,Fy);
    glVertex2f(Ax,Ay);
    glVertex2f(Lx,Ly);
    glVertex2f(Hx,Hy);
    //glVertex2f(Tx+r7,Ty);
    //glVertex2f(Tx-r7,Ty);
    glEnd();

    glColor3f(0,.22,.58);
    glBegin(GL_POINTS);
    //glVertex2f(Tx,Ty);
    //glColor3f(0,1,0);
    //glVertex2f(Sx,Sy);
    //glVertex2f(Rx,Ry);
    //glVertex2f(Px,Py);
    glVertex2f(Wx,Wy);
    glEnd();

*/


    //sun
    glColor3f(.86,.08,.24);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(Wx,Wy);
    for(a=Wx-r6;a<Wx+r6;a++){
        n=Wy-sqrt(r6*r6-(a-Wx)*(a-Wx));
        glVertex2f(a,n);
    }
    glVertex2f(Wx+r6,Wy);
    for(a=Wx+r6;a>Wx-r6;a--){
        n=Wy+sqrt(r6*r6-(a-Wx)*(a-Wx));
        glVertex2f(a,n);
    }
    glVertex2f(Wx-r6,Wy);
    //glVertex2f(Qx,Qy);
    glEnd();


    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(Wx,Wy);
    for(a=Wx-r5;a<Wx+r5;a++){
        n=Wy-sqrt(r5*r5-(a-Wx)*(a-Wx));
        glVertex2f(a,n);
    }
    glVertex2f(Wx+r5,Wy);
    for(a=Wx+r5;a>Wx-r5;a--){
        n=Wy+sqrt(r5*r5-(a-Wx)*(a-Wx));
        glVertex2f(a,n);
    }
    glVertex2f(Wx-r5,Wy);
    //glVertex2f(Qx,Qy);
    glEnd();


    //sun triangles

    /*
    glBegin(GL_POINTS);
    glVertex2f(Wx+r6*cos(0),Wy+r6*sin(0));
    glVertex2f(Wx+r6*cos(PI/6),Wy+r6*sin(PI/6));
    glVertex2f(Wx+r6*cos(PI/3),Wy+r6*sin(PI/3));
    glVertex2f(Wx+r6*cos(PI/2),Wy+r6*sin(PI/2));
    glVertex2f(Wx+r6*cos(PI*2/3),Wy+r6*sin(PI*2/3));
    glVertex2f(Wx+r6*cos(PI*5/6),Wy+r6*sin(PI*5/6));
    glVertex2f(Wx+r6*cos(PI),Wy+r6*sin(PI));
    glVertex2f(Wx+r6*cos(-PI*5/6),Wy+r6*sin(-PI*5/6));
    glVertex2f(Wx+r6*cos(-PI*2/3),Wy+r6*sin(-PI*2/3));
    glVertex2f(Wx+r6*cos(-PI/2),Wy+r6*sin(-PI/2));
    glVertex2f(Wx+r6*cos(-PI/3),Wy+r6*sin(-PI/3));
    glVertex2f(Wx+r6*cos(-PI/6),Wy+r6*sin(-PI/6));
    glColor3f(0,0,0);
    glVertex2f(Wx+r5*cos(PI/12),Wy+r5*sin(PI/12));
    glVertex2f(Wx+r5*cos(PI/4),Wy+r5*sin(PI/4));
    glVertex2f(Wx+r5*cos(PI*5/12),Wy+r5*sin(PI*5/12));
    glVertex2f(Wx+r5*cos(PI*7/12),Wy+r5*sin(PI*7/12));
    glVertex2f(Wx+r5*cos(PI*3/4),Wy+r5*sin(PI*3/4));
    glVertex2f(Wx+r5*cos(PI*11/12),Wy+r5*sin(PI*11/12));
    glVertex2f(Wx+r5*cos(-PI*11/12),Wy+r5*sin(-PI*11/12));
    glVertex2f(Wx+r5*cos(-PI*3/4),Wy+r5*sin(-PI*3/4));
    glVertex2f(Wx+r5*cos(-PI*7/12),Wy+r5*sin(-PI*7/12));
    glVertex2f(Wx+r5*cos(-PI*5/12),Wy+r5*sin(-PI*5/12));
    glVertex2f(Wx+r5*cos(-PI/4),Wy+r5*sin(-PI/4));
    glVertex2f(Wx+r5*cos(-PI/12),Wy+r5*sin(-PI/12));

    glEnd();
    */

    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
    glVertex2f(Wx+r5*cos(PI/12),Wy+r5*sin(PI/12));
    glVertex2f(Wx+r6*cos(PI/6),Wy+r6*sin(PI/6));
    glVertex2f(Wx+r5*cos(PI/4),Wy+r5*sin(PI/4));

    glVertex2f(Wx+r5*cos(PI/4),Wy+r5*sin(PI/4));
    glVertex2f(Wx+r6*cos(PI/3),Wy+r6*sin(PI/3));
    glVertex2f(Wx+r5*cos(PI*5/12),Wy+r5*sin(PI*5/12));

    glVertex2f(Wx+r5*cos(PI*5/12),Wy+r5*sin(PI*5/12));
    glVertex2f(Wx+r6*cos(PI/2),Wy+r6*sin(PI/2));
    glVertex2f(Wx+r5*cos(PI*7/12),Wy+r5*sin(PI*7/12));

    glVertex2f(Wx+r5*cos(PI*7/12),Wy+r5*sin(PI*7/12));
    glVertex2f(Wx+r6*cos(PI*2/3),Wy+r6*sin(PI*2/3));
    glVertex2f(Wx+r5*cos(PI*3/4),Wy+r5*sin(PI*3/4));

    glVertex2f(Wx+r5*cos(PI*3/4),Wy+r5*sin(PI*3/4));
    glVertex2f(Wx+r6*cos(PI*5/6),Wy+r6*sin(PI*5/6));
    glVertex2f(Wx+r5*cos(PI*11/12),Wy+r5*sin(PI*11/12));

    glVertex2f(Wx+r5*cos(PI*11/12),Wy+r5*sin(PI*11/12));
    glVertex2f(Wx+r6*cos(PI),Wy+r6*sin(PI));
    glVertex2f(Wx+r5*cos(-PI*11/12),Wy+r5*sin(-PI*11/12));

    glVertex2f(Wx+r5*cos(-PI*11/12),Wy+r5*sin(-PI*11/12));
    glVertex2f(Wx+r6*cos(-PI*5/6),Wy+r6*sin(-PI*5/6));
    glVertex2f(Wx+r5*cos(-PI*3/4),Wy+r5*sin(-PI*3/4));

    glVertex2f(Wx+r5*cos(-PI*3/4),Wy+r5*sin(-PI*3/4));
    glVertex2f(Wx+r6*cos(-PI*2/3),Wy+r6*sin(-PI*2/3));
    glVertex2f(Wx+r5*cos(-PI*7/12),Wy+r5*sin(-PI*7/12));

    glVertex2f(Wx+r5*cos(-PI*7/12),Wy+r5*sin(-PI*7/12));
    glVertex2f(Wx+r6*cos(-PI/2),Wy+r6*sin(-PI/2));
    glVertex2f(Wx+r5*cos(-PI*5/12),Wy+r5*sin(-PI*5/12));

    glVertex2f(Wx+r5*cos(-PI*5/12),Wy+r5*sin(-PI*5/12));
    glVertex2f(Wx+r6*cos(-PI/3),Wy+r6*sin(-PI/3));
    glVertex2f(Wx+r5*cos(-PI/4),Wy+r5*sin(-PI/4));

    glVertex2f(Wx+r5*cos(-PI/4),Wy+r5*sin(-PI/4));
    glVertex2f(Wx+r6*cos(-PI/6),Wy+r6*sin(-PI/6));
    glVertex2f(Wx+r5*cos(-PI/12),Wy+r5*sin(-PI/12));

    glVertex2f(Wx+r5*cos(-PI/12),Wy+r5*sin(-PI/12));
    glVertex2f(Wx+r6*cos(0),Wy+r6*sin(0));
    glVertex2f(Wx+r5*cos(PI/12),Wy+r5*sin(PI/12));

    glEnd();







    glutSwapBuffers();
}


void reshape(int w,int h){

    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250,250,-250,250);
    glMatrixMode(GL_MODELVIEW);

}

void timer(int){
    glutPostRedisplay();

    switch(state){
    case 1:
        if(Bx<300)
            scale+=1;
        else
            state=-1;
        break;
    case -1:
        if(Bx>0)
            scale-=1;
        else
            state=1;
        break;

    }

    glutTimerFunc(1000/60,timer,0);
}



void makeflag(){
    Ax=0;
    Ay=0;
    //Bx=100;
    By=Ay;
    Cy=Bx*4/3;
    Cx=Ax;
    Dx=Ax;
    Dy=Bx;
    Ex=Bx-Bx*cos(PI/4);
    Ey=sqrt(Bx*Bx-(Bx-Ex)*(Bx-Ex));
    Fx=Ax;
    Fy=Ey;
    Gx=Bx;
    Gy=Ey;

    Hx=Bx/4;
    Hy=Ay;

    Ix=Hx;
    Iy=Cy+((Gy-Cy)/(Gx-Cx))*(Hx-Cx);
    Jx=Ax;
    Jy=(Cy+Fy)/2;
    Ky=Jy;
    Kx=Cx+((Gx-Cx)/(Gy-Cy))*(Ky-Cy);
    Lx=Hx;
    Ly=Jy;

    Mx=Hx;
    My=Jy+((Gy-Jy)/(Gx-Jx))*(Mx-Jx);
    Nx= Hx;
    d=(abs(-(Mx/Bx)-(My/Dy)+1))/sqrt(1/(Bx*Bx)+1/(Dy*Dy));
    Ny=My-d;
    Oy=My;
    Ox=Ax;
    //1sthalf circle center L
    r1=Ly-Ny;
    Py=Oy;
    Qy=Oy;
    Px=Lx-sqrt(r1*r1-(Py-Ly)*(Py-Ly));
    Qx=sqrt(r1*r1-(Qy-Ly)*(Qy-Ly))+Lx;

    //2nd circle center M
    r2=Qx-Mx;

    //3rd circle center N
    r3=My-Ny;

    Tx=Hx;
    Ty=Ny+(My-Ny)/PI;

    Ry=Ty;
    Sy=Ty;

    Rx=Nx-sqrt((My-Ny)*(My-Ny)-(Ry-Ny)*(Ry-Ny));
    Sx=Tx+(Tx-Rx);
    //4th circle radius t
    r4=Sx-Tx;

    //7th circle
    r7=My-Ty;



    Uy=(Fy-Ay)/2;
    Ux=Ax;
    Vy=Uy;
    Vx=Dx+((Bx-Dx)/(By-Dy))*(Vy-Dy);
    Wx=Hx;
    Wy=Vy;
    //5th circle
    r5=My-Ny;

    //6th circcle
    r6=Ly-Ny;
    Zx=Hx;
    Zy=My-(Qx-Mx);
    tn=Ty-Ny;




}
