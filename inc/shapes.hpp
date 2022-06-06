#pragma once
#include <camera.hpp>
namespace mt
{
	class Sphere
	{
	public:
		Sphere(double x0, double y0, double z0, double r);
		~Sphere();
		void Rotate(double t);
		Point Get_Points(int i);
		int Get_Size();
	private:
		Point* m_points = nullptr;
		int m_size = 0;
		double m_x0, m_y0, m_z0, m_r;
	};
	class Line
	{
	public:
		Line(double x0, double y0, double z0, double r, double fi, double teta);
		~Line();
		void Rotate(double t);
		Point Get_Points(int i);
		int Get_Size();
	private:
		Point* m_points = nullptr;
		int m_size = 0;
		double m_x0, m_y0, m_z0, m_fi, m_teta, m_r;
	};
	/*class Pillar
	{
	public:
		Pillar(double x0, double y0, double z0, double r);
		~Pillar();
		Point Get_Points(int i);
		int Get_Size();
	private:
		Point* m_points = nullptr;
		int m_size = 0;
		double m_x0, m_y0, m_z0, m_r;
	};*/
}