// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#pragma once

#include "Core/CoreTypes.h"

namespace Moonlit {

	class MOON_API Platform
	{
	public:
		static bool Initialize();
		static void Shutdown();
	};

}