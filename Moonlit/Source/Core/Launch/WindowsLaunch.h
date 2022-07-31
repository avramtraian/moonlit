// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#pragma once

#include "ExitCodes.h"

namespace Moonlit {

	ExitCode GuardedMain(char** cmd_params, uint32 cmd_params_count);

}

#include <Windows.h>

#if MOON_BUILD_SHIPPING

INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	return (INT)((Moonlit::int32)Moonlit::GuardedMain((char**)__argv, (Moonlit::uint32)__argc));
}

#else

int main(int argc, char** argv)
{
	return (int)((Moonlit::int32)Moonlit::GuardedMain((char**)argv, (Moonlit::uint32)argc));
}

#endif