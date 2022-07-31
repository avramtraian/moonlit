// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#pragma once

/** Platform switch. */
#if MOON_PLATFORM_WINDOWS
#	define MOON_EXPORT_SPECIFIER __declspec(dllexport)
#	define MOON_IMPORT_SPECIFIER __declspec(dllimport)
#elif MOON_PLATFORM_MACOS
#	define MOON_EXPORT_SPECIFIER __declspec(dllexport)
#	define MOON_IMPORT_SPECIFIER __declspec(dllimport)
#elif MOON_PLATFORM_LINUX
#	define MOON_EXPORT_SPECIFIER __declspec(dllexport)
#	define MOON_IMPORT_SPECIFIER __declspec(dllimport)
#endif

#ifdef MOON_BUILD_SHARED_LIB
#	define MOON_API MOON_EXPORT_SPECIFIER
#else
#	define MOON_API MOON_IMPORT_SPECIFIER
#endif