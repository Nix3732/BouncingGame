#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace ez
{
	const float pi = acos(-1);

	class Circle
	{
		float c_r;
		float c_x;
		float c_y;
		float c_vx;
		float c_vy;
		int c_red;
		int c_g;
		int c_b;
		sf::CircleShape c_shape;

	public:
		Circle() = default;

		Circle(float x, float y, float r, float vx, float vy, int red, int green, int blue)
		{
			Setup(x, y, r, vx, vy, red, green, blue);
		}

		void Setup(float x, float y, float r, float vx, float vy, int red, int green, int blue)
		{
			c_x = x;
			c_y = y;
			c_r = r;
			c_vx = vx;
			c_vy = vy;
			c_red = red;
			c_g = green;
			c_b = blue;
			c_shape.setOrigin(c_r, c_r);
			c_shape.setRadius(c_r);
			c_shape.setPosition(c_x, c_y);
			c_shape.setFillColor(sf::Color::Color(c_red, c_g, c_b));
		}

		sf::CircleShape Get()
		{
			return c_shape;
		}

		float X()
		{
			return c_x;
		}
		float Y()
		{
			return c_y;
		}
		float R()
		{
			return c_r;
		}
		float VX()
		{
			return c_vx;
		}
		void VX(float vx)
		{
			c_vx = vx;
		}
		float VY()
		{
			return c_vy;
		}
		void VY(float vy)
		{
			c_vy = vy;
		}
		int RED()
		{
			return c_red;
		}
		int GREEN()
		{
			return c_g;
		}
		int BLUE()
		{
			return c_b;
		}


		void Move(float dt)
		{
			c_x += c_vx * dt;
			c_y += c_vy * dt;
			c_shape.setPosition(c_x, c_y);
		}
	};
}