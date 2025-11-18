# Find packages of dependencies
include(CMakeFindDependencyMacro)

# Find Qt6 dependencies
find_dependency(Qt6 REQUIRED COMPONENTS Widgets PrintSupport WebEngineWidgets Xml)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/modules")

# Include target definition (includes and definition)
include("${CMAKE_CURRENT_LIST_DIR}/@PROJECT_NAME@Targets.cmake")
