#include<bits/stdc++.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

#define int GLint
#define PI 3.1416

GLint i, j, k;
GLfloat sun_spin=0, sun_x=0, sun_y=0;
GLfloat ax=0,bx=0,cx=0,dx=0,str=500.0,mn=500.0;
GLfloat sr=0.0,sg=0.749,sb=1.0;
GLfloat spin = 0.0;
bool f=1;
float pos1=0,pos3=600,pos2=400,speed1=2.5f, speed2=2.5f, speed3=2.5f;

///Circle
void circle(GLfloat x, GLfloat y, GLfloat rad){
    GLint triangle_amt=60,i;
    GLfloat t_pi=2*PI;
    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(43,78,88);
    glVertex2f(x,y);
    for(i=0;i<=triangle_amt;i++){
        GLfloat dx=rad*cos(i*t_pi/triangle_amt), dy=rad*sin(i*t_pi/triangle_amt);
        ///cout<<"---"<<x<<" "<<y<<" "<<dx<<" "<<dy<<"---"<<endl;
        glVertex2f(x+dx,y+dy);
    }
    glEnd();
}
///Cloud Model-1
void cloudModel1(){

    glColor3f(1.25,0.924,0.930);

    glPushMatrix();
    circle(320,210,15);///Left
    circle(340,225,16);///Top
    circle(360,210,16);///Right
    ///Bottom
    circle(330, 210, 16);
    circle(340, 210, 16);
    circle(350, 210, 16);

    glPopMatrix();

}
///Cloud Model-2
void cloudModel2(){

    glColor3f(1.25,0.924,0.930);

    glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();
}
///Cloud Model-3
void cloudModel3(){

    glColor3f(1.25,0.924,0.930);

    glPushMatrix();
    circle(300,200,15);///Left
    circle(320,210,15);///Top_Left
    circle(340,220,16);///Top
    circle(360, 210, 15);///Top_Right
    circle(380,200,15);///Right
    circle(360,190,20);///Bottom_Right
    circle(320,190,20);///Bottom_Left
    circle(340,190,20);///Bottom
    glPopMatrix();
}

///Hill Model
///Big hill
void hill_big(){
    glBegin(GL_POLYGON);
    //glColor3ub(96, 118, 130);
    glVertex2i(70,70);
    glVertex2i(200,225);
    glVertex2i(330,70);
    glEnd();
    ///snow
    glBegin(GL_POLYGON);
    glColor3f(255,255,255);
    glVertex2i(200,225);
    glVertex2i(230,190);
    glVertex2i(220,180);
    glVertex2i(200,190);
    glVertex2i(190,180);
    glVertex2i(170,190);
    glEnd();

}
///Small_hill
void hill_small(){
    ///Hill_Small
	glBegin(GL_POLYGON);
    ///glColor3f(0.11, 0.23, 0.36);
	glVertex2i(250, 100);
	glVertex2i(310, 175);
	glVertex2i(370, 100);

	glEnd();

    ///Hill_Small_Snow
	glBegin(GL_POLYGON);
    glColor3f(1.25, 0.924, 0.930);
    glVertex2i(290, 150);
	glVertex2i(310, 175);
	glVertex2i(330, 150);
	glVertex2i(325, 140);
	glVertex2i(310, 150);
	glVertex2i(300, 140);
	glEnd();
}
///Tilla
void tillaModel1(){

	glBegin(GL_POLYGON);
	if(f)glColor3f(0.1, 1.293, 0.0);
	else glColor3ub(15, 59, 11);
	glVertex2i(125, 70);
	glVertex2i(150, 80);
	glVertex2i(160, 90);
	glVertex2i(170, 90);
	glVertex2i(180, 100);
	glVertex2i(190, 105);
	glVertex2i(200, 108);
	glVertex2i(300, 110);
	glVertex2i(300, 70);

	glEnd();

}
void tillaModel2(){
    if(f)glColor3f(0.1, 1.293, 0.0);
	else glColor3ub(15, 59, 11);
    glPushMatrix();
    circle(430,90,30);
    circle(420,87,30);
    circle(410,80,30);
    circle(400,80,30);
    circle(390,70,30);
    circle(445,80,30);
    circle(455,75,30);
    circle(465,70,30);
    circle(470,65,30);
    circle(480,60,30);
    circle(485,55,20);
    glPopMatrix();
}

