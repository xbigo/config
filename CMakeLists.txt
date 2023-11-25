cmake_minimum_required(VERSION 3.14)

project(ApeConfig
	VERSION "0.4.0"
	DESCRIPTION "C++ compiler, OS, and standard library detect"
	LANGUAGES CXX)

if (NOT DEFINED APE_SUPERPROJECT AND NOT AMUN_INCLUDED)
	find_package(Ape 0.2.0 QUIET COMPONENTS amun)
	if (NOT Ape_FOUND)
		find_package(ApeAmun 0.2.0 QUIET)
		if (NOT ApeAmun_FOUND)
			include(FetchContent)
			FetchContent_Declare( amun
				GIT_REPOSITORY https://github.com/xbigo/amun.git
				GIT_TAG v0.3.0
				)
			FetchContent_MakeAvailable(amun)
			include(${amun_SOURCE_DIR}/lib/amun/amun.cmake)
		endif()
	endif()
endif()
amun_disable_build_in_source()


amun_check_build(CONFIG NORMAL INSTALL TEST)

if(${CONFIG_NORMAL})
	add_library(ape_config INTERFACE)
	add_library(Ape::config ALIAS ape_config )
	target_compile_features(ape_config INTERFACE cxx_std_20)
	if (MSVC)
		target_compile_options(ape_config INTERFACE "/Zc:__cplusplus")
	endif()
	target_include_directories(ape_config INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

	amun_reorg_project(ape_config
		SOURCES include/ape/config.hpp
		PRIVATE_SOURCES src/dummy.cpp
		INCLUDES include
		FOLDER Libs)
endif()

if(${CONFIG_INSTALL})
	amun_get_cmake_install_dir(CONFIG_INSTALL_DIR)

	if (NOT DEFINED APE_SUPERPROJECT)
		amun_install_targets(${CONFIG_INSTALL_DIR} ape_config)
		amun_install_config_version(${CONFIG_INSTALL_DIR} NOARCH)
	endif()

	install(DIRECTORY include/ DESTINATION include)
endif()

if(${CONFIG_TEST})
	amun_enable_testing()
	add_subdirectory(test)
endif()
