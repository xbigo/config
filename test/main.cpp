#include <catch2/catch_all.hpp>
#include <ape/config.hpp>

#include <type_traits>

TEST_CASE( "Basic check for Ape::config", "[ape_config]" ) {
	bool result = std::is_same_v<APE_NAMESPACE::os_type, APE_NAMESPACE::os::OS_TYPE>;
    REQUIRE( result);
}
