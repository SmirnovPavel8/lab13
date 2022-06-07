#include <lines.hpp>
namespace mt
{
	Line::Line(double x0, double y0, double z0, double r, double fi, double teta) :Shapes(x0, y0, z0, r)
	{
		
		m_x0 = x0;
		m_y0 = y0;
		m_z0 = z0;
		m_fi = fi;
		m_r = r;
		m_teta = teta;
		m_points = new Point[200000];
		for (double i = 0.00; i < m_r; i += 0.001)
		{

			m_points[m_size].x = i * sin(m_teta) * cos(m_fi) + m_x0;
			m_points[m_size].y = i * sin(m_teta) * sin(m_fi) + m_y0;
			m_points[m_size].z = i * cos(m_teta) + m_z0;
			m_size++;
		}

	}

	
	void Line::Rotate(double t)
	{
		m_size = 0;
		for (double i = 0.00; i < m_r; i += 0.001)
		{

			m_points[m_size].x = i * sin(3.14 * t / 180) * cos(0) + m_x0;
			m_points[m_size].y = i * sin(3.14 * t / 180) * sin(0) + m_y0;
			m_points[m_size].z = i * cos(3.14 * t / 180)+m_z0;
			m_size++;
		}
	}
	Line::~Line()
	{
		//if (m_points != nullptr)
			//delete[] m_points;
	}
}