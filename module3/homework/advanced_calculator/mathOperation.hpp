#pragma once
#include "errorCodeEnum.hpp"
#include <cmath>
#include <functional>
#include <map>
#include <regex>
#include <string>
using funcType = std::function<double(double &, double &)>;
class mathOperation {

public:
  mathOperation(std::string& inputString);
  double getResult() const;
  ErrorCode getErrorCode() const;

private:
  std::string& dataString_;
  double firstValue_;
  double secondValue_;
  double result_;
  std::string operationCharacter_;
  ErrorCode actualError_;
  std::smatch regexMatchGroups_;

  void removeSpaces();
  ErrorCode checkIfBadFormat();
  ErrorCode checkIfBadCharacter();
  ErrorCode checkIfDivideByZero();
  ErrorCode checkIfSqrtOfNegativeNumber();
  ErrorCode checkIfmoduleOfNonIntegerValue();
  void calculateResult();

  static double add(double &firstValue, double &secondValue);
  static double subtract(double &firstValue, double &secondValue);
  static double multiplicate(double &firstValue, double &secondValue);
  static double divide(double &firstValue, double &secondValue);
  static double modulo(double &firstValue, double &secondValue);
  static double factorial(double &firstValue, double &secondValue);
  static double power(double &firstValue, double &secondValue);
  static double squareRoot(double &firstValue, double &secondValue);

    std::map<char, std::function<double(double& firstValue, double&
  secondValue)>> FunctionalMap_ = {
        {'+', mathOperation::add},          {'-', mathOperation::subtract},
        {'*', mathOperation::multiplicate}, {'/', mathOperation::divide},
        {'%', mathOperation::modulo},       {'!', mathOperation::factorial},
        {'^', mathOperation::power},        {'$', mathOperation::squareRoot}};
  };
