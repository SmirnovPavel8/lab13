#pragma once
#include<shapes.hpp>
#include <circles.hpp>
#include<lines.hpp>
namespace mt 
{
	void Rotation(int m_N,int m_N1,double& t,bool& flag,Pixel& first_c,  std::vector<Line*>& lines, std::vector<Sphere*>& spheres);//функция сдвига маятника
	void Paint(int m_N, int m_N1,std::vector<Line*>& lines, std::vector<Sphere*>& spheres, std::unique_ptr<Line>& pillar, Camera& m_camera);//функция отрисовки фигур

}