void house(){
    ///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);
	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);
	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();
    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();
    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);
	glEnd();
    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);
	glVertex2i(310, 90);
	glVertex2i(310, 75);
	glEnd();
    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);
	glEnd();
    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();

}

void house2(){
    ///body
    glTranslatef(50,100,0);
    glColor3ub(64, 73, 237);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(100,0);
    glVertex2i(100,49);
    glVertex2i(0,49);
    glEnd();
    ///roof
    glBegin(GL_POLYGON);
    glColor3ub(255,0,0);
    glVertex2i(0,50);
    glVertex2i(105,50);
    glVertex2i(105,60);
    glVertex2i(0,67);
    glEnd();

    ///window1
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(15,7);
    glVertex2i(35,7);
    glVertex2i(35,25);
    glVertex2i(15,25);
    glEnd();
    ///window2
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(78,7);
    glVertex2i(95,7);
    glVertex2i(95,25);
    glVertex2i(78,25);
    glEnd();

    ///door
    glBegin(GL_POLYGON);
    glColor3ub(35, 36, 54);
    glVertex2i(42,0);
    glVertex2i(68,0);
    glVertex2i(68,33);
    glVertex2i(42,33);
    glEnd();

    ///extra design

    glBegin(GL_POLYGON);
    glColor3ub(224, 169, 121);
    glVertex2i(-20,0);
    glVertex2i(0,0);
    glVertex2i(0,70);
    glVertex2i(-20,70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(47, 38, 224);
    glVertex2i(-20,70);
    glVertex2i(0,70);
    glVertex2i(-5,80);
    glVertex2i(-25,80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(224, 169, 121);
    glVertex2i(-25,10);
    glVertex2i(-20,0);
    glVertex2i(-20,70);
    glVertex2i(-25,80);
    glEnd();



}
///Field Model
void field(){
    ///Field
	glBegin(GL_POLYGON);
    glColor3f(0.533, 1.293, 0.0);
	glVertex2i(0, 200);
	glVertex2i(0, 220);
	glVertex2i(1000, 220);
	glVertex2i(1000, 200);

	glEnd();


    ///Field_Shadow
	glBegin(GL_POLYGON);
	glColor3f(0.1, 1.293, 0.0);
	glVertex2i(0, 180);
	glVertex2i(1000, 180);
	glVertex2i(1000,200);
	glVertex2i(0, 200);

	glEnd();


}
///Tree Model
void treeModel1(){
    glColor3ub(0, 173, 36);
    circle(110,110,15);
    circle(110,100,15);
    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(109,70);
    glVertex2i(109,90);
    glVertex2i(111,90);
    glVertex2i(111,70);
    glEnd();
}

void treeModel2(){
    glColor3ub(0, 173, 36);
    circle(130,130,5);
    circle(125,126,5);
    circle(135,126,5);
    circle(130,125,5);

    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(129,110);
    glVertex2i(129,124);
    glVertex2i(131,124);
    glVertex2i(131,110);
    glEnd();
}
void treeModel3(){
    glColor3ub(0, 173, 36);
    glBegin(GL_POLYGON);
    glVertex2i(125,123);
    glVertex2i(133,145);
    glVertex2i(141,123);
    glEnd();

    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(132,110);
    glVertex2i(132,124);
    glVertex2i(134,124);
    glVertex2i(134,110);
    glEnd();
}

void init(void){
	glClearColor(0.65, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}
///windmill stand
void Windmill_Stand_Model(){
    glColor3f(0.38, 0.41, 0.36);
    glBegin(GL_POLYGON);
    glVertex2i(375, 100);
    glVertex2i(380, 240);
    glVertex2i(384, 240);
    glVertex2i(390, 100);
    glEnd();
}
///windmill blade
void Windmill_Blade(){

    ///Blade_One
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(-5, 0);
    glVertex2i(-85, -36);
    glVertex2i(-83, -37);
    glVertex2i(-3, -8);
    glEnd();
    glPopMatrix();

    ///Blade_Two
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(0, 5);
    glVertex2i(45, 70);
    glVertex2i(50, 73);
    glVertex2i(5, 0);
    glEnd();
    glPopMatrix();

    ///Blade_Three
    glPushMatrix();
    glRotatef(spin,0,0,90);
    glBegin(GL_POLYGON);
    glVertex2i(68, -78);
    glVertex2i(0,0);
    glVertex2i(5, 5);
    glVertex2i(70, -77);
    glEnd();
    glPopMatrix();

}
void boat1(){
    glTranslatef(50,100,0);
    glColor3ub(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(20,0);
    glVertex2i(70,0);
    glVertex2i(90,20);
    glVertex2i(0,20);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2i(20,20);
    glVertex2i(45,20);
    glVertex2i(45,40);

    glVertex2i(47,20);
    glVertex2i(72,20);
    glVertex2i(47,38);
    glEnd();

}
/// windmill
void Windmill(){
    ///Windmill_Stand
    glColor3f(0.38, 0.41, 0.36);
    glPushMatrix();
    Windmill_Stand_Model();
    glPopMatrix();

    ///Windmill_Motor
    if(f)glColor3f(0.11, 0.23, 0.36);
    else glColor3ub(107, 130, 199);
    circle(380,250,10);

    ///Windmill_Rotary_Blades
    if(f)glColor3f(0.11, 0.23, 0.36);
    else glColor3ub(107, 130, 199);
    glPushMatrix();
    glTranslatef(380,251,0);
    Windmill_Blade();
    glPopMatrix();

}
///Object Creation


void rightBigHill1(){
    glPushMatrix();
    glTranslatef(600,150,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(0,0,0);
    hill_big();
    glPopMatrix();
}
void rightBigHill2(){
    glPushMatrix();
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(31, 40, 66);
    glTranslatef(550,130,0);
    hill_big();
    glPopMatrix();
}
void leftSmallHill(){
    glPushMatrix();
    glTranslatef(0,120,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(31, 40, 66);
    hill_small();
    glPopMatrix();
}
void rightHouse(){
    glPushMatrix();
    glTranslatef(400,150,0);
    house();
    glPopMatrix();
}
void leftHouse(){
    glPushMatrix();
    glTranslatef(420,120,0);
    house2();
    glPopMatrix();
}
void rightTillaL(){
    glPushMatrix();
    glTranslatef(400,150,0);
    tillaModel1();
    glPopMatrix();
}
void leftTillaL(){
    glPushMatrix();
    glTranslatef(0,150,0);
    tillaModel1();
    glPopMatrix();
}
void rightTillaR(){
    glPushMatrix();
    glTranslatef(500,150,0);
    tillaModel2();
    glPopMatrix();
}
void rightWindmMill(){
    glPushMatrix();
    glTranslatef(530,150,0);
    Windmill();
    glPopMatrix();
}
void leftWindMill(){
    glPushMatrix();
    glTranslatef(0,150,0);
    Windmill();
    glPopMatrix();
}
void leftHillBig(){
    glPushMatrix();

    glTranslatef(0,130,0);
    if(f)glColor3ub(96, 118, 130);
    else glColor3ub(0,0,0);
    hill_big();
    glPopMatrix();
}
void leftTillaL1(){
    glPushMatrix();
    glTranslatef(-140,150,0);
    tillaModel1();
    glPopMatrix();
}

void leftTillaR(){
    glPushMatrix();
    glTranslatef(0,150,0);
    tillaModel2();
    glPopMatrix();
}
void boatA(){
    glPushMatrix();
    glTranslatef(pos1,-15,0);
    boat1();
    glPopMatrix();
}

void boatB(){
    glPushMatrix();
    glTranslatef(pos2,35,0);
    boat1();
    glPopMatrix();
}
void boatC(){
    glPushMatrix();
    glTranslatef(pos3,-70,0);
    boat1();
    glPopMatrix();
}

void tree1(){
    glPushMatrix();
    glTranslatef(0,188,0);
    treeModel1();
    glPopMatrix();
}
void tree2(){
    glPushMatrix();
    glTranslatef(-90,140,0);
    treeModel2();
    glPopMatrix();
}
void tree3(){
    glPushMatrix();
    glTranslatef(-110,130,0);
    treeModel3();
    glPopMatrix();
}
void sky(){
    glPushMatrix();
    if(f)glColor3ub(157, 216, 250);
    else glColor3ub(4, 11, 51);
    glBegin(GL_POLYGON);
    glVertex2i(0,250);
    glVertex2i(1000,250);
    glVertex2i(1000,500);
    glVertex2i(0,500);
    glEnd();
    glPopMatrix();
}
void water(){
    if(f)glColor3ub(107, 117, 255);
    else glColor3ub(0, 10, 143);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(1000,0);
    glVertex2i(1000,250);
    glVertex2i(0,250);
    glEnd();
    glPopMatrix();

}
void sun(){
    if(f){
        glPushMatrix();
        glColor3ub(252, 212, 64);
        circle(620,300,30);
        glPopMatrix();
    }
}
void moon(){
    if(!f){
        glPushMatrix();
        glColor3ub(244, 246, 240);
        circle(620,360,30);
        glColor3ub(4, 11, 51);
        circle(630,380,30);
        glPopMatrix();
    }
}
void star(){
    if(!f){
        glPushMatrix();
        glColor3ub(255,255,255);
        glPointSize(4);
        glBegin(GL_POINTS);

        glVertex2i(100,400);
        glVertex2i(120,420);
        glVertex2i(150,450);
        glVertex2i(170,470);
        glVertex2i(200,430);
        glVertex2i(230,470);
        glVertex2i(350,460);
        glVertex2i(100,400);
        glVertex2i(500,470);
        glVertex2i(400,460);
        glVertex2i(700,400);
        glEnd();


        glPopMatrix();
    }
}


///Main
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255.0,0.0,1.0);
	///Day Scenario
	sky();
	water();
	star();
    rightTillaL();
    rightWindmMill();
    rightBigHill1();
    rightBigHill2();
    rightTillaR();
    rightHouse();

    leftTillaL1();
    leftHillBig();
    leftSmallHill();

    leftWindMill();
    leftTillaR();
    field();
    ///Boat
    boatA();
    boatB();
    boatC();
    leftHouse();

    ///Tree
    tree1();
    tree2();
    tree3();

    sun();
    moon();

	glFlush();
}

void sun_move(){
    sun_spin = sun_spin + 0.0008;
}
void move_right(){

    sun_move();
    spin = spin +.1;
    ax = ax + .05;
    bx = bx + .08;
    cx = cx + .10;
    dx = dx + .15;

    if(cx>1000){
        cx = -300;
    }
    if(bx>1000){
            bx= -400;

    }
    if(cx>1000){
            cx= -400;

    }
    if(dx>1000){
            dx= -500;

    }


    glutPostRedisplay();
}
void update(int value){
    if(pos1>980)pos1=-100;
    if(pos2>980)pos2=-100;
    if(pos3<20)pos3=1000;
    pos1+=speed1;
    pos2+=speed2;
    pos3-=speed3;
    if(f){
        //glColor3ub(0,0,0);
    }
    else{

    }
    glutTimerFunc(100, update, 0);

}


void handleMouse(int key, int state, int x, int y){
    switch (key)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(move_right);
        }
        break;
    case GLUT_MIDDLE_BUTTON:
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    default:
        break;
    }
}
void handleKeypress(unsigned char key, int x, int y) {

	switch (key){
        case 'd':
            f=1;
            break;
        case 'n':
            f=0;
            break;
        glutPostRedisplay();
	}
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1900, 1900);
	glutCreateWindow("Smart Village");
	init();
	glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(1000, update, 0);
    glutMainLoop();
}
