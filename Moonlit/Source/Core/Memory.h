// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#pragma once

#include "CoreTypes.h"

namespace Moonlit {

	class MOON_API Memory
	{
	public:
		static bool Initialize();
		static void Shutdown();
	};

}