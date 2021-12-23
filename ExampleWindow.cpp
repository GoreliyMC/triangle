#include <cmath>

static constexpr double Pi = acos(-1.);

#include "ExampleWindow.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>


ExampleWindow::ExampleWindow(int width, int height)
: Window(800, 600)
{
	_angle = 0.;
	_eye_level = 0.;
}

static const float s_material_green[4]   { 0.f, 1.f, 0.f, 1.f };

void ExampleWindow::setup()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
	glMatrixMode(GL_MODELVIEW);
    glEnd();
}

void drawCube(){
    glBegin(GL_QUADS);

    //Координаты и цвет куба
    glNormal3d(  1.,  0.,  0.);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
    glVertex3d(  1., -1.,  1.);
    glVertex3d(  1.,  1.,  1.);
    glVertex3d(  1.,  1., -1.);
    glVertex3d(  1., -1., -1.);

    glNormal3d( -1.,  0.,  0.);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
    glVertex3d( -1.,  1.,  1.);
    glVertex3d( -1., -1.,  1.);
    glVertex3d( -1., -1., -1.);
    glVertex3d( -1.,  1., -1.);

    glNormal3d(  0.,  1.,  0.);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
    glVertex3d( -1.,  1.,  1.);
    glVertex3d(  1.,  1.,  1.);
    glVertex3d(  1.,  1., -1.);
    glVertex3d( -1.,  1., -1.);

    glNormal3d(  0., -1.,  0.);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
    glVertex3d(  1., -1.,  1.);
    glVertex3d( -1., -1.,  1.);
    glVertex3d( -1., -1., -1.);
    glVertex3d(  1., -1., -1.);

    glNormal3d(  0.,  0.,  1.);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
    glVertex3d( -1.,  1.,  1.);
    glVertex3d(  1.,  1.,  1.);
    glVertex3d(  1., -1.,  1.);
    glVertex3d( -1., -1.,  1.);

    glNormal3d(  0.,  0., -1.);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
    glVertex3d(  1.,  1., -1.);
    glVertex3d( -1.,  1., -1.);
    glVertex3d( -1., -1., -1.);
    glVertex3d(  1., -1., -1.);
    glEnd();
}

void ExampleWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(
            5., 5., 5. * _eye_level,
			0., 0., 0.,
			0., 0., 1.);

    glRotated(_angle, 0.0, 0.0, 1.0);
    glScaled( 0.4, 0.4, 0.4 );

    glPushMatrix();// сохраняем текущие координаты

    glTranslated(0.0, 0.0, -1.0);
    drawCube();

    glTranslated(-2.5, 0.0, 0.0);
    drawCube();

    glTranslated(5.0, 0.0, 0.0);
    drawCube();

    glTranslated(-1.0, 0.0, 2.0);
    drawCube();

    glTranslated(-2.5, 0.0, 0.0);
    drawCube();

    glTranslated(1.25, 0.0, 2.0);
    drawCube();

    glPopMatrix(); // возвращаемся к старой системе координат

}

void ExampleWindow::handle_logic()
{
	_angle += 1.;
	if (_angle >= 360.)
		_angle -= 360.;

    _eye_level = sin(_angle / 180. * Pi);
}
