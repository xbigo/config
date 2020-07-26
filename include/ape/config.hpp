//APE_LICENSE_PLACE_HOLDER

#ifndef APE_CONFIG_H__
#define APE_CONFIG_H__

#include <ape/config/config.hpp>

#if defined (APE_DLL_EXPORT)
#	define APE_API APE_DLL_EXPORT
#	define APE_INTERFACE APE_DLL_INTERFACE
#elif defined (APE_DLL_IMPORT)
#	define APE_API APE_DLL_IMPORT
#	define APE_INTERFACE APE_DLL_INTERFACE
#else
#	define APE_API			//for static
#	define APE_INTERFACE
#endif

BEGIN_APE_NAMESPACE
namespace stl{
    using namespace ::std;
}

using std::size_t;
END_APE_NAMESPACE

#endif //end APE_CONFIG_H__

