#ifndef APE_CONFIG_CONFIG_H__
#define APE_CONFIG_CONFIG_H__

#include <utility>

#if __has_include("ape_user.hpp")
#include "ape_user.hpp"
#endif

#ifndef APE_NAMESPACE
#define APE_NAMESPACE ape
#endif

#define BEGIN_APE_NAMESPACE namespace APE_NAMESPACE { inline namespace v1{
#define END_APE_NAMESPACE }}

BEGIN_APE_NAMESPACE

namespace os{
	struct os_tag{};

	struct linux_os : os_tag{};
	struct bsd_os : os_tag{};
	struct solaris_os : os_tag{};
	struct sgi_irix_os : os_tag{};
	struct hp_unix_os : os_tag{};
	struct cygwin_os : os_tag{};
	struct win32_os : os_tag{};
	struct beos_os : os_tag{};
	struct macos_os : os_tag{};
	struct ibm_os : os_tag{};
	struct amigaos_os : os_tag{};
	struct generic_unix_os : os_tag{};
}

namespace compiler{
	struct compiler_tag{};

	struct como_compiler : compiler_tag{};
	struct dmc_compiler : compiler_tag{};
	struct intel_compiler : compiler_tag{};
	struct gnuc_compiler : compiler_tag{};
	struct kcc_compiler : compiler_tag{};
	struct sgi_compiler : compiler_tag{};
	struct decxx_compiler : compiler_tag{};
	struct ghs_compiler : compiler_tag{};
	struct borland_compiler : compiler_tag{};
	struct mwerks_compiler : compiler_tag{};
	struct sunpro_cc_compiler : compiler_tag{};
	struct hp_acc_compiler : compiler_tag{};
	struct mrc_or_sc_compiler : compiler_tag{};
	struct ibmcpp_compiler : compiler_tag{};
	struct msvc_compiler : compiler_tag{};
	struct clang_compiler : compiler_tag{};
}

namespace stdlib{
	struct stdlib_tag{};

	struct stlport_stdlib : stdlib_tag {};
	struct como_stdlib : stdlib_tag {};
	struct roguewave_stdlib : stdlib_tag {};
	struct gnucpp3_stdlib : stdlib_tag {};
	struct sgi_stdlib : stdlib_tag {};
	struct msl_stdlib : stdlib_tag {};
	struct ibmcpp_stdlib : stdlib_tag {};
	struct msipl_stdlib : stdlib_tag {};
	struct dinkumware_stdlib : stdlib_tag {};
	struct libcpp_stdlib : stdlib_tag {};	//for clang
}
namespace cppstandard {
	struct cppstandard_tag{};
	struct cpppre98_tag : cppstandard_tag{};
	struct cpp98_tag : cpppre98_tag{};
	struct cpp03_tag : cpp98_tag{};
	struct cpp11_tag : cpp03_tag{};
	struct cpp14_tag : cpp11_tag{};
	struct cpp17_tag : cpp14_tag{};
	struct cpp20_tag : cpp17_tag{};

	enum version{
		cpppre98 = 1,
		cpp98 = 199711L,
		cpp03 = cpp98, //TODO: how to check?
		cpp11 = 201103L,
		cpp14 = 201402L,
		cpp17 = 201703L,
		cpp20 = 202002L
	};
}

#if defined(linux) || defined(__linux) || defined(__linux__)
#	define LINUX_OS_	1
#	define OS_TYPE linux_os
using os_type = os::linux_os;

#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
#	define BSD_OS_	1
#	define OS_TYPE bsd_os
using os_type = os::bsd_os;

#elif defined(sun) || defined(__sun)
#	define SOLARIS_OS_	1
#	define OS_TYPE solaris_os
using os_type = os::solaris_os;

#elif defined(__sgi)
#	define SGI_IRIX_OS_	1
#	define OS_TYPE sgi_irix_os
using os_type = os::sgi_irix_os;

#elif defined(__hpux)
#	define HP_UNIX_OS_	1
#	define OS_TYPE hp_unix_os
using os_type = os::hp_unix_os;

#elif defined(__CYGWIN__)
#	define CYGWIN_OS_	1
#	define OS_TYPE cygwin_os
using os_type = os::cygwin_os;

