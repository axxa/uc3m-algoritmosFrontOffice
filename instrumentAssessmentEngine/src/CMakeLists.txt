#cmake_minimum_required (VERSION 3.0)
# Include the directory itself as a path to include directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(PeriodCalc)
add_subdirectory(ZeroCoupon)
add_subdirectory(Instrument)
add_subdirectory(Tir)
add_subdirectory(UnitTest)

#buscar para agregar dependencia a una libreria
add_executable(instrumentAssessmentEngine main.cpp)

set_target_properties(Instrument PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(PeriodCalc PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(UnitTest PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(Tir PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(instrumentAssessmentEngine Instrument)

