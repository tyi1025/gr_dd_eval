#include "executors/EquivalenceCheckerExecutor.hpp"

#include "EquivalenceCheckingManager.hpp"
#include "checker/dd/applicationscheme/ApplicationScheme.hpp"

json EquivalenceCheckerExecutor::execute(const VerificationTask& task) {
  json       result;
  auto const constructionStart = std::chrono::steady_clock::now();

  auto equivalenceCheckingManager =
      std::make_unique<ec::EquivalenceCheckingManager>(*task.getQc1(),
                                                       *task.getQc2());
  equivalenceCheckingManager->disableAllCheckers();
  if (this->runConstructionChecker) {
    equivalenceCheckingManager->setConstructionChecker(true);
  }
  if (this->runSimulationChecker) {
    equivalenceCheckingManager->setSimulationChecker(true);
  }

  if (this->runAlternatingChecker) {
    equivalenceCheckingManager->setAlternatingChecker(true);
  }
  if (this->sequentialApplicationScheme) {
    equivalenceCheckingManager->setApplicationScheme(
        ec::ApplicationSchemeType::Sequential);
  }

  if (this->oneToOneApplicationScheme) {
    equivalenceCheckingManager->setApplicationScheme(
        ec::ApplicationSchemeType::OneToOne);
  }

  if (this->lookaheadApplicationScheme) {
    equivalenceCheckingManager->setApplicationScheme(
        ec::ApplicationSchemeType::Lookahead);
  }

  if (this->gateCostApplicationScheme) {
    equivalenceCheckingManager->setApplicationScheme(
        ec::ApplicationSchemeType::GateCost);
  }

  if (this->proportionalApplicationScheme) {
    equivalenceCheckingManager->setApplicationScheme(
        ec::ApplicationSchemeType::Proportional);
  }

  equivalenceCheckingManager->setParallel(false);

  equivalenceCheckingManager->setSeed(15);
  auto const executionStart = std::chrono::steady_clock::now();

  equivalenceCheckingManager->run();
  result["check_results"] = equivalenceCheckingManager->getResults().json();
  // Add memory usage
  auto const executionStop = std::chrono::steady_clock::now();
  auto const constructionTime =
      std::chrono::duration_cast<std::chrono::microseconds>(executionStart -
                                                            constructionStart);
  auto const execTime = std::chrono::duration_cast<std::chrono::microseconds>(
      executionStop - executionStart);
  result["construction_time"] = constructionTime.count();
  result["execution_time"]    = execTime.count();

  result["executor"] = getIdentifier();
  result["task"]     = task.getIdentifier();

  return result;
}
