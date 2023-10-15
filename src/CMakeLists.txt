include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(bitcask-lib STATIC ${PROJECT_SOURCE_DIR}/src/engine_impl.cpp
        utils.cpp
        operation.cpp)