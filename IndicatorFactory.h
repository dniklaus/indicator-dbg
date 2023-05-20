#pragma once

class Indicator;

class IndicatorFactory
{
public:
  /**
   * @brief Create an Indicator object and the corresponding debug cli commands.
   * 
   * @param name The indicator object's name
   * @param description Description of the Indicator object
   * @return Indicator* Pointer to the Indicator object instance.
   */
  static Indicator* createIndicator(const char* name, const char* description);

private:
  IndicatorFactory() {}
  virtual ~IndicatorFactory() {}
};
