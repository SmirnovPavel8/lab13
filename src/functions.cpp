#include<functions.hpp>
namespace mt
{
	void Rotation(int m_N, int m_N1, double& t, bool& flag, bool& flag_c, Pixel& first_c, Pixel& second_c, std::vector<Line*>& lines, std::vector<Sphere*>& spheres)
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
				flag_c = true;
				for (int i = 0; i < m_N1; i++)
				{
					lines[i]->Rotate(t);
					spheres[i]->Rotate(t);

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
					spheres[i]->Rotate(t);

				}
			}
		}
	}
	void Paint(int m_N, int m_N1,bool flag_c,Pixel first_c,Pixel second_c,std::vector<Line*>& lines, std::vector<Sphere*>& spheres, std::unique_ptr<Line>& pillar ,Camera& m_camera)
	{
		int sphere_size = spheres[0]->Get_Size();
		int line_size = lines[0]->Get_Size();
		for (int i = 0; i < sphere_size; i++)
		{
			//m_camera->ProjectPoint(circle->Get_Points(i), { 255, 0 ,0, 255 });
			//m_camera->ProjectPoint(circle1->Get_Points(i), { 0, 0 ,255, 255 });
			for (int j = 0; j < m_N; j++)
				m_camera.ProjectPoint(spheres[j]->Get_Points(i), { 255,0,0,255 });
			if (flag_c == true)
				for (int k = 0; k < m_N1; k++)
				{
					m_camera.ProjectPoint(spheres[k]->Get_Points(i), first_c);
				}
			if (flag_c == false)
				for (int h = m_N - m_N1; h < m_N; h++)
				{
					m_camera.ProjectPoint(spheres[h]->Get_Points(i), second_c);
				}
		}
		for (int i = 0; i < line_size; i++)
		{
			//m_camera->ProjectPoint(line->Get_Points(i), { 0, 255 ,0, 255 });
			//m_camera->ProjectPoint(line1->Get_Points(i), { 0, 255 ,255, 255 });
			for (int j = 0; j < m_N; j++)
				m_camera.ProjectPoint(lines[j]->Get_Points(i), { 0, 255 ,255, 255 });
		}
		for (int i = 0; i < pillar->Get_Size(); i++)
		{
			m_camera.ProjectPoint(pillar->Get_Points(i), { 0, 255 ,255, 255 });
		}
	}
}