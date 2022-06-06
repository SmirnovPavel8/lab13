#pragma once
#include <shapes.hpp>
namespace mt
{
	class Sphere :public Shapes
	{
	public:
		Sphere(double x0, double y0, double z0, double r);
		virtual ~Sphere();
		void Rotate(double t) override;
		/*private:
			Point* m_points = nullptr;
			int m_size = 0;
			double m_x0, m_y0, m_z0, m_r;*/
	};
}