cmake_minimum_required(VERSION 3.8)
project(brobot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(spinnaker_camera_driver REQUIRED)
find_package(joy REQUIRED)
find_package(rclpy REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

install(DIRECTORY launch
  DESTINATION share/brobot/
)

install(PROGRAMS
  src/control_panel.py
  DESTINATION lib/brobot
)

install(PROGRAMS
  src/brobot_image_acquisition.py
  DESTINATION lib/brobot
)

install(PROGRAMS
  src/joy_driver2.py
  DESTINATION lib/brobot
)

install(PROGRAMS
  src/roboclaw_driver.py
  DESTINATION lib/brobot
)

#If you try to put in in lib/brobot/utils/roboclaw_python/
# Error: utils.roboclaw_python.roboclaw_3 module not found.
#The solution is to put it right next to roboclaw_driver.py and import directly, see notes in roboclaw_driver.py
install(PROGRAMS
  src/utils/roboclaw_python/roboclaw_3.py
  DESTINATION lib/brobot
)

ament_package()
