// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#pragma once

#include "ExitCodes.h"

#include "Core/Application.h"

namespace Moonlit {

	/**
	* The platform-generic application entry function. This is the lifetime of the application.
	* 
	* @param cmd_params The command line arguments passed to the executable.
	* @param cmd_params_count The number of command line arguments passed to the executable.
	* 
	* @returns The application exit code.
	*/
	inline ExitCode GuardedMain(char** cmd_params, uint32 cmd_params_count)
	{
		CommandLineParameters cmd_args(cmd_params, cmd_params_count);
		ExitCode exit_code = ExitCode::Unknown;

		// The application Restart Loop.
		do
		{
			// Initializes Core.
			if (!InitializeCore())
			{
				exit_code = ExitCode::InitializeCoreFailed;
				continue;
			}

			// Instantiates (and initializes) the application.
			Application* application = CreateApplication(cmd_args);

			// Checks that the application was successfully created.
			if (!application)
			{
				exit_code = ExitCode::CreateApplicationFailed;
				ShutdownCore();
				continue;
			}

			// Runs the application.
			exit_code = application->Run();

			// Destroys (and shutdowns) the application.
			delete application;

			// Shutdowns Core.
			ShutdownCore();
		}
		while (ShouldRestartApplication());

		return exit_code;
	}

}

/** Platform switch. */
#if MOON_PLATFORM_WINDOWS
#	include "WindowsLaunch.h"
#elif MOON_PLATFORM_MACOS
#	include "MacOSLaunch.h"
#elif MOON_PLATFORM_LINUX
#	include "LinuxLaunch.h"
#endif