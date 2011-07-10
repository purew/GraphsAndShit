#ifndef SIMPLEPLOTTER_H
#define SIMPLEPLOTTER_H

#include <include/BasePlotter.h>

namespace GraphsAndShit
{


	class SimplePlotter : public BasePlotter
	{
		public:
			SimplePlotter( int positionX, int positionY, int width, int height );
			~SimplePlotter();

			void plot( std::vector<float> &Y );
			void plot( std::vector<float> &X, std::vector<float> &Y );

		private:
	};




}
#endif // SIMPLEPLOTTER_H
