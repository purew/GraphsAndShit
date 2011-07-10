

#include <GL/gl.h>
#include <iostream>

#include "include/BasePlotter.h"

namespace GraphsAndShit
{



	BasePlotter::BasePlotter( int _positionX, int _positionY, int _width, int _height, int _margin)
	{
		positionX = _positionX;
		positionY = _positionY;
		width = _width;
		height = _height;
		margin = _margin;

		dataBorderX1 = positionX+margin;
		dataBorderY1 = positionY+margin;
		dataBorderX2 = positionX+width-margin;
		dataBorderY2 = positionY+height-margin;
	}


	void BasePlotter::drawBorders()
	{
		// Draw the border around the plot
		glColor3fv( properties.graphColour );
		glBegin( GL_LINES );
			glVertex2f( dataBorderX1, dataBorderY1 );
			glVertex2f( dataBorderX2, dataBorderY1 );

			glVertex2f( dataBorderX2, dataBorderY1 );
			glVertex2f( dataBorderX2, dataBorderY2 );

			glVertex2f( dataBorderX2, dataBorderY2 );
			glVertex2f( dataBorderX1, dataBorderY2 );

			glVertex2f( dataBorderX1, dataBorderY2 );
			glVertex2f( dataBorderX1, dataBorderY1 );
		glEnd();


	}

	float BasePlotter::dataInXDimToGraphSpace( float value )
	{
		if (properties.axesType == Linear)
			return dataInXDimToLinearGraphSpace( value );
		else
			throw "Only linear axes implemented so far.";
	}

	float BasePlotter::dataInXDimToLinearGraphSpace( float xValue )
	{
		float scalingFactor = xValue/(properties.XAxis[1]-properties.XAxis[0]);
		std::cout << "Scaling factor = " << scalingFactor << std::endl;
		return positionX + margin + (width-2*margin)*scalingFactor;

	}

	float BasePlotter::dataInYdimToGraphSpace( float value )
	{
		return positionY+margin+ 200*value;
	}




	BasePlotter::~BasePlotter()
	{

	}

}
