#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// angle of rotation for the camera direction
float angle = 0.0f;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f, z=5.0f;
// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;


//For control season , color code
float bush_red = 0.184314f;
float bush_green = 0.309804f;
float bush_blue = 0.184314f;
float berry_red = 0.9f;
float berry_green = 0.25f;
float berry_blue = 0.0f;

float grass_red = 0.309804f;
float grass_green = 0.39804f;
float grass_blue = 0.184314f;

float sky_red =0.22f;
float sky_green =0.69f;
float sky_blue =0.87f;

float pTree2_red = 0.137255f;
float pTree2_green = 0.256863f;
float pTree2_blue = 0.137255f;

float pineTree_leaf1_red = 0.157255f;
float pineTree_leaf1_green = 0.506863f;
float pineTree_leaf1_blue = 0.157255f;

float pineTree_leaf2_red = 0.137255f;
float pineTree_leaf2_green = 0.556863f;
float pineTree_leaf2_blue = 0.137255f;

float pineTree_leaf3_red = 0.157255f;
float pineTree_leaf3_green = 0.56863f;
float pineTree_leaf3_blue = 0.137255f;

float buble_red = 0.184314f;
float buble_green = 0.309804f;
float buble_blue = 0.184314f;

float tree_red = 0.184314f;
float tree_green = 0.409804f;
float tree_blue = 0.284314f;

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // cant make a window of zero width
    if (h == 0)
        h = 1;
    float ratio =  w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void Tree(){
    glColor3f(0.52f,  0.37f , 0.26f);
//ağaç gövdesi
    glutSolidCone(0.08f,1.5f,10,10); //base yarıçap

//ağaç yaprakları
    glColor3f(tree_red, tree_green , tree_blue); //koyu yeşil
    glTranslatef(0.0f ,0.0f, 1.2f);
    glutSolidSphere(0.45f,20,20);
}

void BubleTree(){
    glColor3f(0.52f,  0.37f , 0.26f);
//ağaç gövdesi
    glutSolidCone(0.08f,1.5f,10,10); //base yarıçap

//ağaç yaprakları
    glColor3f(buble_red, buble_green , buble_blue); //koyu yeşil
    glTranslatef(0.0f ,-0.2f, 1.0f);
    glutSolidSphere(0.45f,20,20);

    //ağaç yaprakları

    glTranslatef(0.0f ,0.5f, 0.0f);
    glutSolidSphere(0.35f,20,20);


    glTranslatef(0.0f ,-0.3f, 0.3f);
    glutSolidSphere(0.35f,20,20);

}

void pineTree(){
    glColor3f(0.36f,  0.25f , 0.20f);
//ağaç gövdesi
    glutSolidCone(0.08f,1.0f,10,10); //base yarıçap

//ağaç yaprakları alt kısım

    glColor3f(pineTree_leaf1_red,  pineTree_leaf1_green , pineTree_leaf1_blue); // orman yeşili koyu
    glTranslatef(0.0f ,0.0f, 0.65f);
    glutSolidCone(0.50f,0.6f,10,10); //base yarıçap
//ağaç yaprakları orta kısım

    glColor3f(pineTree_leaf2_red,  pineTree_leaf2_green , pineTree_leaf2_blue); // orman yeşili orta
    glTranslatef(0.0f ,0.0f, 0.3f);
    glutSolidCone(0.40f,0.5f,10,10); //base yarıçap
//ağaç yaprakları üst kısım

    glColor3f(pineTree_leaf3_red,  pineTree_leaf3_green , pineTree_leaf3_blue); // orman yeşili açık
    glTranslatef(0.0f ,0.0f, 0.30f);
    glutSolidCone(0.30f,0.4f,10,10); //base yarıçap
}

void pineTree2(){
    glColor3f(0.36f,  0.25f , 0.20f); // ağaç gövde renklerini sabit bırakacağım
//ağaç gövdesi

    glutSolidCone(0.08f,1.0f,10,10); //base yarıçap

//ağaç yaprakları

    glColor3f(pTree2_red,  pTree2_green , pTree2_blue); // orman yeşili orta
    glTranslatef(0.0f ,0.0f, 0.3f);
    glutSolidCone(0.40f,1.2f,10,10); //base yarıçap

}

void berryBush(){

    glColor3f(bush_red, bush_green , bush_blue); //koyu yeşil
    glutSolidSphere(0.35f,20,20);
//// Draw berry
    glPushMatrix();
    glColor3f(berry_red,berry_green,berry_blue);
    glTranslatef(0.05f, 0.3f, 0.18f);
    glutSolidSphere(0.05f,10,10);

    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.05f,10,10);

    glTranslatef(0.05f, -0.18f, 0.18f);
    glutSolidSphere(0.05f,10,10);

    glTranslatef(-0.2f, 0.0f, -0.1f);
    glutSolidSphere(0.05f,10,10);

    glTranslatef(0.19f, -0.25f, 0.1f);
    glutSolidSphere(0.05f,10,10);
    glPopMatrix();

}

