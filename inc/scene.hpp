#pragma once
#include <SFML/Graphics.hpp>
#include <shapes.hpp>
//#include <camera.hpp>
//#include<camera.hpp>
namespace mt
{
	class Scene
	{
	public:
		Scene(int width, int height);
		~Scene();
		void LifeCycle();

	private:
		std::unique_ptr<Camera> m_camera;
		std::unique_ptr<Sphere> circle;
		//std::vector<Line*>lines;
		//std::unique_ptr<Sphere> circle1;
		std::unique_ptr<Line> line;
		std::unique_ptr<Line> pillar;
		//std::unique_ptr<Line> line1;
		int m_width;
		int m_height;
		std::unique_ptr<sf::RenderWindow> m_window;
		std::unique_ptr<sf::Texture> m_texture;
		std::unique_ptr<sf::Sprite> m_sprite;
	};
}
