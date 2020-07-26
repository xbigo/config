#define APE_ABI_PREFIX <ape/config/abi/msvc_prefix.hpp>
#define APE_ABI_SUFFIX <ape/config/abi/msvc_suffix.hpp>

#define APE_FUNCTION __FUNCTION__

#define APE_SHARED_EXPORT __declspec( dllexport )
#define APE_SHARED_IMPORT __declspec( dllimport )

#define APE_SHARED_INTERFACE __declspec(novtable)

