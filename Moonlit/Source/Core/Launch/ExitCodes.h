// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#pragma once

#include "Core/CoreTypes.h"

namespace Moonlit {

	enum class ExitCode : int32
	{
		Success                 = 0x00,

		Unknown                 = 0x01,
		InitializeCoreFailed    = 0x02,
		CreateApplicationFailed = 0x03,
	};

}