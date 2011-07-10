//============================================================================
// Name        : GraphsAndShit.cpp
// Author      : Anders Bennehag
// Version     :
// Copyright   : MIT
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include <vector>
#include <unistd.h>

#include <SFML/Graphics.hpp>
#include <SFML/System/Randomizer.hpp>

#include "include/Graphics.h"
#include "include/SimplePlotter.h"

sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML OpenGL");

class testGraph
{
	public:
		testGraph( std::string _filename ) {filename = _filename;};
		virtual ~testGraph() {};
		void test() {setupTest();drawTest();doScreenshot();};

	protected:
		virtual void setupTest() = 0;
		virtual void drawTest() = 0;

		void doScreenshot()
		{
			sf::Image Screen = App.Capture();

			Screen.SaveToFile(filename.c_str());
		};
		std::string filename;
};

class testSimplePlotter : public testGraph
{
	public:
		testSimplePlotter( std::string _filename ) : testGraph( _filename ) {};
		GraphsAndShit::SimplePlotter *plotter;
		std::vector<float> data;

		void setupTest()
		{

			plotter = new GraphsAndShit::SimplePlotter(10,10, 500, 400 );

			setOrthogonal( App.GetWidth(), App.GetHeight() );
			sf::Randomizer randomizer;
			randomizer.SetSeed( time(0) );
			for (int i=0; i<5; i++ )
			{
				float randNbr = randomizer.Random( 0.0f, 1.0f ) ;
				std::cout << "Adding " << randNbr << std::endl;
				data.push_back( randNbr );
			}
			plotter->properties.setGraphColour(0.5f,0.5f,0.5f);
		};

		void drawTest() {plotter->plot( data ); };
};

int main()
{

	App.SetFramerateLimit( 1 );
	// Set color and depth clear value
	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	std::string testName("screenshots/SimplePlotter.png");
	testSimplePlotter tsp(testName);
	tsp.test();




	App.Display();


	return 0;
}
