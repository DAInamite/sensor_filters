/*
 * LowPassSimple.h
 *
 *  Created on: 05.10.2015
 *      Author: hrabia
 */

#ifndef LOWPASSSIMPLE_H_
#define LOWPASSSIMPLE_H_

#include "sensor_filters/IFilter1D.h"

namespace sensor_filters{

/**
 * Simple 1d low pass filter that is filtering
 * with the delta between the current and the last
 * measurement multiplied by the smoothing factor
 * @author hrabia
 */
class LowPassSimple:public IFilter1D
{
public:
  /**
   * Constructor
   * @param smoothing value shout be between 0 and 1,
   * higher value corresponds to less smoothing/filtering
   */
  LowPassSimple(double smoothing);

  virtual double filter(double newValue);

  virtual ~LowPassSimple();

private:

  /**
   * current value
   */
  double store;

  /**
   * smoothing/filtering factor
   */
  double smoothing;

  /**
   * store if filter already initialized
   */
  bool init;

};

}
#endif /* LOWPASSSIMPLE_H_ */
