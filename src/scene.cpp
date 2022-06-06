#include <scene.hpp>
namespace mt
{
	Scene::Scene(int width, int height)
	{
		m_width = width;
		m_height = height;
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_width, m_height), "3D Engine");
		m_texture = std::make_unique<sf::Texture>();
		m_texture->create(m_width, m_height);
		m_sprite = std::make_unique<sf::Sprite>(*m_texture);

		Intrinsic intrinsic = { 960.0, 540.0, 960.0, 540.0 };
		Point position = { 0.0, 0.0, 0.0 };
		Angles angles = { 0.0,0.0,0.0 };
		m_camera = std::make_unique<Camera>(m_width, m_height, intrinsic, position, angles);
		circle = std::make_unique<Sphere>(0, 0, 0, 0.1);
		//circle1 = std::make_unique<Sphere>(1, 1, 1, 0.1);
		line = std::make_unique<Line>(0, 0, 0,1,0,130*3.14/180);
		pillar=std::make_unique<Line>(0, 0, 0, 1, 0, 3.14 / 2);
		//line1 = std::make_unique<Line>(1, 1, 1, 1, 0, 3.14 / 2);
		//for (int i = 0; i < 3; i++)
			//lines.push_back(new Line(i+1,0,0,1,0,3.14/2));
	}
	Scene::~Scene()
	{
	}

	void Scene::LifeCycle()
	{
		
		double t = 130;
		bool flag = true;
		while (m_window->isOpen()) {
			sf::Event event;
			while (m_window->pollEvent(event))
				if (event.type == sf::Event::Closed)
					m_window->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				m_camera->dZ(0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				m_camera->dZ(-0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				m_camera->dX(-0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				m_camera->dX(0.1);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_camera->dPitch(-0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_camera->dPitch(0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_camera->dRoll(-0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_camera->dRoll(0.02);
			}
			circle->Rotate(t);
			//circle1->Rotate(-t);
			//for (int i = 0; i < 3; i++)
			//{
			//	lines[i]->Rotate(t);
			//}
			line->Rotate(t);
			//line1->Rotate(-t);
			if (t >= 230)
				flag = false;
			if (t <= 130)
				flag = true;
			if (flag == true)
				t += 0.5;
			if (flag == false)
				t -= 0.5;
			//  
			for (int i = 0; i < circle->Get_Size(); i++)
			{
				m_camera->ProjectPoint(circle->Get_Points(i), { 255, 0 ,0, 255 });
				//m_camera->ProjectPoint(circle1->Get_Points(i), { 0, 0 ,255, 255 });
			}
			for (int i = 0; i < line->Get_Size(); i++)
			{
				m_camera->ProjectPoint(line->Get_Points(i), { 0, 255 ,0, 255 });
				//m_camera->ProjectPoint(line1->Get_Points(i), { 0, 255 ,255, 255 });
				//for(int j=0;j<3;j++)
				//m_camera->ProjectPoint(lines[j]->Get_Points(i), { 0, 255 ,255, 255 });
			}
			for (int i = 0; i < pillar->Get_Size(); i++)
			{
				m_camera->ProjectPoint(pillar->Get_Points(i), { 0, 255 ,255, 255 });
			}

			m_texture->update((uint8_t*)m_camera->Picture(), 1920, 1080, 0, 0);
			m_camera->Clear();


			m_window->clear();
			m_window->draw(*m_sprite);

			m_window->display();

		}
	}
}
