/*
 * MedianFilter.cpp
 *
 *  Created on: 05.10.2015
 *      Author: hrabia
 */

#include "sensor_filters/MedianFilterSimple.h"

using namespace sensor_filters;

MedianFilterSimple::MedianFilterSimple(): current_index_(0)
{
}

MedianFilterSimple::~MedianFilterSimple()
{
}

double MedianFilterSimple::filter(double newValue){
  values_[current_index_++ % sizeof(values_)] = newValue;

  return middle_of_3(values_[0], values_[1], values_[2]);
}

double MedianFilterSimple::middle_of_3(double a, double b, double c)
{
 double middle;

 if ((a <= b) && (a <= c))
 {
   middle = (b <= c) ? b : c;
 }
 else if ((b <= a) && (b <= c))
 {
   middle = (a <= c) ? a : c;
 }
 else
 {
   middle = (a <= b) ? a : b;
 }
 return middle;
}
