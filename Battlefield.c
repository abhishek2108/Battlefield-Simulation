/*
*****************BATTLEFIELD**********************
Project By:
 ABHISHEK KUMAR SINGH - 1PE11CS005

**************************************************
*/


#include<GL/glut.h>
#include<stdio.h>

//global declaration of the variables

static int slices = 36;
static int stacks = 36;

float i, n=0.0;
float p,q,a,b,r,g=0.0,s=0.0,t,in,x1=0.0,y1=0.0;
int itc=1,sub,te,gh=0,wb=0,fh=0;
int gg=0;
float gt=0.0,u=0.0,v=0.0,uu=0.0,vv=0.0;
int tankhit=0, planehit=0;

//Functions prototypes

void main_menu(int);
void bomb();
void hide();
void explodeplane();


//Function to launch the bomb from the tank

void tank()
{
glColor3d(0.0,0.0,0.0);
glPushMatrix();
glTranslated(0.88+n+x1,-0.23+y1,0.1);
glutSolidSphere(0.02,slices,stacks);
glPopMatrix();
}


//Function to explaode the tank

void explode()
{
    if(s>=1.0)
    {
        glColor3d(1.0,1.0,0.0);
        glPushMatrix();
        glTranslated(-0.50+i,-0.40,0.1);
        glutSolidSphere(0.3+g,slices,stacks);
        glPopMatrix();
        if(0.2+n<i-0.2&&1.2+n>i-0.2)
        {
            u=0.3;v=0.3;
        }
        if(g<.5)
        {
            g=g+0.01;
            glutPostRedisplay();
        }
        else
        {
            g=g-.5;
            tankhit++;
        }
    }
}


//Function to explaode the plane

void explodeplane()
{
    if(x1>=1.0)
    {
		glColor3d(1.0,1.0,0.0);
        glPushMatrix();
        glTranslated(1.70+n,0.50,0.1);
        glutSolidSphere(0.3+gt,slices,stacks);
        glPopMatrix();
        if(-1.0+i<n+x1+0.9&&-0.2+i>n+x1+0.9)
        {
            uu=0.0;vv=-1.0;
            planehit++;
		}
        if(gt<.5)
        {
            gt=gt+0.01;
            glutPostRedisplay();
        }
        else
        {
            gt=gt-.5;
        }
	}
}


//Function for light  effect

