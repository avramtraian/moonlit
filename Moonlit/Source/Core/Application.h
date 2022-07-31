// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#pragma once

#include "CoreTypes.h"

#include "Launch/ExitCodes.h"

namespace Moonlit {

	MOON_API bool InitializeCore();
	MOON_API void ShutdownCore();

	MOON_API bool ShouldRestartApplication();
	MOON_API void SetRestartApplication(bool restart_application);

	struct CommandLineParameters
	{
	public:
		CommandLineParameters()
			: Parameters(nullptr)
			, ParametersCount(0)
		{}

		CommandLineParameters(char** cmd_params, uint32 cmd_params_count)
			: Parameters(cmd_params)
			, ParametersCount(cmd_params_count)
		{}

		char* operator[](uint32 index) const
		{
			return Parameters[index];
		}

	public:
		char** Parameters;
		uint32 ParametersCount;
	};

	struct ApplicationSpecification
	{
		CommandLineParameters CommandArgs;
	};

	class MOON_API Application
	{
	public:
		static Application* Get();

	public:
		Application(const ApplicationSpecification& specification);
		virtual ~Application();

	public:
		ExitCode Run();

		const ApplicationSpecification& GetSpecification() const { return m_Specification; }

	private:
		ApplicationSpecification m_Specification;
	};

	Application* CreateApplication(const CommandLineParameters& cmd_args);

}