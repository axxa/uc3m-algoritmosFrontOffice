#cmake_minimum_required (VERSION 3.0)
#project (instrumentAssessmentEngine)
add_subdirectory(PeriodCalc)
add_subdirectory(ZeroCoupon)
add_subdirectory(Instrument)
#add_subdirectory(UnitTest)

#buscar para agregar dependencia a una libreria
add_executable(instrumentAssessmentEngine main.cpp)
target_link_libraries(instrumentAssessmentEngine Instrument)

