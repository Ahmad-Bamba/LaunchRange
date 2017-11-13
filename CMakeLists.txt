cmake_minimum_required(VERSION 3.0.2)

project(launchrange CXX)

# Include header files
include_directories("${CMAKE_SOURCE_DIR}/include")

# Create shared library
add_library(${PROJECT_NAME} SHARED
    include/point.hpp
    include/range.hpp
    include/discontinuous.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Install library
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib
)

# Install library headers
# install(FILES lib/launchrange.h
#         DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
# )

add_executable(unit_tests ${CMAKE_SOURCE_DIR}/tests/unit_tests.cpp)
target_link_libraries(unit_tests ${PROJECT_NAME})

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
      set (CMAKE_CXX_FLAGS "-std=c++$ENV{CPPV} ${CMAKE_CXX_FLAGS}")
elseif(MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++$ENV{CPPV}") #TODO make an actual build scrip for windows
endif()