void lighteff()
{
    GLfloat mat_ambient[] = {0.2,0.2,0.2,1.0};
    GLfloat mat_diffuse[] = {1.,.8,0.0,1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {8.0};
    GLfloat light_position[] = {-1.0,.0,.1,1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
}

//Function to  create the menu

void create_menu()
{
    glutCreateMenu(main_menu);
    glutAddMenuEntry("PRESS  q  TO MOVE TANK LEFT",0);
    glutAddMenuEntry("PRESS  w  TO MOVE TANK RIGHT",0);
    glutAddMenuEntry("PRESS  g  TO DROP BOMB FROM PLANE",0);
    glutAddMenuEntry("PRESS  h  TO LAUNCH BOMB FROM TANK",0);
    glutAddMenuEntry("PRESS  l  TO NIGHT EFFECT",0);
	glutAddMenuEntry("QUIT",itc);
    glutAttachMenu(GLUT_LEFT_BUTTON);
}


//main menu function

void main_menu(int itc)
{
    if(itc==1)
	exit(0);
}


//keyboard interaction

GLfloat viewer[]={0.0,0.0,5.0};
void key(unsigned char key,int x,int y)
{
    if(key=='w')
	{
      	n=n+0.1;
        glutPostRedisplay();
    }
	if(key=='q')
	{
		n=n-0.1;
		glutPostRedisplay();
    }
    if(key=='g')
	{
        wb=1;
        glutPostRedisplay();
	}
    if(key=='l')
    {
        gh=1;
    }
    if(key=='h')
	{
		gg=1;
		glutPostRedisplay();
    }
}



//function for fill to reappear

void hill()
{
    if(in<1.0)
	{
		in=in+0.01;
		glutPostRedisplay();
	}
	else
	{
		in=0.0;
	}

}


//functio to give the moment to plane

void moment()
{
    explodeplane();
    if(i<2.0)
    {
        i=i+0.01;
        glutPostRedisplay();
    }
    else
    {
        i=i-3.0;
    }
}



// function to draw the plane ,hill and tree

void drawplane()
{
    float we=0.0;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

// Draw hills
      glColor3f(.5,0.5,1.5);
      glBegin(GL_POLYGON);
      glVertex3f(-1.1,0.0,0.2);
      glVertex3f(-1.1,1.,0.9);
      glVertex3f(+1.1,1.,0.2);
      glVertex3f(+1.1,0.0,0.2);
      glEnd();

//Draw cloud
    glColor3d(0.5,0.5,0.5);
    glPushMatrix();
    glTranslated(-0.45,0.75,0.1);
    glutSolidSphere(0.04,slices,stacks);
    glPopMatrix();

//Draw cloud
    glColor3d(.5,0.5,0.5);
    glPushMatrix();
    glTranslated(-0.519,0.66,0.1);
    glutSolidSphere(0.08,slices,stacks);
    glPopMatrix();

//Draw cloud
    glColor3d(0.5,0.5,0.5);
    glPushMatrix();
    glTranslated(-0.537,0.761,0.1);
    glutSolidSphere(0.06,slices,stacks);
    glPopMatrix();

//Draw cloud
    glColor3d(0.5,0.5,0.5);
    glPushMatrix();
    glTranslated(0.45,0.65,0.1);
    glutSolidSphere(0.04,slices,stacks);
    glPopMatrix();

//Draw cloud
    glColor3d(.5,0.5,0.5);
    glPushMatrix();
    glTranslated(0.519,0.56,0.1);
    glutSolidSphere(0.08,slices,stacks);
    glPopMatrix();

//Draw cloud
    glColor3d(0.5,0.5,0.5);
    glPushMatrix();
    glTranslated(0.537,0.661,0.1);
    glutSolidSphere(0.06,slices,stacks);
    glPopMatrix();


//Draw hill
    glColor3f(.5,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex3f(-1.1,0.0,0.2);
    glVertex3f(-1.1,-1.,0.9);
    glVertex3f(+1.1,-1.,0.2);
    glVertex3f(+1.1,0.0,0.2);
    glEnd();

//Draw hill
    glColor3f(.5,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-1.1-in,-0.2,0.2);
	glVertex3f(-0.7-in,0.9,0.9);
	glVertex3f(-.1-in,-0.2,0.2);
    glEnd();


//Draw hill
    glColor3f(.5,0.5,0.0);
    glBegin(GL_POLYGON);
	glVertex3f(-0.6-in,-0.2,0.2);
	glVertex3f(-0.2-in,0.9,0.9);
	glVertex3f(0.4-in,-0.2,0.2);
    glEnd();

//Draw hill
    glColor3f(.5,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.1-in,-0.2,0.2);
    glVertex3f(0.3-in,0.9,0.9);
    glVertex3f(0.9-in,-0.2,0.2);
    glEnd();

//Draw hill
    glColor3f(.5,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(.4-in,-0.2,0.2);
	glVertex3f(.8-in,0.9,0.9);
	glVertex3f(1.4-in,-0.2,0.2);
    glEnd();

//Draw hill
    glColor3f(.5,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(.9-in,-0.2,0.2);
    glVertex3f(1.2-in,0.9,0.9);
    glVertex3f(1.9-in,-0.2,0.2);
    glEnd();

//Draw hill
    glColor3f(.5,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.4-in,-0.2,0.2);
    glVertex3f(1.9-in,0.9,0.9);
    glVertex3f(2.4-in,-0.2,0.2);
    glEnd();

//Draw hill
    glColor3f(.5,0.5,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(1.9-in,-0.2,0.2);
    glVertex3f(2.4-in,0.9,0.9);
    glVertex3f(2.9-in,-0.2,0.2);
    glEnd();

    hill();                             //function call to hill


    glColor3d(0.1,0.1,0.1);
    glPushMatrix();
    glTranslated(-.51+i,0.72-s,0.0);
    glutSolidSphere(0.02,slices,stacks);
    glPopMatrix();


    glBegin(GL_POLYGON);
    glShadeModel(GL_SMOOTH);
	glColor3f(1.0,.0,.0);
	glVertex2f(-0.2+i+uu,0.7+vv);
	glColor3f(.0,1.,0.0);               //to draw the body of the plane
	glVertex2f(-0.33+i+uu,0.66+vv);
	glColor3f(.0,.0,1.0);
	glVertex2f(-0.88+i+uu,0.66+vv);
	glColor3f(1.0,1.0,.0);
	glVertex2f(-0.88+i+uu,0.73+vv);
	glColor3f(1.0,.0,.0);
	glVertex2f(-0.5+i+uu,0.79+vv);
	glColor3f(1.0,.0,.0);
	glVertex2f(-0.5+i+uu,0.75+vv);
	glColor3f(1.0,.0,1.0);
	glVertex2f(-0.33+i+uu,0.75+vv);
	glEnd();


    glColor3f(0.0,0.0,0.0);                                 // Set Text color to black
    glRasterPos3f(-0.65+i,0.73,0.0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');


    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-0.33+i+uu,0.75+vv);
    glColor3f(0.0+i,1.0+i+uu,0.0+i);  //to draw thw face
    glVertex2f(-0.5+i+uu,0.75+vv);
    glColor3f(0.0+i,0.0+i,1.0+i);
    glVertex2f(-0.5+i+uu,0.79+vv);
    glColor3f(0.0-i,0.0-i,1.0-i);
    glVertex2f(-0.5+i+uu,0.82+vv);
    glColor3f(0.0-i,1.0-i,1.0-i);
    glVertex2f(-0.42+i+uu,0.82+vv);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-0.7+i+uu,0.7+vv);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(-0.55+i+uu,0.7+vv);
    glColor3f(0.0,.0,1.0);    //to draw the tail
    glVertex2f(-0.7+i+uu,0.5+vv);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(-0.85+i+uu,0.5+vv);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-0.88+i+uu,0.73+vv);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(-0.9+i+uu,0.9+vv);    //to draw the wing
    glColor3f(0.0,.0,1.0);
    glVertex2f(-0.82+i+uu,0.9+vv);
    glColor3f(1.0,1.0,0.0);
    glVertex2f(-0.75+i+uu,0.75+vv);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2f(-0.88+i+uu,0.66+vv);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(-0.88+i+uu,0.73+vv);
    glColor3f(0.0,0.0,1.0);
    glVertex2f(-0.92+i+uu,0.68+vv);
    glColor3f(0.5,0.5,0.0);
    glVertex2f(-0.92+i+uu,0.72+vv);
    glEnd();


    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.9,0.6);
    glVertex2f(-1.0,-.5);
    glVertex2f(-0.8,-.5);
    glEnd();

    glColor3f(0.2,0.3,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.92,-0.5);
    glVertex2f(-0.888,-.5);           //for tree
    glVertex2f(-0.888,-.8);
    glVertex2f(-0.92,-.8);
    glEnd();

    if(gh==1)
    {
        lighteff();                  //calling th elight effect function
    }
}



void display(void)                         //display function starts
{

	glClear(GL_COLOR_BUFFER_BIT);

	drawplane();                           //calling the function ganaplane to be drawn

	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(0.17+n+u,-0.6+v);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(0.07+n+u,-0.4+v);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(0.9+n+u,-0.4+v);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(0.8+n+u,-0.6+v);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(0.21+n+u,-0.4+v);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(0.31+n+u,-0.3+v);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(0.65+n+u,-0.3+v);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(0.75+n+u,-0.4+v);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(0.69+n+u,-0.34+v);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(0.9+n+u,-0.20+v);
	glColor3f(1.0,0.0,1.0);
	glVertex2f(0.92+n+u,-0.22+v);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(0.71+n+u,-0.36+v);
	glEnd();

	moment();                               //CALLING THE POSTREDISPLAY FUNCTION

    glColor3d(0.0,0.0,0.0);
	glPushMatrix();
    glTranslated(0.76+n+u,-0.657+v,0.1);
    glutSolidSphere(0.04,slices,stacks);
	glPopMatrix();

    glColor3d(0.0,0.0,0.0);
	glPushMatrix();
    glTranslated(0.6633+n+u,-0.677+v,0.1);
    glutSolidSphere(0.06,slices,stacks);
    glPopMatrix();

	glColor3d(0.0,0.0,0.0);
    glPushMatrix();
    glTranslated(0.5435+n+u,-0.677+v,0.1);
    glutSolidSphere(0.06,slices,stacks);
    glPopMatrix();

	glColor3d(0.0,0.0,0.0);
	glPushMatrix();
    glTranslated(0.4235+n+u,-0.677+v,0.1);
    glutSolidSphere(0.06,slices,stacks);             //code to draw the shere
    glPopMatrix();

	glColor3d(0.0,0.0,0.0);
    glPushMatrix();
    glTranslated(0.305+n+u,-0.677+v,0.1);
    glutSolidSphere(0.06,slices,stacks);
    glPopMatrix();

	glColor3d(0.0,0.0,0.0);
    glPushMatrix();
    glTranslated(0.207+n+u,-0.657+v,0.1);
    glutSolidSphere(0.04,slices,stacks);
    glPopMatrix();

    float w=0.0;
    for( a=0;a<32;a++)
	{
        glColor3d(0.3,0.3,0.3);
        glPushMatrix();
        glTranslated(0.17+n+w+u,-.614+v,.1);
        glutSolidTorus(0.003,0.007,slices,stacks);     //loop to draw the upper solid torus
        glPopMatrix();

        w=w+0.02;
	}

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.805+n+u,-.645+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.8095+n+u,-.659+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.805+n+u,-.67+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.80+n+u,-.687+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.79+n+u,-.697+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.774+n+u,-.707+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.759+n+u,-.71+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.747+n+u,-.72+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.73+n+u,-.725+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.72+n+u,-.73+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.7069+n+u,-.735+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();
	float e=0.0;
    for( a=0;a<22;a++)
	{

        glColor3d(0.3,0.3,0.3);
        glPushMatrix();
        glTranslated(.69+n-e+u,-.741+v,.1);
        glutSolidTorus(0.003,0.007,slices,stacks);                 //loop to draw the lower solid torus
        glPopMatrix();
        e=e+0.02;
	}

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.255+n+u,-.735+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.241+n+u,-.73+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
	glTranslated(.225+n+u,-.725+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
	glTranslated(.21+n+u,-.72+v,.1);
	glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
	glTranslated(.195+n+u,-.715+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.1845+n+u,-.708+v,.1);
	glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.1735+n+u,-.695+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.165+n+u,-.685+v,.1);
	glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.161+n+u,-.67+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.157+n+u,-.65+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

	glColor3d(0.3,0.3,0.3);
	glPushMatrix();
    glTranslated(.16+n+u,-.63+v,.1);
    glutSolidTorus(0.003,0.007,slices,stacks);
    glPopMatrix();

    if(wb==1)
	{
        s=s+0.1;
        explode();
	}
	if(s>1.2)
	{
		s=0.0;wb=0;
		u=0.0,v=0.0;
	}

    if(gg==1)
	{
        x1=x1+0.05;
        y1=y1+0.05;
        tank();
        explodeplane();
	}
	if(x1>1.3)
	{
		x1=0.0;gg=0;
		y1=0.0;
		uu=0.0,vv=0.0;
	}

    glFlush();

}


void init()
{
    glClearColor(1.5,1.5,1.5,1.5);
    glColor3f(0.3,0.7,0.3);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1200,700);                         // size of the output window
    glutInitWindowPosition(0,0);			              // position of the output window
    glutCreateWindow("BattleField Simulation");
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    create_menu();
    init();
    glutMainLoop();
    return 0;
}