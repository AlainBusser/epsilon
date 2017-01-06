#ifndef PROBABILITE_EXPONENTIAL_LAW_H
#define PROBABILITE_EXPONENTIAL_LAW_H

#include "one_parameter_law.h"

namespace Probability {

class ExponentialLaw : public OneParameterLaw {
public:
  ExponentialLaw();
  ~ExponentialLaw() override {};
  const char * title() override;
  Type type() const override;
  bool isContinuous() const override;
  float xMin() override;
  float yMin() override;
  float xMax() override;
  float yMax() override;
  const char * parameterNameAtIndex(int index) override;
  const char * parameterDefinitionAtIndex(int index) override;
  float evaluateAtAbscissa(float x) const override;
  bool authorizedValueAtIndex(float x, int index) const override;
  float cumulativeDistributiveFunctionAtAbscissa(float x) const override;
  float cumulativeDistributiveInverseForProbability(float * probability) override;
};

}

#endif