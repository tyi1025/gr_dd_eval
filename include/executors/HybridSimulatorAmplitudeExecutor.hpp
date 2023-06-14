#pragma once

#include "Executor.hpp"
#include "tasks/SimulationTask.hpp"

class HybridSimulatorAmplitudeExecutor : public Executor<SimulationTask> {
public:
  json execute(const SimulationTask& task) override;

  [[nodiscard]] std::string getIdentifier() const override {
    return "hybrid_schrodinger_feynman_simulator_amplitude";
  };
};
