/*
 * POOSV 2025
 * 
 */

#include <Tests/GraphicalTests/ChasingTest.hpp>
#include<iostream>

IMPLEMENT_MAIN(ChasingTest)

ChasingTest::~ChasingTest()
{
    delete mAutomaton;
    mAutomaton = nullptr;
}

void ChasingTest::onSimulationStart()
{
  Application::onSimulationStart();
    setSimulationMode(SimulationMode::TEST);
	double position(getAppConfig().simulation_world_size / 2);
    mAutomaton = new ChasingAutomaton({ position , position });
}

void ChasingTest::onEvent(sf::Event event, sf::RenderWindow&)
{
     if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code){

			case sf::Keyboard::T:
			{
			Vec2d const coord = getCursorPositionInView();
			 mAutomaton->setTargetPosition(coord);
			}
			
            break;
			
			default: break;
		}
	 }
}

void ChasingTest::onUpdate(sf::Time dt)
{
  Application::onUpdate(dt);
    mAutomaton->update(dt);
}

void ChasingTest::onDraw(sf::RenderTarget& target)
{
  Application::onDraw(target);
    mAutomaton->draw(target);
}

void ChasingTest::onRun()
{
  Application::onRun();
 // TODO add more stuff here if needed
}

std::string ChasingTest::getHelpTextFile() const {
   return RES_LOCATION + "help_chasing.txt";
}

std::string ChasingTest::getWindowTitle() const {
  return getAppConfig().window_title  + ":    ChasingTest";
}
