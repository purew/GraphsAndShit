

#ifndef PLOTS_H_
#define PLOTS_H_

#include <vector>
#include "include/GraphProperties.h"

namespace GraphsAndShit
{


	/**	Base class supplying the platform for all graphs and plots. */
	class BasePlotter
	{
		public:
			BasePlotter( int positionX, int positionY, int width, int height, int margin=15 );
			virtual ~BasePlotter();

			virtual void plot( std::vector<float> &Y ) = 0;
			virtual void plot( std::vector<float> &X, std::vector<float> &Y ) = 0;

			GraphProperties properties;

		protected:
			void drawBorders();

			float dataInXDimToGraphSpace( float value );
			float dataInYdimToGraphSpace( float value );

			int positionX, positionY, width, height; ///< Positional data for graph object.
			int margin; ///< Margin between graph object border and actual drawing area in pixels.
			int dataBorderX1,dataBorderX2,dataBorderY1,dataBorderY2; ///< Area for actual data.

		private:

			float dataInXDimToLinearGraphSpace( float value );

	};

}
#endif
