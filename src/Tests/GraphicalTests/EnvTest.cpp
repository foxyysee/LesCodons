/*
 * POOSV 2025
 * Marco Antognini & Jamila Sam
 */

#include <Tests/GraphicalTests/EnvTest.hpp>
#include <iostream>
#define STEP 2

IMPLEMENT_MAIN(EnvTest)

void EnvTest::onEvent(sf::Event event, sf::RenderWindow&)
{
#if STEP == 2	
	 if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code){

			case sf::Keyboard::T:
			{
			Vec2d const coord = getCursorPositionInView();
			getAppEnv().addTarget(coord);
			}
			
            break;
			
			default: break;
		}
	 }
#endif	 
}

void EnvTest::onRun()
{
  Application::onRun();
 // TODO add more stuff here if needed
}

void EnvTest::onSimulationStart()
{
  Application::onSimulationStart();
  setSimulationMode(SimulationMode::TEST);
#if STEP != 2		
	std::cout << "##WARNING : this test only works in step 2" << std::endl;
#endif	 	
}

std::string EnvTest::getHelpTextFile() const {
   return RES_LOCATION + "help_env.txt";
}

std::string EnvTest::getWindowTitle() const {
  return getAppConfig().window_title  + ":   EnvTest (WARNING: ONLY WORKS IN STEP2)";
}
