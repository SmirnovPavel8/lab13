#include<shapes.hpp>
namespace mt
{
	
	Shapes::Shapes(double x0, double y0, double z0, double r)
	{
		m_r = r;
		m_x0 = x0;
		m_y0 = y0;
		m_z0 = z0;
		m_points = new Point[200000];
	}
	Shapes::~Shapes()
	{
		if (m_points != nullptr)
			delete[] m_points;
	}
	Point Shapes::Get_Points(int i){return m_points[i];}
	int Shapes::Get_Size() { return m_size; }
/*	Pillar::Pillar(double x0, double y0, double z0, double r)
	{
		m_points = new Point[200000];
		m_r = r;
		m_x0 = x0;
		m_y0 = y0;
		m_z0 = z0;
		double m_l = 0;
		for (double fi = 0; fi < 6.28; fi += 0.1)
		{
			for (double i = 0; i < 1; i += 0.005)
			{
				//m_points[m_size].x = m_r * sin(teta) * cos(fi) + m_x0;
				//m_points[m_size].y = m_r * sin(teta) * sin(fi) + m_y0;
				//m_points[m_size].z = m_r * cos(teta) + m_z0;
				m_points[m_size].x = i + m_x0;
				m_points[m_size].y = m_r * sin(3.1) * sin(fi) + m_y0;
				m_points[m_size].z = m_r * cos(3.1) + m_z0;
				m_size++;
			}
		}
	}
	Pillar::~Pillar()
	{
		if (m_points != nullptr)
			delete[] m_points;
	}
	Point Pillar::Get_Points(int i) { return m_points[i]; }
	int Pillar::Get_Size() { return m_size; }*/
}