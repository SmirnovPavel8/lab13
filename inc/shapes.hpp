#pragma once
#include <camera.hpp>
namespace mt
{
	class Shapes
	{
	public:
		Shapes(double x0, double y0, double z0, double r);
		virtual ~Shapes();
		virtual void Rotate(double t) = 0;
		Point Get_Points(int i);
		int Get_Size();
	protected:
		Point* m_points = nullptr;
		int m_size = 0;
		double m_x0, m_y0, m_z0, m_r;

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