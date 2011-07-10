


#include "include/Graphics.h"
#include <SFML/Window.hpp>

void setOrthogonal( int windowWidth, int windowHeight )
{
	glMatrixMode( GL_PROJECTION );
	glPushMatrix();
	glLoadIdentity();

	gluOrtho2D( 0, windowWidth, 0, windowHeight );

	glMatrixMode( GL_MODELVIEW );
}

void drawLine( float x1, float y1, float x2, float y2 )
{
	glBegin( GL_LINES );
		glVertex2f( x1,y1 );
		glVertex2f( x2,y2 );
	glEnd();
}
