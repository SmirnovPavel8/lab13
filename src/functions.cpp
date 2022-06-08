#include<functions.hpp>
namespace mt
{
	void Rotation(int m_N, int m_N1, double& t, bool& flag, Pixel& first_c, std::vector<Line*>& lines, std::vector<Sphere*>& spheres)
	{
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
				first_c = { unsigned char(rand() % 254),unsigned char(rand() % 254) ,unsigned char(rand() % 254) ,255 };
				for (int i = m_N - m_N1; i < m_N; i++)
				{

					lines[i]->Rotate(t);
					lines[i]->Recolor(first_c);
					spheres[i]->Rotate(t);
					spheres[i]->Recolor(first_c);
				}
			}
		}
	}
	void Paint(int m_N, int m_N1, std::vector<Line*>& lines, std::vector<Sphere*>& spheres, std::unique_ptr<Line>& pillar, Camera& m_camera)
	{
		int sphere_size = spheres[0]->Get_Size();
		int line_size = lines[0]->Get_Size();
		for (int i = 0; i < sphere_size; i++)
		{


			for (int j = 0; j < m_N; j++)
				m_camera.ProjectPoint(spheres[j]->Get_Points(i), spheres[j]->Get_Color());

		}
		for (int i = 0; i < line_size; i++)
		{

			for (int j = 0; j < m_N; j++)
				m_camera.ProjectPoint(lines[j]->Get_Points(i), lines[j]->Get_Color());
		}
		for (int i = 0; i < pillar->Get_Size(); i++)
		{
			m_camera.ProjectPoint(pillar->Get_Points(i), { 0, 255 ,255, 255 });
		}
	}
}