cmake_minimum_required(VERSION 3.14)

file(STRINGS include/ape/config/version.hpp _define_version_ REGEX "APE_CONFIG_VERSION")
string(REGEX MATCH "([0-9\\.]+)" _version_str_ "${_define_version_}")
if (CMAKE_BINARY_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    message(FATAL_ERROR "Building in-source is not supported! Create a build dir and remove ${CMAKE_SOURCE_DIR}/CMakeCache.txt")
endif()

project(ApeConfig 
	VERSION ${_version_str_}
	DESCRIPTION "C++ compiler, OS, and standard library detect"
	LANGUAGES CXX)

add_library(ape_config INTERFACE)
add_library(Ape::config ALIAS ape_config )

target_compile_features(ape_config INTERFACE cxx_std_17)
#target_include_directories(ape_config INTERFACE include)
target_include_directories(ape_config INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

set(CONFIG_INSTALL_DIR lib/cmake/${PROJECT_NAME}-${PROJECT_VERSION})
install(TARGETS ape_config EXPORT ${PROJECT_NAME}Targets)
install(EXPORT ${PROJECT_NAME}Targets DESTINATION ${CONFIG_INSTALL_DIR} NAMESPACE Ape:: FILE ${PROJECT_NAME}Config.cmake)
install(DIRECTORY include/ DESTINATION include)

include(CMakePackageConfigHelpers)
set(OLD_CMAKE_SIZEOF_VOID_P ${CMAKE_SIZEOF_VOID_P})
unset(CMAKE_SIZEOF_VOID_P)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake" COMPATIBILITY AnyNewerVersion)
set(CMAKE_SIZEOF_VOID_P ${OLD_CMAKE_SIZEOF_VOID_P})

install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake" DESTINATION ${CONFIG_INSTALL_DIR})

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	# Top project, enable testing and add 3rd parties 
	enable_testing()
endif()

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR APE_CONFIG_BUILD_TESTING) AND BUILD_TESTING)
	add_subdirectory(test)
endif()

