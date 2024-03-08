#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace ez
{
	const float pi = acos(-1);
	
	class Circle1
	{
		float c_r;
		float c_x;
		float c_y;
		float c_vx;
		float c_vy;
		sf::CircleShape c_shape;

	public:
		Circle1() = default;

		Circle1(float x1, float y1, float r1, float vx1, float vy1)
		{
			Setup(x1, y1, r1, vx1, vy1);
		}

		void Setup(float x1, float y1, float r1, float vx1, float vy1)
		{
			c_x = x1;
			c_y = y1;
			c_r = r1;
			c_vx = vx1;
			c_vy = vy1;
			c_shape.setOrigin(c_r, c_r);
			c_shape.setRadius(c_r);
			c_shape.setPosition(c_x, c_y);
			c_shape.setFillColor(sf::Color::Color(127,255,212));
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


		void Move(float dt)
		{
			c_x += c_vx * dt;
			c_y += c_vy * dt;
			c_shape.setPosition(c_x, c_y);
		}
	};

	class Circle2
	{
		float c_r;
		float c_x;
		float c_y;
		float c_vx;
		float c_vy;
		sf::CircleShape c_shape;

	public:
		Circle2() = default;

		Circle2(float x2, float y2, float r2, float vx2, float vy2)
		{
			Setup(x2, y2, r2, vx2, vy2);
		}

		void Setup(float x2, float y2, float r2, float vx2, float vy2)
		{
			c_x = x2;
			c_y = y2;
			c_r = r2;
			c_vx = vx2;
			c_vy = vy2;
			c_shape.setOrigin(c_r, c_r);
			c_shape.setRadius(c_r);
			c_shape.setPosition(c_x, c_y);
			c_shape.setFillColor(sf::Color::Color(188, 143, 143));
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


		void Move(float dt)
		{
			c_x += c_vx * dt;
			c_y += c_vy * dt;
			c_shape.setPosition(c_x, c_y);
		}
	};
}