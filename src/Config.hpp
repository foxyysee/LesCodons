/*
 * POOSV 2025
 */

#pragma once

#include <string>
#include "JSON/JSON.hpp"
#include <SFML/Graphics.hpp>

// Define resources location
std::string const RES_LOCATION = "../res/";

// Define the location of the config file
std::string const DEFAULT_CFG = "app2.json";

// Define the location of the font file (could be in the config instead of here)
std::string const FONT_LOCATION = RES_LOCATION + "sansation.ttf";


class Config
{
private:
  j::Value mConfig;
  bool simulation_debug;

public:
  Config(const j::Value& cfg);
  // Config(std::string path);

  // enables / disables debug mode
  void switchDebug();
  bool getDebug();

  // returns read
  j::Value& getJsonRead(){
    return mConfig;
  }

  j::Value const& getJsonRead() const {
    return mConfig;
  }


  //window
  const double   window_simulation_width;
  const double  window_simulation_height;
  const double  window_stats_width;
  const double  window_control_width;
  const std::string  window_title;
  const int window_antialiasing_level;

  // stats
  const double stats_refresh_rate;
  const std::string stats_log_folder = "logs/";
  const std::string stats_log_prefix = "log_";
  const std::string stats_log_header = "# Plot with GNUPLOT : gnuplot -e \"plot for [i=1:6] 'log_0.txt' u i w l title columnheader(i)\"";

  // debug
  const sf::Color debug_text_color = sf::Color::White;
  const size_t default_debug_text_size = 20;


  //simulation (general)
  const std::string simulation_world_texture;
  const std::string simulation_world_debug_texture;
  const double simulation_world_size;
  const double  simulation_time_factor;
  const sf::Time  simulation_time_max_dt;

  // environment
  const double environment_breeding_delay;
  const double environment_default_temperature;
  const double environment_min_temperature;
  const double environment_max_temperature;
  const unsigned int environment_max_clouds;
  const double environment_raining_cloud_density;
  const double environment_raining_probability;
  const float environment_raining_duration;
  const double environment_drought_duration;
  const double environment_humidity_duration;
   const double environment_rain_temperature;
  // organic entity
  const std::string entity_texture_tracked = "target.png";
  const double entity_energy_critical = 5;

  // cloud
  const std::string cloud_texture;
  const double cloud_min_size;
  const double cloud_max_size;
  const double cloud_evaporation_size;
  const double cloud_evaporation_rate;

  //cloud generator
  const double cloud_generator_delta;

  //obstacles
  const std::string rock_texture;
  // food
  const std::string food_texture;
  const double food_size;
  const double food_energy;
  const double food_max_energy;
  const double food_growth_rate;

  // animal
  const double animal_idle_probability;
  const double animal_walking_idle_time;
  const double animal_low_energy_factor;
  const double animal_deceleration_tweaker;
  const double animal_flight_coefficient;
  const double animal_distance_coefficient;
  const bool animal_random_walk_low_energy;
  const double animal_safe_distance ;
  const double animal_meal_retention ;
  const double animal_feed_time;
  const double animal_delivery_time;
  const double animal_mating_time;
  const double animal_min_energy;
  const double animal_base_energy_consumption;
  const double animal_eating_pause_time;
  const double animal_mating_pause_time;
  const double animal_delivery_pause_time;
  // lizards
  const double lizard_max_speed;
  const double lizard_mass;
  const double lizard_energy_loss_factor;
  const double lizard_view_range;
  const double lizard_view_distance;
  const double lizard_random_walk_jitter;
  const double lizard_random_walk_radius;
  const double lizard_random_walk_distance;
  const sf::Time lizard_longevity;
  const double lizard_energy_initial;
  const double lizard_energy_min_mating_female;
  const double lizard_energy_min_mating_male;
  const int lizard_min_children;
  const int lizard_max_children;
  const double lizard_gestation_time;
  const double lizard_energy_loss_female_per_child;
  const double lizard_energy_loss_mating_male;
  const std::string lizard_texture_male;
  const std::string lizard_texture_male_down;
  const std::string lizard_texture_female;
  const std::string lizard_texture_female_down;
  const std::string lizard_texture_hidden;
  const double lizard_size;
  const double lizard_min_age_mating;
  const double wave_lizard_frequency;
  const double wave_lizard_energy_loss_factor;


  // scorpion
  const double scorpion_max_speed;
  const double scorpion_mass;
  const double scorpion_energy_loss_factor;
  const double scorpion_view_range;
  const double scorpion_view_distance;
  const double scorpion_random_walk_jitter;
  const double scorpion_random_walk_radius;
  const double scorpion_random_walk_distance;
  const sf::Time scorpion_longevity;
  const double scorpion_energy_initial;
  const double scorpion_energy_min_mating_female;
  const double scorpion_energy_min_mating_male;
  const int scorpion_min_children;
  const int scorpion_max_children;
  const double scorpion_gestation_time;
  const double scorpion_energy_loss_female_per_child;
  const double scorpion_energy_loss_mating_male;
  const std::string scorpion_texture;
  const double scorpion_size;
  const double scorpion_min_age_mating;
  const double scorpion_sensor_radius;
  const double scorpion_minimal_score_for_action;
  const double scorpion_rotation_angle_precision;
  const double neuronal_scorpion_idle_time;
   const double neuronal_scorpion_moving_time;
  const std::string neuronal_scorpion_texture;
  // sensor
  const double sensor_intensity_threshold;
  const double sensor_inhibition_factor;
  const double sensor_inhibition_max;
  const double sensor_activation_duration;

  //wave
  const double wave_intensity_thickness_ratio;
  const double wave_intensity_threshold;
  const double wave_on_wave_marging;
  const double wave_default_energy;
  const double wave_default_radius;
  const double wave_default_mu;
  const double wave_default_speed;
};


