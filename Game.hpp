#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Ball.hpp"
#include "Block.hpp"
#include <thread>

namespace ez
{
	class Game
	{
		int g_Wd;
		int g_Hg;
		std::string w_Name;
		sf::RenderWindow w_Window;
		sf::Image icon;
		ez::Circle1 c1;
		ez::Circle2 c2;

	public:
		Game(int wd, int hg, std::string name)
		{
			g_Wd = wd;
			g_Hg = hg;
			w_Name = name;
		}

		void set()
		{
			w_Window.create(sf::VideoMode(g_Wd, g_Hg), w_Name);

			icon.loadFromFile("assets\\icon.png");
			w_Window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

			srand(time(0));
			int x1 = 250;
			int y1 = 500;
			int r1 = 50;
			int vx1 = 40;
			int vy1 = 40;
			c1.Setup(x1, y1, r1, vx1, vy1);

			int x2 = 750;
			int y2 = 500;
			int r2 = 50;
			int vx2 = -40;
			int vy2 = -40;
			c2.Setup(x2, y2, r2, vx2, vy2);
		}


		void life()
		{
			sf::Clock clock;

			while (w_Window.isOpen())
			{
				sf::Event event;
				while (w_Window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						w_Window.close();
					}
				}

				float dt = clock.getElapsedTime().asSeconds();
				clock.restart();

				c1.Move(dt);
				c2.Move(dt);

				w_Window.clear();

				w_Window.draw(c1.Get());
				w_Window.draw(c2.Get());
				w_Window.display();
			}
		}
	};
}