#pragma once

#include <Core/Core.h>
#include <Utils/StringID.h>

namespace Jem {
	// A base app class.
	class JEM_API Game {
	public:
		                    Game();
		virtual             ~Game();

		static Game*        GetGame();
		void                Run();

	private:
		static Game*        mGame;
	};
}