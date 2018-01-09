/*
 * SimpleLowPass.cpp
 *
 *  Created on: 05.10.2015
 *      Author: hrabia
 */

#include "sensor_filters/LowPassSimple.h"

using namespace sensor_filters;

LowPassSimple::LowPassSimple(double smoothing) :
    init(false), smoothing(smoothing), store(0)
{
}

LowPassSimple::~LowPassSimple()
{
}

double LowPassSimple::filter(double input)
{
  if (init)
  {
    store = input;
    init = false;
  }
  else
  {
    store = store + (input - store) * smoothing;
  }
  return store;
}
