
set(TEST_TARGET "estest")

file(GLOB TEST_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

include_directories(${ES_HEADERS})

add_executable(${TEST_TARGET} ${TEST_SOURCE})
target_link_libraries(${TEST_TARGET} ${ES_MATH_TARGET})