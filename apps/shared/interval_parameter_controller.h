#ifndef SHARED_INTERVAL_PARAM_CONTROLLER_H
#define SHARED_INTERVAL_PARAM_CONTROLLER_H

#include <escher.h>
#include "interval.h"
#include "float_parameter_controller.h"

namespace Shared {

class IntervalParameterController : public Shared::FloatParameterController {
public:
  IntervalParameterController(Responder * parentResponder, Interval * interval);
  Interval * interval();
  const char * title() override;
  void willDisplayCellForIndex(HighlightCell * cell, int index) override;
  int numberOfRows() override;
  void unloadView() override;
protected:
  constexpr static int k_totalNumberOfCell = 3;
  bool setParameterAtIndex(int parameterIndex, float f) override;
  Interval * m_interval;
private:
  HighlightCell * reusableParameterCell(int index, int type) override;
  int reusableParameterCellCount(int type) override;
  float parameterAtIndex(int index) override;
  View * createView() override;
  char m_draftTextBuffer[MessageTableCellWithEditableText::k_bufferLength];
  MessageTableCellWithEditableText * m_intervalCells[k_totalNumberOfCell];
};

}

#endif
