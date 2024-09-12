#pragma once

#include "Executor.hpp"
#include "tasks/VerificationTask.hpp"

class EquivalenceCheckerExecutor : public Executor<VerificationTask> {
public:
  json execute(const VerificationTask& task) override;

  [[nodiscard]] std::string getIdentifier() const override {
    return "equivalence_checker";
  }

private:
  bool runConstructionChecker = false;
  bool runSimulationChecker   = false;
  bool runAlternatingChecker  = true;

public:
  [[maybe_unused]] [[nodiscard]] bool isRunConstructionChecker() const {
    return runConstructionChecker;
  };

  [[maybe_unused]] [[nodiscard]] bool isRunSimulationChecker() const {
    return runSimulationChecker;
  };

  [[maybe_unused]] [[nodiscard]] bool isRunAlternatingChecker() const {
    return runAlternatingChecker;
  };

  [[maybe_unused]] void setRunConstructionChecker(bool run) {
    this->runConstructionChecker = run;
  };

  [[maybe_unused]] void setRunSimulationChecker(bool run) {
    this->runSimulationChecker = run;
  };

  [[maybe_unused]] void setRunAlternatingChecker(bool run) {
    this->runAlternatingChecker = run;
  };

  void disableAllCheckers() {
    this->runConstructionChecker = false;
    this->runSimulationChecker   = false;
    this->runAlternatingChecker  = false;
  };

private:
  bool sequentialApplicationScheme   = false;
  bool oneToOneApplicationScheme     = false;
  bool proportionalApplicationScheme = true;
  bool lookaheadApplicationScheme    = false;
  bool gateCostApplicationScheme     = false;

public:
  [[maybe_unused]] [[nodiscard]] bool isSequentialApplicationScheme() const {
    return sequentialApplicationScheme;
  }

  [[maybe_unused]] [[nodiscard]] bool isOneToOneApplicationScheme() const {
    return oneToOneApplicationScheme;
  }

  [[maybe_unused]] [[nodiscard]] bool isProportionalApplicationScheme() const {
    return proportionalApplicationScheme;
  }

  [[maybe_unused]] [[nodiscard]] bool isLookaheadApplicationScheme() const {
    return lookaheadApplicationScheme;
  }

  [[maybe_unused]] [[nodiscard]] bool isGateCostApplicationScheme() const {
    return gateCostApplicationScheme;
  }

  [[maybe_unused]] void setSequentialApplicationScheme(bool ac) {
    this->sequentialApplicationScheme = ac;
  };

  [[maybe_unused]] void setOneToOneApplicationScheme(bool ac) {
    this->oneToOneApplicationScheme = ac;
  };

  [[maybe_unused]] void setProportionalApplicationScheme(bool ac) {
    this->proportionalApplicationScheme = ac;
  };

  [[maybe_unused]] void setLookaheadApplicationScheme(bool ac) {
    this->lookaheadApplicationScheme = ac;
  };

  [[maybe_unused]] void setGateCostApplicationScheme(bool ac) {
    this->gateCostApplicationScheme = ac;
  };

  void disableAllApplicationSchemes() {
    this->sequentialApplicationScheme   = false;
    this->oneToOneApplicationScheme     = false;
    this->proportionalApplicationScheme = false;
    this->lookaheadApplicationScheme    = false;
    this->gateCostApplicationScheme     = false;
  };
};
