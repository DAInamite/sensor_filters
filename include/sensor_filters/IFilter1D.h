/*
 * IFilter1D.h
 *
 *  Created on: 05.10.2015
 *      Author: hrabia
 */

#ifndef IFILTER_H_
#define IFILTER_H_

namespace sensor_filters{

/**
 * Abstract interface for a generic filter for one dimensional values
 * @author hrabia
 */
class IFilter1D
{
public:

  /**
   * Add a new value to the filter and receive the current filtered version
   * @param newValue
   * @return
   */
  virtual double filter(double newValue) = 0;

  virtual ~IFilter1D(){}
};

}

#endif /* IFILTER_H_ */

