#ifndef GRAPHPROPERTIES_H
#define GRAPHPROPERTIES_H

#include <GL/gl.h>
#include <vector>

namespace GraphsAndShit
{
	enum AxesType
	{
		Linear,
		SemiLogX,
		SemiLogY,
		LogLog
	};


	class GraphProperties
	{
		public:
			GraphProperties();
			virtual ~GraphProperties();

			void setAxesFromData( std::vector<float> &X, std::vector<float> &Y );

			void setGraphColour( GLfloat R, GLfloat G, GLfloat B ) ;
			void setDataColour( GLfloat R, GLfloat G, GLfloat B ) ;

			AxesType axesType;
			void setXAxis( int min, int max );
			void setYAxis( int min, int max );
			int XAxis[2], YAxis[2];

			GLfloat graphColour[3];
			GLfloat dataColour[3];

		protected:
		private:

	};




}
#endif // GRAPHPROPERTIES_H
