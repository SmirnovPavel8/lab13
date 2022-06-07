#pragma once
#include <shapes.hpp>
namespace mt
{

	class Line : public Shapes
	{
	public:
		Line(double x0, double y0, double z0, double r, double fi, double teta);
		virtual~Line();
		void Rotate(double t) override;//функция поворота
	private:
		//Point* m_points = nullptr;
		//int m_size = 0;
		//double m_x0, m_y0, m_z0, m_fi, m_teta, m_r;
		double m_fi, m_teta;//углы прямой
	};
}