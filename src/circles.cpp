#include<circles.hpp>
namespace mt
{

	Sphere::Sphere(double x0, double y0, double z0, double r):Shapes(x0, y0, z0, r)
	{
		
		m_r = r;
		m_x0 = x0;
		m_y0 = y0;
		m_z0 = z0;
		m_points = new Point[200000];
		for (double fi = 0; fi < 6.28; fi += 0.05)
			for (double teta = 0; teta < 3.14; teta += 0.05)
			{
				m_points[m_size].x = m_r * sin(teta) * cos(fi) + m_x0;
				m_points[m_size].y = m_r * sin(teta) * sin(fi) + m_y0;
				m_points[m_size].z = m_r * cos(teta) + m_z0;
				m_size++;
			}
	}
	void Sphere::Rotate(double t)
	{
		double x_s, z_s;
		int A = 1;
		x_s = A * sin(3.14 * t / 180);
		z_s = sqrt(1 - (x_s) * (x_s));
		m_size = 0;
		for (double fi = 0; fi < 6.28; fi += 0.05)
			for (double teta = 0; teta < 3.14; teta += 0.05)
			{
				m_points[m_size].x = m_r * sin(teta) * cos(fi) + x_s + m_x0;
				m_points[m_size].y = m_r * sin(teta) * sin(fi) + m_y0;
				m_points[m_size].z = -(m_r * cos(teta) + z_s) + m_z0;
				m_size++;
			}
	}
	Sphere::~Sphere()
	{
		//if (m_points != nullptr)
			//delete[] m_points;
	}
}