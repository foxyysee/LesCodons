/*
 * POOSV 2025
 * Marco Antognini & Jamila Sam
 */

#pragma once

#include <Application.hpp>

/*!
 * Test the Env and its targets
 *
 * Generate one target on click
 */
class EnvTest : public Application
{
public:
     EnvTest(int argc, char const** argv)
    : Application(argc, argv)
    {
    }

     virtual void onRun() override final;
     virtual void onSimulationStart() override final;
     virtual void onEvent(sf::Event event, sf::RenderWindow& window) override final;
     std::string getHelpTextFile() const override;
     std::string getWindowTitle() const override;
};

