// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#pragma once

#include "Core/CoreDefines.h"

namespace Moonlit {

	struct WindowsPlatformTypes
	{
		using uint8  = unsigned __int8;
		using uint16 = unsigned __int16;
		using uint32 = unsigned __int32;
		using uint64 = unsigned __int64;

		using int8   = signed __int8;
		using int16  = signed __int16;
		using int32  = signed __int32;
		using int64  = signed __int64;
	};

}