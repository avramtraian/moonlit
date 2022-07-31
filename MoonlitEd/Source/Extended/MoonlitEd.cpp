// Copyright to Avram Traian. 2022 - 2022.
// File created on July 30 2022.

#include "Core/Launch/Launch.h"

namespace Moonlit {

	class EditorApplication : public Application
	{
	public:
		EditorApplication(const ApplicationSpecification& specification)
			: Application(specification)
		{}

		virtual ~EditorApplication() override
		{
		}
	};

	Application* CreateApplication(const CommandLineParameters& cmd_args)
	{
		ApplicationSpecification specification;
		specification.CommandArgs = cmd_args;

		return new EditorApplication(specification);
	}

}