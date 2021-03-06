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
		std::vector<Line*>lines;//?????? ?????
		std::vector<Sphere*>spheres;//?????? ?????
		std::unique_ptr<Line> pillar;//?????
		//std::unique_ptr<Pillar> pillar2;
		int m_width;
		int m_height;
		int m_N;//???-?? ????? ? ?????
		int m_N1;//???-?? ???????????? ????? ? ?????
		std::unique_ptr<sf::RenderWindow> m_window;
		std::unique_ptr<sf::Texture> m_texture;
		std::unique_ptr<sf::Sprite> m_sprite;
	};
}
