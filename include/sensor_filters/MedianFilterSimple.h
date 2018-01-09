/*
 * MedianFilterSimple.h
 *
 *  Created on: 05.10.2015
 *      Author: hrabia
 */

#ifndef MEDIANFILTERSIMPLE_H_
#define MEDIANFILTERSIMPLE_H_

#include <ros/ros.h>
#include "sensor_filters/IFilter1D.h"

namespace sensor_filters{

/**
 * Simple 3 value median filter
 * @author hrabia
 */
class MedianFilterSimple: public IFilter1D
{
public:
  MedianFilterSimple();

  virtual double filter(double newValue);

  virtual ~MedianFilterSimple();

private:

  /**
   * Calculate the median of three values
   * based on: http://embeddedgurus.com/stack-overflow/tag/median-filter/
   * @param a
   * @param b
   * @param c
   * @return
   */
  double middle_of_3(double a, double b, double c);

  /**
   * round robin store of the last three values
   */
  double values_[3] = {0};

  /**
   * current index for inserting new values
   */
  u_int8_t current_index_;
};

}

#endif /* MEDIANFILTERSIMPLE_H_ */
