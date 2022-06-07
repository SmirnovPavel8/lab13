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
		Point Get_Points(int i);//возвращение точек фигуры
		Pixel Get_Color();//возвращение цвета
		void Recolor(Pixel p);//функция перекраски
		int Get_Size();//возвращение размера
	protected:
		Point* m_points = nullptr;//массив точек
		Pixel color;//цвет
		int m_size = 0;//кол-во точек
		double m_x0, m_y0, m_z0, m_r;//начальные координаты и m_r-радиус или длина прямой в зависимоти от фигуры

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