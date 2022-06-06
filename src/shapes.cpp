#include<shapes.hpp>
namespace mt
{
	Sphere::Sphere(double x0, double y0, double z0,double r)
	{
		
		m_r = r;
		m_x0 = x0;
		m_y0 = y0;
		m_z0 = z0;
		m_points = new Point[200000];
		for (double fi = 0; fi < 6.28; fi += 0.05)
			for (double teta = 0; teta < 3.14; teta += 0.05)
			{
				m_points[m_size].x = m_r * sin(teta) * cos(fi)+m_x0;
				m_points[m_size].y = m_r * sin(teta) * sin(fi)+m_y0;
				m_points[m_size].z = m_r * cos(teta)+m_z0;
				m_size++;
			}
	}
	Point Sphere::Get_Points(int i) { return m_points[i]; }
	int Sphere::Get_Size() { return m_size; };
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
				m_points[m_size].x = m_r * sin(teta) * cos(fi) + x_s+m_x0;
				m_points[m_size].y = m_r * sin(teta) * sin(fi)+m_y0;
				m_points[m_size].z = -(m_r * cos(teta) + z_s)+m_z0;
				m_size++;
			}
	}
	Sphere::~Sphere()
	{
		if (m_points != nullptr)
			delete[] m_points;
	}
	Line::Line(double x0, double y0, double z0,double r ,double fi,double teta)
	{
		
		m_x0 = x0;
		m_y0 = y0;
		m_z0 = z0;
		m_fi = fi;
		m_r = r;
		m_teta = teta;
		m_points = new Point[m_r/0.001];
		for (double i = 0.00; i < m_r; i += 0.001)
		{

			m_points[m_size].x = i * sin(m_teta) * cos(m_fi)+m_x0;
			m_points[m_size].y = i * sin(m_teta) * sin(m_fi)+m_y0;
			m_points[m_size].z = i * cos(m_teta)+m_z0;
			m_size++;
		}

	}
	
	Line::~Line()
	{
		if (m_points != nullptr)
			delete[] m_points;
	}
	void Line::Rotate(double t)
	{
		m_size = 0;
		for (double i = 0.00; i < m_r; i += 0.001)
		{
			
			m_points[m_size].x = i * sin(3.14 * t / 180) * cos(0)+m_x0;
			m_points[m_size].y = i * sin(3.14 * t / 180) * sin(0)+m_y0;
			m_points[m_size].z =  i* cos(3.14 * t / 180)+m_z0;
			m_size++;
		}
	}
	Point Line::Get_Points(int i)
	{
		return m_points[i];
	}
	int Line::Get_Size()
	{
		return m_size;
	}
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