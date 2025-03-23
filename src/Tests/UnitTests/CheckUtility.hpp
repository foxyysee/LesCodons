/*
 * prjsv 2015, 2016
 * 2014
 * Marco Antognini
 */

#ifndef INFOSV_CHECKUTILITY_HPP
#define INFOSV_CHECKUTILITY_HPP

#include <catch.hpp>

#include <cmath>

#define CHECK_EPSILON 0.0001

#define CHECK_APPROX_EQUAL(a, b) CHECK(std::abs((a) - (b)) <= CHECK_EPSILON)

#endif // INFOSV_CHECKUTILITY_HPP
