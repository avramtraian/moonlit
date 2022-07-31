// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#include "Application.h"

#include "Memory.h"
#include "Platform/Platform.h"

namespace Moonlit {

	static Application* s_ApplicationInstance = nullptr;

	static bool s_RestartApplication = false;

	bool InitializeCore()
	{
		return true;
	}

	void ShutdownCore()
	{
		
	}

	bool ShouldRestartApplication()
	{
		return s_RestartApplication;
	}

	void SetRestartApplication(bool restart_application)
	{
		s_RestartApplication = restart_application;
	}

	Application* Application::Get()
	{
		return s_ApplicationInstance;
	}

	Application::Application(const ApplicationSpecification& specification)
		: m_Specification(specification)
	{
		s_ApplicationInstance = this;
	}

	Application::~Application()
	{
		s_ApplicationInstance = nullptr;
	}

	ExitCode Application::Run()
	{
		return ExitCode::Success;
	}

}