#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#	define WIN32_OS_	1
#	define OS_TYPE win32_os
using os_type = os::win32_os;

#elif defined(__BEOS__)
#	define BEOS_OS_	1
#	define OS_TYPE beos_os
using os_type = os::beos_os;

#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#	define MACOS_OS_	1
#	define OS_TYPE macos_os
using os_type = os::macos_os;

#elif defined(__IBMCPP__) || defined(_AIX)
#	define IBM_OS_	1
#	define OS_TYPE ibm_os
using os_type = os::ibm_os;

#elif defined(__amigaos__)
#	define AMIGAOS_OS_	1
#	define OS_TYPE amigaos_os
using os_type = os::amigaos_os;

#elif defined(unix) \
      || defined(__unix) \
      || defined(_XOPEN_SOURCE) \
      || defined(_POSIX_SOURCE)
#	define GENERIC_UNIX_OS_	1
#	define OS_TYPE generic_unix_os
using os_type = os::generic_unix_os;

#else
#	error "Unknown platform"
#endif


#if defined __COMO__
#	define COMO_COMPILER_	1
#	define COMPILER_TYPE como_compiler
using compiler_type = compiler::como_compiler;

#elif defined __DMC__
#	define DMC_COMPILER_	1
#	define COMPILER_TYPE dmc_compiler
using compiler_type = compiler::dmc_compiler;

#elif defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
#	define INTEL_COMPILER_	1
#	define COMPILER_TYPE intel_compiler
using compiler_type = compiler::intel_compiler;

#elif defined __clang__
#	define CLANG_COMPILER_ 1
#	define COMPILER_TYPE clang_compiler
using compiler_type = compiler::clang_compiler;

#elif defined __GNUC__
#	define GNUC_COMPILER_	1
#	define COMPILER_TYPE gnuc_compiler
using compiler_type = compiler::gnuc_compiler;

#elif defined __KCC
#	define KCC_COMPILER_	1
#	define COMPILER_TYPE kcc_compiler
using compiler_type = compiler::kcc_compiler;

#elif defined __sgi
#	define SGI_COMPILER_	1
#	define COMPILER_TYPE sgi_compiler
using compiler_type = compiler::sgi_compiler;

#elif defined __DECCXX
#	define DECXX_COMPILER_	1
#	define COMPILER_TYPE decxx_compiler
using compiler_type = compiler::decxx_compiler;

#elif defined __ghs
#	define GHS_COMPILER_	1
#	define COMPILER_TYPE ghs_compiler
using compiler_type = compiler::ghs_compiler;

#elif defined __BORLANDC__
#	define BORLAND_COMPILER_	1
#	define COMPILER_TYPE borland_compiler
using compiler_type = compiler::borland_compiler;

#elif defined  __MWERKS__
#	define MWERKS_COMPILER_	1
#	define COMPILER_TYPE mwerks_compiler
using compiler_type = compiler::mwerks_compiler;

#elif defined  __SUNPRO_CC
#	define SUNPRO_CC_COMPILER_	1
#	define COMPILER_TYPE sunpro_cc_compiler
using compiler_type = compiler::sunpro_cc_compiler;

#elif defined __HP_aCC
#	define HP_ACC_COMPILER_	1
#	define COMPILER_TYPE hp_acc_compiler
using compiler_type = compiler::hp_acc_compiler;

#elif defined(__MRC__) || defined(__SC__)
#	define MRC_OR_SC_COMPILER_	1
#	define COMPILER_TYPE mrc_or_sc_compiler
using compiler_type = compiler::mrc_or_sc_compiler;

#elif defined(__IBMCPP__)
#	define IBMCPP_COMPILER_	1
#	define COMPILER_TYPE ibmcpp_compiler
using compiler_type = compiler::ibmcpp_compiler;

#elif defined _MSC_VER
#	define MSVC_COMPILER_	1
#	define COMPILER_TYPE msvc_compiler
using compiler_type = compiler::msvc_compiler;

#else

#  error "Unknown compiler"

#endif


