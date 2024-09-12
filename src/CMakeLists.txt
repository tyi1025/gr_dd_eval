# add MQT::ddsim library
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/ddsim" "extern/ddsim"
                 EXCLUDE_FROM_ALL)

# add MQT::qcec library
add_subdirectory("${PROJECT_SOURCE_DIR}/extern/qcec" "extern/qcec"
                 EXCLUDE_FROM_ALL)

if(NOT TARGET ${PROJECT_NAME})
  add_library(
    ${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/include/Executor.hpp
    ${PROJECT_SOURCE_DIR}/include/executors/CircuitSimulatorExecutor.hpp
    ${PROJECT_SOURCE_DIR}/include/executors/AlternatingVerificationExecutor.hpp
    ${PROJECT_SOURCE_DIR}/include/executors/EquivalenceCheckerExecutor.hpp
    ${PROJECT_SOURCE_DIR}/include/Task.hpp
    ${PROJECT_SOURCE_DIR}/include/tasks/SimulationTask.hpp
    ${PROJECT_SOURCE_DIR}/include/tasks/VerificationTask.hpp
    executors/CircuitSimulatorExecutor.cpp
    executors/AlternatingVerificationExecutor.cpp
    executors/EquivalenceCheckerExecutor.cpp
    tasks/SimulationTask.cpp
    tasks/VerificationTask.cpp)

  # set include directories
  target_include_directories(
    ${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include
                           ${PROJECT_BINARY_DIR}/include)

  # link to the MQT libraries
  target_link_libraries(${PROJECT_NAME} PUBLIC MQT::ddsim MQT::qcec)

  # add MQT alias
  add_library(MQT::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
endif()
