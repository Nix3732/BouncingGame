#pragma once
#include <ostream>
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
		ez::Circle c1;
		ez::Circle c2;
		ez::Block *b;

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
			int x = 250;
			int y = 500;
			int r = 10;
			int vx = 400;
			int vy = 400;
			int red = 127;
			int green = 255;
			int blue = 212;
			c1.Setup(x, y, r, vx, vy, red, green, blue);

			x = 750;
			vx = -400;
			vy = -400;
			red = 0;
			green = 255;
			blue = 127;
			c2.Setup(x, y, r, vx, vy, red, green, blue);

			int amount = pow(g_Wd / (r * 2), 2);

			x = 0;
			y = 0;
			int a = r * 2;

			b = new ez::Block[amount];
			for (int i = 0; i < amount; i++)
			{
				b[i].Setup(x, y, a, red, green, blue);
				y += a;
				if (y % g_Wd == 0)
				{
					y = 0;
					x += 20;
				}
				if (x / (g_Wd/2) >= 1)
				{
					red = 127;
					green = 255;
					blue = 212;
				}
			}
		}

		bool ColorBorder(Circle& c, Block& b)
		{
			float xc = c.X();
			float yc = c.Y();
			float rc = c.R();
			float ex = c.VX();
			float ey = c.VY();
			int cred = c.RED();
			int cg = c.GREEN();
			int cb = c.BLUE();

			float xb = b.X();
			float yb = b.Y();
			int ab = b.A();
			int bred = b.RED();
			int bg = b.GREEN();
			int bb = b.BLUE();

			if ((cred == bred) && (cg == bg) && (cb == bb))
			{
				if ((xb - ab / 2 <= xc && xc <= xb) && (yb <= yc && yc <= yb + ab))
				{
					c.VX(-ex);
					b.RED(cred);
					b.GREEN(cg);
					b.BLUE(cb);
					return true;
				}
				if ((yb - ab / 2 <= yc && yc <= yb) && (xb <= xc && xc <= xb + ab))
				{
					c.VX(-ey);
					b.RED(cred);
					b.GREEN(cg);
					b.BLUE(cb);
					return true;
				}
				if ((xb + ab <= xc && xc <= xb + (ab * 3 / 2)) && (yb <= yc && yc <= yb + ab))
				{
					c.VX(-ex);
					b.RED(cred);
					b.GREEN(cg);
					b.BLUE(cb);
					return true;
				}
				if ((yb + ab <= yc && yc <= yb + (ab * 3 / 2)) && (xb <= xc && xc <= xb + ab))
				{
					c.VX(-ey);
					b.RED(cred);
					b.GREEN(cg);
					b.BLUE(cb);
					return true;
				}
			}
			else
			{
				return false;
			}


		}

		void border(Circle& c)
		{
			float x = c.X();
			float y = c.Y();
			float r = c.R();
			float ex = c.VX();
			float ey = c.VY();
			int cred = c.RED();
			int cg = c.GREEN();
			int cb = c.BLUE();

			
			if ((x - r <= 0) || (x + r >= g_Wd))
			{
				c.VX(-ex);
			}

			if ((y - r <= 0) || (y + r >= g_Hg))
			{
				c.VY(-ey);
			}
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

				border(c1);
				border(c2);

				for (int i = 0; i < 2500; i++)
				{	
					if (ColorBorder(c1, b[i]) == true)
					{
						b[i].Setup(b[i].X(), b[i].Y(), b[i].A(), c1.RED(), c1.GREEN(), c1.BLUE());
					}
					if (ColorBorder(c2, b[i]) == true)
					{
						b[i].Setup(b[i].X(), b[i].Y(), b[i].A(), c2.RED(), c2.GREEN(), c2.BLUE());
					}
				}

				c1.Move(dt);
				c2.Move(dt);

				w_Window.clear();


				for (int i = 0; i < 2500; i++)
				{
					w_Window.draw(b[i].Get());
				}

				w_Window.draw(c1.Get());
				w_Window.draw(c2.Get());
		

				w_Window.display();
			}
		}
	};
}