#if defined(__SGI_STL_PORT) || defined(_STLPORT_VERSION)
#	define STLPORT_STDLIB_	1
#	define STDLIB_TYPE stlport_stdlib
using stdlib_type = stdlib::stlport_stdlib;

#elif defined(__LIBCOMO__)
#	define COMO_STDLIB_	1
#	define STDLIB_TYPE como_stdlib
using stdlib_type = stdlib::como_stdlib;

#elif defined(__STD_RWCOMPILER_H__) || defined(_RWSTD_VER)
#	define ROGUEWAVE_STDLIB_	1
#	define STDLIB_TYPE roguewave_stdlib
using stdlib_type = stdlib::roguewave_stdlib;

#elif defined(__GLIBCPP__) || defined(__GLIBCXX__)
#	define GNUCPP3_STDLIB_	1
#	define STDLIB_TYPE gnucpp3_stdlib
using stdlib_type = stdlib::gnucpp3_stdlib;

#elif defined(__STL_CONFIG_H)
#	define SGI_STDLIB_	1
#	define STDLIB_TYPE sgi_stdlib
using stdlib_type = stdlib::sgi_stdlib;

#elif defined(__MSL_CPP__)
#	define MSL_STDLIB_	1
#	define STDLIB_TYPE msl_stdlib
using stdlib_type = stdlib::msl_stdlib;

#elif defined(__IBMCPP__)
#	define IBMCPP_STDLIB_	1
#	define STDLIB_TYPE ibmcpp_stdlib
using stdlib_type = stdlib::ibmcpp_stdlib;

#elif defined(MSIPL_COMPILE_H)
#	define MSIPL_STDLIB_	1
#	define STDLIB_TYPE msipl_stdlib
using stdlib_type = stdlib::msipl_stdlib;

#elif (defined(_YVALS) && !defined(__IBMCPP__)) || defined(_CPPLIB_VER)
#	define DINKUMWARE_STDLIB_	1
#	define STDLIB_TYPE dinkumware_stdlib
using stdlib_type = stdlib::dinkumware_stdlib;

#elif defined(_LIBCPP_VERSION)
#	define LIBCPP_STD_LIB_	1
#	define STDLIB_TYPE libcpp_stdlib
using stdlib_type = stdlib::libcpp_stdlib;

#elif defined (APE_ASSERT_CONFIG)
#  error "Unknown standard library"

#endif

#if __cplusplus == 1
#	define CPP_PRE98	1
#	define CPP_STANDARD cpppre98
using cpp_standard = cppstandard::cpppre98_tag;
#elif __cplusplus == 199711L
#	define CPP_98	1
#	define CPP_STANDARD cpp98
using cpp_standard = cppstandard::cpp98_tag;
#elif __cplusplus == 201103L
#	define CPP_11	1
#	define CPP_STANDARD cpp11
using cpp_standard = cppstandard::cpp11_tag;
#elif __cplusplus == 201402L
#	define CPP_14	1
#	define CPP_STANDARD cpp14
using cpp_standard = cppstandard::cpp14_tag;
#elif __cplusplus == 201703L
#	define CPP_17	1
#	define CPP_STANDARD cpp17
using cpp_standard = cppstandard::cpp17_tag;
#elif __cplusplus == 202002L
#	define CPP_20	1
#	define CPP_STANDARD cpp20
using cpp_standard = cppstandard::cpp20_tag;
#else
# error "Unknown cpp standard version"
#endif

END_APE_NAMESPACE

#define APE_OS_CONFIG <ape/config/os/OS_TYPE.hpp>
#define APE_COMPILER_CONFIG <ape/config/compiler/COMPILER_TYPE.hpp>
#define APE_STDLIB_CONFIG <ape/config/stdlib/STDLIB_TYPE.hpp>

#include APE_OS_CONFIG
#include APE_COMPILER_CONFIG
#include APE_STDLIB_CONFIG

#undef APE_OS_CONFIG
#undef APE_COMPILER_CONFIG
#undef APE_STDLIB_CONFIG

#if defined(APE_ABI_PREFIX) && defined(APE_ABI_SUFFIX) && !defined(APE_HAS_ABI_HEADERS)
#  define APE_HAS_ABI_HEADERS
#endif

#endif //end APE_CONFIG_CONFIG_H__


