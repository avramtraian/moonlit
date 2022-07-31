// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#pragma once

#include "CoreDefines.h"

/** Platform switch. */
#if MOON_PLATFORM_WINDOWS
#	include "Platform/Windows/WindowsPlatformTypes.h"
	namespace Moonlit { using PlatformTypes = WindowsPlatformTypes; }
#elif MOON_PLATFORM_MACOS
#	include "Platform/MacOS/MacOSPlatformTypes.h"
	namespace Moonlit { using PlatformTypes = LinuxPlatformTypes; }
#elif MOON_PLATFORM_LINUX
#	include "Platform/Linux/LinuxPlatformTypes.h"
	namespace Moonlit { using PlatformTypes = WindowsPlatformTypes; }
#endif

namespace Moonlit {

	/** An 8-bit Unsigned Integer. */
	using uint8 = PlatformTypes::uint8;

	/** A 16-bit Unsigned Integer. */
	using uint16 = PlatformTypes::uint16;

	/** A 32-bit Unsigned Integer. */
	using uint32 = PlatformTypes::uint32;

	/** A 64-bit Unsigned Integer. */
	using uint64 = PlatformTypes::uint64;

	/** An 8-bit Signed Integer. */
	using int8 = PlatformTypes::int8;

	/** A 16-bit Signed Integer. */
	using int16 = PlatformTypes::int16;

	/** A 32-bit Signed Integer. */
	using int32 = PlatformTypes::int32;

	/** A 64-bit Signed Integer. */
	using int64 = PlatformTypes::int64;

}