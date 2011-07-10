
#include "include/SimplePlotter.h"

namespace GraphsAndShit
{


	SimplePlotter::SimplePlotter( int positionX, int positionY, int width, int height )
		: BasePlotter( positionX, positionY, width, height )
	{

	}

	SimplePlotter::~SimplePlotter()
	{

	}


	void SimplePlotter::plot( std::vector<float> &Y )
	{
		std::vector<float> X( Y.size(), 0.0f );

		for ( int i=0; i<X.size(); i++)
			X[i] = (float)i;

		plot( X, Y );
	}


	void SimplePlotter::plot( std::vector<float> &X, std::vector<float> &Y )
	{

		BasePlotter::drawBorders();

		properties.setAxesFromData( X, Y );

		// Draw the data lines
		glBegin( GL_LINES );
		bool lineStarted = true;
		for (int i=0; i<Y.size(); i++ )
		{
			int xPos = dataInXDimToGraphSpace(X[i]);
			int yPos = dataInYdimToGraphSpace(Y[i]);

			glVertex2s( xPos,yPos );

			if (lineStarted)
			{
				lineStarted = false;
			}
			else
			{
				i--;
				lineStarted = true;
			}
		}
		glEnd();


	}

}
