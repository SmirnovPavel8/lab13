#include <scene.hpp>
namespace mt
{
	Scene::Scene(int width, int height,int N,int N1)
	{
m_width = width;
m_height = height;
m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_width, m_height), "3D Engine");
m_texture = std::make_unique<sf::Texture>();
m_texture->create(m_width, m_height);
m_sprite = std::make_unique<sf::Sprite>(*m_texture);
m_N = N;
m_N1 = N1;
Intrinsic intrinsic = { 960.0, 540.0, 960.0, 540.0 };
Point position = { 0.0, 0.0, 0.0 };
Angles angles = { 0.0,0.0,0.0 };
m_camera = std::make_unique<Camera>(m_width, m_height, intrinsic, position, angles);
double x0 = 0;
double y0 = 0;
double z0 = 0;
double length = 1;
double radius = 0.1;
pillar = std::make_unique<Line>(x0, y0, z0, radius*N*2-2*radius, 0, 3.14 / 2);
//pillar2 = std::make_unique<Pillar>(x0, y0, 2, 1);
for (int i = 0; i < m_N; i++)
{
	lines.push_back(new Line((i * 0.2)+x0, y0, z0, length, 0, 3.14));
	spheres.push_back(new Sphere((i * 0.2)+x0, y0, z0-length, radius));
}
	}
	Scene::~Scene()
	{
	}

	void Scene::LifeCycle()
	{
		srand(time(0));
		double t = 130;
		bool flag = true;
		bool flag_c = true;
		int sphere_size = spheres[0]->Get_Size();
		int line_size = lines[0]->Get_Size();
		Pixel first_c = { 255,0,0,255 };
		Pixel second_c= { 255,0,0,255 };
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
			if (t >= 230)
				flag = false;
			if (t <= 130)
				flag = true;
			if (t < 180)
			{
				if (flag == true)
				{
					t += 0.5;
					for (int i = m_N - m_N1; i < m_N; i++)
					{
						lines[i]->Rotate(t);
						spheres[i]->Rotate(t);
					}

				}
				else
				{
					t -= 0.5;
					for (int i = m_N - m_N1; i < m_N; i++)
					{
						lines[i]->Rotate(t);
						spheres[i]->Rotate(t);
					}

				}
			}
			if (t > 180)
			{
				if (flag == true)
				{
					t += 0.5;
					for (int i = 0; i < m_N1; i++)
					{
						lines[i]->Rotate(t);
						spheres[i]->Rotate(t);
					}

				}
				else
				{
					t -= 0.5;
					for (int i = 0; i < m_N1; i++)
					{
						lines[i]->Rotate(t);
						spheres[i]->Rotate(t);
					}

				}
			}
			if (t == 180)
			{
				if (flag == true)
				{
					t += 0.5;
					first_c = { unsigned char(rand() % 254),unsigned char(rand() % 254) ,unsigned char(rand() % 254) ,255 };
					flag_c = true;
					for (int i = 0; i < m_N1; i++)
					{
						
						lines[i]->Rotate(t);
						lines[i]->Recolor(first_c);
						spheres[i]->Rotate(t);
						spheres[i]->Recolor(first_c);
					}

				}
				else
				{
					t -= 0.5;
					second_c = { unsigned char(rand() % 254),unsigned char(rand() % 254) ,unsigned char(rand() % 254) ,255 };
					flag_c = false;
					for (int i = m_N - m_N1; i < m_N; i++)
					{
						
						lines[i]->Rotate(t);
						lines[i]->Recolor(second_c);
						spheres[i]->Rotate(t);
						spheres[i]->Recolor(second_c);
					}
				}
			}
		//не уверен что это лучше для работоспособности
			//Rotation(m_N, m_N1, t, flag, flag_c, first_c, second_c, lines, spheres);
			//Paint(m_N, m_N1, flag_c, first_c, second_c, lines, spheres, pillar, *m_camera);
			int sphere_size = spheres[0]->Get_Size();
			int line_size = lines[0]->Get_Size();
			for (int i = 0; i < sphere_size; i++)
			{
				
				
				for (int j = 0; j < m_N; j++)
					m_camera->ProjectPoint(spheres[j]->Get_Points(i), spheres[j]->Get_Color());
				
			}
			for (int i = 0; i < line_size; i++)
			{
				
				for (int j = 0; j < m_N; j++)
					m_camera->ProjectPoint(lines[j]->Get_Points(i), lines[j]->Get_Color());
			}
			for (int i = 0; i < pillar->Get_Size(); i++)
			{
				m_camera->ProjectPoint(pillar->Get_Points(i), { 0, 255 ,255, 255 });
			}
			/*for (int i = 0; i < pillar2->Get_Size(); i++)
			{
				m_camera->ProjectPoint(pillar2->Get_Points(i), { 0, 255 ,255, 255 });
			}*/
			m_texture->update((uint8_t*)m_camera->Picture(), 1920, 1080, 0, 0);
			m_camera->Clear();


			m_window->clear();
			m_window->draw(*m_sprite);

			m_window->display();

		}
	}
}
