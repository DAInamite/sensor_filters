/*
 * Butterworth.h
 *
 *  Created on: 05.10.2015
 *      Author: hrabia
 */

#ifndef BUTTERWORTH_H_
#define BUTTERWORTH_H_

#include "sensor_filters/IFilter1D.h"

namespace sensor_filters{

/**
 * 2 pole Butterworth filter based on
 * http://baumdevblog.blogspot.de/2010/11/butterworth-lowpass-filter-coefficients.html
 * @author hrabia
 */
class Butterworth : public IFilter1D
{
public:
  Butterworth();

  Butterworth(double frequency, double cutoff);

  virtual ~Butterworth();

  /**
   * Filter one sample
   *
   * @param sample
   * @return
   */
  double filter(double sample);

  /**
   * Filter one sample with specific new cutoff and frequency
   *
   * @param sample
   * @param frequency
   * @param cutoff
   * @return
   */
  double filter(double sample, double frequency, double cutoff);

private:
  void init();

  void getLPCoefficientsButterworth2Pole(double samplerate, double cutoff, double ax[], double by[]);

  double ax[3] = {0};
  double by[3] = {0};

  double xv[3] = {0};
  double yv[3] = {0};

};

}

#endif /* BUTTERWORTH_H_ */
