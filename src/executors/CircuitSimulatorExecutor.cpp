#include "executors/CircuitSimulatorExecutor.hpp"

std::unique_ptr<CircuitSimulator<>>
CircuitSimulatorExecutor::constructSimulator(const SimulationTask& task) {
  auto qc = std::make_unique<qc::QuantumComputation>(task.getQc()->clone());
  auto circuitSimulator = std::make_unique<CircuitSimulator<>>(
      std::move(qc), constants::GLOBAL_SEED);

  return circuitSimulator;
  //    Meant to keep the qc construction in the superclass, but it reports
  //    incomplete type
}

json CircuitSimulatorExecutor::runSimulator(
    std::unique_ptr<CircuitSimulator<>> simulator) {
  json result;
  auto results                  = simulator->simulate(1024U);
  result["measurement_results"] = results;
  return result;
}
