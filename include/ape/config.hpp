//APE_LICENSE_PLACE_HOLDER

#ifndef APE_CONFIG_H__
#define APE_CONFIG_H__

#include <ape/config/config.hpp>

#if defined (APE_BUILD_SHARED)
#	define APE_API APE_SHARED_EXPORT
#	define APE_INTERFACE APE_SHARED_INTERFACE
#elif defined (APE_BUILD_STATIC) || defined (APE_IMPORT_STATIC)
#	define APE_API			//for static
#	define APE_INTERFACE
#else
#	define APE_API APE_SHARED_IMPORT
#	define APE_INTERFACE APE_SHARED_INTERFACE
#endif

BEGIN_APE_NAMESPACE
namespace stl{
    using namespace ::std;
}

using std::size_t;
END_APE_NAMESPACE

#endif //end APE_CONFIG_H__

