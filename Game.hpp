#pragma once
#include <string>

namespace ez
{
	class Game
	{
		int g_Wd;
		int g_Hg;
		std::string w_Name;


	public:
		Game(int wd, int hg)
		{
			g_Wd = wd;
			g_Hg = hg;
		}

		void set(int n);

	};
}