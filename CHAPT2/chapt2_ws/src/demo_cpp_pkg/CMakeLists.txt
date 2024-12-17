cmake_minimum_required(VERSION 3.5)
project(demo_cpp_pkg)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
# find_package(Threads REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

include_directories(include)
# find_package(rclcpp REQUIRED)#直接查找到对应的头文件和库文件
# message(STATUS ${rclcpp_INCLUDE_DIRS})#头文件及rclcpp依赖的头文件
# message(STATUS ${rclcpp_LIBRARIES})#库文件及rclcpp依赖的库文件

# target_include_directories(ros2_cpp_node PUBLIC ${rclcpp_INCLUDE_DIRS})
# target_link_libraries(ros2_cpp_node ${rclcpp_LIBRARIES})
add_executable(cpp_node src/cpp_node.cpp)
add_executable(person_node src/person_node.cpp)
add_executable(learn_shared_ptr src/learn_shared_ptr.cpp)
add_executable(learn_lambda src/learn_lambda.cpp)
add_executable(learn_func src/learn_func.cpp)
add_executable(learn_thread src/learn_thread.cpp)

ament_target_dependencies(cpp_node rclcpp)
ament_target_dependencies(person_node rclcpp)

target_link_libraries(learn_thread ${CMAKE_THREAD_LIBS_INIT})
# target_link_libraries(learn_thread Threads::Threads)
install(TARGETS cpp_node person_node learn_shared_ptr learn_lambda  learn_func learn_thread
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
