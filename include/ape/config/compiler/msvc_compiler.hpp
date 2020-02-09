#define APE_ABI_PREFIX <ape/config/abi/msvc_prefix.hpp>
#define APE_ABI_SUFFIX <ape/config/abi/msvc_suffix.hpp>

#define APE_FUNCTION __FUNCTION__ 

#define APE_DLL_EXPORT __declspec( dllexport )
#define APE_DLL_IMPORT __declspec( dllimport )

#define APE_DLL_INTERFACE __declspec(novtable)

