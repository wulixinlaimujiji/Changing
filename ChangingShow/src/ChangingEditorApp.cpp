#include <Changing.h>
#include <Changing/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Changing {

	class ChangingShow : public Application
	{
	public:
		ChangingShow()
			: Application("ChangingShow")
		{
			PushLayer(new EditorLayer());
		}

		~ChangingShow() {}
	};

	Application* CreateApplication()
	{
		return new ChangingShow();
	}

}
