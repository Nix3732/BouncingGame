#pragma once
#include <SFML/Graphics.hpp>

namespace ez
{
	class Block
	{
		int b_a;
		int b_x;
		int b_y;
		int b_r;
		int b_g;
		int b_b;
		sf::RectangleShape Rect;

	public:

		Block() = default;

		Block(int x, int y, int a, int red, int green, int blue)
		{
			Setup(x, y, a, red, green, blue);
		}

		void Setup(int x, int y, int a, int red, int green, int blue)
		{
			b_x = x;
			b_y = y;
			b_a = a;
			b_r = red;
			b_g = green;
			b_b = blue;
			Rect.setFillColor(sf::Color::Color(b_r, b_g, b_b));
			Rect.setPosition(b_x, b_y);
			Rect.setSize(sf::Vector2f(a, a));
		}

		sf::RectangleShape Get()
		{
			return Rect;
		}
		float X()
		{
			return b_x;
		}
		float Y()
		{
			return b_y;
		}
		float A()
		{
			return b_a;
		}
		int RED()
		{
			return b_r;
		}
		int GREEN()
		{
			return b_g;
		}
		int BLUE()
		{
			return b_b;
		}
		void Color(int r, int g, int b)
		{
			b_r = r;
			b_g = g;
			b_b = b;
			Rect.setFillColor(sf::Color::Color(b_r, b_g, b_b));
		}
	};
}