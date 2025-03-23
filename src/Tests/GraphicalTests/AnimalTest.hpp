/*
 * POOSV 2025
 */

#pragma once

#include <Application.hpp>

/*!
 * Test the Animal : random walk + target in sight
 *
 * Generate one target on click
 */
class AnimalTest : public Application
{
public:
     AnimalTest(int argc, char const** argv)
    : Application(argc, argv)
    {
    }

     virtual void onEvent(sf::Event event, sf::RenderWindow& window) override final;
     void onSimulationStart() override final;
     virtual void onRun() override final;
     std::string getHelpTextFile() const override;
     std::string getWindowTitle() const override;

};
