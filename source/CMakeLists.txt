
set(ES_MATH_TARGET "esmath")
set(ES_MATH_TARGET ${ES_MATH_TARGET} PARENT_SCOPE)

############################################################
#                      MATH LIBRARY                        #
############################################################

file(GLOB MATH_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/math/*.cpp")
file(GLOB MATH_HEADER "${ES_HEADERS}/esmath/*.hpp")

include_directories("${ES_HEADERS}/esmath")

add_library("${ES_MATH_TARGET}_d" SHARED ${MATH_SOURCE} ${MATH_HEADER})
add_library("${ES_MATH_TARGET}" STATIC ${MATH_SOURCE} ${MATH_HEADER})

############################################################