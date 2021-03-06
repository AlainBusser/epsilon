extern "C" {
#include <assert.h>
#include <stdlib.h>
#include <math.h>
}
#include <poincare/store.h>
#include <ion.h>
#include <poincare/context.h>
#include "layout/char_layout.h"
#include "layout/horizontal_layout.h"

namespace Poincare {

Expression::Type Store::type() const {
  return Type::Store;
}

Expression * Store::clone() const {
  return new Store(operands(), true);
}

int Store::polynomialDegree(char symbolName) const {
  return -1;
}

int Store::writeTextInBuffer(char * buffer, int bufferSize, PrintFloat::Mode floatDisplayMode, int numberOfSignificantDigits) const {
  return LayoutEngine::writeInfixExpressionTextInBuffer(this, buffer, bufferSize, floatDisplayMode, numberOfSignificantDigits, "\x90");
}

Expression * Store::shallowReduce(Context& context, AngleUnit angleUnit) {
  context.setExpressionForSymbolName(value(), symbol(), context);
  return replaceWith(editableOperand(1), true)->shallowReduce(context, angleUnit);
}

ExpressionLayout * Store::createLayout(PrintFloat::Mode floatDisplayMode, int numberOfSignificantDigits) const {
  HorizontalLayout * result = new HorizontalLayout();
  result->addOrMergeChildAtIndex(value()->createLayout(floatDisplayMode, numberOfSignificantDigits), 0, false);
  result->addChildAtIndex(new CharLayout(Ion::Charset::Sto), result->numberOfChildren());
  result->addOrMergeChildAtIndex(symbol()->createLayout(floatDisplayMode, numberOfSignificantDigits), result->numberOfChildren(), false);
  return result;
}

template<typename T>
Evaluation<T> * Store::templatedApproximate(Context& context, AngleUnit angleUnit) const {
  context.setExpressionForSymbolName(value(), symbol(), context);
  if (context.expressionForSymbol(symbol()) != nullptr) {
    return context.expressionForSymbol(symbol())->privateApproximate(T(), context, angleUnit);
  }
  return new Complex<T>(Complex<T>::Undefined());
}

}
