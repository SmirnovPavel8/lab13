#pragma once
#include <SFML/Graphics.hpp>
//#include <shapes.hpp>
//#include <lines.hpp>
//#include <circles.hpp>
#include <functions.hpp>
//#include <camera.hpp>
//#include<camera.hpp>
namespace mt
{
	class Scene
	{
	public:
		Scene(int width, int height,int N,int N1);
		~Scene();
		void LifeCycle();

	private:
		std::unique_ptr<Camera> m_camera;
		std::vector<Line*>lines;//массив нитей
		std::vector<Sphere*>spheres;//массив шаров
		std::unique_ptr<Line> pillar;//опора
		//std::unique_ptr<Pillar> pillar2;
		int m_width;
		int m_height;
		int m_N;//кол-во шаров и нитей
		int m_N1;//кол-во колеблющихся шаров и нитей
		std::unique_ptr<sf::RenderWindow> m_window;
		std::unique_ptr<sf::Texture> m_texture;
		std::unique_ptr<sf::Sprite> m_sprite;
	};
}