void computePos(float deltaMove) {

    x += deltaMove * lx * 0.1f;
    z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) {

    angle += deltaAngle;
    lx = sin(angle);
    lz = -cos(angle);
}

void drawSky(){
    //Draw Sky
    glColor3f(sky_red, sky_green, sky_blue);
    glutSolidCube(90);
}

void drawForest(){
    glPushMatrix();
    glTranslatef(0.0,0,0.0);
    glRotatef(180.0f,0.0f, 2.0f, 2.0f);
    BubleTree();
    glPopMatrix();
    for(int i = -3; i < 3; i++)
        for(int j=-3; j < 3; j++) {
            if(i==0 && j == 0){
                continue;
            }
            glPushMatrix();
            glTranslatef(i*8.5+1,0,j * 7.7+3);
            glRotatef(180.0f,0.0f, 2.0f, 2.0f);
            pineTree();
            glPopMatrix();
        }

    for(int i = -3; i < 3; i++)
        for(int j=-3; j < 3; j++) {
            if(i==0 && j == 0){
                continue;
            }
            glPushMatrix();
            glTranslatef(i*10.3,0,j * 10.7);
            glRotatef(180.0f,0.0f, 2.0f, 2.0f);
            pineTree();
            glPopMatrix();
        }
    for(int i = -3; i < 3; i++)
        for(int j=-3; j < 3; j++) {
            if(i==0 && j == 0){
                continue;
            }
            glPushMatrix();
            glTranslatef(i*11.0,0,j * 11.9);
            glRotatef(180.0f,0.0f, 2.0f, 2.0f);
            Tree();
            glPopMatrix();
        }
    for(int i = -3; i < 3; i++)
        for(int j=-3; j < 3; j++) {
            if(i==0 && j == 0){
                continue;
            }
            glPushMatrix();
            glTranslatef(i*13.3-2,0,j * 13.0);
            glRotatef(180.0f,0.0f, 2.0f, 2.0f);
            BubleTree();
            glPopMatrix();
        }
    for(int i = -3; i < 3; i++)
        for(int j=-3; j < 3; j++) {
            if(i==0 && j == 0){
                continue;
            }
            glPushMatrix();
            glTranslatef(i*15.7,0,j * 9.2);
            glRotatef(180.0f,0.0f, 2.0f, 2.0f);
            BubleTree();
            glPopMatrix();
        }
    for(int i = -3; i < 3; i++)
        for(int j=-3; j < 3; j++) {
            if(i==0 && j == 0){
                continue;
            }
            glPushMatrix();
            glTranslatef(i*17.0,0,j * 6.1);
            glRotatef(180.0f,0.0f, 2.0f, 2.0f);
            pineTree2();
            glPopMatrix();
        }
    for(int i = -3; i < 3; i++)
        for(int j=-3; j < 3; j++) {
            if(i==0 && j == 0){
                continue;
            }
            glPushMatrix();
            glTranslatef(i*4.0,0,j * 17.0);
            glRotatef(180.0f,0.0f, 2.0f, 2.0f);
            pineTree2();
            glPopMatrix();
        }
    for(int i = -3; i < 3; i++)
        for(int j=-3; j < 3; j++) {
            if(i==0 && j == 0){
                continue;
            }
            glPushMatrix();
            glTranslatef(i*7.0,0,j * 17.0);
            glRotatef(180.0f,0.0f, 2.0f, 2.0f);
            berryBush();
            glPopMatrix();
        }
}

void renderScene(void) {

    if (deltaMove)
        computePos(deltaMove);
    if (deltaAngle)
        computeDir(deltaAngle);

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(	x, 1.0f, z,
                  x+lx, 1.0f,  z+lz,
                  0.0f, 1.0f,  0.0f);

// Draw ground

    //glColor3f(0.9f, 0.9f, 0.9f);
    glColor3f(grass_red, grass_green, grass_blue);
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f,  100.0f);
    glVertex3f( 100.0f, 0.0f,  100.0f);
    glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();

    drawSky();


// Draw Forest
    drawForest();

    glutSwapBuffers();
}


void pressKey(int key, int xx, int yy) {

    switch (key) {
        case GLUT_KEY_LEFT : deltaAngle = -0.01f; break;
        case GLUT_KEY_RIGHT : deltaAngle = 0.01f; break;
        case GLUT_KEY_UP : deltaMove = 0.5f; break;
        case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
    }
}

void releaseKey(int key, int x, int y) {

    switch (key) {
        case GLUT_KEY_LEFT :
        case GLUT_KEY_RIGHT : deltaAngle = 0.0f;break;
        case GLUT_KEY_UP :
        case GLUT_KEY_DOWN : deltaMove = 0;break;
    }
}

