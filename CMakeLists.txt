cmake_minimum_required (VERSION 3.10)
project(simplesfm)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++14")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fPIC")

find_package(OpenCV REQUIRED)

find_package(Boost REQUIRED COMPONENTS filesystem program_options system)
include_directories(${Boost_INCLUDE_DIRS})

find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})

add_subdirectory(3rdparty/googletest)

# include_directories("/usr/local/include")
enable_testing()
# 查找 GTest 库
find_package(GTest REQUIRED)
# GTest 的头文件
include_directories(${GTEST_INCLUDE_DIRS})

find_package(exiv2 REQUIRED)

# 包含exiv2的头文件路径
include_directories(${EXIV2_INCLUDE_DIRS})

add_executable(simplesfm src/main.cpp)
add_executable(mytest src/test.cpp src/types.cpp)

target_link_libraries(simplesfm  ${Boost_LIBRARIES} ${OpenCV_LIBS} ${CERES_LIBRARIES})

target_link_libraries(mytest  ${Boost_LIBRARIES} ${OpenCV_LIBS} 
                            ${CERES_LIBRARIES}
                            exiv2
                            GTest::gtest GTest::gtest_main
                            pthread)