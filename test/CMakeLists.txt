cmake_minimum_required(VERSION 3.14)

project(ApeConfigTest LANGUAGES CXX)

amun_fetch_lib( catch
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG v2.13.0 )


add_executable(ape_config_test main.cpp)
target_compile_features(ape_config_test PUBLIC cxx_std_17)
target_include_directories(ape_config_test PUBLIC ../include "${catch_SOURCE_DIR}/single_include")

add_test(NAME run_test COMMAND ape_config_test )