void processNormalKeys(unsigned char key, int x, int y) {

    if (key == 27)//ESC
        exit(0);
    else if(key == 's'){// summer mode setting:
        //For control season , color code
        bush_red = 0.184314f;
        bush_green = 0.309804f;
        bush_blue = 0.184314f;
        berry_red = 0.9f;
        berry_green = 0.25f;
        berry_blue = 0.0f;

        grass_red = 0.309804f;
        grass_green = 0.39804f;
        grass_blue = 0.184314f;

        sky_red =0.22f;
        sky_green =0.69f;
        sky_blue =0.87f;

        pTree2_red = 0.137255f;
        pTree2_green = 0.256863f;
        pTree2_blue = 0.137255f;

        pineTree_leaf1_red = 0.157255f;
        pineTree_leaf1_green = 0.506863f;
        pineTree_leaf1_blue = 0.157255f;

        pineTree_leaf2_red = 0.137255f;
        pineTree_leaf2_green = 0.556863f;
        pineTree_leaf2_blue = 0.137255f;

        pineTree_leaf3_red = 0.157255f;
        pineTree_leaf3_green = 0.56863f;
        pineTree_leaf3_blue = 0.137255f;

        buble_red = 0.184314f;
        buble_green = 0.309804f;
        buble_blue = 0.184314f;

        tree_red = 0.184314f;
        tree_green = 0.409804f;
        tree_blue = 0.284314f;

    }
    else if(key == 'w'){// winter modwe setting:
        bush_red = 0.74902f; //declare LightBlue = color red 0.74902 green 0.847059 blue 0.847059
        bush_green = 0.847059f;
        bush_blue = 0.847059f;

        berry_red = 0.9f;
        berry_green = 0.6f;
        berry_blue = 0.5f;

        grass_red = 0.9f;
        grass_green = 0.9f;
        grass_blue = 0.9f;

        sky_red =0.22f;
        sky_green =0.79f;
        sky_blue =0.97f;

        pTree2_red = 0.560784f; //declare LightSteelBlue = color red 0.560784 green 0.560784 blue 0.737255
        pTree2_green = 0.560784f;
        pTree2_blue = 0.737255f;

        pineTree_leaf1_red = 0.560784f; //declare PaleGreen = color red 0.560784 green 0.737255 blue 0.560784
        pineTree_leaf1_green = 0.737255f; //ok
        pineTree_leaf1_blue = 0.560784;

        pineTree_leaf2_red = 0.560784f;
        pineTree_leaf2_green = 0.737255f;//ok
        pineTree_leaf2_blue = 0.760784;

        pineTree_leaf3_red = 0.65f;
        pineTree_leaf3_green = 0.85f;//ok
        pineTree_leaf3_blue = 0.85f;

        buble_red =  0.74902f;
        buble_green = 0.857059f;
        buble_blue = 0.847059f;

        tree_red = 0.184314; //#declare DarkSlateGray = color red 0.184314 green 0.309804 blue 0.309804
        tree_green = 0.309804f;
        tree_blue = 0.309804f;

    }
    else if(key == 'a'){// winter mode setting:
        bush_red = 0.48f; //#declare Feldspar = color red 0.82 green 0.57 blue 0.46
        bush_green = 0.17f;
        bush_blue = 0.10f;

        berry_red = 0.95f;
        berry_green = 0.6f;
        berry_blue = 0.5f;

        grass_red = 0.65f;
        grass_green = 0.49f;
        grass_blue = 0.24f;

        sky_red =0.42f;
        sky_green =0.79f;
        sky_blue =0.87f;

        pTree2_red = 0.79f; //declare LightSteelBlue = color red 0.560784 green 0.560784 blue 0.737255
        pTree2_green = 0.47f;
        pTree2_blue = 0.20f;

        pineTree_leaf1_red = 0.55f; //#declare Bronze = color red 0.55 green 0.47 blue 0.14
        pineTree_leaf1_green = 0.47f; //ok
        pineTree_leaf1_blue = 0.14f;

        pineTree_leaf2_red = 0.81f; //#declare OldGold = color red 0.81 green 0.71 blue 0.23
        pineTree_leaf2_green = 0.71f;//ok
        pineTree_leaf2_blue = 0.23f;

        pineTree_leaf3_red = 0.85f;
        pineTree_leaf3_green = 0.85f;//ok
        pineTree_leaf3_blue = 0.10f;

        buble_red =  0.49f; //
        buble_green = 0.21f;
        buble_blue = 0.11f;

        tree_red = 0.43f;
        tree_green = 0.27f;
        tree_blue = 0.31f;

    }
}
int main(int argc, char **argv) {

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("Forest");

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);

    glutSpecialFunc(pressKey);

    // here are the new entries
    glutIgnoreKeyRepeat(1);
    glutSpecialUpFunc(releaseKey);
    glutKeyboardFunc(processNormalKeys);


    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}
