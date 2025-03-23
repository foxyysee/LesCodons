/*
 * POOSV 2025
 */

#include <Tests/GraphicalTests/AnimalTest.hpp>
#include <Animal/Animal.hpp>
#include <Utility/Utility.hpp>
#define STEP 2

IMPLEMENT_MAIN(AnimalTest)

void AnimalTest::onEvent(sf::Event event, sf::RenderWindow&)
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
        case sf::Keyboard::R:
          {
            getAppEnv().clean();
#if STEP  == 2
	    double position(getAppConfig().simulation_world_size / 2);
	    getAppEnv().addAnimal(new Animal({ position , position }));
#endif
	  }

	  break;
	default: break;
	}
    }
#endif
}

void AnimalTest::onRun()
{
  Application::onRun();
  // TODO add more stuff here if needed
}

void AnimalTest::onSimulationStart()
{
  Application::onSimulationStart();
  setSimulationMode(SimulationMode::TEST);
#if STEP  == 2
  double position(getAppConfig().simulation_world_size / 2);
  getAppEnv().addAnimal(new Animal({ position , position }));
#else
  std::cout << "##WARNING : this test only works in step 2" << std::endl;
#endif	
}

std::string AnimalTest::getHelpTextFile() const {
  return RES_LOCATION + "help_animal.txt";
}

std::string AnimalTest::getWindowTitle() const {
  return getAppConfig().window_title  + ":   AnimalTest (WARNING: ONLY WORKS IN STEP2)";
}
