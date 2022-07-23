cmake_minimum_required(VERSION 3.14)

project(ApeConfigTest LANGUAGES CXX)

amun_fetch_lib( catch
	GIT_REPOSITORY ../Catch2.git
	GIT_TAG v3.1.0 )

amun_add_test(ape config
	FEATURES cxx_std_20
	SOURCES main.cpp
	INCLUDES ../include
	FOLDER unit_tests
	LINKS PRIVATE Catch2::Catch2WithMain
	)